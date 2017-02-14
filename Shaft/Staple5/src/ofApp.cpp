#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255);
    
    for (int x = 0, winWidth = ofGetWidth(); x < winWidth; x += winWidth) {
        ofColor color = ofColor(ofRandom(200), ofRandom(200), ofRandom(200));
        ofVec3f position = ofVec3f(0, 0, -x);
        StaplerLine* staplerLine = new StaplerLine(position, color);
        staplerLines.push_back(staplerLine);
    }
    
    bgImage.load("dogenzaka.jpg");
    bgImage.setImageType(OF_IMAGE_GRAYSCALE);
}

//--------------------------------------------------------------
void ofApp::update(){
    for (StaplerLine* staplerLine : staplerLines) {
        staplerLine->update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    bool isLandscape = bgImage.getWidth() > bgImage.getHeight();
    float imgWidth = 0;
    float imgHeight = 0;
    
    if (isLandscape) {
        imgWidth = ofGetWidth();
        imgHeight = bgImage.getHeight() * imgWidth / bgImage.getWidth();
    } else {
        imgHeight = ofGetHeight();
        imgWidth = bgImage.getWidth() * imgHeight / bgImage.getHeight();
    }
    
    ofSetLineWidth(2);
    
    ofPushMatrix();
    ofSetColor(255);
    bgImage.draw(0, 0, imgWidth, imgHeight);
    ofPopMatrix();
    
    camera.begin();
    
    
    if (isMovingMode) {
        staplePosition.x = ofGetMouseX() - ofGetWidth() / 2;
        staplePosition.y = -(ofGetMouseY() - ofGetHeight() / 2);
    }
    
    ofPushMatrix();
    ofTranslate(staplePosition.x, staplePosition.y);
    ofRotate(5);
    for (StaplerLine* staplerLine : staplerLines) {
        staplerLine->draw();
    }
    if (isDebugMode) {
        ofSetColor(255, 0, 0);
        ofDrawSphere(0, 0, 20);
    }
    ofPopMatrix();
    
    camera.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch (key) {
        case ' ':
            isMovingMode = true;
            break;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    switch (key) {
        case 'd':
            isDebugMode = !isDebugMode;
            break;
            
        case ' ':
            isMovingMode = false;
            break;
            
        case OF_KEY_RETURN:
            for (StaplerLine* staplerLine : staplerLines) {
                staplerLine->reset();
            }
            break;
        
        case 'c':
            for (StaplerLine* staplerLine : staplerLines) {
                staplerLine->setColor(ofColor(ofRandom(200), ofRandom(200), ofRandom(200)));
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
