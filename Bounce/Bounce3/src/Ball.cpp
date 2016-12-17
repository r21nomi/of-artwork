//
//  Ball.cpp
//  Bounce1
//
//  Created by Ryota Takemoto on 2016/12/14.
//
//

#include "Ball.hpp"

Ball::Ball(ofVec2f _position, float _mass, float _radius, ofColor _color) {
    currentPosition = _position;
    mass = _mass;
    radius = _radius;
    acceleration = ofVec2f(0, 0);
    velocity = ofVec2f(0, 0);
    color = _color;
    currentStep = 0;
}

void Ball::applyForce(ofVec2f force) {
    ofVec2f f = force / mass;
    acceleration += f;
}

void Ball::update() {
    velocity += acceleration;
    currentPosition += velocity;
    acceleration *= 0;
}

void Ball::draw() {
    ofSetColor(color);
    ofFill();
    ofDrawEllipse(currentPosition.x, currentPosition.y, radius * 2, radius * 2);
}

void Ball::checkEdges(float stairY, int step) {
    if (step > currentStep && currentPosition.y > stairY - radius) {
        currentPosition.y = stairY - radius;
        velocity.y *= -1;
        currentStep++;
    }
}

bool Ball::shouldDelete(float bottom) {
    return currentPosition.y - radius > bottom;
}
