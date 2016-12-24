//
//  Slide.cpp
//  Easing1
//
//  Created by Ryota Takemoto on 2016/12/21.
//
//

#include "Slide.hpp"
#include "ofxEasing.h"

Slide::Slide(ofPoint _location, float _width, float _height, ofColor _color, Direction _direction) {
    location = _location;
    width = _width;
    height = _height;
    color = _color;
    direction = _direction;
    
    initTime = 0;
    shouldAnimate = false;
    
    switch (direction) {
        case RIGHT:
            startPosition = 0;
            endPosition = ofGetWidth();
            break;
            
        case LEFT:
            startPosition = ofGetWidth();
            endPosition = 0;
            break;
            
        case BOTTOM:
            startPosition = 0;
            endPosition = ofGetHeight();
            break;
            
        case TOP:
            startPosition = ofGetHeight();
            endPosition = 0;
            break;
    }
}

void Slide::update() {
    auto duration = 1.0f;
    auto endTime = initTime + duration;
    auto now = ofGetElapsedTimef();
    
    switch (direction) {
        case RIGHT:
            if (shouldAnimate) {
                location.x = ofxeasing::map_clamp(now, initTime, endTime, startPosition, endPosition, &ofxeasing::quart::easeInOut);
            } else {
                location.x = startPosition;
            }
            break;
            
        case LEFT:
            if (shouldAnimate) {
                width = ofxeasing::map_clamp(now, initTime, endTime, startPosition, endPosition, &ofxeasing::quart::easeInOut);
            } else {
                width = startPosition;
            }
            break;
            
        case BOTTOM:
            if (shouldAnimate) {
                location.y = ofxeasing::map_clamp(now, initTime, endTime, startPosition, endPosition, &ofxeasing::quart::easeInOut);
            } else {
                location.y = startPosition;
            }
            break;
            
        case TOP:
            if (shouldAnimate) {
                height = ofxeasing::map_clamp(now, initTime, endTime, startPosition, endPosition, &ofxeasing::quart::easeInOut);
            } else {
                height = startPosition;
            }
            break;
    }
}

void Slide::draw() {
    ofSetColor(color);
    ofDrawRectangle(location.x, location.y, width - location.x, height - location.y);
}

void Slide::reset() {
    initTime = ofGetElapsedTimef();
}

void Slide::setAnimation(bool _shouldAnimate) {
    shouldAnimate = _shouldAnimate;
}

bool Slide::isAnimated() {
    return shouldAnimate;
}
