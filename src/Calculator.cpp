/*!
\file
\brief основной файл содержащий методы класса Calc
*/
#include "Calculator.h"

void Calc::getButtonClicked(const QString& str) {
  expr_str->append(str);

  emit sendExp(*expr_str);
}
void Calc::equalProcessing() {
  double result = 0;
  QString res;
  if (calculate(&result)) {
    res.setNum(result, 'f', 7);
    display->setText(res);
  } else
    display->setText("wrong expression");
}

bool Calc::calculate(double* result) {
  bool res = false;

  res = s21::calculate(expr_str->toStdString(), *result, spinBoxSetX->value());
  printf("result ===###== test: %.5f\n", *result);

  return res;
}
void Calc::clearStr() {
  expr_str->clear();
  hasX = false;
}

void Calc::setX() {
  if (!hasX) hasX = true;
}

void Calc::setPlot() {
  plot_x = new QVector<double>;
  plot_y = new QVector<double>;

  std::string tmp_str = expr_str->toStdString();

  bool check = 0;
  double result = 0;

  for (double i = spinBoxXmin->value(); i < spinBoxXmax->value(); i += 0.1) {
    check = s21::calculate(tmp_str, result, i);
    plot_x->append(i);
    plot_y->append(result);
  }

  custom_plot->addGraph();
  custom_plot->graph(0)->setData(*plot_x, *plot_y);

  custom_plot->xAxis->setLabel("x");
  custom_plot->yAxis->setLabel("y");

  custom_plot->xAxis->setRangeUpper(spinBoxXmax->value());
  custom_plot->xAxis->setRangeLower(spinBoxXmin->value());

  custom_plot->yAxis->setRangeUpper(spinBoxYmax->value());
  custom_plot->yAxis->setRangeLower(spinBoxYmin->value());

  custom_plot->replot();

  custom_plot->show();

  plot_y->clear();
  plot_x->clear();
}
