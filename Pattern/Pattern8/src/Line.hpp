//
//  Line.hpp
//  Pattern7
//
//  Created by Ryota Takemoto on 2016/12/03.
//
//

#ifndef Line_hpp
#define Line_hpp


#include "ofMain.h"
#include "PatternItem.h"

class Line : public PatternItem {
public:
    Line(ofPoint position, float radius, ofColor color, ofColor maskColor, int bold, float speed);
    virtual void update();
    virtual void draw();
    void setMaskColor(ofColor color);
    
private:
    ofColor color;
    ofColor maskColor;
    float radius;
    float lineRadius;
    int bold;
    float margin;
    float speed;
    vector<ofPoint*> points;
    ofFbo fbo;
};

#endif /* Line_hpp */
