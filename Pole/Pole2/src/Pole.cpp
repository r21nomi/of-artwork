//
//  Pole.cpp
//  Pole1
//
//  Created by Ryota Takemoto on 2017/02/28.
//
//

#include "Pole.hpp"
#include "ofxEasing.h"

Pole::Pole(ofVec3f position, float width, float height, ofColor color) {
    this->position = position;
    this->width = width;
    this->height = height;
    this->color = color;
    this->duration = ofRandom(3, 5);
    
    offsetSpeed = 0;
    initTime = ofGetElapsedTimef();
    startPosition = position;
    endPosition = ofVec3f(position.x, ofGetHeight(), position.z);
}

void Pole::update() {
    endTime = initTime + duration;
    auto now = ofGetElapsedTimef();
    
    offsetSpeed += 0.5;
    
    position.y = offsetSpeed + startPosition.y + ofxeasing::map_clamp(now, initTime, endTime, 0, endPosition.y - startPosition.y, &ofxeasing::quart::easeInOut);
}

void Pole::draw() {
    ofSetColor(color);
    
    ofDrawBox(position.x, position.y, position.z, width, height, width);
}

bool Pole::isFinished() {
    return endTime - ofGetElapsedTimef() < 0;
}

void Pole::resetIfFinished() {
    if (isFinished()) {
        position = startPosition;
        initTime = ofGetElapsedTimef();
        offsetSpeed = 0;
    }
}
