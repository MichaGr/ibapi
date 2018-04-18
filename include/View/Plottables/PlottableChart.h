#ifndef PLOTTABLECHART_H
#define PLOTTABLECHART_H

#include "PlottableItem.h"

class PlottableChart : public PlottableItem<QCPFinancial>
{
public:
    PlottableChart(QCPFinancial* plottable);
    ~PlottableChart();


private:

};

#endif //PLOTTABLECHART_H
