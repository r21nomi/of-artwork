//
//  Circle.cpp
//  Pattern1
//
//  Created by 新家 亮太 on 2016/11/21.
//
//

#include "Circle.hpp"

Circle::Circle(ofPoint _position, float _radius, int _bold, ofColor _color) {
    currentPosition = _position;
    radius = _radius * 0.7;
    bold = _bold;
    color = _color;
}

void Circle::update() {
    // no-op
}

void Circle::draw() {
    ofNoFill();
    
    ofPushMatrix();
    ofTranslate(currentPosition.x, currentPosition.y);
    
    ofSetColor(color);
    ofSetLineWidth(bold);
    ofDrawCircle(0, 0, radius);
    
    ofPopMatrix();
}
