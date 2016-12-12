#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(ofColor(ofRandom(255), ofRandom(255), ofRandom(255)));
    
    color = ofColor(ofRandom(255), ofRandom(255), ofRandom(255));
    noiseValue = 0.5;
    step = 15;
    radius = 200;
    offset = 20;
}

//--------------------------------------------------------------
void ofApp::update(){
    points.clear();
    
    for (int i = 0; i < 360 + step * 3; i += step) {
        float radian = ofDegToRad(i);
        ofVec2f* pos = new ofVec2f(radius * cos(radian), radius * sin(radian));
        float noise = ofNoise(pos->x * 0.1 + 1000, pos->y * 0.1 + 1000, ofGetFrameNum() * 0.01);
        float nradius = radius + noiseValue * ofMap(noise, 0, 1, -offset, offset);
        points.push_back(new ofVec2f(nradius * cos(radian), nradius * sin(radian)));
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(color);
    
    ofPushMatrix();
    ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
    ofBeginShape();
    
    for (ofVec2f* vec : points) {
        ofCurveVertex(vec->x, vec->y);
    }
    
    ofEndShape(OF_CLOSE);
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
