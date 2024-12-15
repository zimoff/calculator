#include "calc.hpp"
using namespace std;

bool s21::calculate(string str, double& result, const double& x) {
  int check_res = 0;

  list<Node> infix;

  check_res = str_to_inf(str, infix, x);  // ----- 1

  if (check_res < 0) return false;

  stack<Node> postfix = inf_to_post(infix);  // ----- 2

  check_res = postfix_processing(postfix, result);  // ----- 3

  return (check_res < 0) ? false : true;
}
int s21::postfix_processing(stack<Node>& postfix, double& res) {
  stack<Node> bufer;

  int check = 0;

  while (!postfix.empty()) {
    if (postfix.top().operand == 'n') {
      bufer.push(postfix.top());
      postfix.pop();
    } else {
      check = operate(postfix, bufer);
      if (check) {
        break;
      }
    }
  }

  if (!bufer.empty()) {
    res = bufer.top().num;
    bufer.pop();

  } else
    res = 0;

  if (!bufer.empty() || !postfix.empty()) check = -1;

  return check;
}

int s21::operate(stack<Node>& postfix, stack<Node>& bufer) {
  if (bufer.empty()) {
    return 1;
  }

  if (bufer.top().operand != 'n') {
    return 1;
  }

  int res = 0;

  double num1 = 0;
  double num2 = 0;

  char operand = postfix.top().operand;
  postfix.pop();

  switch (operand) {
    case 's':
      num1 = bufer.top().num;
      bufer.pop();

      bufer.push(Node(0, 'n', sin(num1)));
      break;
    case 'c':
      num1 = bufer.top().num;
      bufer.pop();
      bufer.push(Node(0, 'n', cos(num1)));
      break;
    case 't':
      num1 = bufer.top().num;
      bufer.pop();
      bufer.push(Node(0, 'n', tan(num1)));
      break;
    case 'S':
      num1 = bufer.top().num;
      bufer.pop();
      bufer.push(Node(0, 'n', asin(num1)));
      break;
    case 'C':
      num1 = bufer.top().num;
      bufer.pop();
      bufer.push(Node(0, 'n', acos(num1)));
      break;
    case 'T':
      num1 = bufer.top().num;
      bufer.pop();
      bufer.push(Node(0, 'n', atan(num1)));
      break;
    case 'q':
      num1 = bufer.top().num;
      bufer.pop();
      bufer.push(Node(0, 'n', sqrt(num1)));
      break;
    case 'l':
      num1 = bufer.top().num;
      bufer.pop();
      bufer.push(Node(0, 'n', log(num1)));
      break;
    case 'L':
      num1 = bufer.top().num;
      bufer.pop();
      bufer.push(Node(0, 'n', log10(num1)));
      break;

    case 'm':

      num2 = bufer.top().num;
      bufer.pop();

      if (bufer.empty() || bufer.top().operand != 'n') {
        res = 1;
        break;
      }

      num1 = bufer.top().num;
      bufer.pop();

      bufer.push(Node(0, 'n', fmod(num1, num2)));
      break;

    case '+':

      num1 = bufer.top().num;
      bufer.pop();

      if (bufer.empty() || bufer.top().operand != 'n') {
        res = 1;
        break;
      }

      num2 = bufer.top().num;
      bufer.pop();

      bufer.push(Node(0, 'n', num1 + num2));
      break;
    case '-':

      num2 = bufer.top().num;
      bufer.pop();

      if (bufer.empty() || bufer.top().operand != 'n') {
        res = 1;
        break;
      }

      num1 = bufer.top().num;
      bufer.pop();

      bufer.push(Node(0, 'n', num1 - num2));
      break;

    case '/':

      num2 = bufer.top().num;
      bufer.pop();

      if (bufer.empty() || bufer.top().operand != 'n') {
        res = 1;
        break;
      }

      num1 = bufer.top().num;
      bufer.pop();

      bufer.push(Node(0, 'n', num1 / num2));
      break;
    case '*':

      num1 = bufer.top().num;
      bufer.pop();

      if (bufer.empty() || bufer.top().operand != 'n') {
        res = 1;
        break;
      }

      num2 = bufer.top().num;
      bufer.pop();

      bufer.push(Node(0, 'n', num1 * num2));
      break;

    case '^':

      num2 = bufer.top().num;
      bufer.pop();

      if (bufer.empty() || bufer.top().operand != 'n') {
        res = 1;
        break;
      }

      num1 = bufer.top().num;
      bufer.pop();

      bufer.push(Node(0, 'n', pow(num1, num2)));
      break;
  }

  return res;
}
