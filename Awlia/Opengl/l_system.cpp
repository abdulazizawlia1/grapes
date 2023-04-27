#include "l_system.h"
#include <qopengl.h>
#include <QTime>
#include <iostream>
#include <fstream>
#include <string>
#include<direct.h>
using namespace std;


GLfloat PI = 3.14;
Transformation trans;
int trunks_pgm[600][600][600];

LSystem::LSystem(Grapes g) // Initial the L-system use a default grape g
{
    stackpointer = 0;
    dx = g.trunk.leap_x;
    dy = g.trunk.leap_y;
    dz = g.trunk.leap_z;
    length = g.trunk.length;
    lengthFactor = g.trunk.length_shrink;
    radius = g.trunk.radius;
    radiusFactor = g.trunk.radius_shrink;
    berriesRadius=g.berry.radius;
    curState = {};
}

void LSystem::clearAll()
{
    grammar.clear();
    trunks.clear();
    berries.clear();
}

void LSystem::clearBerry()
{
    berries.clear();
}

void LSystem::initGrammar()   // generate the rule using the grammar object
{
    grammar.Iteration();
}
//cyn================generate the matrix and pgm files=================
void LSystem::pgm()
{
    int num_stem = this->trunks.size();
    int num_berries=this->berries.size();

    //Find the minimum value of negative coordinates
    double pos_min_x=0,pos_min_z=0,pos_min_y=0;
    int min_y=0,min_x,min_z;
    for(int i=0;i<num_berries;i++)//berry
    {
                if(berries[i].centres.y<pos_min_y)
                {
                pos_min_y=berries[i].centres.y;
                }
                if(berries[i].centres.x<pos_min_x)
                {
                    pos_min_x=berries[i].centres.x;
                }
                if(berries[i].centres.z<pos_min_z)
                {
                    pos_min_z=berries[i].centres.z;
                }
    }
    double pos_min_x1=0,pos_min_z1=0;
    for(int n=0; n<num_stem;n++)//trunk
    {
        if(trunks[n].pos1.x<pos_min_x1)
        {
            pos_min_x1=trunks[n].pos1.x;
        }

        if(trunks[n].pos1.z<pos_min_z1)
        {
            pos_min_z1=trunks[n].pos1.z;
        }
    }

    if(pos_min_x-3<=pos_min_x1)//3 is bigger than the radius
    {
        min_x=abs(pos_min_x-2.4)*20;//min_x:the distance to shift the coordinate to postive domain
    }
    else
    {
        min_x=abs(pos_min_x1-1)*20;
    }
    if(pos_min_z-3<=pos_min_z1)
    {
        min_z=abs(pos_min_z-2.4)*20;//min_z:the distance to shift the coordinate to postive domain
    }
    else
    {
        min_z=abs(pos_min_z1-1)*20;
    }
    if(pos_min_y-3<0)
    {
        min_y=abs(pos_min_y-3)*20;
    }

    //----------------generate stem model--------------------------
    int num_y;
    for (int t = 0; t < num_stem; t++)
    {
        num_y = abs(20*(this->trunks[t].pos2.y - trunks[t].pos1.y));
        TrunkPosition E=this->trunks[t];
        if(num_y<1)
        {
            continue;
        }
        else
        {
            for (int y = 0; y <= num_y; y++)
            {

            for(int r=0;r<= 20*E.radius;r++)
            {
                int z=0;
                while(pow(r,2)+pow(z,2)<=pow(20*E.radius,2))
                {
                    int t_current_x;
                    if (E.pos2.x>=E.pos1.x)
                    {
                        t_current_x=20*(E.pos2.x-E.pos1.x)/num_y*y+20*E.pos1.x;//find the postion of the stem
                    }
                    if(E.pos2.x<E.pos1.x)
                    {
                        t_current_x=20*(E.pos1.x-E.pos2.x)/num_y*y+20*E.pos2.x;
                    }
                    int t_pos_x=r+t_current_x+min_x;//shift the coordinates to postive domain

                    int t_current_z;
                    if(E.pos2.z>=E.pos1.z)
                    {
                        t_current_z=20*(E.pos2.z-E.pos1.z)/num_y*y+20*E.pos1.z;
                    }
                    if(E.pos2.z<E.pos1.z)
                    {
                        t_current_z=20*(E.pos1.z-E.pos2.z)/num_y*y+20*E.pos2.z;
                    }
                    int t_pos_z=z+t_current_z+min_z;

                    int t_pos_y=y+20*E.pos1.y+min_y;
                    int t_pos_x1=-r+t_current_x+min_x;
                    int t_pos_z1=-z+t_current_z+min_z;
                    trunks_pgm[t_pos_x][t_pos_y][t_pos_z]=4;//set the color for stem
                    trunks_pgm[t_pos_x1][t_pos_y][t_pos_z]=4;
                    trunks_pgm[t_pos_x][t_pos_y][t_pos_z1]=4;
                    trunks_pgm[t_pos_x1][t_pos_y][t_pos_z1]=4;


                    z++;
                }
            }
        }
        }
    }
    //-----------------------generate berry model-------------------

        for(int k=0;k<num_berries;k++)
        {

            BerryPosition F=this->berries[k];
            if(berries[k].radius*20==0)
            {
                continue;
            }
            else
            {

            for(int y=0;y<=20*F.radius;y++)
            {
                for(int x=0;x<= 20*F.radius;x++)
                {
                    int z=0;
                    while(pow(y,2)+pow(x,2)+pow(z,2)<=pow(20*F.radius,2))
                    {
                        int current_x=20*F.centres.x;//find the position of the berry
                        int current_z=20*F.centres.z;
                        int current_y=20*F.centres.y;
                        int pos_x=x+current_x+min_x;//shift the coordinates to postive domain
                        int pos_z=z+current_z+min_z;
                        int pos_y=y+current_y+min_y;
                        int pos_x1=-x+current_x+min_x;
                        int pos_z1=-z+current_z+min_z;
                        int pos_y1=-y+current_y+min_y;
                        trunks_pgm[pos_x][pos_y][pos_z]=8;//set the color for berry
                        trunks_pgm[pos_x1][pos_y][pos_z]=8;
                        trunks_pgm[pos_x][pos_y][pos_z1]=8;
                        trunks_pgm[pos_x1][pos_y][pos_z1]=8;
                        trunks_pgm[pos_x][pos_y1][pos_z]=8;
                        trunks_pgm[pos_x1][pos_y1][pos_z]=8;
                        trunks_pgm[pos_x][pos_y1][pos_z1]=8;
                        trunks_pgm[pos_x1][pos_y1][pos_z1]=8;

                        z++;
                    }
                }
            }
            }
        }

//---------------generate pgm files----------------

    string dirName = "";//generate folder
    if (_access(dirName.c_str(), 0) == -1)
        {
            _mkdir(dirName.c_str());
        }
   else
    {
    rmdir(dirName.c_str());
     _mkdir(dirName.c_str());
    }
        int ny = 600, nx = 600, nz = 600;
        for (int y = 0; y < ny; y++)
        {
        string fileName2=dirName+"\\fig_"+to_string(y)+".pgm";
        ofstream(fileName2.c_str());
        ofstream file2;
        file2.open(dirName+"\\fig_"+to_string(y)+".pgm");


        file2 << "P2\n#test\n" + to_string(nx) + " " + to_string(nz) + "\n8 " << endl;

                    for (int x = 0; x < nx; x++)//write data
                    {
                        for (int z = 0; z < nz; z++)
                        {
                            file2 << to_string(trunks_pgm[y][x][z]) << endl;
                        }
                    }
        file2.close();
        }
}



