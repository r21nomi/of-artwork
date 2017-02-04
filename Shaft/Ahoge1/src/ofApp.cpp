#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(ofRandom(200), ofRandom(200), ofRandom(200));

    int count = 6;
    radius = ofGetWidth() / count * 0.8;
    margin = 40;
    for (int x = radius, width = ofGetWidth() + radius; x < width; x += (radius * 2 + margin)) {
        Head* head = createHead(x, radius);
        heads.push_back(head);
    }
}

Head* ofApp::createHead(float x, float radius) {
    ofVec2f position = ofVec2f(x, ofGetHeight() + radius * 0.7);
    ofColor color = ofColor(50);
    return new Head(position, radius, color);
}

//--------------------------------------------------------------
void ofApp::update(){
    for (Head* head : heads) {
        head->update();
    }
    vector<Head*>::iterator it = heads.begin();
    while (it != heads.end()) {
        Head *item = dynamic_cast<Head*>(*it);
        
        if (item->getRight() < 0) {
            it = heads.erase(it);
            break;
        } else {
            ++it;
        }
    }
    if (ofGetWidth() - heads[heads.size() - 1]->getRight() > margin) {
        Head* head = createHead(heads[heads.size() - 1]->getRight() + radius + margin, radius);
        heads.push_back(head);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(ofRandom(200), ofRandom(200), ofRandom(200));
    
    float winWidth = ofGetWidth();
    float winHeight = ofGetHeight();
    
    ofDrawRectangle(100, 100, winWidth - 100 * 2, winHeight - 100 * 2);
    
    for (Head* head : heads) {
        head->draw();
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
