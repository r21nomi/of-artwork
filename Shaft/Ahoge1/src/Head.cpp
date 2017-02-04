//
//  Head.cpp
//  Ahoge1
//
//  Created by Ryota Takemoto on 2017/02/04.
//
//

#include "Head.hpp"

Head::Head(ofVec2f position, float radius, ofColor color) {
    this->position = position;
    this->radius = radius;
    this->color = color;
    this->ahogeHight = originalAhogeHight = radius * 0.5;
    
    ofSetCircleResolution(100);
}

void Head::update() {
    ahogeHight = originalAhogeHight * ofMap(sin(ofGetElapsedTimeMillis() * 0.01), -1, 1, 0.8, 1);
    rotate = ofMap(sin(ofGetElapsedTimeMillis() * 0.01), -1, 1, -5, 5);
    position.x += -4;
}

void Head::draw() {
    ofSetColor(color);
    
    ofPushMatrix();
    ofTranslate(position.x, position.y);
    ofRotate(rotate);
    
    // Head
    ofDrawCircle(0, 0, radius);
    
    // Ahoge
    float rh = ahogeHight;
    float rw = rh * 0.9;
    
    ofPushMatrix();
    ofTranslate(rw * 0.5, -radius - rh * 0.8);
    
    ofBeginShape();
    ofCurveVertex(rw * cos(ofDegToRad(270)), rh * sin(ofDegToRad(270)));
    float step = 10;
    for (int i = 270; i >= 90; i -= step) {
        float r = ofDegToRad(i);
        ofCurveVertex(rw * cos(r), rh * sin(r));
    }
    for (int i = 90; i <= 270; i += step) {
        float r = ofDegToRad(i);
        float offset = i != 90 && i != 270 ? 0.7 : 1;
        ofCurveVertex(rw *  offset * cos(r), rh * sin(r));
    }
    ofCurveVertex(rw * cos(ofDegToRad(270)), rh * sin(ofDegToRad(270)));
    ofEndShape();
    
    ofPopMatrix();
    
    ofPopMatrix();
}

float Head::getRight() {
    return position.x + radius;
}
