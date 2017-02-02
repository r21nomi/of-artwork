#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255);
}

//--------------------------------------------------------------
void ofApp::update(){
    for (Desk* desk : desks) {
        float g = 0.4;  // Fall faster if this value is bigger.
        ofVec3f gravity = ofVec3f(0, g * desk->mass, 0);
        float c = 0.05;
        ofVec3f friction = desk->velocity;
        friction *= -1;
        friction.normalize();
        friction.y *= c;
        
        desk->applyForce(friction);
        desk->applyForce(gravity);
        desk->update();
    }
    vector<Desk*>::iterator it = desks.begin();
    while (it != desks.end()) {
        Desk *item = dynamic_cast<Desk*>(*it);
        
        ofLog(OF_LOG_NOTICE, "getTop = " + ofToString(item->getTop()) + ", height = " + ofToString(ofGetHeight()) + ", size = " + ofToString(desks.size()));
        
        if (item->getTop() > ofGetHeight() + 100) {
            it = desks.erase(it);
            // Commenting out for "break;" makes program slower...
            // But this will delete all items immediately.
//            break;
        } else {
            ++it;
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    for (Desk* desk : desks) {
        desk->draw();
    }
}

void ofApp::generateDesks() {
    ofColor color = ofColor(ofRandom(200), ofRandom(200), ofRandom(200));
    int areaCount = 3;
    float eachAreaWidth = ofGetWidth() / areaCount;
    float area = ofRandom(areaCount);
    
    for (int i = 0; i < 200; i++) {
        float width = ofRandom(50, 80);
        float height = width * 0.8;
        float depth = 50;
        float mass = ofRandom(20, 30);
        
        ofVec3f position = ofVec3f(ofRandom(area * eachAreaWidth, area * eachAreaWidth + eachAreaWidth), ofGetHeight() + height * 2, 0);
        ofVec3f velocity = ofVec3f(ofRandom(-1, 1), mass * -1, 0);
        Desk* desk = new Desk(position, velocity, width, height, depth, mass, color);
        desks.push_back(desk);
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    switch (key) {
        case ' ':
            generateDesks();
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
