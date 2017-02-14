//
//  Staple.cpp
//  Staple1
//
//  Created by Ryota Takemoto on 2017/01/24.
//
//

#include "Staple.hpp"

Staple::Staple(ofVec3f position, float width, float height, float depth, float bold, float speed, ofColor color) {
    this->position = position;
    this->width = width;
    this->height = height;
    this->depth = depth;
    this->bold = bold;
    this->speed = speed;
    this->color = color;
}

void Staple::update() {
//    position.x += speed;
}

void Staple::draw() {
    ofSetColor(color);
    ofNoFill();
    
    ofPushMatrix();
    ofTranslate(position.x, position.y, position.z);
    ofRotateY(90);
    
    ofDrawBox(0, height / 2 - bold / 2, 0, width, bold, depth);
    ofDrawBox(-width / 2, 0, 0, bold, height, depth);
    ofDrawBox(width / 2, 0, 0, bold, height, depth);
    
    ofPopMatrix();
}
ofVec3f Staple::getPosition() {
    return position;
}
