//
//  Graphic.hpp
//  Easing3
//
//  Created by Ryota Takemoto on 2016/12/26.
//
//

#ifndef Graphic_hpp
#define Graphic_hpp

#include "ofMain.h"

class Graphic {
public:
    Graphic(ofPoint _location, float _width, float _height, ofColor _color);
    virtual void update() {};
    virtual void draw() {};
    virtual bool isFinished() {};
    void reset();
    void setAnimation(bool shouldAnimate);
    bool isAnimated();
    
    ofPoint location;
    float width;
    float height;
    ofColor color;
    float initTime;
    float endPosition;
    float startPosition;
    bool shouldAnimate;
};

#endif /* Graphic_hpp */
