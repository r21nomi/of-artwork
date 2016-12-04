//
//  PatternContainer.cpp
//  Pattern6
//
//  Created by Ryota Takemoto on 2016/12/02.
//
//

#include "PatternContainer.hpp"

ofColor getRandomColor() {
    return ofColor(ofRandom(255), ofRandom(255), ofRandom(255));
}

PatternContainer::PatternContainer(ofPoint _position, float _width, float _height, vector<PatternItem*> _patternItems) {
    basePosition = position = _position;
    width = _width;
    height = _height;
    patternItems = _patternItems;
}

void PatternContainer::update() {
    bool isAnimating = false;
    
    for (PatternItem* patternItem : patternItems) {
        if (shouldMoveItem(patternItem)) {
            if (patternItem->isAnimating) {
                isAnimating = true;
                break;
            }
        }
    }
    
    for (PatternItem* patternItem : patternItems) {
        if (shouldMoveItem(patternItem)) {
            if (!isAnimating && patternItem->canChange) {
                float nextDirX = patternItem->currentPosition.x + width;
                
                if (patternItem->currentPosition.x > ofGetWidth()) {
                    // Set first position if current position is over window width.
                    patternItem->setPosition(ofPoint(-width, patternItem->currentPosition.y));
                    patternItem->setDir(ofPoint(0, patternItem->currentPosition.y));
                } else {
                    patternItem->setDir(ofPoint(nextDirX, patternItem->currentPosition.y));
                }
            }
            patternItem->updatePosition();
        }
        patternItem->update();
    }
}

void PatternContainer::draw() {
    for (PatternItem* patternItem : patternItems) {
        patternItem->draw();
    }
}

bool PatternContainer::shouldMoveItem(PatternItem *item) {
//    return dynamic_cast<Circle*>(item) || dynamic_cast<Ball*>(item);
    return false;
}

void PatternContainer::backgroundColorChanged(ofColor color) {
    for (PatternItem* patternItem : patternItems) {
        if (dynamic_cast<Line*>(patternItem)) {
            Line* line = dynamic_cast<Line*>(patternItem);
            line->setMaskColor(color);
        }
    }
}
