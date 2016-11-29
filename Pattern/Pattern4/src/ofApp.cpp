#include "ofApp.h"

//--------------------------------------------------------------
ofColor getRandomColor() {
    return ofColor(ofRandom(255), ofRandom(255), ofRandom(255));
}

void ofApp::setup(){
    ofSetBackgroundColor(getRandomColor());
    
    float baseRadius = getBaseRadius();
    float radius = getRadius();
    int bold = 3;
    ofColor crossColor = getRandomColor();
    ofColor circleColor = getRandomColor();
    ofColor rhombusColor = getRandomColor();
    ofColor smallCrossesColor = getRandomColor();
    ofColor ballColor = getRandomColor();
    
    vector<vector<PatternItem*>> crosses;
    vector<vector<PatternItem*>> circles;
    vector<vector<PatternItem*>> rhombuses;
    vector<vector<PatternItem*>> smallCrossesList;
    vector<vector<PatternItem*>> balls;
    
    for (int y = 0, height = ofGetHeight(); y <= height; y += baseRadius * 2) {
        vector<PatternItem*> line_crosses;
        vector<PatternItem*> line_circles;
        vector<PatternItem*> line_rhombuses;
        vector<PatternItem*> line_smallCrossesList;
        vector<PatternItem*> line_balls;
        
        for (int x = -baseRadius * 2, width = ofGetWidth() + baseRadius * 2; x <= width; x += baseRadius * 2) {
            PatternItem *cross = new Cross(ofPoint(x, y), radius, bold, crossColor);
            PatternItem *circle = new Circle(ofPoint(x, y), radius, bold, circleColor);
            PatternItem *rhombus = new Rhombus(ofPoint(x, y), radius, bold, rhombusColor);
            PatternItem *smallCrosses = new SmallCrosses(ofPoint(x, y), radius, bold, 4, smallCrossesColor);
            PatternItem *ball = new Ball(ofPoint(x, y), radius, 4, ballColor);
            
            line_crosses.push_back(cross);
            line_circles.push_back(circle);
            line_rhombuses.push_back(rhombus);
            line_smallCrossesList.push_back(smallCrosses);
            line_balls.push_back(ball);
        }
        crosses.push_back(line_crosses);
        circles.push_back(line_circles);
        rhombuses.push_back(line_rhombuses);
        smallCrossesList.push_back(line_smallCrossesList);
        balls.push_back(line_balls);
    }
    patternItems.push_back(crosses);
    patternItems.push_back(circles);
    patternItems.push_back(rhombuses);
    patternItems.push_back(smallCrossesList);
    patternItems.push_back(balls);
}

//--------------------------------------------------------------
void ofApp::update(){
    for (vector<vector<PatternItem*>> patternLineLists : patternItems) {
        // List
        for (vector<PatternItem*> patternLists : patternLineLists) {
            // Line
            bool isAnimating = false;
            
            for (PatternItem *patternItem : patternLists) {
                // Item
                if (dynamic_cast<Circle*>(patternItem)) {
                    Circle* circle = dynamic_cast<Circle*>(patternItem);
                    if (circle->isAnimating) {
                        isAnimating = true;
                    }
                }
            }
            
            for (int i = 0, len = patternLists.size(); i < len; i++) {
                PatternItem *patternItem = patternLists[i];
                
                if (dynamic_cast<Circle*>(patternItem)) {
                    Circle* circle = dynamic_cast<Circle*>(patternItem);
                    
                    if (!isAnimating && circle->canChange) {
                        int nextPos = i + 1 < patternLists.size() ? i + 1 : 0;
                        Circle* next = dynamic_cast<Circle*>(patternLists[nextPos]);
                        
                        if (circle->currentPosition.x > ofGetWidth()) {
                            // Set first position if current position is over window width.
                            Circle* firstCircle = dynamic_cast<Circle*>(patternLists[0]);
                            circle->setPosition(ofPoint(firstCircle->originalPosition.x, next->currentPosition.y));
                        }
                        circle->setDir(ofPoint(next->currentPosition.x, next->currentPosition.y));
                    }
                }
            }
            for (PatternItem *patternItem : patternLists) {
                if (dynamic_cast<Circle*>(patternItem)) {
                    Circle* circle = dynamic_cast<Circle*>(patternItem);
                    circle->updatePosition();
                }
                patternItem->update();
            }
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    for (vector<vector<PatternItem*>> patternLineLists : patternItems) {
        for (vector<PatternItem*> patternLists : patternLineLists) {
            for (PatternItem *patternItem : patternLists) {
                patternItem->draw();
            }
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

float ofApp::getBaseRadius() {
    return ofGetWidth() / count / 2;
}

float ofApp::getRadius() {
    return getBaseRadius() - getBaseRadius() * marginRatio;
}
