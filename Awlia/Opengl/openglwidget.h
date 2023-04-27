#ifndef OPENGLWIDGET_H
#define OPENGLWIDGET_H

#include <QOpenGLWidget>
#include <QMouseEvent>
#include <QOpenGLFunctions_3_3_Core>
#include "l_system.h"

#define WindowWidth  640
#define WindowHeight 500

extern int color_a;
extern int color_b;
extern int color_c;

class OpenGLWidget : public QOpenGLWidget,QOpenGLFunctions_3_3_Core
{
    Q_OBJECT
public:
    explicit OpenGLWidget(QWidget *parent = nullptr);
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

signals:
    void OPenGL_Init();
    void OPenGL_Draw();

public slots:

private:
    QPoint lastPos;
    GLuint texture[ 2 ];
    void drawcone(double r,double h);             //Draw a cylinder
    void DrawChannel(Node A, Node B, double r);     // move the the start position of the cylinder
    void DrawBerry(Node A,Node B,double r);         // move to the sphere centre of the berry
    void drawSphere(double r);  //Draw a sphere
    //void  loadGLTextures();
};

#endif // OPENGLWIDGET_H
