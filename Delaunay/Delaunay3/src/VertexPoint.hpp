//
//  VertexPoint.hpp
//  Delaunay2
//
//  Created by Ryota Takemoto on 2016/12/06.
//
//

#ifndef VertexPoint_hpp
#define VertexPoint_hpp

#include "ofMain.h"

class VertexPoint {
    
public:
    VertexPoint(ofVec2f position);
    void update(int mouseX, int mouseY);
    ofPoint getLocation(int mouseX, int mouseY);
    
    ofVec2f position;
    float velocity = 0;
    float smooth = 0.9;
    ofVec2f pMouse;
};

#endif /* VertexPoint_hpp */
