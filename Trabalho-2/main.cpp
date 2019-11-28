#include <QApplication>
#include "cube.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    if (!QGLFormat::hasOpenGL())
        qFatal("This system has no OpenGL support");

    Cube cube;
    cube.resize(500, 500);
    cube.show();

    return app.exec();
}
