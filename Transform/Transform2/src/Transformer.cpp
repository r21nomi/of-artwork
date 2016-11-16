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
    
    for (int i = 0, len = 360; i < len; i += len / vertexCount) {
        ofPoint p = ofPoint(radius * cos(ofDegToRad(i)), radius * sin(ofDegToRad(i)));
        vertexPoints.push_back(new VertexPoint(p));
    }
}

void Transformer::update() {
    bool isShapeChanging = false;
    
    vector<ofPoint*> nextPoints;
    int nextCount = vertexCount - 1;
    for (int i = 0, len = 360; i < len; i += len / nextCount) {
        nextPoints.push_back(new ofPoint(radius * cos(ofDegToRad(i)), radius * sin(ofDegToRad(i))));
    }
    
    int i = 0;
    for (VertexPoint *p : vertexPoints) {
        if (i > nextPoints.size() - 1) {
            break;
        }
        ofPoint targetPoint = *nextPoints[i];
        ofPoint currentLocation = p->getLocation();
        float distX = targetPoint.x - currentLocation.x;
        float distY = targetPoint.y - currentLocation.y;
        
        // TODO
        // if (abs(distX) != 0 && abs(distX) < 1 && abs(distY) != 0 && abs(distY) < 1) {
        if (abs(distX) < 1 && abs(distY) < 1) {
            p->setLocation(ofPoint(targetPoint.x, targetPoint.y));
            continue;
        }
        
        p->setLocation(ofPoint(currentLocation.x + distX * 0.08f, currentLocation.y + distY * 0.08f));
        isShapeChanging = true;
        i++;
    }
    
//    if (!isShapeChanging && vertexCount > 3) {
//        vertexCount -= 1;
//        ofLog(OF_LOG_VERBOSE, "changed");
//    }
}

void Transformer::draw() {
    ofPath path;
    path.setColor(color);
    
    ofPushMatrix();
    ofTranslate(pos.x, pos.y);
    
    for (VertexPoint *vertexPoint : vertexPoints) {
        ofPoint p = vertexPoint->getLocation();
        path.lineTo(p.x, p.y);
    }
    
    path.draw();
    ofPopMatrix();
}
