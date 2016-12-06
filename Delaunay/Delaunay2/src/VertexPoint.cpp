//
//  VertexPoint.cpp
//  Delaunay2
//
//  Created by Ryota Takemoto on 2016/12/06.
//
//

#include "VertexPoint.hpp"

void VertexPoint::update(int mouseX, int mouseY){
    ofVec2f m(mouseX, mouseY);
    ofVec2f dir = m - pMouse;
    
    velocity = smooth * velocity + smooth * dir.x;
    pMouse.set(mouseX, mouseY);
}

ofVec2f VertexPoint::getVec2f(int mouseX, int mouseY){
    return ofVec2f(mouseX - velocity, mouseY - velocity);
}
