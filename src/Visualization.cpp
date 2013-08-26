//
//  Visualization.cpp
//  visualODEs
//
//  Created by Guido c on 7/28/13.
//
//

#include "Visualization.h"

void Visualization::setup(Particle_System* _system ){

    system = *_system;

    color = new ofColor [system.N_particles];

    maxVel = 0.2;
    color_absVel = true;
    color_vel = false;

    ofFbo aux_fbo;
    aux_fbo.allocate(ofGetWidth(),ofGetHeight(),GL_RGBA);


    for(size_t i =0;i<1;i++)
        fbo.push_back(aux_fbo);


    for(size_t i =0;i<1;i++)
    {
        fbo[i].begin();
            ofSetColor(0,0,0, 255);
            ofRect(0,0,ofGetWidth(),ofGetHeight());
        fbo[i].end();

    }


    fbo_active = 0;
    dFBO = false;
    dTraj =false;

}
void Visualization::update(){

    if(dFBO)
    {

    //    cout << system.p[0].vel.x<< endl;
    //    cout << system.p[0].absVel<< "  "<<ofMap(system.p[0].absVel,0,maxVel,1,254,true) << endl;

        //ofEnableBlendMode(OF_BLENDMODE_ADD);
        ofEnableAlphaBlending();

        fbo[fbo_active].begin();


            //ofSetColor(0,0,0);
            //ofRect(0,0,ofGetWidth(),ofGetHeight());
            ofClear(255,255,255,0);

            ofFill();
            ofSetColor(0,0,0, 255);

            ofRect(0,0,ofGetWidth(),ofGetHeight());

            for(size_t i=0; i<system.N_particles;i++){

                //int rc = ofMap(i, 0, system.N_particles, 0, 255);
            /*   int rc = 100;
                int gc = 20;
                int bc = ofMap(system.p[i].absVel,0,0.05,0,255);*/

           // ofPushStyle();

                    if (system.p[i].life>0.5)
                    {
                        if(color_absVel)

                            color[i].setHsb( ofMap(system.p[i].absVel,0,maxVel,1,254,true) , 200,255,255);
                            //ofMap(system.p[i].absVel,0,maxVel,100,200,true)
                            //color[i].set(234,123,43);

                        if(color_vel)
                            color[i].set(ofMap(abs(system.p[i].vel.x),0,maxVel,1,254,true),100,ofMap(abs(system.p[i].vel.y),0,maxVel,1,254,true),255);


                        float rad = system.p[i].rad;


                        //ofSetColor(rc, gc, bc, 100);
                        ofSetColor(color[i]);
                        ofFill();

                        ofCircle((system.p[i].pos.x+2)/4*ofGetWindowWidth(), (system.p[i].pos.y+2)/4*ofGetWindowHeight(),rad);
            //          ofCircle((system.p[i].pos.x+2)/4*ofGetWindowWidth(), (system.p[i].pos.y+2)/4*ofGetWindowHeight(),10+(i%20)*2);
                    }
                    else
                    {
                        system.p[i].life = 1;
                    }


          //  ofPopStyle();
            }

        fbo[fbo_active].end();

    }
}

void Visualization::draw(){

  ofPushMatrix();
  ofTranslate(ofGetWindowWidth()/2.0,ofGetHeight()/2.0, 0);
  //ofScale(100,100,0);

  if(!dFBO)
  {
       ofEnableBlendMode(OF_BLENDMODE_ADD);

        if(dTraj)
        {
            ofNoFill();
            ofSetColor(255,255,255,100);

            for(size_t i=0; i<system.N_traj;i++)
            {
                ofPushStyle();
                    ofPushMatrix();

                    ofSetLineWidth(1);

                        ofBeginShape();

                        for (size_t j= 0; j< system.p[i].tr_l; j++){

                            ofVertex( system.p[i].traj[j]->x/4*ofGetWindowWidth(), system.p[i].traj[j]->y /4*ofGetWindowHeight());
                            //cout << system.p[i].traj[j]->x << " " << system.p[i].traj[j]->y << endl;
                        }
                        ofEndShape(false);

                    ofPopMatrix();
                ofPopStyle();
            }
        }

        for(size_t i=0; i<system.N_particles;i++){


                if (system.p[i].life>0.5)
                {
                    if(color_absVel)

                        color[i].setHsb( ofMap(system.p[i].absVel,0,maxVel,1,254,true) , 200,255,255);

                    if(color_vel)
                        color[i].set(ofMap(abs(system.p[i].vel.x),0,maxVel,1,254,true),100,ofMap(abs(system.p[i].vel.y),0,maxVel,1,254,true),255);


                    float rad = system.p[i].rad;

                    ofSetColor(color[i]);
                    ofFill();

                    ofCircle((system.p[i].pos.x)/4*ofGetWindowWidth(), (system.p[i].pos.y)/4*ofGetWindowHeight(),rad);
                }
                else
                {
                    system.p[i].life = 1;
                }
        }





  }
  else{  fbo[0].draw(0,0);}

  ofPopMatrix();
      //for(size_t i= 0;i<fbo.size();i++)
      //  fbo[i].draw(0,0);
}
