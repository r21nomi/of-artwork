//
//  Staple.hpp
//  Staple1
//
//  Created by Ryota Takemoto on 2017/01/24.
//
//

#ifndef Staple_hpp
#define Staple_hpp

#include "ofMain.h"

class Staple {
public:
    Staple(ofVec3f position, float width, float height, float depth, float bold, float speed, ofColor color);
    void update();
    void draw();
    ofVec3f getPosition();
    
private:
    ofVec3f position;
    ofColor color;
    float width, height, depth, speed, bold;
};

#endif /* Staple_hpp */
