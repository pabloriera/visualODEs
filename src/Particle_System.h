#ifndef visualODEs_SYSTEM_h
    #define visualODEs_SYSTEM_h

#include "Particle.h"

class Particle_System{


public:

    Particle_System(){    }

    void setup();
    void update();
    void reset();

    size_t TOTAL;

    Particle p[TOTAL];

};


#endif
