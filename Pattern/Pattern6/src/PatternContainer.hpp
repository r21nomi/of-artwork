//
//  PatternContainer.hpp
//  Pattern6
//
//  Created by Ryota Takemoto on 2016/12/02.
//
//

#ifndef PatternContainer_hpp
#define PatternContainer_hpp

#include "ofMain.h"
#include "PatternItem.h"
#include "Cross.hpp"
#include "Circle.hpp"
#include "Rhombus.hpp"
#include "SmallCrosses.hpp"
#include "Ball.hpp"

class PatternContainer {
public:
    PatternContainer(ofPoint position, float width, float height, vector<PatternItem*> patternItems);
    virtual void update();
    virtual void draw();
    
private:
    bool shouldMoveItem(PatternItem *patternItem);
    ofPoint basePosition;
    ofPoint position;
    float width;
    float height;
    vector<PatternItem*> patternItems;
};

#endif /* PatternContainer_hpp */
