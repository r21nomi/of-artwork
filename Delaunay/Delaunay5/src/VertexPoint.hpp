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
    VertexPoint(ofVec2f position, ofColor color, bool shouldMove);
    void update(int mouseX, int mouseY);
    ofPoint getLocation();
    ofColor getColor();
    
    ofVec2f position;
    ofVec2f originalPosition;
    ofColor color;
    bool shouldMove;
    float velocityX = 0;
    float velocityY = 0;
    float smooth = 0.9;
    ofVec2f stepSpeed;
    ofVec2f pMouse;
};

#endif /* VertexPoint_hpp */
