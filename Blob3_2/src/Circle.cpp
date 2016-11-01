//
//  Circle.cpp
//  Blob2
//
//  Created by 新家 亮太 on 2016/10/25.
//
//

#include "Circle.hpp"

Circle::Circle() {
    location = ofPoint(ofGetWidth() / 2, ofGetHeight() / 2);
    radius = 300;
    offset = ofPoint(ofRandom(1000), ofRandom(1000));
    velocity = ofRandom(0.1, 0.5);
    
    float angleStep = 1;
    isCircle = true;
    
    for (float angle = 0, len = 360; angle < 360; angle += angleStep) {
        float radian = ofDegToRad(angle);
        float ex = radius * cos(radian);
        float ey = radius * sin(radian);
        float nr = radius - ofMap(ofNoise(ex * 0.01 + offset.x, ey * 0.01 + offset.y), 0, 1, 0, radius * 0.05);
        float nx = nr * cos(radian);
        float ny = nr * sin(radian);
        
        ofPoint target;
        if (angle >= 0 && angle < 90) {
            target = ofPoint(radius * cos(ofDegToRad(45)), radius * sin(ofDegToRad(45)));
            
        } else if (angle >= 90 && angle < 180) {
            target = ofPoint(radius * cos(ofDegToRad(135)), radius * sin(ofDegToRad(135)));
            
        } else if (angle >= 180 && angle < 270) {
            target = ofPoint(radius * cos(ofDegToRad(225)), radius * sin(ofDegToRad(225)));
            
        } else {
            target = ofPoint(radius * cos(ofDegToRad(315)), radius * sin(ofDegToRad(315)));
        }
        
        originalVertexs.push_back(new CirclePoint(ofPoint(nx, ny), ofPoint(target.x * 0.7, target.y * 0.7)));
    }
    
    copy(originalVertexs.begin(), originalVertexs.end(), back_inserter(currentVertexs));
}

void Circle::update() {
    bool isChanged = false;
    float velocity = 0.09;
    
    if (isCircle) {
        for (CirclePoint *vertex : currentVertexs) {
            ofPoint location = vertex->getLocation();
            ofPoint targetLocation = vertex->getTargetLocation();
            float distX = targetLocation.x - location.x;
            float distY = targetLocation.y - location.y;
            
            if (abs(distX) < 0.5 && abs(distY) < 0.5) {
                continue;
            }
            
            vertex->setLocation(ofPoint(location.x + distX * velocity, location.y + distY * velocity));
            isChanged = true;
        }
    } else {
        for (CirclePoint *vertex : currentVertexs) {
            ofPoint location = vertex->getLocation();
            ofPoint targetLocation = vertex->getOriginalLocation();
            float distX = targetLocation.x - location.x;
            float distY = targetLocation.y - location.y;
            
            if (abs(distX) < 0.5 && abs(distY) < 0.5) {
                continue;
            }
            
            vertex->setLocation(ofPoint(location.x + distX * velocity, location.y + distY * velocity));
            isChanged = true;
        }
    }
    
    if (!isChanged) {
        isCircle = !isCircle;
    }
}

void Circle::draw() {
    ofPushMatrix();
    ofTranslate(location.x, location.y);
    ofBeginShape();
    
    float angleStep = 1;
    for (CirclePoint *vertex : originalVertexs) {
        ofVertex(vertex->getLocation().x, vertex->getLocation().y);
    }
    
    ofEndShape(OF_CLOSE);
    ofPopMatrix();
}

ofPoint Circle::getLocation() {
    return location;
}

float Circle::getRadius() {
    return radius;
}
