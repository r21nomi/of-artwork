//
//  SmallCrosses.cpp
//  Pattern2
//
//  Created by 新家 亮太 on 2016/11/23.
//
//

#include "SmallCrosses.hpp"

SmallCrosses::SmallCrosses(ofPoint _position, float _radius, int _bold, int _count, ofColor _color) : PatternItem(_position, ofPoint(0, 0)) {
    radius = _radius * 0.9;
    bold = _bold;
    count = _count;
    color = _color;
    currentDegree = 0;
}

void SmallCrosses::update() {
    currentDegree += 1;
}

void SmallCrosses::draw() {
    ofNoFill();
    
    ofPushMatrix();
    ofTranslate(currentPosition.x, currentPosition.y);
    ofRotate(45);
    
    ofSetColor(color);
    ofSetLineWidth(bold);
    
    for (int i = 0; i < count; i++) {
        float angle = i * 360 / count;
        float x = radius * cos(ofDegToRad(angle));
        float y = radius * sin(ofDegToRad(angle));
        int crossRadius = 10;;
        
        ofPushMatrix();
        ofTranslate(x, y);
        ofRotate(currentDegree);
        
        ofDrawLine(-crossRadius, 0, crossRadius, 0);
        ofDrawLine(0, -crossRadius, 0, crossRadius);
        
        ofPopMatrix();
    }
    
    ofPopMatrix();
}
