 #ifndef PELOTA
    #define PELOTA

    #include "ofMain.h"

    class Pelota {
    public:
        Pelota();

        void agregarFuerza(ofVec2f fuerza);  //agregará un movimiento aleatorio suave

        bool pasoElBorde();
        bool estaViva();                        // esta función chequea si esta viva

        void update();  // el update quitará vida y limitará el movimiento

        void draw();

        ofColor color;

        ofVec2f pos, vel, acc;
        float alphaF, escalaF;
        int vida,vidaInicial, tamanio;

        float t,tbuf,Xbuf,Ybuf,x,y,kx1,kx2,kx3,kx4,ky1,ky2,ky3,ky4,dt,dX,dY;
        float a1,a2,b1,b2,c1,c2,d1,d2,e1,e2,tau1,tau2;
        float dx0, dy0;
        float in1,in2;
        float tol, absVel;

    };
    #endif
