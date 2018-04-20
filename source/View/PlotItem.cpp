#include "PlotItem.h"
#include "qcustomplot.h"
#include <QDebug>
#include <stdlib.h>

PlotItem::PlotItem( QQuickItem* parent ) : QQuickPaintedItem( parent )
    , m_customPlot( nullptr ), m_timerId( 0 )
{
    setFlag( QQuickItem::ItemHasContents, true );
    setAcceptedMouseButtons( Qt::AllButtons );

    connect( this, &QQuickPaintedItem::widthChanged, this, &PlotItem::updateCustomPlotSize );
    connect( this, &QQuickPaintedItem::heightChanged, this, &PlotItem::updateCustomPlotSize );
}

PlotItem::~PlotItem()
{
    delete m_customPlot;
    m_customPlot = nullptr;

    if(m_timerId != 0) {
        killTimer(m_timerId);
    }
}

void PlotItem::initCustomPlot()
{
    m_customPlot = new QCustomPlot();

    updateCustomPlotSize();
    m_customPlot->legend->setVisible(true);

    // generate two sets of random walk data (one for candlestick and one for ohlc chart):
    int n = 50000;
    QVector<double> time(n), value1(n), value2(n);
    QDateTime start = QDateTime(QDate(2014, 6, 11));
    start.setTimeSpec(Qt::UTC);
    double startTime = start.toTime_t();
    double binSize = 3600*24; // bin data in 1 day intervals
    time[0] = startTime;
    value1[0] = 60;
    value2[0] = 20;
    qsrand(9);
    for (int i=1; i<n; ++i)
    {
      time[i] = startTime + 3600*i;
      value1[i] = value1[i-1] + (qrand()/(double)RAND_MAX-0.5)*10;
      value2[i] = value2[i-1] + (qrand()/(double)RAND_MAX-0.5)*3;
    }

    // create candlestick chart:
    QCPFinancial *candlesticks = new QCPFinancial(m_customPlot->xAxis, m_customPlot->yAxis);
    candlesticks->setName("Candlestick");
    candlesticks->setChartStyle(QCPFinancial::csCandlestick);
    candlesticks->data()->set(QCPFinancial::timeSeriesToOhlc(time, value1, binSize, startTime));
    candlesticks->setWidth(binSize);
    candlesticks->setTwoColored(true);
    candlesticks->setBrushPositive(QColor(0, 250, 0));
    candlesticks->setBrushNegative(QColor(250, 0, 0));
    candlesticks->setPenPositive(QPen(QColor(0, 0, 0)));
    candlesticks->setPenNegative(QPen(QColor(0, 0, 0)));



    // interconnect x axis ranges of main and bottom axis rects:
//    connect(m_customPlot->xAxis, SIGNAL(rangeChanged(QCPRange)), volumeAxisRect->axis(QCPAxis::atBottom), SLOT(setRange(QCPRange)));
//    connect(volumeAxisRect->axis(QCPAxis::atBottom), SIGNAL(rangeChanged(QCPRange)), m_customPlot->xAxis, SLOT(setRange(QCPRange)));
    // configure axes of both main and bottom axis rect:
    QSharedPointer<QCPAxisTickerDateTime> dateTimeTicker(new QCPAxisTickerDateTime);
    dateTimeTicker->setDateTimeSpec(Qt::UTC);
    dateTimeTicker->setDateTimeFormat("dd.mm.yy");
//   volumeAxisRect->axis(QCPAxis::atBottom)->setTicker(dateTimeTicker);
//    volumeAxisRect->axis(QCPAxis::atBottom)->setTickLabelRotation(15);
    m_customPlot->xAxis->setBasePen(Qt::NoPen);
    m_customPlot->xAxis->setTickLabels(true);
    m_customPlot->xAxis->setTicks(true); // only want vertical grid in main axis rect, so hide xAxis backbone, ticks, and labels
    m_customPlot->xAxis->setTicker(dateTimeTicker);
    m_customPlot->rescaleAxes();
    m_customPlot->xAxis->scaleRange(1.025, m_customPlot->xAxis->range().center());
    m_customPlot->yAxis->scaleRange(1.1, m_customPlot->yAxis->range().center());

    // make axis rects' left side line up:
    QCPMarginGroup *group = new QCPMarginGroup(m_customPlot);
    m_customPlot->axisRect()->setMarginGroup(QCP::msLeft|QCP::msRight, group);
//    volumeAxisRect->setMarginGroup(QCP::msLeft|QCP::msRight, group);


    connect( m_customPlot, &QCustomPlot::afterReplot, this, &PlotItem::onReplot );
    m_customPlot->setInteractions(QCP::iRangeDrag | QCP::iSelectPlottables);
    m_customPlot->replot();
}


