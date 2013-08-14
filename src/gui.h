/*
*  GUI.h
*
*
*  Created on 2/2/09.
*  Copyright 2009 NUI Group. All rights reserved.
*
*  File with gui setup.
*
*/

#ifndef GUI_CONTROLS_H
#define GUI_CONTROLS_H

#include "testApp.h"

testApp  *appPtr;

void testApp::setupControls()
{
	appPtr = this;

	//panel border color
	controls->mGlobals->mBorderColor.r = 0;
	controls->mGlobals->mBorderColor.g = 0;
	controls->mGlobals->mBorderColor.b = 0;
	controls->mGlobals->mBorderColor.a = .3;
	//panel color
	controls->mGlobals->mCoverColor.r = 1;
	controls->mGlobals->mCoverColor.g = 1;
	controls->mGlobals->mCoverColor.b = 1;
	controls->mGlobals->mCoverColor.a = .4;
	//control outline color
	controls->mGlobals->mFrameColor.r = 0;
	controls->mGlobals->mFrameColor.g = 0;
	controls->mGlobals->mFrameColor.b = 0;
	controls->mGlobals->mFrameColor.a = .1;
	//text color
	controls->mGlobals->mTextColor.r = 0;
	controls->mGlobals->mTextColor.g = 0;
	controls->mGlobals->mTextColor.b = 0;
	controls->mGlobals->mTextColor.a = 1;
	//button color
	controls->mGlobals->mButtonColor.r = .1;
	controls->mGlobals->mButtonColor.g = .1;
	controls->mGlobals->mButtonColor.b = .1;
	controls->mGlobals->mButtonColor.a = .8;
	//slider tip color
	controls->mGlobals->mHandleColor.r = 0;
	controls->mGlobals->mHandleColor.g = 0;
	controls->mGlobals->mHandleColor.b = 0;
	//slider color
	controls->mGlobals->mSliderColor.r = .1;
	controls->mGlobals->mSliderColor.g = .1;
	controls->mGlobals->mSliderColor.b = .1;
	controls->mGlobals->mSliderColor.a = .8;

    int panels_pos_y_0 = 20;
    int slider_width = 140;

       //PANEL PARAMETROS
	ofxGuiPanel* panel_params = controls->addPanel(appPtr->panel_params, "", 10, panels_pos_y_0, OFXGUI_PANEL_BORDER, OFXGUI_PANEL_SPACING);
	panel_params->addSlider(appPtr->slider_dt, "DT", slider_width, 15, 0.001f, 1.0f, 0.0f, kofxGui_Display_Float4, 0);
	panel_params->addSlider(appPtr->slider_rad, "Rad", slider_width, 15, 0.01f, 50.0f, 0.0f, kofxGui_Display_Float2, 0);
	panel_params->addSlider(appPtr->slider_maxVel, "maxVel", slider_width, 15, 0.001f, 0.5f, 0.0f, kofxGui_Display_Float2, 0);
	panel_params->addSlider(appPtr->slider_sponReset, "sponReset", slider_width, 15, 0.00001f, 1.0f, 0.0f, kofxGui_Display_Float2, 0);
	panel_params->addButton(appPtr->button_velReset, "velReset", 15, 15,kofxGui_Button_On, kofxGui_Button_Switch);
	panel_params->addButton(appPtr->button_screenReset, "screenReset", 15, 15,kofxGui_Button_On, kofxGui_Button_Switch);

    //PANEL ORDER 2
    ofxGuiPanel* panel_2 = controls->addPanel(appPtr->panel_2, "", ofGetWidth()-slider_width-30, panels_pos_y_0, OFXGUI_PANEL_BORDER, OFXGUI_PANEL_SPACING);

	panel_2->addSlider(appPtr->slider_dx, "d.x", slider_width, 15, -2.0f, 2.0f, 0.0f, kofxGui_Display_Float2, 0);
	panel_2->addSlider(appPtr->slider_dy, "d.y", slider_width, 15, -2.0f, 2.0f, 0.0f, kofxGui_Display_Float2, 0);
	panel_2->addSlider(appPtr->slider_ex, "e.x", slider_width, 15, -2.0f, 2.0f, 0.0f, kofxGui_Display_Float2, 0);
	panel_2->addSlider(appPtr->slider_ey, "e.y", slider_width, 15, -2.0f, 2.0f, 0.0f, kofxGui_Display_Float2, 0);
	panel_2->addSlider(appPtr->slider_fx, "f.x", slider_width, 15, -2.0f, 2.0f, 0.0f, kofxGui_Display_Float2, 0);
	panel_2->addSlider(appPtr->slider_fy, "f.y", slider_width, 15, -2.0f, 2.0f, 0.0f, kofxGui_Display_Float2, 0);

    //PANEL ORDEN 1
    ofxGuiPanel* panel_1 = controls->addPanel(appPtr->panel_1, "",  ofGetWidth()-(slider_width+30)*2, panels_pos_y_0, OFXGUI_PANEL_BORDER, OFXGUI_PANEL_SPACING);

    panel_1->addSlider(appPtr->slider_bx, "b.x", slider_width, 15, -2.0f, 2.0f, 0.0f, kofxGui_Display_Float2, 0);
	panel_1->addSlider(appPtr->slider_by, "b.y", slider_width, 15, -2.0f, 2.0f, 0.0f, kofxGui_Display_Float2, 0);
	panel_1->addSlider(appPtr->slider_cx, "c.x", slider_width, 15, -2.0f, 2.0f, 0.0f, kofxGui_Display_Float2, 0);
	panel_1->addSlider(appPtr->slider_cy, "c.y", slider_width, 15, -2.0f, 2.0f, 0.0f, kofxGui_Display_Float2, 0);


    //PANEL ORDEN 0
    ofxGuiPanel* panel_0 = controls->addPanel(appPtr->panel_0, "",ofGetWidth()-(slider_width+30)*3, panels_pos_y_0, OFXGUI_PANEL_BORDER, OFXGUI_PANEL_SPACING);
    panel_0->addSlider(appPtr->slider_ax, "a.x", slider_width, 15, -2.0f, 2.0f, 0.0f, kofxGui_Display_Float2, 0);
	panel_0->addSlider(appPtr->slider_ay, "a.y", slider_width, 15, -2.0f, 2.0f, 0.0f, kofxGui_Display_Float2, 0);



	//do update while inactive
	controls->forceUpdate(false);
	controls->activate(true);

	/****************************
	* Set GUI values on startup
	****************************/
	//controls->update(appPtr->slider_dt, kofxGui_Set_Bool, &appPtr->system.dt, sizeof(bool));
}

