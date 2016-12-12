#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    float radius = 50;
    float margin = 70;
    
    for (int x = 0, width = ofGetWidth(); x < width; x += (radius + margin)) {
        for (int y = 0, height = ofGetHeight(); y < height; y += (radius + margin)) {
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
    ofBackground(29, 52, 208);
    ofSetColor(214, 180, 11);
    
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
