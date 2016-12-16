#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255);
    
    init();
}

void ofApp::init() {
    ofColor color = ofColor(ofRandom(255), ofRandom(255), ofRandom(255));
    float radius = 50;
    float mass = 0.4;  // Bound faster if this value is smaller...why?
    
    balls.clear();
    for (int i = radius, len = ofGetWidth(); i < len; i += radius * 2) {
        balls.push_back(new Ball(ofVec2f(i, ofRandom(0, ofGetHeight() / 5)), mass, radius, color));
    }
    
    ofColor stairColor = ofColor(ofRandom(255), ofRandom(255), ofRandom(255));
    stairs.clear();
    for (int i = 0, len = 4; i < len; i++) {
        stairs.push_back(new Stair(i + 1, ofVec2f(0, (i + 1) * 150), ofGetWidth(), 10, stairColor));
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    for (Ball* ball : balls) {
        float g = 0.4;  // Fall faster if this value is bigger.
        ofVec2f gravity = ofVec2f(0, g * ball->mass);
        float c = 0.05;
        ofVec2f friction = ball->velocity;
        friction *= -1;
        friction.normalize();
        friction *= c;
        
        ball->applyForce(friction);
        ball->applyForce(gravity);
        
        for (Stair* stair : stairs) {
            ball->checkEdges(stair->getStairY(), stair->getStepNum());
        }
        
        ball->update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    for (Stair* stair : stairs) {
        stair->draw();
    }
    for (Ball* ball : balls) {
        ball->draw();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    switch (key) {
        case ' ':
            init();
            break;
            
        default:
            break;
    }
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
