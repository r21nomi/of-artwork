//
//  CirclePoint.hpp
//  Blob_3
//
//  Created by 新家 亮太 on 2016/10/31.
//
//

#ifndef CirclePoint_hpp
#define CirclePoint_hpp

#include "ofMain.h"

class CirclePoint {
public:
    CirclePoint(ofPoint location, ofPoint targetLocation);
    ofPoint getLocation();
    ofPoint getTargetLocation();
    ofPoint getOriginalLocation();
    void setLocation(ofPoint location);
    
    ofPoint location;
    ofPoint targetLocation;
    ofPoint originalLocation;
};

#endif /* CirclePoint_hpp */
