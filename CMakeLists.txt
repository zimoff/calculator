cmake_minimum_required(VERSION 3.2)


set(PROJ_NAME s21_calc)
set(TEST_NAME s21_calc_test)
set(TEST_CPP_NAME s21_calc_cpp_test)

project(${PROJ_NAME})


set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON) 
set(CMAKE_AUTOUIC ON)

set(CMAKE_BUILD_TYPE Debug)

if(CMAKE_VERSION VERSION_LESS "3.7.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()


find_package(Qt6 COMPONENTS Widgets PrintSupport REQUIRED)
if(NOT Qt6_FOUND)
    message(SEND_ERROR "find Qt failed !!!")
    return()
else()
    message("Qt has found!")
endif()

file(GLOB PROJ_SRC "src/*")
file(GLOB LIB_CPP_BACK "src/cpp_back/*.cpp")
file(GLOB TEST_CPP_SRC "src/cpp_back/*.cpp" "src/tests/*.cpp")
#file(GLOB LIB_SRC "src/calc/*.c")
#file(GLOB LIB_SRC "src/calc/*.c" "src/calc/banking/*.c")
#file(GLOB TEST_SRC "src/calc/*.c" "src/calc/test/s21_test.c" "src/calc/test/cases/*.c")

add_library(cpp_calc STATIC ${LIB_CPP_BACK})
#add_library(calc STATIC ${LIB_SRC})

message("=================== proj_src: " ${PROJ_SRC})
message("=================== lib_cpp_back: " ${LIB_CPP_BACK})
message("=================== test_cpp_src: " ${TEST_CPP_SRC})
#message("=================== test_src: " ${TEST_SRC})
#message("=================== lib_src: " ${LIB_SRC})


add_executable(${PROJ_NAME} ${PROJ_SRC})
target_link_libraries(${PROJ_NAME} Qt6::Widgets Qt6::PrintSupport cpp_calc)
#target_link_libraries(${PROJ_NAME} Qt6::Widgets Qt6::PrintSupport calc cpp_calc)

#add_executable(${TEST_NAME} ${TEST_SRC})
#target_link_libraries(${TEST_NAME} check subunit gcov)
#target_compile_options(${TEST_NAME} PRIVATE -Wall -Werror -Wextra --coverage -g)

add_executable(${TEST_CPP_NAME} ${TEST_CPP_SRC})
target_link_libraries(${TEST_CPP_NAME} gcov gtest)
target_compile_options(${TEST_CPP_NAME} PRIVATE -Wall --coverage -g)

message("test_source_dir: " ${CMAKE_SOURCE_DIR})

#add_custom_command(TARGET ${TEST_NAME}
    #COMMAND echo "=================== GCOV ===================="
    #COMMAND ./${TEST_NAME}
    #COMMAND gcov -b -p -c ${CMAKE_BINARY_DIR}/CMakeFiles/${TEST_NAME}.dir/src/calc/*.gcno
    #COMMAND mkdir report
    #COMMAND gcovr -o ./report/gcov_report.html --html --html-details -g -k -r ../ --html --html-details 
	#COMMAND open report/gcov_report.html
    #)

add_custom_target(gcov_report 
    DEPENDS ${TEST_CPP_NAME}
    COMMAND echo "=================== GCOV ===================="
    COMMAND ./${TEST_CPP_NAME}
    COMMAND gcov -b -p -c ${CMAKE_BINARY_DIR}/CMakeFiles/${TEST_CPP_NAME}.dir/src/cpp_back/*.gcno
    COMMAND mkdir report
    COMMAND gcovr -o ./report/gcov_report.html --html --html-details -g -k -r ../ --html --html-details 
	COMMAND open report/gcov_report.html
    )

#add_custom_command(TARGET ${TEST_CPP_NAME}
    #COMMAND echo "=================== GCOV ===================="
    #COMMAND ./${TEST_CPP_NAME}
    #COMMAND gcov -b -p -c ${CMAKE_BINARY_DIR}/CMakeFiles/${TEST_CPP_NAME}.dir/src/cpp_back/*.gcno
    #COMMAND mkdir report
    #COMMAND gcovr -o ./report/gcov_report.html --html --html-details -g -k -r ../ --html --html-details 
	#COMMAND open report/gcov_report.html
    #)

add_custom_target(check_clang
    COMMAND clang-format -style=Google -n ${CMAKE_SOURCE_DIR}/src/*.cpp
    COMMAND clang-format -style=Google -n ${CMAKE_SOURCE_DIR}/src/*.h
    COMMAND clang-format -style=Google -n ${CMAKE_SOURCE_DIR}/src/calc/*.c
    COMMAND clang-format -style=Google -n ${CMAKE_SOURCE_DIR}/src/calc/*.h
    COMMAND clang-format -style=Google -n ${CMAKE_SOURCE_DIR}/src/calc/banking/*.c
    COMMAND clang-format -style=Google -n ${CMAKE_SOURCE_DIR}/src/calc/test/*.c
    COMMAND clang-format -style=Google -n ${CMAKE_SOURCE_DIR}/src/calc/test/*.h
    COMMAND clang-format -style=Google -n ${CMAKE_SOURCE_DIR}/src/calc/test/cases/*.c
    )

add_custom_target(format_clang
    COMMAND clang-format -style=Google -i ${CMAKE_SOURCE_DIR}/src/*.cpp
    COMMAND clang-format -style=Google -i ${CMAKE_SOURCE_DIR}/src/*.h
    COMMAND clang-format -style=Google -i ${CMAKE_SOURCE_DIR}/src/calc/*.c
    COMMAND clang-format -style=Google -i ${CMAKE_SOURCE_DIR}/src/calc/*.h
    COMMAND clang-format -style=Google -i ${CMAKE_SOURCE_DIR}/src/calc/banking/*.c
    COMMAND clang-format -style=Google -i ${CMAKE_SOURCE_DIR}/src/calc/test/*.c
    COMMAND clang-format -style=Google -i ${CMAKE_SOURCE_DIR}/src/calc/test/*.h
    COMMAND clang-format -style=Google -i ${CMAKE_SOURCE_DIR}/src/calc/test/cases/*.c
    )

#add_custom_target( clean
    #COMMAND enho "its clean cmd" 
    #)

#install(TARGETS ${PROJ_NAME} DESTINATION /home/zimoff/21_school/my_projects)

