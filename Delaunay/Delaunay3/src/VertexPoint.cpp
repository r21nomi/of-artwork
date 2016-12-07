//
//  VertexPoint.cpp
//  Delaunay2
//
//  Created by Ryota Takemoto on 2016/12/06.
//
//

#include "VertexPoint.hpp"

VertexPoint::VertexPoint(ofVec2f _position) {
    position = _position;
    pMouse.set(position.x, position.y);
}

void VertexPoint::update(int mouseX, int mouseY){
    ofVec2f m(mouseX, mouseY);
    ofVec2f dir = m - pMouse;
    int offset = 100;
    
    ofLog(OF_LOG_NOTICE, ofToString(dir.x));
    
    if (abs(position.x - mouseX) > offset && abs(position.y - mouseY) > offset) {
        velocity = 0;
    } else {
        velocity = smooth * velocity + (1 - smooth) * dir.x + smooth * dir.y;
    }
    
    pMouse.set(mouseX, mouseY);
}

ofPoint VertexPoint::getLocation(int mouseX, int mouseY){
    return ofPoint(position.x - velocity, position.y - velocity);
}
