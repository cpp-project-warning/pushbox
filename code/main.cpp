#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "APP/App.h"
int main(int argc, char *argv[])
{
#if defined(Q_OS_WIN)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    
    QGuiApplication a(argc, argv);
    App app;
    app.run();
//    QQmlApplicationEngine engine;
//    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
//    if (engine.rootObjects().isEmpty())
 //       return -1;

    return a.exec();
}
