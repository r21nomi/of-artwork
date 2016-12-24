#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255);
    
    Slide* slide = new Slide(ofPoint(0, 0), ofGetWidth(), ofGetHeight(), ofColor(ofRandom(255), ofRandom(255), ofRandom(255)), Slide::RIGHT);
    slide->reset();
    slides.push_back(slide);
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
    }
}
 
//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    switch (key) {
        case ' ':
            Slide::Direction dir = Slide::LEFT;
            int num = ((int)ofRandom(5)) % 4;
            switch (num) {
                case 0:
                    dir = Slide::RIGHT;
                    break;
                    
                case 1:
                    dir = Slide::LEFT;
                    break;
                    
                case 2:
                    dir = Slide::BOTTOM;
                    break;
                    
                case 3:
                    dir = Slide::TOP;
                    break;
            }
            Slide* slide = new Slide(ofPoint(0, 0), ofGetWidth(), ofGetHeight(), ofColor(ofRandom(255), ofRandom(255), ofRandom(255)), dir);
            slides.push_back(slide);
            
            for (Slide* s : slides) {
                if (!s->isAnimated()) {
                    s->setAnimation(true);
                    s->reset();
                    break;
                }
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
