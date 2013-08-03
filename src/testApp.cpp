 #include "testApp.h"
 #include <vector>

void testApp::setup(){

   // cout << "hola"<< endl;

    ofEnableAlphaBlending();

     //cout << "hola2"<< endl;
    ofSetFrameRate(100);


    receiver.setup(PORT);

    N_particles = 100;
    system.setup(N_particles);
    visual.setup(&system);


}


void testApp::update(){


    //cout <<"c"<< endl;

/*    while(receiver.hasWaitingMessages()){
        // get the next message
        ofxOscMessage m;
        receiver.getNextMessage(&m);

        // check for mouse moved message
        if(m.getAddress() == "/4/multifader1/1")
            a1 = m.getArgAsFloat(0)*2-1;


        if(m.getAddress() == "/4/multifader1/2")
            b1 = m.getArgAsFloat(0)*2-1;

        if(m.getAddress() == "/4/multifader1/3")
            c1 = m.getArgAsFloat(0)*2-1;



        if(m.getAddress() == "/4/multifader2/1")
            a2 = m.getArgAsFloat(0)*2-1;


        if(m.getAddress() == "/4/multifader2/2")
            b2 = m.getArgAsFloat(0)*2-1;

        if(m.getAddress() == "/4/multifader2/3")
            c2 = m.getArgAsFloat(0)*2-1;

        if(m.getAddress() == "/4/multifader1/24")
            tau1 = ofMap(m.getArgAsFloat(0),0,1,-0.4,0.4,0);


        if(m.getAddress() == "/4/multifader2/24")
            tau2= ofMap(m.getArgAsFloat(0),0,1,-0.4,0.4,0);

       // cout <<m.getAddress() << endl;

    }
*/

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
