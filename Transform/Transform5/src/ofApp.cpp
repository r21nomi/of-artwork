#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255);
    canStart = false;
    
    initTransformers();
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
            
        case 'r':
            initTransformers();
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

void ofApp::initTransformers() {
    int vertex = 7;
    int count = 12;
    float radius = ofGetWidth() / count / 2;
    ofColor color = ofColor(ofRandom(255), ofRandom(255), ofRandom(255));
    
    transformers.clear();
    
    int line = 1;
    for (int y = radius, height = ofGetHeight() + radius; y <= height; y += radius * 2) {
        int startY;
        switch (vertex) {
            case 3:
                startY = line % 2 != 0 ? radius : 0;
                break;
                
            default:
                startY = radius;
                break;
        }
        for (int x = startY, width = ofGetWidth() + radius; x <= width; x += radius * 2) {
        transformers.push_back(new Transformer(
                                               ofPoint(x, y),
                                               radius,
                                               vertex,
                                               color
                                               ));
        }
        line++;
    }
}
