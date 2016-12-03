//
//  Line.cpp
//  Pattern7
//
//  Created by Ryota Takemoto on 2016/12/03.
//
//

#include "Line.hpp"

Line::Line(ofPoint _position, float _radius, ofColor _color, int _bold, float _speed) : PatternItem(_position, ofPoint(0, 0)) {
    radius = _radius;
    color = _color;
    bold = _bold;
    margin = bold * 8;
    speed = _speed;
    
    int x = 0;
    for (int y = 0, height = radius * 2; y < height; y += (bold + margin)) {
        points.push_back(new ofPoint(x, y));
    }
}

void Line::update() {
    float y = radius * 2;
    for (ofPoint *point : points) {
        if (point->y < y) {
            y = point->y;
        }
    }
    for (ofPoint *point : points) {
        point->y += speed;
        
        if (point->y > radius * 2) {
            point->y = y - margin;
        }
    }
}

void Line::draw() {
    ofPushMatrix();
    ofTranslate(currentPosition.x, currentPosition.y);
//    ofRotate(45);
    
    ofSetColor(color);
    ofFill();
    for (ofPoint *point : points) {
        ofDrawRectangle(point->x - radius, point->y - radius, radius * 2, bold);
    }
    
    ofPopMatrix();
}
