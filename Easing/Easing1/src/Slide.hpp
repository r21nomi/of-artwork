//
//  Slide.hpp
//  Easing1
//
//  Created by Ryota Takemoto on 2016/12/21.
//
//

#ifndef Slide_hpp
#define Slide_hpp

#include "ofMain.h"

class Slide {
public:
    Slide(ofPoint location, float width, float height, ofColor color);
    void update();
    void draw();
    void reset();
    
private:
    ofPoint location;
    float width;
    float height;
    ofColor color;
    
    float initTime;
    float endPosition;
};

#endif /* Slide_hpp */
