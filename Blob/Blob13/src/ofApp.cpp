#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    backgroudColor = ofColor(ofRandom(255), ofRandom(255), ofRandom(255));
//    backgroudColor = ofColor(255);
    color = ofColor(ofRandom(255), ofRandom(255), ofRandom(255));
    noiseValue = 0.5;
    step = 15;
    radius = 200;
    offset = 20;
    image.load("r21nomi.png");
    
    ofBackground(backgroudColor);
    fbo.allocate(radius * 2, radius * 2, GL_RGBA);
}

//--------------------------------------------------------------
void ofApp::update(){
    points.clear();
    
    for (int i = 0; i < 360 + step * 3; i += step) {
        float radian = ofDegToRad(i);
        ofVec2f* pos = new ofVec2f(radius * cos(radian), radius * sin(radian));
        float noise = ofNoise(pos->x * 0.1 + 1000, pos->y * 0.1 + 1000, ofGetFrameNum() * 0.02);
        float nradius = radius + noiseValue * ofMap(noise, 0, 1, -offset, offset);
        points.push_back(new ofVec2f(nradius * cos(radian), nradius * sin(radian)));
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofPushMatrix();
    ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
    
    ofSetColor(backgroudColor);
    ofFill();
    fbo.begin();
    
    // If you don't execute this, mask will not be applied correctly.
    ofClear(0, 0, 0, 0);
    
    ofPushMatrix();
    ofTranslate(radius, radius);
    ofBeginShape();
    for (ofVec2f* vec : points) {
        ofCurveVertex(vec->x, vec->y);
    }
    ofEndShape(OF_CLOSE);
    ofPopMatrix();
    
    fbo.end();
    
    image.getTexture().setAlphaMask(fbo.getTexture());
    image.draw(-radius, -radius, radius * 2, radius * 2);
    
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
