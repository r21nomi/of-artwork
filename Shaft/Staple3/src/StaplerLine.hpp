//
//  StaplerLine.hpp
//  Staple3
//
//  Created by Ryota Takemoto on 2017/01/29.
//
//

#ifndef StaplerLine_hpp
#define StaplerLine_hpp

#include "ofMain.h"
#include "Stapler.hpp"
#include "Staple.hpp"

class StaplerLine {
public:
    StaplerLine(ofVec3f position, ofColor stapleColor);
    void update();
    void draw();
    Stapler* getStapler();
    
private:
    Staple* getStaple(ofVec3f position);
    
    ofVec3f position;
    vector<Staple*> staples;
    Stapler* stapler;
    
    float stapleWidth;
    float stapleHeight;
    float stapleDepth;
    float stapleMargin;
    float stapleSpeed;
    float stapleBold;
    ofColor stapleColor;
};

#endif /* StaplerLine_hpp */
