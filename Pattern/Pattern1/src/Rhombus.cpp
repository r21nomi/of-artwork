//
//  Rhombus.cpp
//  Pattern1
//
//  Created by 新家 亮太 on 2016/11/21.
//
//

#include "Rhombus.hpp"

Rhombus::Rhombus(ofPoint _position, float _radius, int _bold, ofColor _color) {
    currentPosition = _position;
    radius = _radius * 0.3;
    bold = _bold;
    color = _color;
    currentDegree = 0;
}

void Rhombus::update() {
    currentDegree -= 1;
}

void Rhombus::draw() {
    ofNoFill();
    
    ofPushMatrix();
    ofTranslate(currentPosition.x, currentPosition.y);
    ofRotate(currentDegree);
    
    ofSetColor(color);
    ofSetLineWidth(bold);
    ofDrawRectangle(-radius, -radius, radius * 2, radius * 2);
    
    ofPopMatrix();
}
