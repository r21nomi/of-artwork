#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    float radius = 85;
    float margin = 10;
    
    for (int x = radius, width = ofGetWidth() - radius; x < width; x += (radius * 2 + margin)) {
        for (int y = radius, height = ofGetHeight() - radius; y < height; y += (radius * 2 + margin)) {
            Circle *circle = new Circle(x, y, radius);
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
    ofBackground(140,0,255);
    ofSetColor(255,255,0);
    
    for (Circle *circle : circles) {
        circle->draw();
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
