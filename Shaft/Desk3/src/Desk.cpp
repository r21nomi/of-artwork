//
//  Desk.cpp
//  Desk1
//
//  Created by Ryota Takemoto on 2017/01/31.
//
//

#include "Desk.hpp"

Desk::Desk(ofVec3f position,
           ofVec3f initialVelocity,
           float width,
           float height,
           float depth,
           float mass,
           ofColor color) {
    this->position = position;
    this->width = width;
    this->height = height;
    this->depth = depth;
    this->mass = mass;
    this->color = color;
    
    acceleration = ofVec3f(0, 0, 0);
    velocity = initialVelocity;
    rotate = ofRandom(-0.1, 0.1);
}

void Desk::applyForce(ofVec3f force) {
    ofVec3f f = force / mass;
    acceleration += f;
}

void Desk::update() {
    velocity += acceleration;
    position += velocity;
    acceleration *= 0;
}

void Desk::draw() {
    ofSetColor(color);
    ofNoFill();
    ofPushMatrix();
    ofTranslate(position.x, position.y, position.z);
    ofRotate(ofGetElapsedTimeMillis() * rotate);
    
    float tableBold = height / 4;
    float legBold = tableBold / 3;
    ofDrawBox(0, tableBold / 2 - height / 2, 0, width, tableBold, depth);
    
    ofDrawBox(legBold / 2 - width / 2, 0, depth / 2, legBold, height, legBold);
    ofDrawBox(width / 2 - legBold / 2, 0, depth / 2, legBold, height, legBold);
    ofDrawBox(legBold / 2 - width / 2, 0, -depth / 2, legBold, height, legBold);
    ofDrawBox(width / 2 - legBold / 2, 0, -depth / 2, legBold, height, legBold);
    
    ofPopMatrix();
}

float Desk::getTop() {
    return position.y - height / 2;
}

float Desk::getBottom() {
    return position.y + height / 2;
}
