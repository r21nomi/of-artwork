//
//  Stair.hpp
//  Bounce2
//
//  Created by Ryota Takemoto on 2016/12/16.
//
//

#ifndef Stair_hpp
#define Stair_hpp

#include "ofMain.h"

class Stair {
public:
    Stair(int stepNum, ofVec2f position, float width, float height, ofColor color);
    void draw();
    int getStepNum();
    float getStairY();
    void update(int stepNum, ofColor color);
    
private:
    int stepNum;
    ofVec2f position;
    float width;
    float height;
    ofColor color;
};

#endif /* Stair_hpp */
