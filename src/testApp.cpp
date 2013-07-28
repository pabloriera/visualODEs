 #include "testApp.h"
 #include <vector>

    void testApp::setup(){

       // cout << "hola"<< endl;

        ofEnableAlphaBlending();

         //cout << "hola2"<< endl;
        ofSetFrameRate(100);

        for(int i = 0; i < TOTAL; i++)
        {
            p[i].pos.set( ofRandom(-2,2), ofRandom(-2,2));
             // cout <<i<< endl;
        }

        a1 = -1;a2 = -1;
        b1 = 0; b2 = 0;
        tau1 = 1; tau2 = 1;

        tiempo = 0;

        cout <<"a"<< endl;

        receiver.setup(PORT);
        cout <<"b"<< endl;
        
        visual.setup();


    }


    void testApp::update(){


        //cout <<"c"<< endl;

        while(receiver.hasWaitingMessages()){
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



        for(int i = 0; i < TOTAL; i++){

//            p[i].agregarFuerza(ofVec2f((ofRandom(0,2)-1)/1000,(ofRandom(0,2)-1)/1000));
//            p[i].agregarNoise(1.57, 0.003,mouseX, mouseY);
//            p[i].agregarAlphaFade(false);
//            p[i].agregarScaleFade(false);

            p[i].a1 = a1; p[i].b1 = b1;
            p[i].a2 = a2; p[i].b2 = b2;
            p[i].tau1 = tau1;p[i].tau2 = tau2;
            p[i].update();

            //cout << i << endl;

            if (p[i].pasoElBorde() || !p[i].estaViva() ){
                p[i].vida = 1;
                p[i].pos.set( ofRandom(-2,2), ofRandom(-2,2));
            }
        }

        //cout <<"d"<< endl;
        tiempo++;
        //cout <<"e"<< endl;

    }


    void testApp::draw(){
        ofBackground(0);
        
        /*
        for(int i = 0; i < TOTAL; i++)
            p[i].draw();
         */
        
        visual.displayPelotas(p, TOTAL);
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


        for(int i = 0; i < TOTAL; i++)
        {
            p[i].pos.set( ofRandom(-2,2), ofRandom(-2,2));
             // cout <<i<< endl;
        }



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
