//
//  VertexPoint.hpp
//  Transform
//
//  Created by 新家 亮太 on 2016/11/15.
//
//

#ifndef VertexPoint_hpp
#define VertexPoint_hpp

#include "ofMain.h"

class VertexPoint {
public:
    VertexPoint(ofPoint location);
    ofPoint getLocation();
    ofPoint getTargetLocation();
    ofPoint getOriginalLocation();
    void setLocation(ofPoint location);
    
    ofPoint location;
    ofPoint targetLocation;
    ofPoint originalLocation;
};

#endif /* VertexPoint_hpp */