void LSystem::generateFractal()   // generate the vertexes data using the rule
{
    QTime time = QTime::currentTime();
    qsrand((int)time.msec());//生成随机种子
    trunks.clear();
    curState.pos = Node(0, 0, 0);
    curState.dir = Node(0, 1, 0);

    State stack[3000]; // state stacks (for brunching)
    for (int i = 0; i <3000; i++)
    {
        stack[i].pos.x = 0.0;
        stack[i].pos.y = 0.0;
        stack[i].pos.z = 0.0;
        stack[i].dir.x = 0.0;
        stack[i].dir.y = 0.0;
        stack[i].dir.z = 0.0;
    }
    size_t i = 0;
    unsigned int len=grammar.getRule().length();
    while (i <len) {
        TrunkPosition tmp_trunk;
        BerryPosition tmp_berry;
        Node Z;

        char key=grammar.getRule()[i].toLatin1();
        switch (key)
        {
        case 'F':   //Rachis
            tmp_trunk.pos1 = curState.pos;//起始点
            curState.pos.x += length * curState.dir.x;
            curState.pos.y += length * curState.dir.y;
            curState.pos.z += length * curState.dir.z;
            tmp_trunk.pos2 = curState.pos;//终点

            Z.x=0.5*(tmp_trunk.pos1.x+tmp_trunk.pos2.x)+(qrand()%20-5)/10;
            Z.y=0.5*(tmp_trunk.pos1.y+tmp_trunk.pos2.y)-(qrand()%20-2)/10;
            Z.z=0.5*(tmp_trunk.pos1.z+tmp_trunk.pos2.z)+(qrand()%20-4)/10;
            Z.w=curState.pos.w;
            Bezier(BezierN,trunks,tmp_trunk.pos1,Z,tmp_trunk.pos2,radius);//把茎随机弯曲一下
            break;

        case 'W':   //pedicel
            tmp_trunk.pos1 = curState.pos;
            curState.pos.x += 0.1*length * curState.dir.x;
            curState.pos.y += 0.1*length * curState.dir.y;
            curState.pos.z += 0.1*length * curState.dir.z;
            tmp_trunk.pos2 = curState.pos;
            Z.x=0.5*(tmp_trunk.pos1.x+tmp_trunk.pos2.x)+(qrand()%20-5)/10;
            Z.y=0.5*(tmp_trunk.pos1.y+tmp_trunk.pos2.y)-(qrand()%20-2)/10;
            Z.z=0.5*(tmp_trunk.pos1.z+tmp_trunk.pos2.z)+(qrand()%20-4)/10;
            Z.w=curState.pos.w;
            Bezier(BezierN,trunks,tmp_trunk.pos1,Z,tmp_trunk.pos2,radius);  
            break;

        case 'U':  //peduncle
            tmp_trunk.pos1 = curState.pos;
            curState.pos.x += 0.20*length * curState.dir.x;
            curState.pos.y += 0.20*length * curState.dir.y;
            curState.pos.z += 0.20*length * curState.dir.z;
            tmp_trunk.pos2 = curState.pos;
            Z.x=0.5*(tmp_trunk.pos1.x+tmp_trunk.pos2.x)+(qrand()%20-5)/10;
            Z.y=0.5*(tmp_trunk.pos1.y+tmp_trunk.pos2.y)-(qrand()%20-2)/10;
            Z.z=0.5*(tmp_trunk.pos1.z+tmp_trunk.pos2.z)+(qrand()%20-4)/10;
            Z.w=curState.pos.w;
            Bezier(BezierN,trunks,tmp_trunk.pos1,Z,tmp_trunk.pos2,radius);
            break;

        case 'D':   //Bud
                    tmp_trunk.pos1 = curState.pos;
                    curState.pos.x += berriesRadius * curState.dir.x;
                    curState.pos.y += berriesRadius * curState.dir.y;
                    curState.pos.z += berriesRadius * curState.dir.z;
                    tmp_trunk.pos2 = curState.pos;
                    Z.x=0.5*(tmp_trunk.pos1.x+tmp_trunk.pos2.x)+(qrand()%20-5)/10;
                    Z.y=0.5*(tmp_trunk.pos1.y+tmp_trunk.pos2.y)-(qrand()%20-2)/10;
                    Z.z=0.5*(tmp_trunk.pos1.z+tmp_trunk.pos2.z)+(qrand()%20-4)/10;
                    Z.w = curState.pos.w;
                    Bezier(BezierN,trunks,tmp_trunk.pos1,Z,tmp_trunk.pos2,radius);
                    break;

        case 'X':   //Berry
              tmp_berry.pos1 = curState.pos;
              curState.pos.x += 2*berriesRadius * curState.dir.x;
              curState.pos.y += 2*berriesRadius * curState.dir.y;
              curState.pos.z += 2*berriesRadius * curState.dir.z;
              tmp_berry.pos2 = curState.pos;
              tmp_berry.radius = berriesRadius;
              tmp_berry.getCentres();
              berries.push_back(tmp_berry);
           break;

        case 'A':    //Shrinks length
            length = length * lengthFactor;
            radius = radius * radiusFactor;
            break;
        case 'B':    //Scale length
            length = length / lengthFactor;
            radius = radius / radiusFactor;
            break;
        case '[':    //Branch out
            stack[stackpointer] = curState;
            stackpointer++;;
            break;
        case ']':    //return to the bifurcation point
            curState = stack[stackpointer - 1];
            stackpointer--;
            break;
        case '^':    //rotate around x-axis
            trans.set(curState.dir);
            curState.dir = trans.Rotate('X', dx+(qrand()%20-10)); //add random here
            break;
        case '&':
            trans.set(curState.dir);
            curState.dir = trans.Rotate('X', -dx+(qrand()%20-10));
            break;
        case '$': //rotate around y-axis
            trans.set(curState.dir);
            curState.dir = trans.Rotate('Y', dy);//转动dy度
            break;
        case '%':
            trans.set(curState.dir);
            curState.dir = trans.Rotate('Y', -dy);//转动-dy度
            break;
        case '*'://rotate around z-axis
            trans.set(curState.dir);
            curState.dir = trans.Rotate('Z', dz+(qrand()%20-10));
            break;
        case '/':
            trans.set(curState.dir);
            curState.dir = trans.Rotate('Z', -dz+(qrand()%20-10));
            break;
        default:
            break;
        }
        i++;
    }
    //---------------------------------------cyn pgm--------------------------




}


