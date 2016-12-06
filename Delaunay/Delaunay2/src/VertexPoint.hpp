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
    void update(int mouseX, int mouseY);
    ofVec2f getVec2f(int mouseX, int mouseY);
    
    float velocity = 0;
    float smooth = 0.9;
    ofVec2f pMouse;
};

#endif /* VertexPoint_hpp */
