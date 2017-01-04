#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255);
    ofEnableLighting();
    light.setPosition(ofGetWidth() / 2, ofGetHeight() / 2, 300);
    light.enable();
    
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_NORMALIZE);
    
    float size = 100;
    for (int x = 0, width = ofGetWidth(); x < width; x += size * 1.5) {
        for (int y = 0, height = ofGetHeight(); y < height; y += size * 1.5) {
            Graphic* slide = new Slide(ofPoint(x, y), ofGetWidth(), ofGetHeight(), ofColor(ofRandom(255), ofRandom(255), ofRandom(255)), Slide::RIGHT);
            slide->reset();
            slides.push_back(slide);
        }
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    for (int i = slides.size(); i > 0; i--) {
        slides[i - 1]->update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    for (int i = slides.size(); i > 0; i--) {
        slides[i - 1]->draw();
        
        if (slides[i - 1]->isFinished()) {
            slides[i - 1]->setAnimation(false);
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    switch (key) {
        case ' ':
            for (Graphic* s : slides) {
                s->setAnimation(true);
                s->reset();
            }
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
