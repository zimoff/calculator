#include "calc.hpp"
using namespace std;

stack<s21::Node> s21::inf_to_post(list<s21::Node>& infix) {
  stack<Node> postfix;
  stack<Node> bufer;
  stack<Node> exit;

  size_t priority_count = 0;

  while (!infix.empty()) {
    if (infix.front().operand == ')') {
      infix.pop_front();
      extract(bufer, exit, 5);

      if (bufer.empty())
        priority_count = 0;
      else
        priority_count = bufer.top().priority;

    } else if (infix.front().operand == '(') {
      priority_count = 0;
      bufer.push(infix.front());
      infix.pop_front();

    } else if (infix.front().operand == 'n') {
      exit.push(infix.front());
      infix.pop_front();

    } else if (infix.front().priority > priority_count) {
      priority_count = infix.front().priority;

      bufer.push(infix.front());
      infix.pop_front();

    } else {
      extract(bufer, exit, priority_count);

      if (bufer.empty() || bufer.top().operand == '(') {
        priority_count = 0;
      } else {
        priority_count = bufer.top().priority;
      }
    }
  }
  if (!bufer.empty()) extract(bufer, exit, 5);

  while (!exit.empty()) {
    postfix.push(exit.top());
    exit.pop();
  }

  // num - 0;
  // ( + , - ) - 1;
  // ( * , / ) - 2;
  // ( sin , cos ) - 3;
  // ( ^ ) - 4;
  // ),( - 5;

  return postfix;
}

void s21::extract(stack<Node>& in_, stack<s21::Node>& out_,
                  const size_t priority_count) {
  while (!in_.empty()) {
    if (priority_count < in_.top().priority) {
      break;
    }

    if (in_.top().operand == '(') {
      in_.pop();
      break;
    }

    out_.push(in_.top());
    in_.pop();
  }

  return;
}
