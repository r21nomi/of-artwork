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
    enum Direction {
        LEFT,
        TOP,
        RIGHT,
        BOTTOM
    };
    Slide(ofPoint location, float width, float height, ofColor color, Direction direction);
    void update();
    void draw();
    void reset();
    void setAnimation(bool shouldAnimate);
    bool isAnimated();
    
private:
    ofPoint location;
    float width;
    float height;
    ofColor color;
    Direction direction;
    
    float initTime;
    float endPosition;
    float startPosition;
    bool shouldAnimate;
};

#endif /* Slide_hpp */
