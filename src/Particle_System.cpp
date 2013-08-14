
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
    a.x = -1;
    b.y = 1;
    rad = 10;
    dt = 0.01;

    update_parameters();

    spontaneous = 1;
    dead = 1;
    sponReset = .9;
}

void Particle_System::update()
{
    for(size_t i = 0; i < N_particles; i++)
    {
        p[i].update();

        if (p[i].border_crossing() || p[i].is_dead()*dead || ofRandom(1)>sponReset*spontaneous)
        {
            p[i].life = 0.5;
            p[i].pos.set( ofRandom(-2,2), ofRandom(-2,2));
        }
    }

}

void Particle_System::OscMessage(ofxOscMessage* m)
{
    string address = m->getAddress();

    if (address=="/visualODEs/a/x")
        a.x = m->getArgAsFloat(0);
    else if(address=="/visualODEs/a/y")
        a.y = m->getArgAsFloat(0);
    else if(address=="/visualODEs/b/x")
        b.x = m->getArgAsFloat(0);
    else if(address=="/visualODEs/b/y")
        b.y = m->getArgAsFloat(0);
    else if(address=="/visualODEs/c/x")
        c.x = m->getArgAsFloat(0);
    else if(address=="/visualODEs/c/y")
        c.y = m->getArgAsFloat(0);
    else if(address=="/visualODEs/d/x")
        d.x = m->getArgAsFloat(0);
    else if(address=="/visualODEs/d/y")
        d.y = m->getArgAsFloat(0);
    else if(address=="/visualODEs/e/x")
        e.x = m->getArgAsFloat(0);
    else if(address=="/visualODEs/e/y")
        e.y = m->getArgAsFloat(0);
    else if(address=="/visualODEs/f/x")
        f.x = m->getArgAsFloat(0);
    else if(address=="/visualODEs/f/y")
        f.y = m->getArgAsFloat(0);

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
        p[i].a = a;p[i].b = b;
        p[i].c = c;p[i].d = d;
        p[i].e = e;p[i].f = f;
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
