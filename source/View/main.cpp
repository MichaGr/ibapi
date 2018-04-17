#include <QGuiApplication>
#include <QApplication>
#include <QQmlApplicationEngine>

#include "PlotItem.h"

int main(int argc, char* argv[])
{
#if defined(Q_OS_WIN)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QApplication app(argc, argv);

    qmlRegisterType<PlotItem>("Plot",1,0,"PlotItem");
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
