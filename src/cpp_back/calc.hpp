/*!
\file
\brief Заголовочный файл с описанием функций для высисления выражения
*/
#pragma once
#include <array>
#include <cmath>
#include <list>
#include <set>
#include <stack>
#include <string>

using namespace std;
/*!
namespace s21;
\brief основное пространство имен
*/
namespace s21 {

/*! \brief структура с которой работает алгоритм дейкстры
 *
используется для преобразования в инфиксную запись и рассчётов для получения
финильного результата*/
struct Node {
  size_t priority = 0;
  /*!<
     \brief приоритет выполнения операции

      num - 0;\n
      + , -  => 1;\n
      * , /  => 2;\n
      sin , cos  => 3;\n
      ^  => 4;\n
     ),( => 5;\n

     */
  char operand = 'n';  ///< в зависимости от значения операнда алгоритм
                       ///< выполняет нужную фуркцию
  double
      num;  ///< числовое значение подстовояемое в формулу если операнд равен n

  /*!\brief конструктор 1*/
  Node(double num) : num{num} {};
  /*!\brief конструктор 2*/
  Node(size_t priority, char operand, double num)
      : priority{priority}, operand{operand}, num{num} {};
};

/*!
\brief парсит строку с инфиксным выражением в лист с инфиксным выражением
\param[in] str входная строка содержащая математическое выражение
\param[in] infix лист в который парсится входная строка для последующей
обработки \param[in] x значение x для подстановки в выражение если присуцтвует x
\return возвращает -1 если во входной строке была ошибка
*/
int str_to_inf(string str, list<Node>& infix, double x);
/*!
\brief часть функции str_to_inf парсит строку в число
\return возвращает -1 если во входной строке была ошибка
*/
bool check_nums(string& str, size_t& index, list<Node>& infix);
/*!
\brief часть функции str_to_inf парсит строковое название функции в Node с
соотведствующим операндом \return возвращает -1 если во входной строке была
ошибка
*/
int check_functions(string& str, size_t& index, list<Node>& infix);
/*!
\brief часть функции str_to_inf парсит строковое представление операнда(+,- и
т.д.) в Node с соотведствующим операндом \return возвращает -1 если во входной
строке была ошибка
*/
bool check_operands(string& str, size_t& index, int& brack_counter,
                    list<Node>& infix);

/*!
\brief преобразует список в инфиксном порядке в стек в постфиксном порядке
готовом для рассчетов
*/
stack<Node> inf_to_post(list<Node>& infix);
/*!
\brief просто перебрасывает значения из одного стека в другой с учётом
приоритета оперендов
*/
void extract(stack<Node>& infix, stack<Node>& postfix,
             const size_t priority_count);

/*!
\brief берет значения из стека с инфиксным порядком выполняет операцию в соотв.
с операндом \return возвращает 1 если в postfix стеке была ошибка
*/
int operate(stack<Node>& postfix, stack<Node>& bufer);
/*!
\brief обрабатывает postfix стек и записывает результат в res
\return возвращает 1 если в postfix стеке была ошибка
*/
int postfix_processing(stack<Node>& postfix, double& res);
/*!
\brief основная функция калькулятора, использует все остальные функции для
рассчёта значения полученного выражения \param[in] str входная строка содержащая
математическое выражение \param[out] result результат вычесляемого выражения
\param[in] x значение x для подстановки в выражение если присуцтвует x
\return возвращает false если в str была ошибка
*/
bool calculate(string str, double& result, const double& x);

}  // namespace s21
