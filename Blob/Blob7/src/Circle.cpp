//
//  Circle.cpp
//  Blob3_4
//
//  Created by 新家 亮太 on 2016/10/25.
//
//

#include "Circle.hpp"

Circle::Circle(float _x, float _y, float _radius) {
    location = ofPoint(_x, _y);
    radius = _radius;
    offset = ofPoint(ofRandom(radius), ofRandom(radius));
    velocity = ofRandom(0.05, 0.09);
    currentState = CIRCLE;
    
    float angleStep = 1;
    
    for (float angle = 0, len = 360; angle < 360; angle += angleStep) {
        float radian = ofDegToRad(angle);
        float ex = radius * cos(radian);
        float ey = radius * sin(radian);
        float nr = radius - ofMap(ofNoise(ex * 0.01 + offset.x, ey * 0.01 + offset.y), 0, 1, 1, radius * 0.1);
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
    
    switch (currentState) {
        case CIRCLE:
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
            break;
            
        case RECTANGLE:
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
            break;
            
        default:
            break;
    }
    
    if (!isChanged) {
        changeState();
    }
}

void Circle::draw() {
    ofPushMatrix();
    ofTranslate(location.x, location.y);
    ofRotate(ofGetFrameNum() * 0.8);
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

void Circle::changeState() {
    switch (currentState) {
        case CIRCLE:
            currentState = RECTANGLE;
            break;
            
        case RECTANGLE:
            currentState = CIRCLE;
            break;
            
        default:
            break;
    }
}
