#ifndef L_SYSTEM_H
#define L_SYSTEM_H

#include "grammar.h"
#include "grapes.h"
#include "transformation.h"
#include <vector>
#include <QtCore/qmath.h>
class State      // current state
{
public:
    Node pos;
    Node dir;    // travelling direction
    State() {}
};


class TrunkPosition
{
public:
    Node pos1;
    Node pos2;
    double radius;
    TrunkPosition() {}
};

class BerryPosition
{
public:
    Node pos1;
    Node pos2;
    Node centres;
    double radius ;

    void getCentres(){
        this->centres.x = (this->pos1.x + this->pos2.x)/2;
        this->centres.y = (this->pos1.y + this->pos2.y)/2;
        this->centres.z = (this->pos1.z + this->pos2.z)/2;
    }

    BerryPosition() {}
};


class LSystem
{
public:
    int stackpointer;
    double dx, dy, dz;
    double length;      //rachis length of a unit layer
    double lengthFactor; //stem length shrinks ratio
    double radius;   //stem radius
    double radiusFactor;  //stem radius shrinks ratio
    State curState;  // current position and travelling direction
    double berriesRadius;
    int BezierN = 10;
    double cylinder_step = 30;
    int lats = 30;
    int longs= 30;
    bool Draw_Berry = true;
    Grammar grammar;    // grammar object to generate and store rule

    //Grapes grape;
    std::vector<TrunkPosition> trunks; // Stem vertexes
    std::vector<BerryPosition> berries;// Berryy vertexes
    LSystem(Grapes g);
    void clearAll();
    void clearBerry();  //clear the vertexex data
    void initGrammar();
    void generateFractal(); //generate vertexes
    void pgm();
    void Bezier(int BezierN,std::vector<TrunkPosition>& trunks, Node& X, Node& Y, Node& Z, double radius); //generate bezier curves for the stem
    void collision_detection(); // detect collison

    // Update grape parameters
    void update_trunkLen(double len);
    void update_trunkLen_ratio(double ratio);
    void update_trunkRa(double r);
    void update_trunkRa_ratio(double ratio);
    void update_berryRa(double r);
    void update_Bezier_n(int n);
    void update_Cylinder_steps(double Cs);
    void update_lats(int lat);
    void update_longs(int longss);
    void update_berry_radius(int idx, double r);
    void update_Grammar(QString newGrammar);
    void update_dxyz(double x, double y, double z);
};

#endif // L_SYSTEM_H
