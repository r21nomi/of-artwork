//
//  SmallCrosses.hpp
//  Pattern2
//
//  Created by 新家 亮太 on 2016/11/23.
//
//

#ifndef SmallCrosses_hpp
#define SmallCrosses_hpp

#include "ofMain.h"
#include "PatternItem.h"

class SmallCrosses : public PatternItem {
public:
    SmallCrosses(ofPoint position, float radius, int bold, int count, ofColor color);
    virtual void update();
    virtual void draw();
    
private:
    ofPoint currentPosition;
    ofColor color;
    float radius;
    int bold;
    int count;
    int currentDegree;
};

#endif /* SmallCrosses_hpp */