void testApp::handleGui(int parameterId, int task, void* data, int length){
	switch(parameterId){

		case slider_dt:
				system.dt = *(float*)data;
				system.update_parameters();
			break;
        case slider_rad:
				system.rad = *(float*)data;
				system.update_parameters();
			break;
        case slider_maxVel:
				visual.maxVel = *(float*)data;
			break;
        case slider_sponReset:
				system.sponReset = *(float*)data;
			break;
		case button_velReset:
				system.velReset = *(float*)data;
			break;
        case button_screenReset:
				system.screenReset = *(float*)data;
			break;
        case slider_ax:
				system.a.x = *(float*)data;
				system.update_parameters();
			break;
        case slider_ay:
				system.a.y = *(float*)data;
				system.update_parameters();
			break;
        case slider_bx:
				system.b.x = *(float*)data;
				system.update_parameters();
			break;
        case slider_by:
				system.b.y = *(float*)data;
				system.update_parameters();
			break;
        case slider_cx:
				system.c.x = *(float*)data;
				system.update_parameters();
			break;
        case slider_cy:
				system.c.y = *(float*)data;
				system.update_parameters();
			break;
        case slider_dx:
				system.d.x = *(float*)data;
				system.update_parameters();
			break;
        case slider_dy:
				system.d.y = *(float*)data;
				system.update_parameters();
			break;
        case slider_ex:
				system.e.x = *(float*)data;
				system.update_parameters();
			break;
        case slider_ey:
				system.e.y = *(float*)data;
				system.update_parameters();
			break;
        case slider_fx:
				system.f.x = *(float*)data;
				system.update_parameters();
			break;
        case slider_fy:
				system.f.y = *(float*)data;
				system.update_parameters();
			break;

	}
}

void coord_sliders_panel(ofxGuiPanel* panel,int slider_width, int slider_sep_y, int nslid)
{
    panel->mObjHeight = nslid*slider_sep_y+10;
	panel->mObjWidth = slider_width+10;

	for(int i =0; i<nslid;i++)
	{
        panel->mObjects[i]->mObjX = 5;
        panel->mObjects[i]->mObjY = 5 + i*slider_sep_y;
    }
	panel->adjustToNewContent(100, 0);
}
#endif //GUI_CONTROLS_H

