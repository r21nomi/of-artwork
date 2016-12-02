//
//  Ball.cpp
//  Pattern2
//
//  Created by 新家 亮太 on 2016/11/23.
//
//

#include "Ball.hpp"

Ball::Ball(ofPoint _position, float _radius, float _ballRadius, ofColor _color) : PatternItem(_position, ofPoint(0, 0)) {
    radius = _radius * 0.7;
    ballRadius = maxBallRadius = _ballRadius;
    color = _color;
    currentDegree = 0;
    minBallRadiusRatio = 0.4;
}

void Ball::update() {
    currentDegree += 3;
    
    if (currentDegree > 360) {
        currentDegree = 0;
    }
    float r = abs(sin(ofGetElapsedTimeMillis() * 0.002));
    ballRadius = maxBallRadius * ofMap(r, 0, 1, minBallRadiusRatio, 1);
}

void Ball::draw() {
    ofPushMatrix();
    ofTranslate(currentPosition.x, currentPosition.y);
    
    float x = radius * cos(ofDegToRad(currentDegree));
    float y = radius * sin(ofDegToRad(currentDegree));
    
    ofSetColor(color);
    
    ofFill();
    ofDrawCircle(x, y, maxBallRadius * minBallRadiusRatio);
    
    ofNoFill();
    ofDrawCircle(x, y, ballRadius);
    
    ofPopMatrix();
}
