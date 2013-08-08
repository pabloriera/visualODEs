 #include "testApp.h"
 #include "gui.h"
 #include <vector>

void testApp::setup(){

   // cout << "hola"<< endl;

    ofEnableAlphaBlending();

     //cout << "hola2"<< endl;
    ofSetFrameRate(100);


    receiver.setup(PORT);

    N_particles = 5000;
    system.setup(N_particles);
    visual.setup(&system);

    drop = 0;

}


void testApp::update(){


    //cout <<"c"<< endl;
    if(ofGetMousePressed(0))
    {
        if(drop>=N_particles)
            drop = 0;

        //system.p[drop].life = 0.6;
        system.p[drop].pos.set((float)mouseX/ofGetWidth()*4.0-2,(float)mouseY/ofGetHeight()*4.0-2);

        drop++;
        cout << "dr " << drop << endl;
    }


    while(receiver.hasWaitingMessages()){
        // get the next message
        ofxOscMessage m;
        receiver.getNextMessage(&m);

        string address = m.getAddress();

        if (address=="/visualODEs/maxVel")
        {
             visual.maxVel = m.getArgAsFloat(0);

        }
        else
            system.OscMessage(&m);
    }

    system.update();
}


void testApp::draw(){
    ofBackground(0);
    visual.displayParticles();
}
//--------------------------------------------------------------
void testApp::keyPressed(int key){

    if(key=='r')
        system.reset();

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

   /* if(button==0)
    {

        if(drop>=N_particles)
            drop = 0;

        system.p[drop].pos.set(x,y);

        drop++;
        cout << "but " << drop << endl;
    }
*/
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){

}
