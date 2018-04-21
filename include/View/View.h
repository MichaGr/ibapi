#ifndef VIEW_H
#define VIEW_H

#include <QObject>

class View : public QObject
{
    Q_OBJECT

public:
    View(QObject* parent = nullptr);
    ~View();

public slots:

    Q_INVOKABLE void addPlot();
protected:

private:


};


#endif //VIEW_H
