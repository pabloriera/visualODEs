#include "Particle.h"
#include <functional>
#include "rk4.h"

void Particle::setup(){

    t = 0.0;

    a.set(0,0);
    b.set(0,0);
    c.set(0,0);
    d.set(0,0);
    e.set(0,0);
    tau.set(1,1);

    rad = 10;

    dt = 0.01;

    life = 1;
    tol = 0.001*dt;

    xlim1 = -2;
    xlim2 = 2;
    ylim1 = -2;
    ylim2 = 2;

}

void Particle::update(){

    if(life>0)
    {

        double X[2];
        X[0] = pos.x; X[1] = pos.y;

        //function <void* ()> faux = bind(,this);

        //integrates dynamical system
        rk4(X,2,t,dt, this, derivsParticle);


        //calculate velocity and evaluate if the particle is quiete
        vel.set(pos.x-X[0],pos.y-X[1]);
        absVel = vel.length();
        if (absVel < tol)
            if (ofRandom(1)<0.6)
                life = 0;

        //set new position
        pos.set(X[0],X[1]);

        //increase time
        t += dt;
    }

}

bool Particle::border_crossing(){
    return ( pos.x < xlim1 || pos.y < ylim1 || pos.x > xlim2 || pos.y > ylim2);
}

bool Particle::is_dead(){
    return (life <= 0);
}


void derivsParticle(int nX, double X[], double dX[], double t, Particle* p)
{
    double x = X[0];
    double y = X[1];

    dX[0] = (p->a.x + p->b.x*x + p->c.x*y + p->d.x* x*x + p->e.x* y*y + p->f.x*x*y)/p->tau.x + p->in.x;
    dX[1] = (p->a.y + p->b.y*y + p->c.y*x + p->d.y* y*y + p->e.y* x*x + p->f.y*x*y)/p->tau.y + p->in.y;
}

