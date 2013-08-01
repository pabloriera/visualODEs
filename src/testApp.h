#pragma once

    #include "ofMain.h"
    #include "Particle_System.h"
    #include "ofxOsc.h"
    #include "Visualization.h"

    // listen on port 12345
    #define PORT 8000
    #define NUM_MSG_STRINGS 20

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


            size_t N_particles;
            Particle_System system;

            int tiempo;


            ofxOscReceiver receiver;

            Visualization visual;
    };
