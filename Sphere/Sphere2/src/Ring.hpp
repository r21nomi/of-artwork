//
//  Ring.hpp
//  Sphere2
//
//  Created by Ryota Takemoto on 2017/01/18.
//
//

#ifndef Ring_hpp
#define Ring_hpp

#include "ofMain.h"

class Ring {
public:
    Ring(float radius, int lineStep, float radianZ, float positoinZ, ofColor color);
    void update();
    void draw();
    
private:
    ofColor color;
    float radius;
    float circleStep = 1;
    float lineStep;
    float lineWidth = 8;
    float lastX, lastY, lastZ;
    vector<ofPoint*> points;
};

#endif /* Ring_hpp */
