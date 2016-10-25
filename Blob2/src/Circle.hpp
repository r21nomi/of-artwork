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

class Circle {
public:
    Circle();
    void update();
    void draw();
    
    ofPoint location;
    float radius;
    vector<ofPoint*> vertexs;
};

#endif /* Circle_hpp */
