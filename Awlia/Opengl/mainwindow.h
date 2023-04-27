#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <openglwidget.h>
#include <QImage>
#include <QFileDialog>
#include <QFile>
#include <QDir>
#include <QJsonObject>
#include <QJsonDocument>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    //Update grapes

    void on_pB_Generate_clicked();
        void on_pB_Generate_2_clicked();
            void on_pB_Generate_3_clicked();

    void on_pB_Clear_clicked();

    void on_checkBox_clicked();

    void on_pB_Grammar_clicked();

    void on_pB_AddGra_clicked();

    void on_pB_Json_clicked();

    void on_pB_LoadJson_clicked();

    void on_pB_Dp_clicked();

private:
    Ui::MainWindow *ui;
    OpenGLWidget OpenGL;
};


#endif // MAINWINDOW_H
