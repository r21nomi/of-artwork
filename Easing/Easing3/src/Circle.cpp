//
//  Circle.cpp
//  Easing3
//
//  Created by Ryota Takemoto on 2016/12/26.
//
//

#include "Circle.hpp"
#include "ofxEasing.h"

Circle::Circle(ofPoint _location, float _width, float _height, ofColor _color) : Graphic(_location, _width, _height, _color) {
    startPosition = ofGetWidth() / 1.3;
    endPosition = 0;
    initialRadius = radius = startPosition;
}

void Circle::update() {
    auto duration = 1.0f;
    auto endTime = initTime + duration;
    auto now = ofGetElapsedTimef();
    
    if (shouldAnimate) {
        radius = ofxeasing::map_clamp(now, initTime, endTime, startPosition, endPosition, &ofxeasing::quart::easeInOut);
    } else {
        radius = initialRadius;
    }
}

void Circle::draw() {
    ofSetColor(color);
    ofDrawCircle(location.x, location.y, radius);
}

bool Circle::isFinished() {
    return radius <= 0;
}
