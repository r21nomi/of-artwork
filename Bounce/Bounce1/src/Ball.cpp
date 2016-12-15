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

void Ball::checkEdges() {
    int windowWidth = ofGetWidth();
    int windowHeight = ofGetHeight();
    
    if (currentPosition.x > windowWidth - radius) {
        currentPosition.x = windowWidth - radius;
        velocity.x *= -1;
    } else if (currentPosition.x < radius) {
        currentPosition.x = radius;
        velocity.x *= -1;
    }
    
    if (currentPosition.y > windowHeight - radius) {
        currentPosition.y = windowHeight - radius;
        velocity.y *= -1;
    } else if (currentPosition.y < radius) {
        currentPosition.y = radius;
        velocity.y *= -1;
    }
}
