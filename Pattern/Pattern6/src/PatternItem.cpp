//
//  PatternItem.cpp
//  Pattern5
//
//  Created by Ryota Takemoto on 2016/12/01.
//
//

#include "PatternItem.h"

PatternItem::PatternItem(ofPoint _originalPosition, ofPoint _dirPosition) {
    currentPosition = originalPosition = _originalPosition;
    dirPosition = _dirPosition;
    canChange = true;
    isAnimating = false;
}

void PatternItem::updatePosition() {
    float distX = dirPosition.x - currentPosition.x;
    float distY = dirPosition.y - currentPosition.y;
    float offset = 0.1;
    
    // x
    if (abs(distX) < 1) {
        currentPosition.x = dirPosition.x;
    } else {
        currentPosition.x += distX * offset;
    }
    // y
    if (abs(distY) < 1) {
        currentPosition.y = dirPosition.y;
    } else {
        currentPosition.y += distY * offset;
    }
    
    isAnimating = !(abs(distX) < 1) || !(abs(distY) < 1);
    canChange = !isAnimating;
}

void PatternItem::setPosition(ofPoint _position) {
    currentPosition = _position;
}

void PatternItem::setDir(ofPoint _dir) {
    dirPosition = _dir;
}
