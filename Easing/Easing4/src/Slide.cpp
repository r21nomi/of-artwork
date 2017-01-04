//
//  Slide.cpp
//  Easing1
//
//  Created by Ryota Takemoto on 2016/12/21.
//
//

#include "Slide.hpp"
#include "ofxEasing.h"

Slide::Slide(ofPoint _location, float _width, float _height, ofColor _color, Direction _direction) : Graphic(_location, _width, _height, _color) {
    direction = _direction;
    box.set(100);
    minVal = 0.1;
    maxVal = 3;
}

void Slide::update() {
    auto duration = 1.0f;
    auto endTime = initTime + duration;
    auto now = ofGetElapsedTimef();
    
    if (shouldAnimate) {
        rotation = ofxeasing::map_clamp(now, initTime, endTime, minVal, maxVal, &ofxeasing::quart::easeInOut);
    } else {
        rotation = minVal;
    }
    box.setPosition(location.x, location.y, 0);
}

void Slide::draw() {
    ofSetColor(color);
    box.rotate(rotation, 1.0, 0, 0);
    box.rotate(rotation, 0, 1.0, 0);
    box.draw();
}

bool Slide::isFinished() {
    return rotation == maxVal;
}
