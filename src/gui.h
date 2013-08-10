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

    int nslid = 11;

	ofxGuiPanel* panel = controls->addPanel(appPtr->panel, "", 10, 10, OFXGUI_PANEL_BORDER, OFXGUI_PANEL_SPACING);
	panel->addSlider(appPtr->slider_dt, "DT", 140, 15, 0.00001f, 1.0f, 0.0f, kofxGui_Display_Float4, 0);
	panel->addSlider(appPtr->slider_rad, "Rad", 140, 15, 0.01f, 50.0f, 0.0f, kofxGui_Display_Float2, 0);
	panel->addSlider(appPtr->slider_maxVel, "maxVel", 140, 15, 0.00001f, 1.0f, 0.0f, kofxGui_Display_Float2, 0);
	panel->addSlider(appPtr->slider_ax, "a.x", 140, 15, -2.0f, 2.0f, 0.0f, kofxGui_Display_Float2, 0);
	panel->addSlider(appPtr->slider_ay, "a.y", 140, 15, -2.0f, 2.0f, 0.0f, kofxGui_Display_Float2, 0);
	panel->addSlider(appPtr->slider_bx, "b.x", 140, 15, -2.0f, 2.0f, 0.0f, kofxGui_Display_Float2, 0);
	panel->addSlider(appPtr->slider_by, "b.y", 140, 15, -2.0f, 2.0f, 0.0f, kofxGui_Display_Float2, 0);
	panel->addSlider(appPtr->slider_cx, "c.x", 140, 15, -2.0f, 2.0f, 0.0f, kofxGui_Display_Float2, 0);
	panel->addSlider(appPtr->slider_cy, "c.y", 140, 15, -2.0f, 2.0f, 0.0f, kofxGui_Display_Float2, 0);
	panel->addSlider(appPtr->slider_dx, "d.x", 140, 15, -2.0f, 2.0f, 0.0f, kofxGui_Display_Float2, 0);
	panel->addSlider(appPtr->slider_dy, "d.y", 140, 15, -2.0f, 2.0f, 0.0f, kofxGui_Display_Float2, 0);

	panel->mObjHeight = nslid*30+10;
	panel->mObjWidth = 150;
	for(int i =0; i<nslid;i++)
	{
        panel->mObjects[i]->mObjX = 5;
        panel->mObjects[i]->mObjY = 5+i*30;
    }
	panel->adjustToNewContent(100, 0);

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
	}
}
#endif //GUI_CONTROLS_H

