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

    dt = 0.01;

    life = 1;
    tol = 0.000001*dt;

    xlim1 = -2;
    xlim2 = 2;
    ylim1 = -2;
    ylim2 = 2;

}

void Particle::update(){

    double X[2];
    X[0] = pos.x; X[1] = pos.y;

    //function <void* ()> faux = bind(,this);

    rk4(X,2,t,dt, this, derivsParticle);

    pos.x = X[0]; pos.y = X[1];

    t += dt;

     /*
    absVel = ((pos.x-x)*(pos.x-x)+(pos.y-y)*(pos.y-y));

    if ( absVel < tol*ofRandom(0,100))
        vida = 0;

    pos.set(x,y);

    */

}




bool Particle::border_crossing(){

    return ( pos.x < xlim1 || pos.y < ylim1 || pos.x > xlim2 || pos.y > ylim2);

}

bool Particle::is_alive(){

    return (life >= 0);
}


void derivsParticle(int nX, double X[], double dX[], double t, Particle* p)
{
    double x = X[0];
    double y = X[1];

    dX[0] = (p->a.x + p->b.x*x + p->c.x*y + p->d.x* x*x + p->e.x*y*y + p->f.x*x*y)/p->tau.x + p->in.x;
    dX[1] = (p->a.y + p->b.y*x + p->c.y*y + p->d.y* x*x + p->e.y*y*y + p->f.y*x*y)/p->tau.y + p->in.y;
}

