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
    radiusX = radiusY = _radius;
    acceleration = ofVec2f(0, 0);
    velocity = ofVec2f(0, 0);
    color = _color;
    currentStep = 0;
    pressure = 1;
}

void Ball::applyForce(ofVec2f force) {
    ofVec2f f = force / mass;
    acceleration += f;
}

void Ball::update() {
    velocity += acceleration;
    currentPosition += velocity;
    acceleration *= 0;
    radiusX += 0.05;
    radiusY += 0.05;
}

void Ball::draw() {
    ofSetColor(color);
    ofFill();
    ofDrawEllipse(currentPosition.x, currentPosition.y, radiusX * 2, radiusY * 2);
}

void Ball::checkEdges(float stairY, int step) {
    float boundThreshould = 25;
    float minRadiusY = radiusX * 0.6;
    
    if (step > currentStep && currentPosition.y > stairY - radiusY) {
        if (radiusY < minRadiusY) {
            // Bounce
            velocity.y *= -1;
            currentStep++;
        } else {
            // Pressure
            radiusY -= (radiusX - minRadiusY) / boundThreshould * abs(velocity.y);
        }
        currentPosition.y = stairY - radiusY;
    }
    
    if (velocity.y < 0) {
        if (radiusY < radiusX) {
            // Revert pressure
            float diffRadiusY = (radiusX - radiusY) / boundThreshould * abs(velocity.y);
            radiusY += diffRadiusY;
            currentPosition.y -= diffRadiusY;
        } else {
            radiusY = radiusX;
        }
    }
}

bool Ball::shouldDelete(float bottom) {
    return currentPosition.y - radiusY > bottom;
}
