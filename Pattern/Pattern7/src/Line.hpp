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
    Line(ofPoint position, float radius, ofColor color, int bold, float speed);
    virtual void update();
    virtual void draw();
    
private:
    ofColor color;
    float radius;
    int bold;
    float margin;
    float speed;
    vector<ofPoint*> points;
};

#endif /* Line_hpp */
