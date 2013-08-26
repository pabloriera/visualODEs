 #ifndef visualODEs_PARTICLE_h
    #define visualODEs_PARTICLE_h

    #include "ofMain.h"

    enum {a,b,c,d,e,f,tau};


    using namespace std;

    class Particle {
    public:

        Particle(){  }

        void setup();

        bool border_crossing();
        bool is_dead();
        void update();

        ofVec2f pos, vel, pos0;
        vector <ofVec2f*> traj;
        size_t tr_p, max_tr_p,tr_l;
        bool dTraj;

        int life;

        float t,tbuf,Xbuf,Ybuf,x,y,kx1,kx2,kx3,kx4,ky1,ky2,ky3,ky4,dt,dX,dY;

        float max_t;
        int t_dir;

        ofVec2f co[7],in;

        float tol, absVel;
        float rad;

        float xlim1, xlim2, ylim1, ylim2;

    };
    void derivsParticle(int nX, double X[], double dX[], double t, Particle* p);

#endif
