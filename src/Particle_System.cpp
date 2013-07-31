
#include "Particle_System.h"

Particle_System::setup(size_t _TOTAL)
{
    TOTAL = _TOTAL;


    for(int i = 0; i < TOTAL; i++)
    {
        p[i].pos.set( ofRandom(-2,2), ofRandom(-2,2));
    }

    a1 = -1;a2 = -1;
    b1 = 0; b2 = 0;
    tau1 = 1; tau2 = 1;

    tiempo = 0;

    cout <<"a"<< endl;

    receiver.setup(PORT);
    cout <<"b"<< endl;

}

Particle_System::update()
{


}


Particle_System::reset()
{
    for(int i = 0; i < TOTAL; i++)
    {
        p[i].pos.set( ofRandom(-2,2), ofRandom(-2,2));
    }
}
