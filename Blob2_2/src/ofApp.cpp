#include "ofApp.h"

/**
 * 2016.10.25
 * Referenced by http://30min-processing.hatenablog.com/?page=1476802800
 */
void ofApp::setup(){
    for (int i = 0, len = 500; i < len; i++) {
        Circle *circle = new Circle();
        
        bool isOverlap = false;
        ofPoint targetLocation = circle->getLocation();
        
        for (Circle *c : circles) {
            ofPoint anotherLocation = c->getLocation();
            if (ofDist(targetLocation.x, targetLocation.y, anotherLocation.x, anotherLocation.y) < circle->getRadius() + c->getRadius()) {
                isOverlap= true;
                break;
            }
        }
        if(!isOverlap) {
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
    ofBackground(255, 255, 255);
    ofSetColor(0, 0, 0);
    
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
