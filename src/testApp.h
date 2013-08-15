#pragma once

    #include "ofMain.h"
    #include "Particle_System.h"
    #include "ofxOsc.h"
    #include "ofxGui.h"
    #include "Visualization.h"

    // listen on port 12345
    #define PORT 54321
    #define NUM_MSG_STRINGS 20


    class testApp : public ofBaseApp, ofxGuiListener{
    public:
            void setup();
            void update();
            void draw();
            ~testApp();

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
            size_t drop;

            bool guiOn;

            ofxOscReceiver receiver;

            Visualization visual;

            //Basic for GUI
            void    setupControls();
            void    handleGui(int parameterId, int task, void* data, int length);
            ofxGui* controls;

            enum {
                panel_params, panel_0, panel_1, panel_2,
                button_velReset,
                button_screenReset,
                slider_dt,
                slider_rad,
                slider_maxVel,
                slider_sponReset,
                slider_ax,
                slider_ay,
                slider_bx,
                slider_by,
                slider_cx,
                slider_cy,
                slider_dx,
                slider_dy,
                slider_ex,
                slider_ey,
                slider_fx,
                slider_fy,

            };

    };



