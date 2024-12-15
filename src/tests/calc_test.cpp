#include "../cpp_back/calc.hpp"

#include <gtest/gtest.h>
using namespace std;
using namespace s21;

TEST(basic_test, arithmetic_test) {
  vector<string> expressions{
      "2 + (48.643 - 394) * 4",
      "-4 + 9.004 - (583 * (-3)) / 9.05",
      "0.35 * 30485",
      "47mod 5 / 3",
      "-(-5.537 +89.097 - 325) * (-(-5))",
      "757.09 * (-495)",
      "93.0543 + 5^3",
      "11^5 / 7.08",
      "3 * (-sqrt(4 + 9))",
      "sqrt(2^2 + 7^2) * 32 - 9 /3.98",
  };

  vector<double> answers{
      2 + (48.643 - 394) * 4,
      (-4 + 9.004 - (583 * (-3)) / 9.05),
      0.35 * 30485,
      (47 % 5) / 3.0,
      -(-5.537 + 89.097 - 325) * -(-5),
      757.09 * -495,
      93.0543 + pow(5, 3),
      pow(11, 5) / 7.08,
      3 * (-sqrt(4 + 9)),
      sqrt(pow(2, 2) + pow(7, 2)) * 32 - 9 / 3.98,
  };

  int index = 0;
  double result = 0;
  bool check_res = false;
  for (string& str : expressions) {
    check_res = calculate(str, result, 0);
    if (!check_res) {
      cout << "calculate error!!!!" << endl;
      result = 0;
    }
    ASSERT_NEAR(result, answers[index++], DBL_EPSILON);
  }
}

TEST(basic_test, sin_test) {
  vector<string> expressions{"sin(0)",
                             "sin(1)",
                             "sin(3.141593)+sin(-45)",
                             "sin(3.141593/2)",
                             "sin(-3.141593/2)",
                             "2*sin(3*3.141593/2)",
                             "sin (-3*3.141593/2)",
                             "sin(5.1234567890123456)",
                             "3+(-sin(9+9))"};

  vector<double> answers{sin(0),
                         sin(1),
                         sin(3.141593) + sin(-45),
                         sin(3.141593 / 2),
                         sin(-3.141593 / 2),
                         2 * sin(3 * 3.141593 / 2),
                         sin(-3 * 3.141593 / 2),
                         sin(5.1234567890123456),
                         3 + -sin(9 + 9)};

  int index = 0;
  double result = 0;
  bool check_res = false;
  for (string& str : expressions) {
    check_res = calculate(str, result, 0);
    if (!check_res) {
      cout << "calculate error!!!!" << endl;
      result = 0;
    }
    ASSERT_NEAR(result, answers[index++], DBL_EPSILON);
  }
}