void PlotItem::paint( QPainter* painter )
{
    if (m_customPlot)
    {
        QPixmap    picture( boundingRect().size().toSize() );
        QCPPainter qcpPainter( &picture );

        m_customPlot->toPainter( &qcpPainter );

        painter->drawPixmap( QPoint(), picture );
    }
}

void PlotItem::mousePressEvent( QMouseEvent* event )
{
    if(event->button() == Qt::RightButton)
    {
        emit rightClicked(event->pos().x(),event->pos().y());
    }
    routeMouseEvents( event );
}

void PlotItem::mouseReleaseEvent( QMouseEvent* event )
{
//    qDebug() << Q_FUNC_INFO;
    routeMouseEvents( event );
}

void PlotItem::mouseMoveEvent( QMouseEvent* event )
{
    routeMouseEvents( event );
}

void PlotItem::mouseDoubleClickEvent( QMouseEvent* event )
{
//    qDebug() << Q_FUNC_INFO;
    routeMouseEvents( event );
}

void PlotItem::wheelEvent( QWheelEvent *event )
{
    routeWheelEvents( event );
}

void PlotItem::timerEvent(QTimerEvent *event)
{
//    static double t, U;
//    U = ((double)rand() / RAND_MAX) * 5;
//    m_customPlot->graph(0)->addData(t, U);
////    qDebug() << Q_FUNC_INFO << QString("Adding dot t = %1, S = %2").arg(t).arg(U);
//    t++;
//    m_customPlot->replot();
}

void PlotItem::graphClicked( QCPAbstractPlottable* plottable )
{
    qDebug() << Q_FUNC_INFO << QString( "Clicked" ).arg( plottable->name() );
}

void PlotItem::routeMouseEvents( QMouseEvent* event )
{
    if (m_customPlot)
    {
        QMouseEvent* newEvent = new QMouseEvent( event->type(), event->localPos(), event->button(), event->buttons(), event->modifiers() );
        QCoreApplication::postEvent( m_customPlot, newEvent );
    }
}

void PlotItem::routeWheelEvents( QWheelEvent* event )
{
    if (m_customPlot)
    {
        QWheelEvent* newEvent = new QWheelEvent( event->pos(), event->delta(), event->buttons(), event->modifiers(), event->orientation() );
        QCoreApplication::postEvent( m_customPlot, newEvent );
    }
}

void PlotItem::updateCustomPlotSize()
{
    if (m_customPlot)
    {
        m_customPlot->setGeometry(0, 0, (int)width(), (int)height());
        m_customPlot->setViewport(QRect(0, 0, (int)width(), (int)height()));
    }
}

void PlotItem::onReplot()
{
    qDebug() << Q_FUNC_INFO;
    update();
}

void PlotItem::removeSelectedGraph()
{
    if(m_customPlot->selectedGraphs().size() > 0)
    {
//        m_customPlot->removeGraph(m_customPlot->selectedGraphs().first());
        m_customPlot->selectedGraphs().first()->setPen(QPen(Qt::black));
        m_customPlot->selectedGraphs().first()->selectionDecorator()->setPen(QPen(QBrush(Qt::black),3));
        m_customPlot->replot();
    }
//    if (ui->customPlot->selectedGraphs().size() > 0)
//    {
//      ui->customPlot->removeGraph(ui->customPlot->selectedGraphs().first());
//      ui->customPlot->replot()
//    }
}

void PlotItem::horzScrollBarChanged(int value)
{
    if(qAbs(m_customPlot->xAxis->range().center()+value/100.0) > 0.01)
    {
        m_customPlot->xAxis->setRange(m_customPlot->xAxis->range().center(),3600.0*24.0*exp(value/10.0),Qt::AlignCenter);
        m_customPlot->replot();
    }
}

void PlotItem::vertScrollBarChanged(int value)
{
    if(qAbs(m_customPlot->yAxis->range().center()+value/100.0) > 0.01)
    {
        m_customPlot->yAxis->setRange(m_customPlot->yAxis->range().center(),5.0 * exp(value/10.0),Qt::AlignCenter);
        m_customPlot->replot();
    }
}

void PlotItem::startIBGateway(QString user, QString password)
{
    std::string command = "/home/michael/Jts/ibgateway/970/ibgateway username=" +
            user.toStdString() +
            " password=" +
            password.toStdString() +
            " &";

    system(command.c_str());
}
