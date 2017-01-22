//
//  CurveItem.hpp
//  Sphere3
//
//  Created by Ryota Takemoto on 2017/01/22.
//
//

#ifndef CurveItem_hpp
#define CurveItem_hpp

#include "ofMain.h"

class CurveItem {
public:
    CurveItem(ofVec3f position,
              ofColor color,
              float radius,
              float bold,
              float initialAngle,
              float speedOffSet,
              float ratateOffSet);
    void update();
    void draw();
    
private:
    ofVec3f position;
    ofColor color;
    float radius;
    float bold;
    float initialAngle, angleBegin, angleEnd;
    float speedOffSet;
    float ratateOffSet;
};

#endif /* CurveItem_hpp */
