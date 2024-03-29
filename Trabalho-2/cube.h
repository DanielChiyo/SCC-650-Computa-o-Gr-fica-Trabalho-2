#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>
#include <QVector3D>
#include <vector>

using namespace std;

class Cube : public QGLWidget
{
private:
    vector<QVector3D>      vertices;         // 8 vertices
    vector<vector<size_t>> faces;            // 6 faces of 4 vertices
    vector<QColor>         faceColors;       // 6 faces
    int tab = 0;

public:
    Cube(QWidget *parent = nullptr);

protected:
    void initializeGL();
    void resizeGL(int width, int height);
    void paintGL();

private:
    void draw();
    vector<QVector3D> getVertices();
};

#endif // GLWIDGET_H
