#include "mainwindow.h"
#include "ui_mainwindow.h"

int color_a=8;
int color_b=46;
int color_c=84;

extern LSystem lsrule;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
//cyn=========table grape color========
void MainWindow::on_pB_Generate_2_clicked()
{
    color_a=8;
    color_b=46;
    color_c=84;
}
//cyn=========wine grape color========
void MainWindow::on_pB_Generate_3_clicked()
{
    color_a=130;
    color_b=42;
    color_c=58;
}

void MainWindow::on_pB_Generate_clicked()
{
    //generate the grapes
    lsrule.clearAll();//Clear the previous vertexes
    //Update grapes's parameters
    lsrule.update_trunkLen(ui->lE_TrunkLen->text().toDouble());
    lsrule.update_trunkLen_ratio(ui->lE_TrunkLen_ratio->text().toDouble());
    lsrule.update_trunkRa(ui->LE_TrunkR->text().toDouble());
    lsrule.update_trunkRa_ratio(ui->lE_TrunkR_ratio->text().toDouble());
    lsrule.update_Bezier_n(ui->lE_BezierN->text().toInt());
    lsrule.update_Cylinder_steps(ui->l_Cylinder_step->text().toDouble());
    lsrule.update_lats(ui->l_lats->text().toInt());
    lsrule.update_longs(ui->l_longs->text().toInt());
    lsrule.update_berryRa(ui->lE_BerryR->text().toDouble());
    lsrule.update_dxyz(ui->lE_dx->text().toDouble(),ui->lE_dy->text().toDouble(),ui->lE_dz->text().toDouble());
    ui->textBrowser->append(QString("Received new input"));
    lsrule.initGrammar();                                                               //generate new rule
    lsrule.generateFractal();                                                     //generate new vertexes
    //-------------------------------------cyn
    lsrule.collision_detection();//detect collision
    //--------------------------------------cyn
    update();
    ui->textBrowser->append(QString("Grape generated successfully"));
    ui->textBrowser->append(QString("............................"));
}

void MainWindow::on_pB_Clear_clicked()
{
    // Clear vertexes
     lsrule.clearAll();
     ui->textBrowser->append(QString("Grape cleared successfully"));
     ui->textBrowser->append(QString("............................"));
}

void MainWindow::on_checkBox_clicked()
{
    //clear grape berries
    lsrule.clearBerry();
    ui->textBrowser->append(QString("Berries are concealed"));
    ui->textBrowser->append(QString("............................"));
}

void MainWindow::on_pB_Grammar_clicked()
{
    //save grammar to a file

    //open a directory
    QDir dir;
    QString dirName = "Grammar_txt";
    if(!dir.exists(dirName))
        dir.mkdir(dirName);
    QString path = ("./Grammar_txt/" + ui->lE_file->text() +".txt");
    QFile f(path);
    if(!f.open(QIODevice::WriteOnly | QIODevice::Text |QIODevice::Append)){
        ui->textBrowser->append(QString("!!!!!!!!!Open file failed!!!!!!!!!!!"));
        f.close();
        return;
    }
    int n=lsrule.grammar.grammarlist.size();
    for(int i=0; i<n; i++){
        QString grammar = (lsrule.grammar.grammarlist[i] + '\n');
        QByteArray strByte = grammar.toUtf8();
        f.write(strByte,strByte.length());
    }
    ui->textBrowser->append(QString("Grammar text created successfully"));
    ui->textBrowser->append(QString("............................"));
    f.close();

}

void MainWindow::on_pB_AddGra_clicked()
{
    // Add new grammar/unit layer to grammar list
    lsrule.update_Grammar(ui->lE_Grammar->text());
    ui->textBrowser_3->append(ui->lE_Grammar->text());
    ui->textBrowser->append(QString("New Grammar added successfully"));
    ui->textBrowser->append(QString("............................"));
}



void MainWindow::on_pB_Json_clicked()
{
    //Save current model as a json file
    QDir dir;
    QString dirName = "ModelJson";
    if(!dir.exists(dirName))
        dir.mkdir(dirName);
    QString path = ("./ModelJson/" + ui->lE_file->text() + ".json");
    QFile file(path);
    file.open(QIODevice::WriteOnly | QIODevice::Text);

    // Create json object
    QJsonObject Jsonobj;
    Jsonobj.insert("dx",lsrule.dx);
    Jsonobj.insert("dy",lsrule.dy);
    Jsonobj.insert("dz",lsrule.dz);
    Jsonobj.insert("TrunkLength",ui->lE_TrunkLen->text().toDouble());
    Jsonobj.insert("length_shrink",lsrule.lengthFactor);
    Jsonobj.insert("TrunkRadius",ui->LE_TrunkR->text().toDouble());
    Jsonobj.insert("radius_shrink",lsrule.radiusFactor);
    Jsonobj.insert("BerryRadius",lsrule.berriesRadius);
    Jsonobj.insert("Bezier",lsrule.BezierN);
    Jsonobj.insert("Rule",lsrule.grammar.rule);
    Jsonobj.insert("cylinder_step",lsrule.cylinder_step);
    Jsonobj.insert("lats",lsrule.lats);
    Jsonobj.insert("longs",lsrule.longs);

    //transfer json object into binary object write to the file
    QJsonDocument jsonDoc(Jsonobj);
    QByteArray ba = jsonDoc.toJson();
    file.write(ba);
    file.close();
    ui->textBrowser->append(QString("Created new Json Model"));
    ui->textBrowser->append(QString("............................"));

}

void MainWindow::on_pB_LoadJson_clicked()
{
    //laod a mododel from a json file
    lsrule.clearAll();
    QString path = QFileDialog::getOpenFileName(this,"Select File","./ModelJson/","*.json");
    QFile file(path);
    file.open(QIODevice::ReadOnly);


    QJsonParseError jsonError;
    QJsonDocument jdoc=QJsonDocument::fromJson(file.readAll(),&jsonError);
    QJsonObject obj = jdoc.object();

    //get parameters from json object
    lsrule.update_trunkLen(obj.value("TrunkLength").toDouble());
    lsrule.update_trunkLen_ratio(obj.value("length_shrink").toDouble());
    lsrule.update_trunkRa(obj.value("TrunkRadius").toDouble());
    lsrule.update_trunkRa_ratio(obj.value("radius_shrink").toDouble());
    lsrule.update_berryRa(obj.value("BerryRadius").toDouble());
    lsrule.update_Bezier_n(obj.value("Bezier").toInt());
    lsrule.update_dxyz(obj.value("dx").toDouble(), obj.value("dy").toDouble(), obj.value("dz").toDouble());
    lsrule.update_Cylinder_steps(obj.value("cylinder_step").toDouble());
    lsrule.update_lats(obj.value("lats").toInt());
    lsrule.update_longs(obj.value("longs").toInt());
    lsrule.grammar.rule = obj.value("Rule").toString();
    lsrule.generateFractal();//
    //-------------------------------cyn
        lsrule.collision_detection();//detect collision
    //-------------------------------cyn
    update();
    file.close();
    ui->textBrowser->append(QString("Load Model successfully"));
    ui->textBrowser->append(QString("............................"));

}

//Note: don't use it
void MainWindow::on_pB_Dp_clicked()
{

    //==============================cyn_pgm_generate==================
    lsrule.pgm();
        ui->textBrowser->append(QString("Save pgm successfully, Please Check it"));
        ui->textBrowser->append(QString("............................"));

}
