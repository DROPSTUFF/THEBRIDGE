#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){


    bHide = true;
    bgImage.allocate(ofGetWidth(), ofGetHeight(), OF_IMAGE_COLOR);
    bgImage.loadImage("bg.jpg");
    bgImage.resize(ofGetWidth(), ofGetHeight());


    gui.setup("settings", "settings.xml", 20, 320);
    gui.add(cam1URI.set("cam1uri", "http://localhost:1338/color"));
    gui.add(cam1Width.set("cam1Width", 320, 320, 1920));
    gui.add(cam1Height.set("cam1Height", 240, 230, 1080));
    gui.add(cam1x.set("cam1x", 0, 0, ofGetWidth()));
    gui.add(cam1y.set("cam1y", 0, 0, ofGetHeight()));
    gui.add(cam2URI.set("cam2uri", "http://localhost:1338/color"));
    gui.add(cam2Width.set("cam2Width", 320, 320, 1920));
    gui.add(cam2Height.set("cam2Height", 240, 230, 1080));
    gui.add(cam2x.set("cam2x", 0, 0, ofGetWidth()));
    gui.add(cam2y.set("cam2y", 0, 0, ofGetHeight()));
    gui.add(appPositionX.set("appPositionX", 10, 0, ofGetScreenWidth()));
    gui.add(appPositionY.set("appPositionY", 10, 0, ofGetScreenHeight()));
    gui.add(appfps.set("appfps", 10, 0, 200));

	gui.loadFromFile("settings.xml");


    ofLogNotice() << "ofApp:setup: cam1:" << cam1URI << " cam2:" << cam2URI;
	ofSetFrameRate(appfps);

    ofSetWindowPosition(appPositionX,appPositionY);
    activateCams();

}

//--------------------------------------------------------------
void ofApp::activateCams(){
    cam.init(cam1Width, cam1Height, true);
    cam.setHost(cam1URI);
    cam.setCredentials("", "");
    cam.setVerbose(false);

    cam2.init(cam2Width, cam2Height);
    cam2.setHost(cam2URI);
    cam2.setCredentials("", "");
    cam2.setVerbose(false);

    cam.open();
    cam2.open();

}
void ofApp::updateCams(){
    //cam.width = cam1Width;
    //cam.height = cam1Height;
    cam.update();
    cam2.update();
}
//--------------------------------------------------------------
void ofApp::closeCams(){
    //cam.width = cam1Width;
    //cam.height = cam1Height;
    cam.close();
    cam2.close();
}

//--------------------------------------------------------------
void ofApp::drawCams(){
    //ofSetColor(255, 255, 255, 255);

    cam.draw(cam1x,cam1y, cam1Width, cam1Height);
    cam2.draw(cam2x,cam2y, cam2Width, cam2Height);

}
//--------------------------------------------------------------
void ofApp::update(){
    //ofBackground(100,100,100);
    updateCams();


    //cam1Img.setFromPixels(cam.getPixels(), cam1Width, cam1Height);
}

//--------------------------------------------------------------
void ofApp::draw(){

    ofSetColor(255);
    bgImage.draw(0,0);

	//report:
	ofSetColor(255,255,255);
	char reportStr[1024];
	sprintf(reportStr, "Cams open press o \nCams close press c \n open|close GUI press s \nfps: %f", ofGetFrameRate());
	ofDrawBitmapString(reportStr, 20, cam1Height+10);

    drawCams();

    if( !bHide ){
		gui.draw();
	}

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
switch (key){
        case 'o':
        	activateCams();
            break;

        case 'c':
        	closeCams();
            break;

        case 'g':
        	//cam.grabFrame();
            break;
        case 's':
            bHide = !bHide;
            break;

	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}
//--------------------------------------------------------------
