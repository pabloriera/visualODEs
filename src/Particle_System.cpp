
#include "Particle_System.h"

void Particle_System::setup(size_t _N_particles)
{
    N_particles = _N_particles;

    p = new Particle[N_particles];

    for(size_t i = 0; i < N_particles; i++)
    {
        p[i].setup();
    }
    reset();
    co[a].x = -1;
    co[b].y = 1;
    co[tau].set(1,1);

    rad = 10;
    dt = 0.01;

    update_parameters();

    screenReset = 1;
    velReset = 1;
    sponReset = .1;
}

void Particle_System::update()
{
    for(size_t i = 0; i < N_particles; i++)
    {
        p[i].update();

        if (p[i].border_crossing()*screenReset || p[i].is_dead()*velReset || ofRandom(1)<(sponReset-0.01) )
        {
            p[i].life = 0.5;
            p[i].pos.set( ofRandom(-2,2), ofRandom(-2,2) );
        }
    }

}

void Particle_System::OscMessage(ofxOscMessage* m)
{
    string address = m->getAddress();

    if (address=="/visualODEs/a/x")
        co[a].x = m->getArgAsFloat(0);
    else if(address=="/visualODEs/a/y")
        co[a].y = m->getArgAsFloat(0);
    else if(address=="/visualODEs/b/x")
        co[b].x = m->getArgAsFloat(0);
    else if(address=="/visualODEs/b/y")
        co[b].y = m->getArgAsFloat(0);
    else if(address=="/visualODEs/c/x")
        co[c].x = m->getArgAsFloat(0);
    else if(address=="/visualODEs/c/y")
        co[c].y = m->getArgAsFloat(0);
    else if(address=="/visualODEs/d/x")
        co[d].x = m->getArgAsFloat(0);
    else if(address=="/visualODEs/d/y")
        co[d].y = m->getArgAsFloat(0);
    else if(address=="/visualODEs/e/x")
        co[e].x = m->getArgAsFloat(0);
    else if(address=="/visualODEs/e/y")
        co[e].y = m->getArgAsFloat(0);
    else if(address=="/visualODEs/f/x")
        co[f].x = m->getArgAsFloat(0);
    else if(address=="/visualODEs/f/y")
        co[f].y = m->getArgAsFloat(0);

    else if(address=="/visualODEs/rad")
        rad = m->getArgAsFloat(0);
    else if(address=="/visualODEs/dt")
        dt = m->getArgAsFloat(0);
    else if(address=="/visualODEs/sponReset")
        sponReset = m->getArgAsFloat(0);

    update_parameters();
}

void Particle_System::update_parameters()
{

    for(size_t i = 0; i < N_particles; i++)
    {
        for(size_t j = 0; j < 7; j++)
            p[i].co[j] = co[j];

        p[i].rad = rad; p[i].dt = dt;
    }

}
void Particle_System::reset()
{
    for(size_t i = 0; i < N_particles; i++)
    {
        p[i].pos.set( ofRandom(-2,2), ofRandom(-2,2));
    }
}
