//
//  Stapler.hpp
//  Staple2
//
//  Created by Ryota Takemoto on 2017/01/25.
//
//

#ifndef Stapler_hpp
#define Stapler_hpp

#include "ofMain.h"

class Stapler {
public:
    Stapler(ofVec3f position, float width, float height, float depth, ofColor color);
    void update();
    void draw();
    ofVec3f getPosition();
    
private:
    ofVec3f position;
    ofColor color;
    float width, height, depth;
    float speedOffset;
    int degree, degStep;
};

#endif /* Stapler_hpp */
