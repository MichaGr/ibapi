#ifndef PLOTITEM_H
#define PLOTITEM_H

#include <QtQuick>
class QCustomPlot;
class QCPAbstractPlottable;

class PlotItem : public QQuickPaintedItem
{
    Q_OBJECT

public:
    PlotItem( QQuickItem* parent = 0 );
    virtual ~PlotItem();

    void paint( QPainter* painter );

    Q_INVOKABLE void initCustomPlot();
    Q_INVOKABLE void removeSelectedGraph();
    Q_INVOKABLE void horzScrollBarChanged(int value);
    Q_INVOKABLE void vertScrollBarChanged(int value);

signals:
    void rightClicked(unsigned int x,unsigned int y);

protected:
    void routeMouseEvents( QMouseEvent* event );
    void routeWheelEvents( QWheelEvent* event );

    virtual void mousePressEvent( QMouseEvent* event );
    virtual void mouseReleaseEvent( QMouseEvent* event );
    virtual void mouseMoveEvent( QMouseEvent* event );
    virtual void mouseDoubleClickEvent( QMouseEvent* event );
    virtual void wheelEvent( QWheelEvent *event );

    virtual void timerEvent(QTimerEvent *event);

private:
    QCustomPlot*         m_customPlot;
    int                  m_timerId;

private slots:
    void graphClicked( QCPAbstractPlottable* plottable );
    void onReplot();
    void updateCustomPlotSize();

}; //PlotItem



#endif //PLOTITEM_H
