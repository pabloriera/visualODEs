#ifndef visualODEs_rk4_h
    #define visualODEs_rk4_h

        #include "Particle.h"

        void rk4(double X[], int nX, double t, double dt, Particle* p,
                 void (*derivsRK)(int nX, double X[], double deriv[], double t, Particle* p ) );

#endif
