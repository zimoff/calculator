#include "calc.hpp"
#include  <iostream>

using namespace std;

int s21::str_to_inf(string str, list<s21::Node>& infix, double x) {
  set<char> oper{'+', '-', '*', '/', '^', '(', ')'};
  int res = 0;
  bool res_check = true;
  size_t str_index = 0;
  int brack_counter = 0;

  while (str_index < str.size() && res_check && res >= 0) {
    if (islower(str[str_index])) {
      if (str[str_index] == 'x') {
        infix.push_back(Node(x));
        str_index++;
      } else
        res = check_functions(str, str_index, infix);
    }
    if(str[str_index] == '.') {
        res = -1;
        break;
    }
    
    if (isdigit(str[str_index])) {
      res_check = check_nums(str, str_index, infix);
      if (!res_check) res = -1;
    }

    if (str[str_index] == ' ') str_index++;

    if (oper.end() != oper.find(str[str_index]))
      check_operands(str, str_index, brack_counter, infix);
  }

  if (brack_counter != 0) res = -1;

  return res;
}
bool s21::check_nums(string& str, size_t& index, list<s21::Node>& infix) {
  double num = 0;
  int dot_counter = 0;

  num = stod(str.substr(index));
  while (isdigit(str[index]) || str[index] == '.') {
    dot_counter = (str[index] == '.') ? dot_counter + 1 : dot_counter;
    index++;
  }

  infix.push_back(Node(num));

  return (dot_counter > 1) ? false : true;
}

// num - 0;
// ( + , - ) - 1;
// ( * , / ) - 2;
// ( sin , cos ) - 3;
// ( ^ ) - 4;
// ),( - 5;

int s21::check_functions(string& str, size_t& index, list<s21::Node>& infix) {
  int res = -1;

  array<pair<string, char>, 10> comp_functions{
      pair("sin", 's'),  pair("cos", 'c'),  pair("tan", 't'),
      pair("asin", 'S'), pair("acos", 'C'), pair("atan", 'T'),
      pair("sqrt", 'q'), pair("ln", 'l'),   pair("log", 'L'),
      pair("mod", 'm')};

  for (size_t i = 0; i < comp_functions.size(); i++) {
    if (!str.compare(index, comp_functions[i].first.size(),
                     comp_functions[i].first)) {
      index += comp_functions[i].first.size();
      res = i;

      if (comp_functions[i].second == 'm')
        infix.push_back(Node(2, comp_functions[i].second, 0.0));
      else
        infix.push_back(Node(3, comp_functions[i].second, 0.0));

      break;
    }
  }

  return res;
}

bool s21::check_operands(string& str, size_t& index, int& brack_counter,
                         list<s21::Node>& infix) {
  // num - 0;
  // ( + , - ) - 1;
  // ( * , / ) - 2;
  // ( sin , cos ) - 3;
  // ( ^ ) - 4;
  // ),( - 5;

  //{'+','-','*','/','^'}

  if (str[index] == '(') {
    brack_counter++;
    infix.push_back(Node(5, str[index], 0.0));

    if ((index < str.size() - 1) && (str[index + 1] == '-')) {
      infix.push_back(Node(0));
    }
  }

  if (str[index] == ')') {
    infix.push_back(Node(5, str[index], 0.0));
    brack_counter--;
  }

  if (str[index] == '+' || str[index] == '-') {
    if (str[index] == '-' && index == 0) infix.push_back(Node(0));

    infix.push_back(Node(1, str[index], 0.0));
  }

  if ((str[index] == '*') || (str[index] == '/'))
    infix.push_back(Node(2, str[index], 0.0));

  if (str[index] == '^') infix.push_back(Node(4, str[index], 0.0));

  index++;

  return true;
}
