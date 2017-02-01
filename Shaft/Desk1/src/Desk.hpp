//
//  Desk.hpp
//  Desk1
//
//  Created by Ryota Takemoto on 2017/01/31.
//
//

#ifndef Desk_hpp
#define Desk_hpp

#include "ofMain.h"

class Desk {
public:
    Desk(ofVec3f position,
         ofVec3f initialVelocity,
         float width,
         float height,
         float depth,
         float mass,
         ofColor color);
    void update();
    void draw();
    void applyForce(ofVec3f force);
    float getBottom();
    float mass;
    ofVec3f velocity;
    
private:
    ofVec3f position;
    ofVec3f acceleration;
    float width, height, depth;
    ofColor color;
    float rotate;
};

#endif /* Desk_hpp */
