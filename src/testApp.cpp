 #include "testApp.h"
 #include <vector>

void testApp::setup(){

   // cout << "hola"<< endl;

    ofEnableAlphaBlending();

     //cout << "hola2"<< endl;
    ofSetFrameRate(100);


    receiver.setup(PORT);

    N_particles = 1000;
    system.setup(N_particles);
    visual.setup(&system);


}


void testApp::update(){


    //cout <<"c"<< endl;

    while(receiver.hasWaitingMessages()){
        // get the next message
        ofxOscMessage m;
        receiver.getNextMessage(&m);

        // check for mouse moved message
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

    system.reset();

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
