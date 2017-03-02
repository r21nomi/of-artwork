#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255);
    ofEnableLighting();
    light.setPosition(ofGetWidth() / 2, ofGetHeight() / 2, 0);
    light.enable();
    
    float w = 15;
    float h = 300;
    ofColor color = ofColor(ofRandom(200), ofRandom(200), ofRandom(200));
    
    for (int x = -ofGetWidth() / 2, winWidth = ofGetWidth() / 2; x < winWidth; x += w) {
        Pole* pole = new Pole(
                              ofVec3f(x, ofRandom(-ofGetHeight() * 1.5, -ofGetHeight() / 2), ofRandom(-winWidth, winWidth)),
                              w,
                              h,
                              color
        );
        poles.push_back(pole);
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    for (Pole* pole : poles) {
        pole->resetIfFinished();
        pole->update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofPushMatrix();
    ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
    ofRotateY(ofGetElapsedTimeMillis() * 0.04);
    
    for (Pole* pole : poles) {
        pole->draw();
    }
    ofPopMatrix();
}

void ofApp::createPoles() {
    // TODO
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
