#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    backgroundColor = ofColor(ofRandom(50, 200), ofRandom(50, 200), ofRandom(50, 200));
    
    float radius = ofGetWidth() / COUNT / 2;
    float step = radius * 2 + MERGIN;
    
    for (int x = radius, width = ofGetWidth() - radius; x <= width; x += step) {
        for (int y = radius, height = ofGetHeight() + radius; y <= height; y += step) {
            Circle *circle = new Circle(x, y, radius, ofColor(255), Circle::RECTANGLE);
            circles.push_back(circle);
        }
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    for (Circle *circle : circles) {
        circle->updateShape();
        circle->updateLocation();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(backgroundColor);
    
    for (Circle *circle : circles) {
        circle->draw();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch (key) {
            case ' ':
                vector<Circle*> tempVectors;
                copy(circles.begin(), circles.end(), back_inserter(tempVectors));
                
                for (Circle *circle : circles) {
                    circle->enableCanUpdateShape();
                    
                    Circle *tempCircle = tempVectors[(int)ofRandom(tempVectors.size() - 1)];
                    ofPoint point = tempCircle->getLocation();
                    circle->setTargetLocation(point);
                    
                    vector<Circle*>::iterator it = tempVectors.begin();
                    while (it != tempVectors.end()) {
                        Circle *item = dynamic_cast<Circle*>(*it);
                        if (item == tempCircle) {
                            it = tempVectors.erase(it);
                            break;
                        } else {
                            ++it;
                        }
                    }
                }
                break;
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
