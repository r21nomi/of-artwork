//
//  Stair.cpp
//  Bounce2
//
//  Created by Ryota Takemoto on 2016/12/16.
//
//

#include "Stair.hpp"

Stair::Stair(int _stepNum, ofVec2f _position, float _width, float _height, ofColor _color) {
    stepNum = _stepNum;
    position = _position;
    width = _width;
    height = _height;
    color = _color;
}

void Stair::draw() {
    ofSetColor(color);
    ofFill();
    
    ofDrawRectangle(position.x, position.y, width, height);
}

float Stair::getStairY() {
    return position.y;
}

int Stair::getStepNum() {
    return stepNum;
}
