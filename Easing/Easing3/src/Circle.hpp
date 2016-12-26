//
//  Circle.hpp
//  Easing3
//
//  Created by Ryota Takemoto on 2016/12/26.
//
//

#ifndef Circle_hpp
#define Circle_hpp

#include "ofMain.h"
#include "Graphic.hpp"

class Circle : public Graphic {
public:
    Circle(ofPoint location, float width, float height, ofColor color);
    virtual void update();
    virtual void draw();
    virtual bool isFinished();
    void reset();
    void setAnimation(bool shouldAnimate);
    bool isAnimated();
    
private:
    float initialRadius;
    float radius;
};

#endif /* Circle_hpp */
