//
//  CurveItem.cpp
//  Sphere3
//
//  Created by Ryota Takemoto on 2017/01/22.
//
//

#include "CurveItem.hpp"

CurveItem::CurveItem(ofVec3f position,
                     ofColor color,
                     float radius,
                     float bold,
                     float initialAngle,
                     float speedOffSet,
                     float ratateOffSet) {
    this->position = position;
    this->color = color;
    this->radius = radius;
    this->bold = bold;
    this->initialAngle = this->angleBegin = this->angleEnd = initialAngle;
    this->speedOffSet = speedOffSet;
    this->ratateOffSet = ratateOffSet;
}

void CurveItem::update() {
    if (angleEnd < initialAngle + 360) {
        angleEnd += speedOffSet;
    } else {
        angleBegin += speedOffSet;
        
        if (angleBegin >= angleEnd) {
            angleBegin = initialAngle;
            angleEnd = initialAngle + speedOffSet;
        }
    }
    
//    printf("angleBegin %f: angleEnd %f\n", angleBegin, angleEnd);
}

void CurveItem::draw() {
    ofPushMatrix();
    
    ofTranslate(position.x, position.y);
    
    ofRotateX(ofGetElapsedTimeMillis() * ratateOffSet);
    ofRotateY(ofGetElapsedTimeMillis() * ratateOffSet);
    ofRotateZ(ofGetElapsedTimeMillis() * ratateOffSet);
    
    ofSetColor(color);
    ofSetLineWidth(bold);

    ofPolyline curve;
    curve.arc(0, 0, position.z, radius, radius, angleBegin, angleEnd, 100);
    curve.draw();
    
    ofPopMatrix();
}
