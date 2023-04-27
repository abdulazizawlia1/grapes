/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include <openglwidget.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    OpenGLWidget *openGLWidget;
    QPushButton *pB_Generate;
    QPushButton *pB_Clear;
    QTabWidget *tabWidget;
    QWidget *Setting;
    QGroupBox *groupBox;
    QLabel *l_TrunkLen;
    QLineEdit *lE_TrunkLen;
    QLabel *l_TrunkLen_ratio;
    QLineEdit *lE_TrunkLen_ratio;
    QLabel *l_TrunkR;
    QLineEdit *LE_TrunkR;
    QLabel *l_TrunkLenR_ratio;
    QLineEdit *lE_TrunkR_ratio;
    QLabel *l_BerryR;
    QLineEdit *lE_BerryR;
    QLineEdit *lE_BezierN;
    QLabel *l_BezierN;
    QLineEdit *lE_dx;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *lE_dy;
    QLabel *label_4;
    QLineEdit *lE_dz;
    QLabel *label_6;
    QLineEdit *l_Cylinder_step;
    QLabel *label_7;
    QLabel *label_8;
    QLineEdit *l_lats;
    QLineEdit *l_longs;
    QWidget *Grammar;
    QTextBrowser *textBrowser_3;
    QLabel *label;
    QLineEdit *lE_Grammar;
    QPushButton *pB_AddGra;
    QWidget *Information;
    QTextBrowser *textBrowser_2;
    QWidget *tab;
    QPushButton *pB_Grammar;
    QPushButton *pB_Json;
    QLabel *label_5;
    QLineEdit *lE_file;
    QPushButton *pB_LoadJson;
    QPushButton *pB_Dp;
    QTextBrowser *textBrowser;
    QCheckBox *checkBox;
    QPushButton *pB_Generate_2;
    QPushButton *pB_Generate_3;
    QLabel *label_9;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(994, 750);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        openGLWidget = new OpenGLWidget(centralWidget);
        openGLWidget->setObjectName(QString::fromUtf8("openGLWidget"));
        openGLWidget->setGeometry(QRect(10, 10, 661, 541));
        pB_Generate = new QPushButton(centralWidget);
        pB_Generate->setObjectName(QString::fromUtf8("pB_Generate"));
        pB_Generate->setGeometry(QRect(690, 630, 141, 41));
        pB_Clear = new QPushButton(centralWidget);
        pB_Clear->setObjectName(QString::fromUtf8("pB_Clear"));
        pB_Clear->setGeometry(QRect(840, 630, 141, 41));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(670, 20, 321, 501));
        Setting = new QWidget();
        Setting->setObjectName(QString::fromUtf8("Setting"));
        groupBox = new QGroupBox(Setting);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 20, 341, 501));
        l_TrunkLen = new QLabel(groupBox);
        l_TrunkLen->setObjectName(QString::fromUtf8("l_TrunkLen"));
        l_TrunkLen->setGeometry(QRect(10, 20, 121, 16));
        lE_TrunkLen = new QLineEdit(groupBox);
        lE_TrunkLen->setObjectName(QString::fromUtf8("lE_TrunkLen"));
        lE_TrunkLen->setGeometry(QRect(160, 20, 131, 21));
        l_TrunkLen_ratio = new QLabel(groupBox);
        l_TrunkLen_ratio->setObjectName(QString::fromUtf8("l_TrunkLen_ratio"));
        l_TrunkLen_ratio->setGeometry(QRect(-10, 50, 171, 20));
        lE_TrunkLen_ratio = new QLineEdit(groupBox);
        lE_TrunkLen_ratio->setObjectName(QString::fromUtf8("lE_TrunkLen_ratio"));
        lE_TrunkLen_ratio->setGeometry(QRect(160, 50, 131, 21));
        l_TrunkR = new QLabel(groupBox);
        l_TrunkR->setObjectName(QString::fromUtf8("l_TrunkR"));
        l_TrunkR->setGeometry(QRect(10, 90, 121, 16));
        LE_TrunkR = new QLineEdit(groupBox);
        LE_TrunkR->setObjectName(QString::fromUtf8("LE_TrunkR"));
        LE_TrunkR->setGeometry(QRect(160, 90, 131, 21));
        l_TrunkLenR_ratio = new QLabel(groupBox);
        l_TrunkLenR_ratio->setObjectName(QString::fromUtf8("l_TrunkLenR_ratio"));
        l_TrunkLenR_ratio->setGeometry(QRect(10, 130, 151, 20));
        lE_TrunkR_ratio = new QLineEdit(groupBox);
        lE_TrunkR_ratio->setObjectName(QString::fromUtf8("lE_TrunkR_ratio"));
        lE_TrunkR_ratio->setGeometry(QRect(162, 130, 131, 21));
        l_BerryR = new QLabel(groupBox);
        l_BerryR->setObjectName(QString::fromUtf8("l_BerryR"));
        l_BerryR->setGeometry(QRect(20, 170, 111, 16));
        lE_BerryR = new QLineEdit(groupBox);
        lE_BerryR->setObjectName(QString::fromUtf8("lE_BerryR"));
        lE_BerryR->setGeometry(QRect(160, 170, 131, 21));
        lE_BezierN = new QLineEdit(groupBox);
        lE_BezierN->setObjectName(QString::fromUtf8("lE_BezierN"));
        lE_BezierN->setGeometry(QRect(160, 210, 131, 21));
        l_BezierN = new QLabel(groupBox);
        l_BezierN->setObjectName(QString::fromUtf8("l_BezierN"));
        l_BezierN->setGeometry(QRect(20, 210, 91, 21));
        lE_dx = new QLineEdit(groupBox);
        lE_dx->setObjectName(QString::fromUtf8("lE_dx"));
        lE_dx->setGeometry(QRect(160, 250, 131, 21));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 250, 91, 21));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 290, 72, 15));
        lE_dy = new QLineEdit(groupBox);
        lE_dy->setObjectName(QString::fromUtf8("lE_dy"));
        lE_dy->setGeometry(QRect(160, 290, 131, 21));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 330, 72, 15));
        lE_dz = new QLineEdit(groupBox);
        lE_dz->setObjectName(QString::fromUtf8("lE_dz"));
        lE_dz->setGeometry(QRect(160, 330, 131, 21));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(20, 360, 131, 31));
        l_Cylinder_step = new QLineEdit(groupBox);
        l_Cylinder_step->setObjectName(QString::fromUtf8("l_Cylinder_step"));
        l_Cylinder_step->setGeometry(QRect(160, 370, 131, 21));
        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(20, 400, 72, 15));
        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(20, 430, 72, 15));
        l_lats = new QLineEdit(groupBox);
        l_lats->setObjectName(QString::fromUtf8("l_lats"));
        l_lats->setGeometry(QRect(160, 400, 131, 21));
        l_longs = new QLineEdit(groupBox);
        l_longs->setObjectName(QString::fromUtf8("l_longs"));
        l_longs->setGeometry(QRect(160, 430, 131, 21));
        tabWidget->addTab(Setting, QString());
        Grammar = new QWidget();
        Grammar->setObjectName(QString::fromUtf8("Grammar"));
        textBrowser_3 = new QTextBrowser(Grammar);
        textBrowser_3->setObjectName(QString::fromUtf8("textBrowser_3"));
        textBrowser_3->setGeometry(QRect(10, 10, 301, 351));
        label = new QLabel(Grammar);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 390, 151, 21));
        lE_Grammar = new QLineEdit(Grammar);
        lE_Grammar->setObjectName(QString::fromUtf8("lE_Grammar"));
        lE_Grammar->setGeometry(QRect(150, 390, 161, 21));
        pB_AddGra = new QPushButton(Grammar);
        pB_AddGra->setObjectName(QString::fromUtf8("pB_AddGra"));
        pB_AddGra->setGeometry(QRect(150, 420, 93, 28));
        tabWidget->addTab(Grammar, QString());
        Information = new QWidget();
        Information->setObjectName(QString::fromUtf8("Information"));
        textBrowser_2 = new QTextBrowser(Information);
        textBrowser_2->setObjectName(QString::fromUtf8("textBrowser_2"));
        textBrowser_2->setGeometry(QRect(10, 10, 281, 431));
        tabWidget->addTab(Information, QString());
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        pB_Grammar = new QPushButton(tab);
        pB_Grammar->setObjectName(QString::fromUtf8("pB_Grammar"));
        pB_Grammar->setGeometry(QRect(120, 90, 171, 41));
        pB_Json = new QPushButton(tab);
        pB_Json->setObjectName(QString::fromUtf8("pB_Json"));
        pB_Json->setGeometry(QRect(120, 140, 171, 41));
        label_5 = new QLabel(tab);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(30, 50, 91, 31));
        lE_file = new QLineEdit(tab);
        lE_file->setObjectName(QString::fromUtf8("lE_file"));
        lE_file->setGeometry(QRect(130, 50, 151, 31));
        pB_LoadJson = new QPushButton(tab);
        pB_LoadJson->setObjectName(QString::fromUtf8("pB_LoadJson"));
        pB_LoadJson->setGeometry(QRect(120, 190, 171, 41));
        pB_Dp = new QPushButton(tab);
        pB_Dp->setObjectName(QString::fromUtf8("pB_Dp"));
        pB_Dp->setGeometry(QRect(120, 300, 171, 41));
        tabWidget->addTab(tab, QString());
        textBrowser = new QTextBrowser(centralWidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(10, 560, 661, 111));
        checkBox = new QCheckBox(centralWidget);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(680, 520, 191, 41));
        pB_Generate_2 = new QPushButton(centralWidget);
        pB_Generate_2->setObjectName(QString::fromUtf8("pB_Generate_2"));
        pB_Generate_2->setGeometry(QRect(820, 590, 151, 31));
        pB_Generate_3 = new QPushButton(centralWidget);
        pB_Generate_3->setObjectName(QString::fromUtf8("pB_Generate_3"));
        pB_Generate_3->setGeometry(QRect(820, 560, 151, 31));
        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(680, 560, 131, 20));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 994, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        pB_Generate->setText(QApplication::translate("MainWindow", "Generate", nullptr));
        pB_Clear->setText(QApplication::translate("MainWindow", "Clear", nullptr));
        groupBox->setTitle(QString());
        l_TrunkLen->setText(QApplication::translate("MainWindow", "Trunk length:", nullptr));
        lE_TrunkLen->setText(QApplication::translate("MainWindow", "5.5", nullptr));
        l_TrunkLen_ratio->setText(QApplication::translate("MainWindow", "   TrunkLength ratio :", nullptr));
        lE_TrunkLen_ratio->setText(QApplication::translate("MainWindow", "0.85", nullptr));
        l_TrunkR->setText(QApplication::translate("MainWindow", "Trunk radius:", nullptr));
        LE_TrunkR->setText(QApplication::translate("MainWindow", "0.3", nullptr));
        l_TrunkLenR_ratio->setText(QApplication::translate("MainWindow", "TrunkRadius ratio:", nullptr));
        lE_TrunkR_ratio->setText(QApplication::translate("MainWindow", "0.75", nullptr));
        l_BerryR->setText(QApplication::translate("MainWindow", "Berry radius:", nullptr));
        lE_BerryR->setText(QApplication::translate("MainWindow", "2", nullptr));
        lE_BezierN->setText(QApplication::translate("MainWindow", "10", nullptr));
        l_BezierN->setText(QApplication::translate("MainWindow", "Bezier n :", nullptr));
        lE_dx->setText(QApplication::translate("MainWindow", "60", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "dx:", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "dy:", nullptr));
        lE_dy->setText(QApplication::translate("MainWindow", "10", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "dz:", nullptr));
        lE_dz->setText(QApplication::translate("MainWindow", "60", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "Cylinder_step:", nullptr));
        l_Cylinder_step->setText(QApplication::translate("MainWindow", "30", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "lats:", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "longs:", nullptr));
        l_lats->setText(QApplication::translate("MainWindow", "30", nullptr));
        l_longs->setText(QApplication::translate("MainWindow", "30", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Setting), QApplication::translate("MainWindow", "Setting", nullptr));
        textBrowser_3->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#008000;\">FB[/&amp;UUS&amp;FS]AWB[^^/USFS]AWW[*&amp;FS]AW[//FS]AWW[&amp;*FS]A$$C</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; color:#008000;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; color:#008000;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0;"
                        " text-indent:0px;\"><span style=\" font-family:'Courier New'; color:#008000;\">FB[*^FS]AUB[/&amp;UUS&amp;FS]AW[^//FS]AW[&amp;&amp;US&amp;FS]A$C</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Courier New'; color:#008000;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Courier New'; color:#008000;\">FB[^US*FS]AWB[//US/FS]AW[/^^FS]A%%C&quot;</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Courier New'; color:#008000;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Courier New'; color:#008000;\">FB[/^US^FS]AUB[&amp;*US*FS]AUW[*^^FS]AW[///"
                        "FS]%C</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Courier New'; color:#c0c0c0;\">     </span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Courier New'; color:#008000;\">FB[//FS]AWB[&amp;&amp;FS]AUW[**FS]AWW[//&amp;FS]A$C</span></p></body></html>", nullptr));
        label->setText(QApplication::translate("MainWindow", "Give new Grammar:", nullptr));
        pB_AddGra->setText(QApplication::translate("MainWindow", "Add", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Grammar), QApplication::translate("MainWindow", "Grammar", nullptr));
        textBrowser_2->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#808000;\">double</span><span style=\" color:#c0c0c0;\"> </span><span style=\" color:#800000;\">length</span><span style=\" color:#c0c0c0;\"> </span>=<span style=\" color:#c0c0c0;\"> </span><span style=\" color:#000080;\">5.5</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Courier New'; color:#808000;\">double</span><span style=\" font-family:'Courier New'; color:#c0c0c0;\"> </span><span style=\" font-family:'Courier New'; color:#"
                        "800000;\">length_shrink</span><span style=\" font-family:'Courier New'; color:#c0c0c0;\"> </span><span style=\" font-family:'Courier New';\">=</span><span style=\" font-family:'Courier New'; color:#c0c0c0;\"> </span><span style=\" font-family:'Courier New'; color:#000080;\">0.85</span><span style=\" font-family:'Courier New';\">;</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Courier New'; color:#808000;\">double</span><span style=\" font-family:'Courier New'; color:#c0c0c0;\"> </span><span style=\" font-family:'Courier New'; color:#800000;\">radius</span><span style=\" font-family:'Courier New'; color:#c0c0c0;\"> </span><span style=\" font-family:'Courier New';\">=</span><span style=\" font-family:'Courier New'; color:#c0c0c0;\"> </span><span style=\" font-family:'Courier New'; color:#000080;\">0.3</span><span style=\" font-family:'Courier New';\">;</span></p>\n"
