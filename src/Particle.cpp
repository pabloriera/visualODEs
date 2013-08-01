#include "Particle.h"
#include <functional>

void Particle::setup(){

    t = 0.0;

    a.set(0,0);
    b.set(0,0);
    c.set(0,0);
    d.set(0,0);
    e.set(0,0);
    tau.set(0,0);

    dt = 0.01;

    life = 1;
    tol = 0.000001*dt;

}

void Particle::update(){

    double X[2];
    X[0] = pos.x; X[1] = pos.y;

    //function <void* ()> faux = bind(,this);

    rk4(X,2,t,dt, &this.derivsParticle);

    t += dt;

     /*
    absVel = ((pos.x-x)*(pos.x-x)+(pos.y-y)*(pos.y-y));

    if ( absVel < tol*ofRandom(0,100))
        vida = 0;

    pos.set(x,y);

    */

}

static void Particle::derivsParticle(int nX, double X[], double dX[], double t)
{
    double x = X[0];
    double y = X[1];

    dX[0] = (a.x + b.x*x + c.x*y + d.x* x*x + e.x*y*y + f.x*x*y)/tau.x + in.x;
    dX[1] = (a.y + b.y*x + c.y*y + d.y* x*x + e.y*y*y + f.y*x*y)/tau.y + in.y;
}


bool Particle::border_crossing(){

    return ( pos.x < -2 || pos.y < -2 || pos.x > 2 || pos.y > 2);
}

bool Particle::is_alive(){

    return (life <= 0);
}
