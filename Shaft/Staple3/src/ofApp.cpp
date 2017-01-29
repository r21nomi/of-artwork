#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255);
    
    for (int x = 0, winWidth = ofGetWidth(); x < winWidth; x += 150) {
        ofColor color = ofColor(ofRandom(200), ofRandom(200), ofRandom(200));
        ofVec3f position = ofVec3f(0, 0, -x);
        StaplerLine* staplerLine = new StaplerLine(position, color);
        staplerLines.push_back(staplerLine);
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    for (StaplerLine* staplerLine : staplerLines) {
        staplerLine->update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    camera.begin();
    
    ofPushMatrix();
    
    ofTranslate(-staplerLines[0]->getStapler()->getPosition().x, 0, ofGetWidth() / 2);
    
    float offset = ofGetElapsedTimeMillis() * 0.001;
    camera.setPosition(
                       sin(offset) * ofGetWidth(),
                       ofMap(cos(offset), -1, 1, 0, 1) * ofGetHeight(),
                       cos(offset) * ofGetHeight() / 10
                       );
    
    ofVec3f center = ofVec3f(0, 0, 0);
    camera.lookAt(center);
    
    for (StaplerLine* staplerLine : staplerLines) {
        staplerLine->draw();
    }
    
    ofPopMatrix();
    
    camera.end();
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
