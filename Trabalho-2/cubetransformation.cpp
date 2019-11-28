#include "cubetransformation.h"

#include <QMatrix4x4>
#include <cmath>

vector<QVector3D> CubeTransformation::Transform(vector<QVector3D>& points, int tab)
{
    // moves the cube 10 units backwards,
    // so it can fit in the far / near clipping planes

    auto reg = translation(0,0,-10); // reg = região onde a camera renderiza (entre -5 e -15 em z)
    auto transformacoes = translation(0.5f,0.7f,0); //inicializando transformacoes
    auto vetorF = applyTransformation(points, transformacoes);

    //usar  tab para alternar entre os casos
    if (tab==0){
        //transformacoes = translation(0,0,0);
        vetorF = applyTransformation(points, transformacoes);
    }
    else if(tab==1){
        transformacoes = rotateX(25);
        vetorF = applyTransformation(points, transformacoes);
        transformacoes = rotateY(45);
        vetorF = applyTransformation(vetorF, transformacoes);
        transformacoes = rotateZ(65);
        vetorF = applyTransformation(vetorF, transformacoes);
    }
    else if(tab==2)
    {
        transformacoes = transformScale(0.7f,1.2f,1.1f);
        vetorF = applyTransformation(points, transformacoes);
    }
    else if(tab==3)
    {
        transformacoes = translation(1,0,0);
        vetorF = applyTransformation(points, transformacoes);
        transformacoes = rotateZ(45);
        vetorF = applyTransformation(vetorF, transformacoes);
    }
    else if(tab==4)
    {
        transformacoes = translation(0.5f,0,0);
        vetorF = applyTransformation(points, transformacoes);
        transformacoes = rotateX(45);
        vetorF = applyTransformation(vetorF, transformacoes);
        transformacoes = rotateY(45);
        vetorF = applyTransformation(vetorF, transformacoes);
        transformacoes = rotateZ(45);
        vetorF = applyTransformation(vetorF, transformacoes);
        transformacoes = transformScale(0.5f,0.7f,1.1f);
        vetorF = applyTransformation(vetorF, transformacoes);
    }
    else if(tab==5)
    {
        transformacoes = translation(0.5f,0,0);
        vetorF = applyTransformation(points, transformacoes);
        transformacoes = transformScale(0.5f,0.7f,1.1f);
        vetorF = applyTransformation(vetorF, transformacoes);
        transformacoes = rotateX(45);
        vetorF = applyTransformation(vetorF, transformacoes);
        transformacoes = rotateY(45);
        vetorF = applyTransformation(vetorF, transformacoes);
        transformacoes = rotateZ(45);
        vetorF = applyTransformation(vetorF, transformacoes);
    }
    else if(tab==6)
    {
        transformacoes = rotateX(45);
        vetorF = applyTransformation(points, transformacoes);
        transformacoes = rotateY(45);
        vetorF = applyTransformation(vetorF, transformacoes);
        transformacoes = rotateZ(45);
        vetorF = applyTransformation(vetorF, transformacoes);
        transformacoes = transformScale(0.5f,0.7f,1.1f);
        vetorF = applyTransformation(vetorF, transformacoes);
        transformacoes = translation(0.5f,0,0);
        vetorF = applyTransformation(vetorF, transformacoes);
    }

    return applyTransformation(vetorF, reg);

}

vector<vector<float>> CubeTransformation::translation (float x, float y, float z)
{
    return
    {
        {1, 0, 0, x},
        {0, 1, 0, y},
        {0, 0, 1, z},
        {0, 0, 0, 1},
    };
}

vector<vector<float>> CubeTransformation::transformScale (float sx, float sy, float sz)
{
    return
    {
        {sx, 0, 0, 0},
        {0, sy, 0, 0},
        {0, 0, sz, 0},
        {0, 0, 0, 1},
    };
}

vector<vector<float>> CubeTransformation::rotateX(float angle)
{
    return
    {
        {1,             0,          0,              0},
        {0,             cos(angle), -sin(angle),    0},
        {0,             sin(angle), cos(angle),     0},
        {0,             0,          0,              1},
    };
}

vector<vector<float>> CubeTransformation::rotateY(float angle)
{
    return
    {
        {cos(angle),    0,      sin(angle),     0},
        {0,             1,      0,              0},
        {-sin(angle),   0,      cos(angle),     0},
        {0,             0,      0,              1},
    };
}

vector<vector<float>> CubeTransformation::rotateZ(float angle)
{
    return
    {
        {cos(angle),    -sin(angle),    0,      0},
        {sin(angle),    cos(angle),     0,      0},
        {0,             0,              1,      0},
        {0,             0,              0,      1},
    };
}



vector<QVector3D> CubeTransformation::applyTransformation (vector<QVector3D>& pts,
                                                           vector<vector<float>> trans)
{
    vector<QVector3D> outpts (pts.size());

    for (size_t i = 0; i < pts.size(); i++) {
        auto pt = pts[i];

        outpts[i] = QVector3D(
                trans[0][0] * pt.x() + trans[0][1] * pt.y() + trans[0][2] * pt.z() + trans[0][3],
                trans[1][0] * pt.x() + trans[1][1] * pt.y() + trans[1][2] * pt.z() + trans[1][3],
                trans[2][0] * pt.x() + trans[2][1] * pt.y() + trans[2][2] * pt.z() + trans[2][3]
        );
    }

    return outpts;
}
