//
//  Slide.cpp
//  Easing1
//
//  Created by Ryota Takemoto on 2016/12/21.
//
//

#include "Slide.hpp"
#include "ofxEasing.h"

Slide::Slide(ofPoint _location, float _width, float _height, ofColor _color) {
    location = _location;
    width = _width;
    height = _height;
    color = _color;
    
    initTime = 0;
    endPosition = ofGetWidth();
}

void Slide::update() {
    auto duration = 1.0f;
    auto endTime = initTime + duration;
    auto now = ofGetElapsedTimef();
    
    location.x = ofxeasing::map_clamp(now, initTime, endTime, 0, endPosition, &ofxeasing::quart::easeInOut);
}

void Slide::draw() {
    ofSetColor(color);
    ofDrawRectangle(location.x, location.y, width - location.x, height);
}

void Slide::reset() {
    initTime = ofGetElapsedTimef();
}
