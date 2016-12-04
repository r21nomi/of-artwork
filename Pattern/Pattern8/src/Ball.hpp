//
//  Ball.hpp
//  Pattern2
//
//  Created by 新家 亮太 on 2016/11/23.
//
//

#ifndef Ball_hpp
#define Ball_hpp

#include "ofMain.h"
#include "PatternItem.h"

class Ball : public PatternItem {
public:
    Ball(ofPoint position, float radius, float ballRadius, ofColor color);
    virtual void update();
    virtual void draw();
    
private:
    ofColor color;
    float radius;
    float ballRadius;
    float maxBallRadius;
    float minBallRadiusRatio;
    float currentDegree;
};

#endif /* Ball_hpp */
