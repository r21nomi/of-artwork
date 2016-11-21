//
//  Circle.hpp
//  Pattern1
//
//  Created by 新家 亮太 on 2016/11/21.
//
//

#ifndef Circle_hpp
#define Circle_hpp

#include "ofMain.h"
#include "PatternItem.h"

class Circle : public PatternItem {
public:
    Circle(ofPoint position, float radius, int bold, ofColor color);
    virtual void update();
    virtual void draw();
    
private:
    ofPoint currentPosition;
    ofColor color;
    float radius;
    int bold;
};

#endif /* Circle_hpp */
