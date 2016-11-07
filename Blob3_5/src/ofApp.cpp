#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    float radius = ofGetWidth() / 10 / 2;
    float step = radius * 2 + MERGIN;
    
    for (int x = radius, width = ofGetWidth() - radius; x <= width; x += step) {
        for (int y = radius, height = ofGetHeight() - radius; y <= height; y += step) {
            Circle *circle = new Circle(x, y, radius, ofColor(ofRandom(60, 255)));
            circles.push_back(circle);
        }
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    for (Circle *circle : circles) {
        circle->update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(100, 60, 255);
    
    for (Circle *circle : circles) {
        circle->draw();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    for (Circle *circle : circles) {
        circle->setTargetLocation(ofPoint(ofRandom(ofGetWidth()), ofRandom(ofGetHeight())));
    }
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
