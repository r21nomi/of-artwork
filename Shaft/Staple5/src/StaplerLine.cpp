//
//  StaplerLine.cpp
//  Staple3
//
//  Created by Ryota Takemoto on 2017/01/29.
//
//

#include "StaplerLine.hpp"

StaplerLine::StaplerLine(ofVec3f position, ofColor stapleColor) {
    this->position = position;
    this->stapleColor = stapleColor;
    
    stapleWidth = 50;
    stapleHeight = 30;
    stapleDepth = 5;
    stapleMargin = -11;
    stapleSpeed = -2;
    stapleBold = 5;
    
    reset();
}

void StaplerLine::reset() {
    staples.clear();
    
    for (int x = 0, winWidth = 1; x < winWidth; x += (stapleWidth + stapleMargin)) {
        ofVec3f position = ofVec3f(x, 0, 0);
        Staple* staple = getStaple(position);
        staples.push_back(staple);
    }
    
    stapler = new Stapler(
                          ofVec3f(staples[staples.size() - 1]->getPosition().x, 0, 0),
                          300,
                          30,
                          100,
                          stapleColor
                          );
}

void StaplerLine::setColor(ofColor stapleColor) {
    this->stapleColor = stapleColor;
}

void StaplerLine::update() {
    ofVec3f staplerPosition = stapler->getPosition();
    Staple* lastStaple = staples[staples.size() - 1];
    
    if (lastStaple->getPosition().x < staplerPosition.x) {
        ofVec3f position = lastStaple->getPosition();
        position.x += (stapleWidth + stapleMargin);
        Staple* staple = getStaple(position);
        staples.push_back(staple);
        
        cout << ofToString(lastStaple->getPosition().x) + ", " + ofToString(staplerPosition.x) << endl;
    }
    
    stapler->update();
    
    for (Staple* staple : staples) {
        staple->update();
    }
}

void StaplerLine::draw() {
    ofPushMatrix();
    ofTranslate(position.x, position.y, position.z);
    
    stapler->draw();
    
    for (Staple* staple : staples) {
        staple->draw();
    }
    
    ofPopMatrix();
}

Stapler* StaplerLine::getStapler() {
    return stapler;
}

Staple* StaplerLine::getStaple(ofVec3f position) {
    return new Staple(position, stapleWidth, stapleHeight, stapleDepth, stapleBold, stapleSpeed, ofColor(stapleColor, 200));
}
