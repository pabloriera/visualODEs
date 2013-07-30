#pragma once

    #include "ofMain.h"
    #include "Particle.h"
    #include "ofxOsc.h"
    #include "Visualization.h"

    // listen on port 12345
    #define PORT 8000
    #define NUM_MSG_STRINGS 20
    #define TOTAL 1000      // Esta bueno explorar hasta que número puede llegar

    class testApp : public ofBaseApp{
    public:
            void setup();
            void update();
            void draw();

            void keyPressed  (int key);
            void keyReleased(int key);
            void mouseMoved(int x, int y );
            void mouseDragged(int x, int y, int button);
            void mousePressed(int x, int y, int button);
            void mouseReleased(int x, int y, int button);
            void windowResized(int w, int h);
            void dragEvent(ofDragInfo dragInfo);
            void gotMessage(ofMessage msg);


            Particle_System system;

            int tiempo;
            float a1,a2,b1,b2,c1,c2,d1,d2,e1,e2,tau1,tau2;

            ofxOscReceiver receiver;

            Visualization visual;
    };
