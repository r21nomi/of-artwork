//
//  Ring.cpp
//  Sphere2
//
//  Created by Ryota Takemoto on 2017/01/18.
//
//

#include "Ring.hpp"

Ring::Ring(float _radius, int _lineStep, float _radianZ, float _positoinZ, ofColor _color) {
    radius = _radius;
    lineStep = _lineStep;
    color = _color;
    
    for(int t = 0; t <= 360; t += circleStep){
        float radianT = ofDegToRad(t);
        float x = radius * sin(_radianZ) * cos(radianT);
        float y = radius * sin(_radianZ) * sin(radianT);
        points.push_back(new ofPoint(x, y, _positoinZ));
    }
}

void Ring::update() {
    
}

void Ring::draw() {
    ofSetColor(color);
    ofSetLineWidth(lineWidth);
    
    int i = 0;
    for (ofPoint* point : points) {
        ofDrawEllipse(point->x, point->y, point->z, lineWidth * 1.5, lineWidth * 1.5);
        
        if (i != 0) {
            ofDrawLine(point->x, point->y, point->z, lastX, lastY, lastZ);
        }
        
        lastX = point->x;
        lastY = point->y;
        lastZ = point->z;
        
        i += circleStep;
    }
}
