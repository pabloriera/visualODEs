//
//  Visualization.cpp
//  visualODEs
//
//  Created by Guido c on 7/28/13.
//
//

#include "Visualization.h"

void Visualization::setup(){

    ofEnableBlendMode(OF_BLENDMODE_ADD);

}


void Visualization::displayPelotas(Particle *particles, int total){


    for(int i=0; i<total;i++){

        int rc = ofMap(i, 0, total, 0, 255);
        int gc = 50;
        int bc = 100;


        ofSetColor(rc, gc, bc, 100);


        ofCircle((particles[i].pos.x+2)/4*ofGetWindowWidth(), (particles[i].pos.y+2)/4*ofGetWindowHeight(),10+(i%20)*2);



    }




}
