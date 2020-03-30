#include <iostream>

class particle
{
public:
    float pos_x;
    float pos_y;
    float vel_x;
    float vel_y;
    float mass;
    //bool charge;

    particle(float px=0, float py=0, float vx=0, float vy=0,float m=1)
    {
        pos_x = px;
        pos_y = py;
        vel_x = vx;
        vel_y = vy;
        mass = m;
    }
    ~particle() {}
    particle(const particle &p) {}

};


