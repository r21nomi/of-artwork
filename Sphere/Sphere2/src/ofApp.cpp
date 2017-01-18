#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255, 255, 255);
    
    float lineStep = 10;
    float radius = 300;
    
    for(int s = 0; s <= 180; s += lineStep){
        ofColor color = ofColor(ofRandom(255), ofRandom(255), ofRandom(255));
        float radianS = s == 0 ? ofDegToRad(3) : ofDegToRad(s);
        float z = radius * cos(radianS);
        
        rings.push_back(new Ring(radius, lineStep, radianS, z, color));
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    for (Ring* ring : rings) {
        ring->update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofPushMatrix();
    ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
    
    ofRotateZ(ofGetElapsedTimeMillis() * 0.01);
    ofRotateX(ofGetElapsedTimeMillis() * 0.01);
    
    for (Ring* ring : rings) {
        ring->draw();
    }
    
    ofPopMatrix();
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
