//
//  Pole.cpp
//  Pole1
//
//  Created by Ryota Takemoto on 2017/02/28.
//
//

#include "Pole.hpp"

Pole::Pole(ofVec3f position, float width, float height, ofColor color) {
    this->position = position;
    this->width = width;
    this->height = height;
    this->color = color;
}

void Pole::update() {
    
}

void Pole::draw() {
    ofSetColor(color);
    
    ofDrawBox(position.x, position.y, position.z, width, height, width);
}
