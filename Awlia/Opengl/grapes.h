#ifndef GRAPES_H
#define GRAPES_H



class Berry //Berry
{
public:
    double radius = 2.40;//berry radius
    Berry() {}
    ~Berry() {}
};


class Trunk //Stem
{
public:
    double length = 5.5;//rachis length of a unit layer
    double length_shrink = 0.85;//stem length shrinks ratio
    double radius = 0.3;//stem radius
    double radius_shrink = 0.75;//stem radius shrinks ratio
    double leap_x = 60.00;// x degree
    double leap_y = 10.00;//y degree
    double leap_z = 60.00;//z degree
    Trunk() {}
    ~Trunk() {}
};


class Grapes
{
public:
    Grapes();
    Trunk trunk;
    Berry berry;
};

#endif // GRAPES_H
