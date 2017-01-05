//
//  Slide.cpp
//  Easing1
//
//  Created by Ryota Takemoto on 2016/12/21.
//
//

#include "Cube.hpp"
#include "ofxEasing.h"

Cube::Cube(ofPoint _location, float _width, float _height, float _depth, ofColor _color, Direction _direction) : Graphic(_location, _width, _height, _color) {
    depth = _depth;
    direction = _direction;
    minVal = 0.3;
    maxVal = 6;
    duration = 1;
}

void Cube::update() {
    auto endTime = initTime + duration;
    auto now = ofGetElapsedTimef();
    
    rotation = ofxeasing::map_clamp(now, initTime, endTime, maxVal, minVal, &ofxeasing::cubic::easeInOut);
    
    float w = ofMap(sin(ofGetFrameNum() * 0.1), -1, 1, 0.9, 1) * width;
    float h = ofMap(cos(ofGetFrameNum() * 0.1), -1, 1, 0.9, 1) * height;
    float d = ofMap(sin(ofGetFrameNum() * 0.1), -1, 1, 0.9, 1) * depth;
    
    box.set(w, h, d);
    box.setPosition(location.x, location.y, 0);
}

void Cube::draw() {
    ofSetColor(color);
    box.rotate(rotation, 1.0, 0, 0);
    box.rotate(rotation, 0, 1.0, 0);
    box.draw();
}

bool Cube::isFinished() {
    return rotation == maxVal;
}
