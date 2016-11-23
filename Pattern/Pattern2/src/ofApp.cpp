#include "ofApp.h"

//--------------------------------------------------------------
ofColor getRandomColor() {
    return ofColor(ofRandom(255), ofRandom(255), ofRandom(255));
}

void ofApp::setup(){
    ofSetBackgroundColor(getRandomColor());
    
    int count = 10;
    float marginRatio = 0;
    float baseRadius = ofGetWidth() / count / 2;
    float radius = baseRadius - baseRadius * marginRatio;
    int bold = 3;
    ofColor crossColor = getRandomColor();
    ofColor circleColor = getRandomColor();
    ofColor rhombusColor = getRandomColor();
    ofColor smallCrossesColor = getRandomColor();
    ofColor ballColor = getRandomColor();
    
    vector<PatternItem*> crosses;
    vector<PatternItem*> circles;
    vector<PatternItem*> rhombuses;
    vector<PatternItem*> smallCrossesList;
    vector<PatternItem*> balls;
    
    for (int y = 0, height = ofGetHeight(); y <= height; y += baseRadius * 2) {
        for (int x = 0, width = ofGetWidth(); x <= width; x += baseRadius * 2) {
            PatternItem *cross = new Cross(ofPoint(x, y), radius, bold, crossColor);
            PatternItem *circle = new Circle(ofPoint(x, y), radius, bold, circleColor);
            PatternItem *rhombus = new Rhombus(ofPoint(x, y), radius, bold, rhombusColor);
            PatternItem *smallCrosses = new SmallCrosses(ofPoint(x, y), radius, bold, 4, smallCrossesColor);
            PatternItem *ball = new Ball(ofPoint(x, y), radius, 4, ballColor);
            
            crosses.push_back(cross);
            circles.push_back(circle);
            rhombuses.push_back(rhombus);
            smallCrossesList.push_back(smallCrosses);
            balls.push_back(ball);
        }
    }
    patternItems.push_back(crosses);
    patternItems.push_back(circles);
    patternItems.push_back(rhombuses);
    patternItems.push_back(smallCrossesList);
    patternItems.push_back(balls);
}

//--------------------------------------------------------------
void ofApp::update(){
    for (vector<PatternItem*> patternLists : patternItems) {
        for (PatternItem *patternItem : patternLists) {
            patternItem->update();
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    for (vector<PatternItem*> patternLists : patternItems) {
        for (PatternItem *patternItem : patternLists) {
            patternItem->draw();
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    switch(key) {
        case ' ':
            ofSetBackgroundColor(getRandomColor());
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