void LSystem::Bezier(int BezierN,std::vector<TrunkPosition>& trunks, Node& X, Node& Y, Node& Z,double radius){
            float f1, f2, f3;
            float deltaT = 1.0 / BezierN;
            float T;
            Node pre=X;//起点
            Node cur;
            TrunkPosition tmp;
            //generate a small cylinder
            for (int i = 0; i <= BezierN; i++) {
                tmp.pos1=pre;//起点
                T = i * deltaT;
                f1 = (1 - T) * (1 - T);
                f2 = 2 * T * (1 - T);
                f3 = T*T;
                float x = f1 * X.x + f2 * Y.x + f3 * Z.x;
                float y = f1 * X.y + f2 * Y.y + f3 * Z.y;
                float z = f1 * X.z + f2 * Y.z + f3 * Z.z;
                cur.x=x;
                cur.y=y;
                cur.z=z;
                tmp.pos2=cur;//终点
                tmp.radius=radius;
                pre=cur;
                trunks.push_back(tmp);
            }

}





void LSystem::collision_detection()
{


     int num_stem=this->trunks.size();

    int num=this->berries.size();//berries的数量
    for(int i=0;i<num;i++){
        BerryPosition A=this->berries[i];

        //cyn=============collision detection for berries and stems============
                for(int k=0;k<num_stem;k++){//跟每一个茎的转弯点对比
                    TrunkPosition C=this->trunks[k];
                    // find the distance bewteen two points
                    double distance=sqrt(qPow((A.centres.x - C.pos1.x),2)+qPow((A.centres.y-C.pos1.y),2)+qPow((A.centres.z-C.pos1.z),2));
                    double differ=A.radius+C.radius-distance;
                    if(differ > 0){ //COLLISION !
                        double rminusd=A.radius-differ;
                        if(rminusd>0)
                        {
                        update_berry_radius(i,rminusd);//把A的半径减小differs
                        }
                        else
                        {
                            update_berry_radius(i,0);
                        }
                    }
                }
        //cyn=============collision detection for berries and stems============


        for(int j=0;j<num;j++){
            if(i==j) continue;//跟除了这个果实的每个果实都对比一遍
            BerryPosition B=this->berries[j];
            // find the distance bewteen two points
            double distance=sqrt(qPow((A.centres.x - B.centres.x),2)+qPow((A.centres.y-B.centres.y),2)+qPow((A.centres.z-B.centres.z),2));
            double differ=A.radius+B.radius-distance;
            if(differ > 0){ //COLLISION !
            //cyn====The reduced radius cannot be negative========
                double rminusd2=A.radius-differ;
                if(rminusd2>0)
                {
                update_berry_radius(i,rminusd2);//把A的半径减小differ
                }
                else
                {
                    update_berry_radius(i,0);
                }
            //cyn====The reduced radius cannot be negative========

////               /* qDebug()<<differ;
////                qDebug()<<"before: "<<berries[j].radius;

//                update_berry_radius(i,A.radius-differ);//把A的半径减小differ
////                qDebug()<<"now:"<<berries[j].radius;*/
            }
        }


    }


}

//Update functions
void LSystem::update_trunkLen(double len)
{
    this->length=len;
}

void LSystem::update_trunkLen_ratio(double ratio)
{
    this->lengthFactor=ratio;
}

void LSystem::update_trunkRa(double r)
{
    this->radius=r;
}

void LSystem::update_trunkRa_ratio(double ratio)
{
    this->radiusFactor=ratio;
}

void LSystem::update_berryRa(double r)
{
    this->berriesRadius=r;
}

void LSystem::update_Bezier_n(int n)
{
    this->BezierN=n;
}

void LSystem::update_Cylinder_steps(double Cs)
{
    this->cylinder_step = Cs;
}

void LSystem::update_lats(int lat)
{
    this->lats = lat;
}

void LSystem::update_longs(int longss)
{
    this->longs = longss;
}

void LSystem::update_berry_radius(int idx, double r)
{
    this->berries[idx].radius = r;
}

void LSystem::update_Grammar(QString newGrammar)
{
    this->grammar.grammarlist.append(newGrammar);
}

void LSystem::update_dxyz(double x, double y, double z)
{
    this->dx = x;
    this->dy = y;
    this->dz = z;
}



























