#include "Particle.h"
#include <functional>
#include "rk4.h"

void Particle::setup(){

    t = 0.0;

    co[a].set(0,0);
    co[b].set(0,0);
    co[c].set(0,0);
    co[d].set(0,0);
    co[e].set(0,0);
    co[tau].set(1,1);

    rad = 10;

    dt = 0.01;

    life = 1;
    tol = 0.01*dt;

    xlim1 = -2;
    xlim2 = 2;
    ylim1 = -2;
    ylim2 = 2;

    tr_p = 0;
    max_tr_p = 500;
    tr_l = 0;
    max_t = 10000;
    t_dir = 1;
    dTraj = false;

}

void Particle::update(){

    if(life>0)
    {

        double X[2];
        X[0] = pos.x; X[1] = pos.y;

        //function <void* ()> faux = bind(,this);

        //integrates dynamical system
        rk4(X,2,t,t_dir*dt, this, derivsParticle);


        //calculate velocity and evaluate if the particle is quiete
        vel.set(pos.x-X[0],pos.y-X[1]);
        absVel = vel.length();
        //if (absVel < tol)
          //  life = 0;

        //set new position
        pos.set(X[0],X[1]);
        tr_p++;

        if(tr_p > traj.size())
            traj.push_back(new ofVec2f(X[0],X[1]));
        else
            traj[tr_p-1]->set(X[0],X[1]);


        if(tr_p>max_tr_p)
        {
            tr_l = max_tr_p;
            tr_p = 0;
            if (dTraj)
                pos = pos0;
        }


        //increase time
        t += t_dir*dt;
        if(ABS(t)>max_t)
        {
            t = 0;
        }

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

    dX[0] = (p->co[a].x + p->co[b].x*x + p->co[c].x*y + p->co[d].x* x*x + p->co[e].x* y*y + p->co[f].x*x*y)*p->co[tau].x + p->in.x;
    dX[1] = (p->co[a].y + p->co[b].y*y + p->co[c].y*x + p->co[d].y* y*y + p->co[e].y* x*x + p->co[f].y*x*y)*p->co[tau].y + p->in.y;

}

