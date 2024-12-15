#include <QtWidgets>

#include "Calculator.h"
//#include "Credit.h"
//#include "Deposit.h"

int main(int argc, char** argv) {
  QApplication app(argc, argv);
  setlocale(LC_ALL, "C");

  Calc calc(&app);
  calc.show();

  return app.exec();
}
