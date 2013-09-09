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


    //aux_fbo.allocate(ofGetWidth(),ofGetHeight(),GL_RGBA32F_ARB);

    N_fbos = 5;

    for(size_t i =0;i<N_fbos;i++){
        ofFbo aux_fbo;
        aux_fbo.allocate(ofGetWidth(),ofGetHeight(),GL_RGBA);
        fbo.push_back(aux_fbo);
        fbo_state.push_back(true);
    }

    for(size_t i =0;i<N_fbos;i++)
    {
        fbo[i].begin();
            ofSetColor(0,0,0,0);
            ofRect(0,0,ofGetWidth(),ofGetHeight());
        fbo[i].end();
    }

    fbo_active = 0;
    dFBO  = false;
    dTraj = false;

}

void Visualization::update(){

    //cout << fbo_active << endl;
    if(dFBO)
    {
        fbo[fbo_active].begin();

        ofPushMatrix();


            ofTranslate(ofGetWindowWidth()/2.0,ofGetHeight()/2.0, 0);

            ofPushStyle();
                ofEnableAlphaBlending();
                ofEnableBlendMode(OF_BLENDMODE_ADD);
                 ofClear(0,0,0,0);

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

                ofDisableBlendMode();
                ofDisableAlphaBlending();

            ofPopStyle();

        ofPopMatrix();

        fbo[fbo_active].end();
    }
}

void Visualization::draw(){

  if(!dFBO)
  {
       ofPushMatrix();
           ofTranslate(ofGetWindowWidth()/2.0,ofGetHeight()/2.0, 0);
           ofEnableAlphaBlending();
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


            ofDisableAlphaBlending();
        ofPopMatrix();

    }

    else
    {

    ofPushStyle();
     ofEnableAlphaBlending();
    ofEnableBlendMode(OF_BLENDMODE_ADD);

        for(size_t i =0; i < fbo.size(); i++)
        {
            if(fbo_state[i])
            {
                ofSetColor(255,255,255,180);
                fbo[i].draw(0,0);
            }
        }
         ofDisableAlphaBlending();
    ofPopStyle();

    }

}
