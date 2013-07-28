//
//  Visual.cpp
//  visualODEs
//
//  Created by Guido c on 7/28/13.
//
//

#include "Visual.h"

void Visual::setup(){

    ofEnableBlendMode(OF_BLENDMODE_ADD);

}


void Visual::displayPelotas(Pelota *pelotas, int total){

    
    for(int i=0; i<total;i++){
        
        int rc = ofMap(i, 0, total, 0, 255);
        int gc = 50;
        int bc = 100;
        
        
        ofSetColor(rc, gc, bc, 100);
        
        
        ofCircle((pelotas[i].pos.x+2)/4*ofGetWindowWidth(), (pelotas[i].pos.y+2)/4*ofGetWindowHeight(),10+(i%20)*2);
            
        
    
    }




}