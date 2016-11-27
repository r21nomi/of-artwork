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
    canChange = true;
    isAnimating = false;
}

void Circle::update() {
    // no-op
}

void Circle::updatePosition() {
    float distX = dirPosition.x - currentPosition.x;
    float distY = dirPosition.y - currentPosition.y;
    
    // x
    if (abs(distX) < 1) {
        currentPosition.x = dirPosition.x;
    } else {
        currentPosition.x += distX * 0.1;
    }
    // y
    if (abs(distY) < 1) {
        currentPosition.y = dirPosition.y;
    } else {
        currentPosition.y += distY * 0.1;
    }
    
    isAnimating = !(abs(distX) < 1) || !(abs(distY) < 1);
    canChange = !isAnimating;
}

void Circle::setPosition(ofPoint _position) {
    currentPosition = _position;
}

void Circle::setDir(ofPoint _dir) {
    dirPosition = _dir;
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
