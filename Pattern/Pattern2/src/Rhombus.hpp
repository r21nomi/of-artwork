//
//  Rhombus.hpp
//  Pattern1
//
//  Created by 新家 亮太 on 2016/11/21.
//
//

#ifndef Rhombus_hpp
#define Rhombus_hpp

#include "ofMain.h"
#include "PatternItem.h"

class Rhombus : public PatternItem {
public:
    Rhombus(ofPoint position, float radius, int bold, ofColor color);
    virtual void update();
    virtual void draw();
    
private:
    ofPoint currentPosition;
    ofColor color;
    float radius;
    int bold;
    int currentDegree;
};

#endif /* Rhombus_hpp */
