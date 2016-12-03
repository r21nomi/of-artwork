#include "ofApp.h"

//--------------------------------------------------------------
ofColor getRandomColor() {
    return ofColor(ofRandom(255), ofRandom(255), ofRandom(255));
}

void ofApp::setup(){
    ofSetBackgroundColor(getRandomColor());
    
    count = 12;
    marginRatio = 0;
    
    float itemWidth = ofGetWidth() / count;
    float radius = (itemWidth - itemWidth * marginRatio) / 2;
    int bold = 3;
    
    ofColor crossColor = getRandomColor();
    ofColor circleColor = getRandomColor();
    ofColor rhombusColor = getRandomColor();
    ofColor smallCrossesColor = getRandomColor();
    ofColor ballColor = getRandomColor();
    ofColor lineColor = getRandomColor();
    
    for (int y = 0, winHeight = ofGetHeight(); y <= winHeight; y += itemWidth) {
        for (int x = -itemWidth, winWidth = ofGetWidth() + itemWidth; x <= winWidth; x += itemWidth) {
            vector<PatternItem*> patternItems;
            ofPoint position = ofPoint(x, y);
            patternItems.push_back(new Line(position, radius * 0.6, lineColor, 2, 0.5));
//            patternItems.push_back(new Cross(position, radius, bold, crossColor));
//            patternItems.push_back(new Circle(position, radius, bold, circleColor));
            patternItems.push_back(new Rhombus(position, radius, bold, rhombusColor));
//            patternItems.push_back(new SmallCrosses(position, radius, bold, 4, smallCrossesColor));
//            patternItems.push_back(new Ball(position, radius, 10, ballColor));
            
            items.push_back(new PatternContainer(ofPoint(x, y), itemWidth, itemWidth, patternItems));
        }
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    for (PatternContainer* item : items) {
        item->update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    for (PatternContainer* item : items) {
        item->draw();
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
