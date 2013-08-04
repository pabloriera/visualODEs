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
    ofEnableBlendMode(OF_BLENDMODE_ADD);
}


void Visualization::displayParticles(){


    for(size_t i=0; i<system.N_particles;i++){

        //int rc = ofMap(i, 0, system.N_particles, 0, 255);
    /*   int rc = 100;
        int gc = 20;
        int bc = ofMap(system.p[i].absVel,0,0.05,0,255);*/

        ofColor color;
        color.setHsb(ofMap(system.p[i].absVel,0,0.2,0,254,true),200,200);

        float rad = system.p[i].rad;

        //ofSetColor(rc, gc, bc, 100);
        ofSetColor(color);

        ofCircle((system.p[i].pos.x+2)/4*ofGetWindowWidth(), (system.p[i].pos.y+2)/4*ofGetWindowHeight(),rad);
//        ofCircle((system.p[i].pos.x+2)/4*ofGetWindowWidth(), (system.p[i].pos.y+2)/4*ofGetWindowHeight(),10+(i%20)*2);

    }

}
