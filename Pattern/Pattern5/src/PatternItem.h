//
//  PatternItem.h
//  Pattern1
//
//  Created by 新家 亮太 on 2016/11/21.
//
//

#ifndef PatternItem_h
#define PatternItem_h

#include "ofMain.h"

class PatternItem {
public:
    PatternItem(ofPoint originalPosition, ofPoint dirPosition);
    virtual void update() {};
    virtual void draw() {};
    void setPosition(ofPoint position);
    void setDir(ofPoint dir);
    void updatePosition();
    bool isAnimating;
    bool canChange;
    ofPoint currentPosition;
    ofPoint originalPosition;
    ofPoint dirPosition;
};

#endif /* PatternItem_h */