"<p style=\" margin-top:0px; ma"
                        "rgin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Courier New'; color:#808000;\">double</span><span style=\" font-family:'Courier New'; color:#c0c0c0;\"> </span><span style=\" font-family:'Courier New'; color:#800000;\">radius_shrink</span><span style=\" font-family:'Courier New'; color:#c0c0c0;\"> </span><span style=\" font-family:'Courier New';\">=</span><span style=\" font-family:'Courier New'; color:#c0c0c0;\"> </span><span style=\" font-family:'Courier New'; color:#000080;\">0.75</span><span style=\" font-family:'Courier New';\">;</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Courier New'; color:#808000;\">double</span><span style=\" font-family:'Courier New'; color:#c0c0c0;\"> </span><span style=\" font-family:'Courier New'; color:#800000;\">leap_x</span><span style=\" font-family:'Courier New'; color:#c0c0c0;\"> </span>"
                        "<span style=\" font-family:'Courier New';\">=</span><span style=\" font-family:'Courier New'; color:#c0c0c0;\"> </span><span style=\" font-family:'Courier New'; color:#000080;\">60.00</span><span style=\" font-family:'Courier New';\">;</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Courier New'; color:#808000;\">double</span><span style=\" font-family:'Courier New'; color:#c0c0c0;\"> </span><span style=\" font-family:'Courier New'; color:#800000;\">leap_y</span><span style=\" font-family:'Courier New'; color:#c0c0c0;\"> </span><span style=\" font-family:'Courier New';\">=</span><span style=\" font-family:'Courier New'; color:#c0c0c0;\"> </span><span style=\" font-family:'Courier New'; color:#000080;\">10.00</span><span style=\" font-family:'Courier New';\">;</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><sp"
                        "an style=\" font-family:'Courier New'; color:#808000;\">double</span><span style=\" font-family:'Courier New'; color:#c0c0c0;\"> </span><span style=\" font-family:'Courier New'; color:#800000;\">leap_z</span><span style=\" font-family:'Courier New'; color:#c0c0c0;\"> </span><span style=\" font-family:'Courier New';\">=</span><span style=\" font-family:'Courier New'; color:#c0c0c0;\"> </span><span style=\" font-family:'Courier New'; color:#000080;\">60.00</span></p></body></html>", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Information), QApplication::translate("MainWindow", "Default_Setting", nullptr));
        pB_Grammar->setText(QApplication::translate("MainWindow", "Output Grammar", nullptr));
        pB_Json->setText(QApplication::translate("MainWindow", "Output Model(Json)", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "File name:", nullptr));
        pB_LoadJson->setText(QApplication::translate("MainWindow", "Load Model", nullptr));
        pB_Dp->setText(QApplication::translate("MainWindow", "Digital phantom", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Output", nullptr));
        checkBox->setText(QApplication::translate("MainWindow", "Disable Berry", nullptr));
        pB_Generate_2->setText(QApplication::translate("MainWindow", "wine grape", nullptr));
        pB_Generate_3->setText(QApplication::translate("MainWindow", "table grape", nullptr));
        label_9->setText(QApplication::translate("MainWindow", "berry color", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
