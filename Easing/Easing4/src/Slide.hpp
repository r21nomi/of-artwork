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
#include "Graphic.hpp"

class Slide : public Graphic {
public:
    enum Direction {
        LEFT,
        TOP,
        RIGHT,
        BOTTOM
    };
    Slide(ofPoint location, float width, float height, ofColor color, Direction direction);
    virtual void update();
    virtual void draw();
    virtual bool isFinished();
    void reset();
    void setAnimation(bool shouldAnimate);
    bool isAnimated();
    
private:
    Direction direction;
    ofBoxPrimitive box;
    float rotation;
    float minVal;
    float maxVal;
};

#endif /* Slide_hpp */
