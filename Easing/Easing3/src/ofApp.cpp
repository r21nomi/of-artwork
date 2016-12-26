#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255);
    
    Graphic* slide = new Slide(ofPoint(0, 0), ofGetWidth(), ofGetHeight(), ofColor(ofRandom(255), ofRandom(255), ofRandom(255)), Slide::RIGHT);
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
    
    // Delete
    vector<Graphic*>::iterator it = slides.begin();
    while (it != slides.end()) {
        Graphic *item = dynamic_cast<Graphic*>(*it);
        if (item->isFinished()) {
            it = slides.erase(it);
            break;
        } else {
            ++it;
        }
    }
}

Graphic* ofApp::getGraphic() {
    int n = ((int)ofRandom(2)) % 2;
    Graphic* graphic;
    
    switch (n) {
        case 0: {
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
            graphic = new Slide(ofPoint(0, 0), ofGetWidth(), ofGetHeight(), ofColor(ofRandom(255), ofRandom(255), ofRandom(255)), dir);
            break;
        }
            
        case 1: {
            graphic = new Circle(ofPoint(ofGetWidth() / 2, ofGetHeight() / 2), ofGetWidth(), ofGetHeight(), ofColor(ofRandom(255), ofRandom(255), ofRandom(255)));
            break;
        }
    }
    
    return graphic;
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    switch (key) {
        case ' ':
            slides.push_back(getGraphic());
            
            for (Graphic* s : slides) {
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
