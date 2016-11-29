//
//  Ball.cpp
//  Pattern2
//
//  Created by 新家 亮太 on 2016/11/23.
//
//

#include "Ball.hpp"

Ball::Ball(ofPoint _position, float _radius, float _ballRadius, ofColor _color) {
    currentPosition = _position;
    radius = _radius * 0.7;
    ballRadius = _ballRadius;
    color = _color;
    currentDegree = 0;
}

void Ball::update() {
    currentDegree += 3;
    
    if (currentDegree > 360) {
        currentDegree = 0;
    }
}

void Ball::draw() {
    ofPushMatrix();
    ofTranslate(currentPosition.x, currentPosition.y);
    
    float x = radius * cos(ofDegToRad(currentDegree));
    float y = radius * sin(ofDegToRad(currentDegree));
    
    ofFill();
    ofSetColor(color);
    ofDrawCircle(x, y, ballRadius);
    
    ofPopMatrix();
}
