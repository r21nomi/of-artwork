#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255);
    
    float width = 100;
    float height = 80;
    float depth = 20;
    float margin = 0;
    
    for (int x = 0, winWidth = ofGetWidth(); x < winWidth; x += (width + margin)) {
        ofVec3f position = ofVec3f(x, ofGetHeight() / 2, 0);
        float bold = 10;
        ofColor color = ofColor(255, 0, 0);
        Staple* staple = new Staple(position, width, height, depth, bold, color);
        staples.push_back(staple);
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    for (Staple* staple : staples) {
        staple->update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    camera.begin();
    
    ofPushMatrix();
    ofRotateY(ofGetElapsedTimeMillis() * 0.05);
    ofTranslate(-ofGetWidth() / 2, -ofGetHeight() / 2);
    
    for (Staple* staple : staples) {
        staple->draw();
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
