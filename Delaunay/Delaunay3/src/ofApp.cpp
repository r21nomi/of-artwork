#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofEnableSmoothing();
    ofBackground(ofRandom(255), ofRandom(255), ofRandom(255));
    
    for (int i = 0, len = 6; i < len; i++) {
        vertexPoints.push_back(new VertexPoint(ofVec2f(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()))));
    }
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofNoFill();
    ofSetLineWidth(6);
    
    delaunay.reset();
    
    for (VertexPoint* point : vertexPoints) {
        point->update(mouseX, mouseY);
        delaunay.addPoint(point->getLocation(mouseX, mouseY));
        delaunay.triangulate();
    }
    
    delaunay.draw();
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
    vertexPoints.push_back(new VertexPoint(ofVec2f(x, y)));
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
