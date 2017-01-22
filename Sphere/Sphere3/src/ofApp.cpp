#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    
    float lineStep = 3;
    float radius = (ofGetHeight() / 2) * 0.8;
    
    for(int s = 0; s <= 180; s += lineStep){
        ofColor color = ofColor(ofRandom(255), 0, ofRandom(255));
        float radianS = s == 0 ? ofDegToRad(3) : ofDegToRad(s);
        float z = 0;
        float r = radius;
        
        ofVec3f position = ofVec3f(ofGetWidth() / 2, ofGetHeight() / 2, z);
        float radius = 360;
        float bold = ofRandom(3, 6);
        float angle = ofRandom(0, 240);
        float speedOffSet = ofRandom(3, 6);
        float ratateOffSet = ofRandom(0.01, 0.1);
        curveItems.push_back(new CurveItem(position, color, r, bold, angle, speedOffSet, ratateOffSet));
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    for (CurveItem* item : curveItems) {
        item->update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    for (CurveItem* item : curveItems) {
        item->draw();
    }
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
