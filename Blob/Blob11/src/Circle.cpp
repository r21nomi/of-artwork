//
//  Circle.cpp
//  Blob3_4
//
//  Created by 新家 亮太 on 2016/10/25.
//
//

#include "Circle.hpp"

Circle::Circle(float _x, float _y, float _radius, ofColor _color, State _initialState) {
    location = targetLocation = ofPoint(_x, _y);
    radius = _radius;
    color = _color;
    offset = ofPoint(ofRandom(radius), ofRandom(radius));
    velocity = ofRandom(0.05, 0.09);
    initialState = _initialState;
    currentState = _initialState;
    isShapeChanging = false;
    isLocationUpdating = false;
    
    float angleStep = 1;
    
    for (float angle = 0, len = 360; angle < len; angle += angleStep) {
        float radian = ofDegToRad(angle);
        float ex = radius * cos(radian);
        float ey = radius * sin(radian);
        float nr = radius - ofMap(ofNoise(ex * 0.01 + offset.x, ey * 0.01 + offset.y), 0, 1, 1, radius * 0.1);
        float nx = nr * cos(radian);
        float ny = nr * sin(radian);
        ofPoint circle = ofPoint(nx, ny);
        
        ofPoint rectangle;
        if (angle >= 0 && angle < 90) {
            rectangle = ofPoint(radius * cos(ofDegToRad(0)), radius * sin(ofDegToRad(90)));
            
        } else if (angle >= 90 && angle < 180) {
            rectangle = ofPoint(radius * cos(ofDegToRad(180)), radius * sin(ofDegToRad(90)));
            
        } else if (angle >= 180 && angle < 270) {
            rectangle = ofPoint(radius * cos(ofDegToRad(180)), radius * sin(ofDegToRad(270)));
            
        } else {
            rectangle = ofPoint(radius * cos(ofDegToRad(360)), radius * sin(ofDegToRad(270)));
        }
        rectangle = ofPoint(rectangle.x, rectangle.y);
        
        ofPoint current;
        ofPoint target;
        
        switch (currentState) {
            case CIRCLE:
                current = circle;
                target = rectangle;
                break;
                
            case RECTANGLE:
                current = rectangle;
                target = circle;
                break;
        }
        
        originalVertexs.push_back(new CirclePoint(current, target));
    }
    
    copy(originalVertexs.begin(), originalVertexs.end(), back_inserter(currentVertexs));
}

void Circle::updateShape() {
    isShapeChanging = false;
    
    switch (currentState) {
        case CIRCLE:
            for (CirclePoint *vertex : currentVertexs) {
                ofPoint location = vertex->getLocation();
                ofPoint targetLocation = vertex->getTargetLocation();
                float distX = targetLocation.x - location.x;
                float distY = targetLocation.y - location.y;
                
                if (abs(distX) < 1 && abs(distY) < 1) {
                    vertex->setLocation(ofPoint(targetLocation.x, targetLocation.y));
                    continue;
                }
                
                vertex->setLocation(ofPoint(location.x + distX * velocity, location.y + distY * velocity));
                isShapeChanging = true;
            }
            break;
            
        case RECTANGLE:
            for (CirclePoint *vertex : currentVertexs) {
                ofPoint location = vertex->getLocation();
                ofPoint targetLocation = vertex->getOriginalLocation();
                float distX = targetLocation.x - location.x;
                float distY = targetLocation.y - location.y;
                
                if (abs(distX) < 1 && abs(distY) < 1) {
                    vertex->setLocation(ofPoint(targetLocation.x, targetLocation.y));
                    continue;
                }
                
                vertex->setLocation(ofPoint(location.x + distX * velocity, location.y + distY * velocity));
                isShapeChanging = true;
            }
            break;
            
        default:
            break;
    }
    
    if (!isShapeChanging) {
        // no-op
    }
}

void Circle::updateLocation() {
    isLocationUpdating = true;
    
    float distX = targetLocation.x - location.x;
    float distY = targetLocation.y - location.y;
    
    if (abs(distX) > 0.5) {
        location.x += distX * 0.08;
    } else {
        location.x = targetLocation.x;
    }
    if (abs(distY) > 0.5) {
        location.y += distY * 0.08;
    } else {
        location.y = targetLocation.y;
    }
    
    if (location.x == targetLocation.x && location.y == targetLocation.y) {
        isLocationUpdating = false;
    }
}

void Circle::draw() {
    ofSetColor(color);
    ofPushMatrix();
    ofTranslate(location.x, location.y);
    ofBeginShape();
    
    for (CirclePoint *vertex : originalVertexs) {
        ofVertex(vertex->getLocation().x, vertex->getLocation().y);
    }
    
    ofEndShape(OF_CLOSE);
    ofPopMatrix();
}

void Circle::setTargetLocation(ofPoint _location) {
    targetLocation = _location;
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
    isShapeChanging = true;
}

Circle::State Circle::getCurrentState() {
    return currentState;
}

bool Circle::getIsShapeChanging() {
    return isShapeChanging;
}

bool Circle::getIsLocationUpdating() {
    return isLocationUpdating;
}
