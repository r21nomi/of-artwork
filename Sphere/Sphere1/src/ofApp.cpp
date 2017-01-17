#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255, 255, 255);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofColor color = ofColor(255, 0, 0);
    ofSetColor(color);

    ofPushMatrix();
    ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
    
    ofRotateZ(ofGetElapsedTimeMillis() * 0.01);
    ofRotateX(ofGetElapsedTimeMillis() * 0.01);
    
    float radius = 300;
    float circleStep = 1;
    float lineStep = 10;
    float lineWidth = 8;
    float lastX, lastY, lastZ;
    
    for(int s = 0; s <= 180; s += lineStep){
        float radianS = s == 0 ? ofDegToRad(3) : ofDegToRad(s);
        float expansion = ofMap(sin(ofGetElapsedTimeMillis() * 0.005), -1, 1, 1, 1.5);
        float z = radius * cos(radianS) * expansion;
        
        for(int t = 0; t <= 360; t += circleStep){
            float radianT = ofDegToRad(t);
            float x = radius * sin(radianS) * cos(radianT);
            float y = radius * sin(radianS) * sin(radianT);
            ofSetLineWidth(lineWidth);
            ofDrawEllipse(x, y, z, lineWidth * 1.5, lineWidth * 1.5);
            
            if (t != 0) {
                ofDrawLine(x, y, z, lastX, lastY, lastZ);
            }
            
            lastX = x;
            lastY = y;
            lastZ = z;
        }
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
