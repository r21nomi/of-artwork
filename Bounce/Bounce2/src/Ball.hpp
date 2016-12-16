//
//  Ball.hpp
//  Bounce1
//
//  Created by Ryota Takemoto on 2016/12/14.
//
//

#ifndef Ball_hpp
#define Ball_hpp

#include "ofMain.h"

class Ball {
public:
    Ball(ofVec2f position, float mass, float radius, ofColor color);
    void applyForce(ofVec2f force);
    void checkEdges(float stairY, int step);
    void update();
    void draw();
    float mass;
    ofVec2f velocity;
    
private:
    ofVec2f currentPosition;
    float radius;
    int currentStep;
    ofVec2f acceleration;
    ofColor color;
};

#endif /* Ball_hpp */
