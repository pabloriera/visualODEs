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

        int rc = ofMap(i, 0, system.N_particles, 0, 255);
        int gc = 20;
        int bc = 100;

        ofSetColor(rc, gc, bc, 100);

        ofCircle((system.p[i].pos.x+2)/4*ofGetWindowWidth(), (system.p[i].pos.y+2)/4*ofGetWindowHeight(),10);
//        ofCircle((system.p[i].pos.x+2)/4*ofGetWindowWidth(), (system.p[i].pos.y+2)/4*ofGetWindowHeight(),10+(i%20)*2);

    }

}