TEST(basic_test, cos_test) {
  vector<string> expressions{"cos(0)",
                             "cos(3.1415926)+cos(-45)",
                             "cos(3.1415926/2)",
                             "cos(-3.1415926/2)",
                             "2*cos(3*3.1415926/2)",
                             "cos(-3*3.1415926/2)",
                             "cos(5.1234567890123456)",
                             "3+(-cos(9+9))"};

  vector<double> answers{cos(0),
                         cos(3.1415926) + cos(-45),
                         cos(3.1415926 / 2),
                         cos(-3.1415926 / 2),
                         2 * cos(3 * 3.1415926 / 2),
                         cos(-3 * 3.1415926 / 2),
                         cos(5.1234567890123456),
                         3 + -cos(9 + 9)};

  int index = 0;
  double result = 0;
  bool check_res = false;
  for (string& str : expressions) {
    check_res = calculate(str, result, 0);
    if (!check_res) {
      cout << "calculate error!!!!" << endl;
      result = 0;
    }
    ASSERT_NEAR(result, answers[index++], DBL_EPSILON);
  }
}
TEST(basic_test, tan_test) {
  vector<string> expressions{"tan(0)",
                             "tan(3.1415926)+tan(-45)",
                             "tan(3.1415926/2)",
                             "tan(-3.1415926/2)",
                             "2*tan(3*3.1415926/2)",
                             "tan(-3*3.1415926/2)",
                             "tan(5.1234567890123456)",
                             "3+(-tan(9 + 9))"};

  vector<double> answers{tan(0),
                         tan(3.1415926) + tan(-45),
                         tan(3.1415926 / 2),
                         tan(-3.1415926 / 2),
                         2 * tan(3 * 3.1415926 / 2),
                         tan(-3 * 3.1415926 / 2),
                         tan(5.1234567890123456),
                         3 + -tan(9 + 9)};

  int index = 0;
  double result = 0;
  bool check_res = false;
  for (string& str : expressions) {
    check_res = calculate(str, result, 0);
    if (!check_res) {
      cout << "calculate error!!!!" << endl;
      result = 0;
    }
    ASSERT_NEAR(result, answers[index++], DBL_EPSILON);
  }
}
TEST(basic_test, asin_test) {
  vector<string> expressions{"asin(0)",
                             "asin(1)",
                             "asin(-1)",
                             "asin(-0.7)+94*4",
                             "9*asin(0.0001)-2.987",
                             "asin (-0.8/2)",
                             "asin(0.1234567890123456)",
                             "3+(-asin(-0.007))"};

  vector<double> answers{asin(0),
                         asin(1),
                         asin(-1),
                         asin(-0.7) + 94 * 4,
                         9 * asin(0.0001) - 2.987,
                         asin(-0.8 / 2),
                         asin(0.1234567890123456),
                         3 + -asin(-0.007)};

  int index = 0;
  double result = 0;
  bool check_res = false;
  for (string& str : expressions) {
    check_res = calculate(str, result, 0);
    if (!check_res) {
      cout << "calculate error!!!!" << endl;
      result = 0;
    }
    ASSERT_NEAR(result, answers[index++], DBL_EPSILON);
  }
}
TEST(basic_test, acos_test) {
  vector<string> expressions{"acos(0)",
                             "acos(1)",
                             "acos(-1)",
                             "acos(-0.7) + 94 * 4",
                             "9*acos(0.0001)-2.987",
                             "acos(-0.8/2)",
                             "acos(0.1234567890123456)",
                             "3+(-acos(-0.007))"};

  vector<double> answers{acos(0),
                         acos(1),
                         acos(-1),
                         acos(-0.7) + 94 * 4,
                         9 * acos(0.0001) - 2.987,
                         acos(-0.8 / 2),
                         acos(0.1234567890123456),
                         3 + -acos(-0.007)};

  int index = 0;
  double result = 0;
  bool check_res = false;
  for (string& str : expressions) {
    check_res = calculate(str, result, 0);
    if (!check_res) {
      cout << "calculate error!!!!" << endl;
      result = 0;
    }
    ASSERT_NEAR(result, answers[index++], DBL_EPSILON);
  }
}
TEST(basic_test, atan_test) {
  vector<string> expressions{"atan(0)",
                             "atan(1)",
                             "atan(-1)",
                             "atan(-0.7)+94*4",
                             "9*atan(0.0001)-2.987",
                             "2*atan(1 / 2)",
                             "atan(-0.8/2)",
                             "atan(0.1234567890123456)",
                             "3+(-atan(-0.007))"};

  vector<double> answers{atan(0),
                         atan(1),
                         atan(-1),
                         atan(-0.7) + 94 * 4,
                         9 * atan(0.0001) - 2.987,
                         2 * atan(1 / 2.0),
                         atan(-0.8 / 2),
                         atan(0.1234567890123456),
                         3 + -atan(-0.007)};

  int index = 0;
  double result = 0;
  bool check_res = false;
  for (string& str : expressions) {
    check_res = calculate(str, result, 0);
    if (!check_res) {
      cout << "calculate error!!!!" << endl;
      result = 0;
    }
    ASSERT_NEAR(result, answers[index++], DBL_EPSILON);
  }
}
TEST(basic_test, ln_log_test) {
  vector<string> expressions{"ln(9)",
                             "log(1)",
                             "log(10)",
                             "log(25)",
                             "ln(348*8-293)+93234",
                             "9*ln(83*32)-2.987",
                             "ln(0.8/2)",
                             "ln(0.1234567890123456)",
                             "3+(-ln(0.007))"};

  vector<double> answers{log(9),
                         log10(1),
                         log10(10),
                         log10(25),
                         log(348 * 8 - 293) + 93234,
                         9 * log(83 * 32) - 2.987,
                         log(0.8 / 2),
                         log(0.1234567890123456),
                         3 + -log(0.007)};

  int index = 0;
  double result = 0;
  bool check_res = false;
  for (string& str : expressions) {
    check_res = calculate(str, result, 0);
    if (!check_res) {
      cout << "calculate error!!!!" << endl;
      result = 0;
    }
    ASSERT_NEAR(result, answers[index++], DBL_EPSILON);
  }
}
TEST(basic_test, x_test_1) {
  string str{"cos(x)"};
  double result = 0;
  bool check_res = false;

  for (double x = 0; x <= 10; x++) {
    check_res = calculate(str, result, x);
    if (!check_res) {
      cout << "calculate error!!!!" << endl;
      result = 0;
    }
    ASSERT_NEAR(result, cos(x), DBL_EPSILON);
  }
}
TEST(basic_test, x_test_2) {
  string str{"sin(2 * x) + 5.5"};
  double result = 0;
  bool check_res = false;

  for (double x = 0; x <= 10; x++) {
    check_res = calculate(str, result, x);
    if (!check_res) {
      cout << "calculate error!!!!" << endl;
      result = 0;
    }
    ASSERT_NEAR(result, sin(2 * x) + 5.5, DBL_EPSILON);
  }
}
TEST(basic_test, x_test_3) {
  string str{"9*ln(x*3.2)-2.987"};
  double result = 0;
  bool check_res = false;

  for (double x = 0; x <= 10; x++) {
    check_res = calculate(str, result, x);
    if (!check_res) {
      cout << "calculate error!!!!" << endl;
      result = 0;
    }
    ASSERT_DOUBLE_EQ(result, (9 * log(x * 3.2) - 2.987));
  }
}
TEST(basic_test, x_test_4) {
  string str{"2 * log(x) + ln(x)"};
  double result = 0;
  bool check_res = false;

  for (double x = 0; x <= 10; x++) {
    check_res = calculate(str, result, x);
    if (!check_res) {
      cout << "calculate error!!!!" << endl;
      result = 0;
    }
    ASSERT_DOUBLE_EQ(result, (2 * log10(x) + log(x)));
  }
}
TEST(basic_test, x_test_5) {
  string str{"94.0003+x*2"};
  double result = 0;
  bool check_res = false;

  for (double x = 0; x <= 10; x++) {
    check_res = calculate(str, result, x);
    if (!check_res) {
      cout << "calculate error!!!!" << endl;
      result = 0;
    }
    ASSERT_NEAR(result, 94.0003 + x * 2, DBL_EPSILON);
  }
}
TEST(basic_test, x_test_6) {
  string str{"x+3+x^2-3"};
  double result = 0;
  bool check_res = false;

  for (double x = 0; x <= 10; x++) {
    check_res = calculate(str, result, x);
    if (!check_res) {
      cout << "calculate error!!!!" << endl;
      result = 0;
    }
    ASSERT_NEAR(result, (x + 3 + pow(x, 2) - 3), DBL_EPSILON);
  }
}
TEST(basic_test, error_test) {
  vector<string> expressions{"ln(9))", "sdfsdaf", "sig(21)+3",   "lot(25)",
                             "2++3-1", "--31-2",  "21()12.25.25"};

  double result = 0;
  bool check_res = false;
  for (string& str : expressions) {
    check_res = calculate(str, result, 0);
    ASSERT_FALSE(check_res);
  }
}

int main(int argc, char* argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
