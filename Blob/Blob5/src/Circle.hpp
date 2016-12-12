//
//  Circle.hpp
//  Blob2
//
//  Created by 新家 亮太 on 2016/10/25.
//
//

#ifndef Circle_hpp
#define Circle_hpp

#include "ofMain.h"
#include "CirclePoint.hpp"

class Circle {
public:
    Circle();
    void update();
    void draw();
    ofPoint getLocation();
    float getRadius();
    
    ofPoint location;
    float radius;
    vector<CirclePoint*> originalVertexs;
    vector<CirclePoint*> currentVertexs;
    ofPoint offset;
    float velocity;
    bool isCircle;
};

#endif /* Circle_hpp */
