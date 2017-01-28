//
//  Stapler.cpp
//  Staple2
//
//  Created by Ryota Takemoto on 2017/01/25.
//
//

#include "Stapler.hpp"

Stapler::Stapler(ofVec3f position, float width, float height, float depth, ofColor color) {
    this->position = position;
    this->width = width;
    this->height = height;
    this->depth = depth;
    this->color = color;
    
    degStep = 8;
    speedOffset = 0.02;
}

void Stapler::update() {
    degree = ofMap(sin(ofGetElapsedTimeMillis() * speedOffset) * degStep, -degStep, degStep, 0, degStep);
}

void Stapler::draw() {
    ofSetColor(color);
    
    ofPushMatrix();
    ofTranslate(position.x, position.y, position.z);
    
    // top
    ofPushMatrix();
    ofRotateZ(-degree * 2);
    ofTranslate(-width, 0);
    ofDrawBox(0, 0, 0, width, height * 2, depth);
    ofPopMatrix();
    
    // bottom
    ofPushMatrix();
    ofRotateZ(degree);
    ofTranslate(-width, 0);
    ofDrawBox(0, 0, 0, width, height, depth);
    ofPopMatrix();
    
    ofPopMatrix();
}

ofVec3f Stapler::getPosition() {
    return ofVec3f(position.x - width * 1.6, position.y, position.z);
}
