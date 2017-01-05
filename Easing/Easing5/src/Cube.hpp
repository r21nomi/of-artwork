//
//  Slide.hpp
//  Easing1
//
//  Created by Ryota Takemoto on 2016/12/21.
//
//

#ifndef Cube_hpp
#define Cube_hpp

#include "ofMain.h"
#include "Graphic.hpp"

class Cube : public Graphic {
public:
    enum Direction {
        LEFT,
        TOP,
        RIGHT,
        BOTTOM
    };
    Cube(ofPoint location, float width, float height, float depth, ofColor color, Direction direction);
    virtual void update();
    virtual void draw();
    virtual bool isFinished();
    void reset();
    void setAnimation(bool shouldAnimate);
    bool isAnimated();
    
private:
    Direction direction;
    ofBoxPrimitive box;
    float depth;
    float rotation;
    float minVal;
    float maxVal;
    float duration;
};

#endif /* Slide_hpp */
