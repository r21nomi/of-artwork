//
//  VertexPoint.cpp
//  Delaunay2
//
//  Created by Ryota Takemoto on 2016/12/06.
//
//

#include "VertexPoint.hpp"

VertexPoint::VertexPoint(ofVec2f _position, ofColor _color, bool _shouldMove) {
    originalPosition = position = _position;
    stepSpeed = ofVec2f(ofRandom(-1, 1), ofRandom(-1, 1));
    color = _color;
    shouldMove = _shouldMove;
    pMouse.set(position.x, position.y);
}

void VertexPoint::update(int mouseX, int mouseY){
    if (!shouldMove) {
        return;
    }
    
    position.x += stepSpeed.x;
    position.y += stepSpeed.y;
    ofVec2f poditionDir = position - originalPosition;
    
    if (abs(poditionDir.x) > 50) {
        stepSpeed.x *= -1;
    }
    if (abs(poditionDir.y) > 50) {
        stepSpeed.y *= -1;
    }
    
    ofVec2f m(mouseX, mouseY);
    ofVec2f dir = m - pMouse;
    int offset = 100;
    
    if (abs(ofDist(position.x, position.y, mouseX, mouseY)) > offset) {
        velocityX = 0;
        velocityY = 0;
    } else {
        velocityX = smooth * velocityX + smooth * -dir.x;
        velocityY = smooth * velocityY + smooth * -dir.y;
    }
    
    pMouse.set(mouseX, mouseY);
}

ofPoint VertexPoint::getLocation(){
    return ofPoint(position.x - velocityX, position.y - velocityY);
}

ofColor VertexPoint::getColor() {
    return color;
}
