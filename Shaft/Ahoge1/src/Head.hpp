//
//  Head.hpp
//  Ahoge1
//
//  Created by Ryota Takemoto on 2017/02/04.
//
//

#ifndef Head_hpp
#define Head_hpp

#include "ofMain.h"

class Head {
public:
    Head(ofVec2f position, float radius, ofColor color);
    void update();
    void draw();
    float getRight();
    
private:
    ofVec2f position;
    float radius;
    ofColor color;
    float originalAhogeHight, ahogeHight;
    float rotate;
};

#endif /* Head_hpp */
