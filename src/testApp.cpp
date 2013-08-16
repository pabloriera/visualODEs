 #include "testApp.h"
 #include "gui.h"
 #include <vector>

void testApp::setup(){

     // cout << "hola"<< endl;
     //cout << "hola2"<< endl;
    ofSetFrameRate(100);

    receiver.setup(PORT);

    N_particles = 10000;
    system.setup(N_particles);
    visual.setup(&system);

    drop = 0;
    guiOn=false;

    //Gui setup
    controls = ofxGui::Instance(this);
   // setupControls();

    controls->buildFromXml("controls_config.xml");
    verdana.loadFont("verdana.ttf", 20);

    monomialX[0] = "";
    monomialX[1] = "X";
    monomialX[2] = "Y";
    monomialX[3] = "X^2";
    monomialX[4] = "Y^2";
    monomialX[5] = "XY";

    monomialY[0] = "";
    monomialY[1] = "Y";
    monomialY[2] = "X";
    monomialY[3] = "Y^2";
    monomialY[4] = "X^2";
    monomialY[5] = "XY";

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


    visual.update();
    system.update();

}

void testApp::draw(){

    ofBackground(0);

    visual.draw();

    ofSetColor(255);

    string drawStringX, drawStringY;
    bool changeX=false,changeY=false;
    float aux;

    drawStringX = "dx/dt = ";
    drawStringY = "dy/dt = ";

    for(size_t j = 0; j<6;j++)
    {
        aux = system.co[j].x;
        if(aux!=0)
            {
                drawStringX += ofToString(system.co[j].x,1,4,' ') + " " + monomialX[j] + " + ";
                changeX = true;
            }

        aux = system.co[j].y;
        if(aux!=0)
            {
                drawStringY += ofToString(system.co[j].y,1,4,' ') + " " + monomialY[j] + " + ";
                changeY = true;
            }
    }

    if(!changeX)
        drawStringX += "0";
    else
        drawStringX.resize(drawStringX.size()-3);

    if(!changeY)
        drawStringY += "0";
    else
        drawStringY.resize(drawStringY.size()-3);




    verdana.drawString(drawStringX,20,ofGetHeight()-60);
    verdana.drawString(drawStringY,20,ofGetHeight()-30);

    //Gui Draw
    if(guiOn)
        controls->draw();
}
//--------------------------------------------------------------
void testApp::keyPressed(int key){

    if(key=='r')
        system.reset();

    if(key=='c')
        guiOn=!guiOn;

    if(key=='o')
    {
        visual.color_absVel = true;
        visual.color_vel = false;
    }

    if(key=='p')
    {
        visual.color_absVel = false;
        visual.color_vel = true;
    }

    if(key=='s')
    {
      controls->saveToXml("controls_config.xml");
    }

    if(key=='1')
    {
        visual.fbo_active=1;
    }
    if(key=='2')
    {
        visual.fbo_active=1;
    }
    if(key=='3')
    {
        visual.fbo_active=1;
    }
    if(key=='f')
        visual.dFBO = !visual.dFBO;
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    if(guiOn)
        controls->mouseDragged(x, y, button);
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

    if(guiOn)
        controls->mousePressed(x, y, button);

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    if(guiOn)
        controls->mouseReleased(x, y, button);
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

testApp::~testApp()
{
     //controls->saveToXml("controls_config.xml");
    cout << "end" << endl;
}
