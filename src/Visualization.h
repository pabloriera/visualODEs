//
//  Visualization.h
//  visualODEs
//
//  Created by Guido c on 7/28/13.
//
//

#ifndef visualODEs_VISUALIZATION_h
    #define visualODEs_VISUALIZATION_h

#include "Particle_System.h"

class Visualization{


public:

    Visualization(){ }

    void setup(Particle_System* _system);
    void update();
    void draw();

    Particle_System system;

    ofColor* color;

    bool color_absVel, color_vel;

    float maxVel;

    vector<ofFbo> fbo;
    size_t fbo_active;
    bool dFBO;

};


#endif
