//
//  Pole.hpp
//  Pole1
//
//  Created by Ryota Takemoto on 2017/02/28.
//
//

#ifndef Pole_hpp
#define Pole_hpp

#include "ofMain.h"

class Pole {
public:
    Pole(ofVec3f position, float width, float height, ofColor color);
    void update();
    void draw();
    bool isFinished();
    void resetIfFinished();
    
private:
    ofVec3f position;
    float width;
    float height;
    ofColor color;
    float speed;
    float initTime, endTime;
    float duration;
    float offsetSpeed;
    ofVec3f startPosition, endPosition;
};

#endif /* Pole_hpp */
