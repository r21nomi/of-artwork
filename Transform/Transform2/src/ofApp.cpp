#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255);
    float radius = 100;
    canStart = false;
    
    for (int x = radius, width = ofGetWidth() - radius; x < width; x += radius * 2) {
        for (int y = radius, height = ofGetHeight() - radius; y < height; y += radius * 2) {
            transformers.push_back(new Transformer(
                                                   ofPoint(x, y),
                                                   radius,
                                                   (int)ofRandom(3, 12),
                                                   ofColor(ofRandom(255), ofRandom(255), ofRandom(255))
                                                   ));
        }
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    if (!canStart) {
        return;
    }
    for (Transformer *transformer : transformers) {
        transformer->update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    for (Transformer *transformer : transformers) {
        transformer->draw();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    switch (key) {
        case ' ':
            canStart = true;
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
