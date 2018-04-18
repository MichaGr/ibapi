#ifndef PLOTTABLEITEM_H
#define PLOTTABLEITEM_H


#include "qcustomplot.h"

template<QCPAbstractPlottable T>
class PlottableItem
{
public:
    PlottableItem(T* plottable);
    virtual ~PlottableItem();

protected:
    T* m_plottable;

};


#endif //PLOTTABLEITEM_H
