//
//  Graphic.cpp
//  Easing3
//
//  Created by Ryota Takemoto on 2016/12/26.
//
//

#include "Graphic.hpp"

Graphic::Graphic(ofPoint _location, float _width, float _height, ofColor _color) {
    location = _location;
    width = _width;
    height = _height;
    color = _color;
    
    initTime = 0;
    shouldAnimate = false;
}

void Graphic::reset() {
    initTime = ofGetElapsedTimef();
}

void Graphic::setAnimation(bool _shouldAnimate) {
    shouldAnimate = _shouldAnimate;
}

bool Graphic::isAnimated() {
    return shouldAnimate;
}
