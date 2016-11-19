//
//  Transformer.cpp
//  Transform
//
//  Created by 新家 亮太 on 2016/11/15.
//
//

#include "Transformer.hpp"

Transformer::Transformer(ofPoint _pos, float _radius, int _vertexCount, ofColor _color) {
    pos = _pos;
    radius = _radius;
    vertexCount = _vertexCount;
    color = _color;
    rotate = 0;
    
    for (int i = 0; i < vertexCount; i++) {
        int angle = i * 360 / vertexCount;
        ofPoint p = ofPoint(radius * cos(ofDegToRad(angle)), radius * sin(ofDegToRad(angle)));
        vertexPoints.push_back(new VertexPoint(p));
    }
}

void Transformer::update() {
    bool isShapeChanging = false;
    float rotateVelocity = 0;
    
    if (vertexCount <= 3) {
        return;
    }
    
    vector<ofPoint*> nextPoints;
    int nextCount = vertexCount - 1;
    for (int i = 0; i < nextCount; i++) {
        int angle = i * 360 / nextCount;
        nextPoints.push_back(new ofPoint(radius * cos(ofDegToRad(angle)), radius * sin(ofDegToRad(angle))));
    }
    
    int i = 0;
    for (VertexPoint *p : vertexPoints) {
        ofPoint targetPoint;
        if (i == nextPoints.size()) {
            targetPoint = *nextPoints[nextPoints.size() - 1];
        } else {
            targetPoint = *nextPoints[i];
        }
        
        ofPoint currentLocation = p->getLocation();
        float distX = targetPoint.x - currentLocation.x;
        float distY = targetPoint.y - currentLocation.y;
        
        if (abs(distX) < 0.5 && abs(distY) < 0.5) {
            p->setLocation(ofPoint(targetPoint.x, targetPoint.y));
        } else {
            p->setLocation(ofPoint(currentLocation.x + distX * 0.08f, currentLocation.y + distY * 0.08f));
            isShapeChanging = true;
        }
        
        if (i == nextPoints.size()) {
            rotate += abs(distX) * 0.3;
        }
        
        i++;
    }
    
    if (!isShapeChanging) {
        vertexPoints.pop_back();
        vertexCount -= 1;
        for (VertexPoint *point : vertexPoints) {
            point->setOriginalLocation(point->getLocation());
        }
    }
}

void Transformer::draw() {
    ofPath path;
    path.setColor(color);
    
    ofPushMatrix();
    ofTranslate(pos.x, pos.y);
    ofRotate(rotate);
    
    for (VertexPoint *vertexPoint : vertexPoints) {
        ofPoint p = vertexPoint->getLocation();
        path.lineTo(p.x, p.y);
    }
    
    path.draw();
    ofPopMatrix();
}
