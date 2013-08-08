/*
*  GUI.h
*
*
*  Created on 2/2/09.
*  Copyright 2009 NUI Group. All rights reserved.
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
	controls->mGlobals->mFrameColor.a = .3;
	//text color
	controls->mGlobals->mTextColor.r = 0;
	controls->mGlobals->mTextColor.g = 0;
	controls->mGlobals->mTextColor.b = 0;
	controls->mGlobals->mTextColor.a = 1;
	//button color
	controls->mGlobals->mButtonColor.r = 1;
	controls->mGlobals->mButtonColor.g = 0;
	controls->mGlobals->mButtonColor.b = 0;
	controls->mGlobals->mButtonColor.a = .8;
	//slider tip color
	controls->mGlobals->mHandleColor.r = 0;
	controls->mGlobals->mHandleColor.g = 0;
	controls->mGlobals->mHandleColor.b = 0;
	//slider color
	controls->mGlobals->mSliderColor.r = 1;
	controls->mGlobals->mSliderColor.g = 0;
	controls->mGlobals->mSliderColor.b = 0;
	controls->mGlobals->mSliderColor.a = .8;

	ofxGuiPanel* panel = controls->addPanel(appPtr->panel, "Tracked Image", 376, 255, OFXGUI_PANEL_BORDER, OFXGUI_PANEL_SPACING);
	panel->addSlider(appPtr->slider, "Image Threshold", 140, 13, 0.0f, 255.0f, dt, kofxGui_Display_Int, 0);
	panel->mObjHeight = 120;
	panel->mObjWidth = 319;
	panel->mObjects[0]->mObjX = 120;
	panel->mObjects[0]->mObjY = 11;
	panel->adjustToNewContent(100, 0);

	//do update while inactive
	controls->forceUpdate(false);
	controls->activate(true);

	/****************************
	* Set GUI values on startup
	****************************/
	controls->update(appPtr->slider, kofxGui_Set_Bool, &appPtr->dt, sizeof(bool));
}
/*
void testApp::handleGui(int parameterId, int task, void* data, int length){
	switch(parameterId){
		//Calibration
		case calibrationPanel_calibrate:
				bShowInterface = false;
				//Enter/Exit Calibration
				bCalibration = true;
				calib.calibrating = true;
				tracker.isCalibrating = true;
				if (bFullscreen == false) ofToggleFullscreen();
				bFullscreen = true;
			break;
		//Source
		case propertiesPanel_flipH:
			if(length == sizeof(bool))
				filter->bHorizontalMirror = *(bool*)data;
				//filter_fiducial->bHorizontalMirror = *(bool*)data;
			break;
		case propertiesPanel_flipV:
			if(length == sizeof(bool))
				filter->bVerticalMirror = *(bool*)data;
				//filter_fiducial->bVerticalMirror = *(bool*)data;
			break;

		//Tracking Panel
		case trackingPanel_trackBlobs:
			if(length == sizeof(bool))
				contourFinder.bTrackBlobs=*(bool*)data;
			break;
		case trackingPanel_trackFingers:
			if(length == sizeof(bool))
				contourFinder.bTrackFingers=*(bool*)data;
			break;
		case trackingPanel_trackObjects:
			if(length == sizeof(bool))
			{
				contourFinder.bTrackObjects=*(bool*)data;
				if(contourFinder.bTrackObjects)
				{
					templates.loadTemplateXml();
				}
				else
				{
					templates.saveTemplateXml();
				}
			}
			break;
		//Communication
		case optionPanel_tuio_osc:
			if(length == sizeof(bool))
				myTUIO.bOSCMode = *(bool*)data;
			//	bTUIOMode = *(bool*)data;
				//set tcp to opposite
			//	myTUIO.bTCPMode = false;
			//	controls->update(appPtr->optionPanel_tuio_tcp, kofxGui_Set_Bool, &appPtr->myTUIO.bTCPMode, sizeof(bool));
			//	myTUIO.bBinaryMode = false;
			//	controls->update(appPtr->optionPanel_bin_tcp, kofxGui_Set_Bool, &appPtr->myTUIO.bBinaryMode, sizeof(bool));
				//clear blobs
//				myTUIO.blobs.clear();
			break;
		case optionPanel_tuio_tcp:
			if(length == sizeof(bool))
				myTUIO.bTCPMode = *(bool*)data;
			//	bTUIOMode = *(bool*)data;
				//set osc to opposite
			//	myTUIO.bOSCMode = false;
			//	controls->update(appPtr->optionPanel_tuio_osc, kofxGui_Set_Bool, &appPtr->myTUIO.bOSCMode, sizeof(bool));
			//	myTUIO.bBinaryMode = false;
			//	controls->update(appPtr->optionPanel_bin_tcp, kofxGui_Set_Bool, &appPtr->myTUIO.bBinaryMode, sizeof(bool));
				//clear blobs
//				myTUIO.blobs.clear();
			break;
		case optionPanel_bin_tcp:
			if(length == sizeof(bool))
				myTUIO.bBinaryMode = *(bool*)data;
			bTUIOMode = *(bool*)data;
			//set tcp & osc to opposite
			myTUIO.bTCPMode = false;
			controls->update(appPtr->optionPanel_tuio_tcp, kofxGui_Set_Bool, &appPtr->myTUIO.bTCPMode, sizeof(bool));
			myTUIO.bOSCMode = false;
			controls->update(appPtr->optionPanel_tuio_osc, kofxGui_Set_Bool, &appPtr->myTUIO.bOSCMode, sizeof(bool));
			//clear blobs
//				myTUIO.blobs.clear();
			break;
// 		case optionPanel_tuio_height_width:
// 			if(length == sizeof(bool))
// 				myTUIO.bHeightWidth = *(bool*)data;
// 			break;
		//Background
		case backgroundPanel_dynamic:
			if(length == sizeof(bool))
				filter->bDynamicBG = *(bool*)data;
				//filter_fiducial->bDynamicBG = *(bool*)data;
			break;
		case backgroundPanel_remove:
			if(length == sizeof(bool))
				filter->bLearnBakground = *(bool*)data;
				//filter_fiducial->bLearnBakground = *(bool*)data;
			break;
		case backgroundPanel_learn_rate:
			if(length == sizeof(float))
				backgroundLearnRate = *(float*)data;
			break;
		//Highpass
		case highpassPanel_use:
			if(length == sizeof(bool))
				filter->bHighpass = *(bool*)data;
			break;
		case highpassPanel_blur:
			if(length == sizeof(float))
				filter->highpassBlur = *(float*)data;
			break;
		case highpassPanel_noise:
			if(length == sizeof(float))
				filter->highpassNoise = *(float*)data;
			break;
		//Amplify
		case amplifyPanel_use:
			if(length == sizeof(bool))
				filter->bAmplify = *(bool*)data;
			break;
		case amplifyPanel_amp:
			if(length == sizeof(float))
				filter->highpassAmp = *(float*)data;
			break;
		case trackedPanel_darkblobs:
			if(length == sizeof(bool))
				filter->bTrackDark = *(bool*)data;
			break;
		case trackedPanel_threshold:
			if(length == sizeof(float))
				filter->threshold = *(float*)data;
			break;
		case trackedPanel_min_movement:
			if(length == sizeof(float))
				tracker.MOVEMENT_FILTERING = *(float*)data;
			break;
		case trackedPanel_min_blob_size:
			if(length == sizeof(float))
				MIN_BLOB_SIZE = *(float*)data;
			break;
		case trackedPanel_max_blob_size:
			if(length == sizeof(float))
				MAX_BLOB_SIZE = *(float*)data;
			break;
		case trackedPanel_outlines:
			if(length == sizeof(bool))
				bDrawOutlines = *(bool*)data;
			break;
		case trackedPanel_ids:
			if(length == sizeof(bool))
				bShowLabels = *(bool*)data;
			break;
		//smooth
		case smoothPanel_smooth:
			if(length == sizeof(float))
				filter->smooth = *(float*)data;
			break;
		case smoothPanel_use:
			if(length == sizeof(bool))
				filter->bSmooth = *(bool*)data;
			break;
		//Template Range Sliders
		case TemplatePanel_minArea:
			nearThreshold = *(float*)data;
			break;
		case TemplatePanel_maxArea:
			farThreshold = *(float*)data;
			break;
		//Save Settings
		case kParameter_SaveXml:
			if(length == sizeof(bool))
			{
				if(*(bool*)data)
				{
					controls->saveToXml(OFXGUI_XML);
					saveXMLSettings();
				}
			}
			break;
		case kParameter_LoadTemplateXml:
			if(length == sizeof(bool))
				if(*(bool*)data)
					if(templates.loadTemplateXml())
						printf("Templates Loaded\n");
			break;
		case kParameter_SaveTemplateXml:
			if(length == sizeof(bool))
				if(*(bool*)data)
					templates.saveTemplateXml();
			break;
	}
}*/
#endif //GUI_CONTROLS_H

