#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255);
    
    stapleWidth = 50;
    stapleHeight = 30;
    stapleDepth = 5;
    stapleMargin = -11;
    stapleSpeed = -2;
    stapleBold = 5;
    stapleColor = ofColor(ofRandom(200), ofRandom(200), ofRandom(200));
    
    for (int x = 0, winWidth = ofGetWidth() / 2; x < winWidth; x += (stapleWidth + stapleMargin)) {
        ofVec3f position = ofVec3f(x, ofGetHeight() / 2, 0);
        Staple* staple = getStaple(position);
        staples.push_back(staple);
    }
    
    Stapler* stapler = new Stapler(
                                   ofVec3f(ofGetWidth(), ofGetHeight() / 2, 0),
                                   300,
                                   30,
                                   100,
                                   stapleColor
    );
    staplers.push_back(stapler);
}

//--------------------------------------------------------------
void ofApp::update(){
    ofVec3f staplerPosition = staplers[0]->getPosition();
    Staple* lastStaple = staples[staples.size() - 1];
    
    if (lastStaple->getPosition().x < staplerPosition.x) {
        ofVec3f position = lastStaple->getPosition();
        position.x += (stapleWidth + stapleMargin);
        Staple* staple = getStaple(position);
        staples.push_back(staple);
        
        cout << ofToString(lastStaple->getPosition().x) + ", " + ofToString(staplerPosition.x) << endl;
    }
    
    for (Stapler* stapler : staplers) {
        stapler->update();
    }
    for (Staple* staple : staples) {
        staple->update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    camera.begin();
    
    ofPushMatrix();
    ofRotateY(45);
    ofRotateZ(15);
    ofTranslate(-ofGetWidth() / 2, -ofGetHeight() / 2);
    
    for (Stapler* stapler : staplers) {
        stapler->draw();
    }
    for (Staple* staple : staples) {
        staple->draw();
    }
    
    ofPopMatrix();
    
    camera.end();
}

Staple* ofApp::getStaple(ofVec3f position) {
    return new Staple(position, stapleWidth, stapleHeight, stapleDepth, stapleBold, stapleSpeed, ofColor(stapleColor, 200));
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
