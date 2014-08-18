#pragma once

#include "ofMain.h"
#include "ofUtils.h"
#include "ofxOpenCv.h"
#include "ofxIpCamera.h"
#include "ofxXmlSettings.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

        void activateCams();
        void updateCams();
        void drawCams();
        void closeCams();

		ofxIpCamera             cam;
        ofxIpCamera             cam2;
		ofxXmlSettings          settings;
        ofxPanel                gui;
        ofxCvColorImage		    cam1Img;
        ofxCvColorImage         cam2Img;
        ofxCvContourFinder 	    contourFinder;

		bool                    bHide; //gui boolean
		ofImage                 bgImage;

		ofParameter<string>     cam1URI;
		ofParameter<int>        cam1Width;
		ofParameter<int>        cam1Height;
		ofParameter<int>        cam1x;
		ofParameter<int>        cam1y;
		ofParameter<string>     cam2URI;
		ofParameter<int>        cam2Width;
		ofParameter<int>        cam2Height;
		ofParameter<int>        cam2x;
		ofParameter<int>        cam2y;
		ofParameter<int>        appPositionX;
		ofParameter<int>        appPositionY;
		ofParameter<int>        appfps;

};
