#ifndef TRANSFORMATION_H
#define TRANSFORMATION_H
#include <qopengl.h>

class Node // homogeneous coordinate point
{
public:
    Node() :x(0), y(0), z(0), w(1) {}
    Node(GLfloat xx, GLfloat yy, GLfloat zz) :x(xx), y(yy), z(zz), w(1) {}
public:
    GLfloat x, y, z, w;
};

class Transformation {
public:
    Transformation() {}
    void set(Node point);
    void Identity();//Unit matrix
    Node Translate(float, float, float);//Translation matrix
    Node Scale(float, float, float);//Scale matrix
    Node Rotate(char, double);//Rotate matrix (x,y,z)
    void MultiMatrix();//Multplication of matrix
public:
    Node POld;
    float T[4][4];
};

#endif // TRANSFORMATION_H
