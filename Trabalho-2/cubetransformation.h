#ifndef CUBETRANSFORMATION_H
#define CUBETRANSFORMATION_H

#include <QVector3D>
#include <vector>
using namespace std;

class CubeTransformation
{
public:
    static vector<QVector3D> Transform(vector<QVector3D>&, int tab);

private:
    // returns the transformation matrix to a translation alongside "Z"

    static vector<QVector3D> applyTransformation (vector<QVector3D>&, vector<vector<float>>);
    static vector<vector<float>> translation (float x, float y, float z);
    static vector<vector<float>> transformScale (float sx, float sy, float sz);
    static vector<vector<float>> rotateX(float angle);
    static vector<vector<float>> rotateY(float angle);
    static vector<vector<float>> rotateZ(float angle);

 };

#endif // CUBETRANSFORMATION_H
