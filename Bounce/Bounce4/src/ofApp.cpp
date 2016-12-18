#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255);
    
    ballColor = ofColor(ofRandom(255), ofRandom(255), ofRandom(255));
    stairColor = ofColor(ofRandom(255), ofRandom(255), ofRandom(255));
    
    initStairs();
}

void ofApp::initStairs() {
    int count = 6;
    float alpha = 255 / count;
    float height = ofGetHeight() / count;
    stairs.clear();
    for (int i = 0; i <= count; i++) {
        float stairAlpha = ofMap(alpha * (i + 1), alpha, 255, 160, 255);
        stairs.push_back(new Stair(i + 1, ofVec2f(0, i * height), ofGetWidth(), height, ofColor(stairColor, stairAlpha)));
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    for (Ball* ball : balls) {
        float g = 0.4;  // Fall faster if this value is bigger.
        ofVec2f gravity = ofVec2f(0, g * ball->mass);
        float c = 0.05;
        ofVec2f friction = ball->velocity;
        friction *= -1;
        friction.normalize();
        friction *= c;
        
        ball->applyForce(friction);
        ball->applyForce(gravity);
        ball->update();
        
        for (Stair* stair : stairs) {
            ball->checkEdges(stair->getStairY(), stair->getStepNum());
        }
    }
    vector<Ball*>::iterator it = balls.begin();
    while (it != balls.end()) {
        Ball *item = dynamic_cast<Ball*>(*it);
        if (item->shouldDelete(ofGetHeight())) {
            it = balls.erase(it);
            break;
        } else {
            ++it;
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    for (Stair* stair : stairs) {
        stair->draw();
    }
    for (Ball* ball : balls) {
        ball->draw();
    }
}

Ball* ofApp::getBall() {
    float radius = 40;
    float mass = 0.4;  // Bound faster if this value is smaller...why?
    float x = ofRandom(radius, ofGetWidth() - radius);
    return new Ball(ofVec2f(x, ofRandom(0, ofGetHeight() / 5)), mass, radius, ofColor(ballColor, ofRandom(180, 255)));
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    switch (key) {
        case ' ':
            balls.push_back(getBall());
            break;
            
        case 'b':
            ballColor = ofColor(ofRandom(255), ofRandom(255), ofRandom(255));
            break;
            
        case 's':
            stairColor = ofColor(ofRandom(255), ofRandom(255), ofRandom(255));
            initStairs();
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
