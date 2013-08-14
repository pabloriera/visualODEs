//
//  Visualization.cpp
//  visualODEs
//
//  Created by Guido c on 7/28/13.
//
//

#include "Visualization.h"

void Visualization::setup(Particle_System* _system ){

    system = *_system;

    color = new ofColor [system.N_particles];

    maxVel = 0.2;
    color_absVel = true;
    color_vel = false;
}


void Visualization::displayParticles(){


    ofFill();
    ofEnableBlendMode(OF_BLENDMODE_ADD);

    for(size_t i=0; i<system.N_particles;i++){

        //int rc = ofMap(i, 0, system.N_particles, 0, 255);
    /*   int rc = 100;
        int gc = 20;
        int bc = ofMap(system.p[i].absVel,0,0.05,0,255);*/

        if (system.p[i].life>0.5)
        {
            if(color_absVel)
                color[i].setHsb(ofMap(system.p[i].absVel,0,maxVel,1,254,true),200,ofMap(system.p[i].absVel,0,maxVel,100,200,true));

            if(color_vel)
                color[i].set(ofMap(abs(system.p[i].vel.x),0,maxVel,1,254,true),100,ofMap(abs(system.p[i].vel.y),0,maxVel,1,254,true));

            float rad = system.p[i].rad;

            //ofSetColor(rc, gc, bc, 100);
            ofSetColor(color[i]);

            ofCircle((system.p[i].pos.x+2)/4*ofGetWindowWidth(), (system.p[i].pos.y+2)/4*ofGetWindowHeight(),rad);
//          ofCircle((system.p[i].pos.x+2)/4*ofGetWindowWidth(), (system.p[i].pos.y+2)/4*ofGetWindowHeight(),10+(i%20)*2);
        }
        else
            system.p[i].life = 1;


    }

}
