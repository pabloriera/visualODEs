
#include "Particle_System.h"

void Particle_System::setup(size_t _N_particles)
{
    N_particles = _N_particles;

    p = new Particle[N_particles];

    for(size_t i = 0; i < N_particles; i++)
    {
        p[i].setup();
        p[i].a.x = -1;
        p[i].a.y = -1;

        p[i].pos.set( ofRandom(-2,2), ofRandom(-2,2));
    }

   /* a.x = -1; a.y = -1;
    b.x = 0;  b.y = 0;
    tau.x = 1; tau.y = 1;*/


}

void Particle_System::update()
{
    for(size_t i = 0; i < N_particles; i++)
    {
        p[i].update();

        if (p[i].border_crossing() || !p[i].is_alive() )
        {
            p[i].life = 1;
            p[i].pos.set( ofRandom(-2,2), ofRandom(-2,2));
        }
    }

}


void Particle_System::reset()
{
    for(size_t i = 0; i < N_particles; i++)
    {
        p[i].pos.set( ofRandom(-2,2), ofRandom(-2,2));
    }
}
