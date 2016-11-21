//
//  Cross.cpp
//  Pattern1
//
//  Created by 新家 亮太 on 2016/11/21.
//
//

#include "Cross.hpp"

Cross::Cross(ofPoint _position, float _radius,int _bold, ofColor _color) {
    currentPosition = _position;
    radius = _radius;
    bold = _bold;
    color = _color;
    currentDegree = 0;
}

void Cross::update() {
    currentDegree += 1;
}

void Cross::draw() {
    ofPushMatrix();
    ofTranslate(currentPosition.x, currentPosition.y);
    ofRotate(currentDegree);
    
    ofSetColor(color);
    ofSetLineWidth(bold);
    ofDrawLine(-radius, 0, radius, 0);
    ofDrawLine(0, -radius, 0, radius);
    
    ofPopMatrix();
}
