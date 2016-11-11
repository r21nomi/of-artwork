//
//  Circle.hpp
//  Blob3_4
//
//  Created by 新家 亮太 on 2016/10/25.
//
//

#ifndef Circle_hpp
#define Circle_hpp

#include "ofMain.h"
#include "CirclePoint.hpp"

class Circle {
public:
    enum State {
        CIRCLE,
        RECTANGLE
    };
    
    Circle(float x, float y, float radius, ofColor color, State initialState);
    void updateShape();
    void updateLocation();
    void draw();
    void changeState();
    void setTargetLocation(ofPoint location);
    void enableCanUpdateShape();
    ofPoint getLocation();
    float getRadius();
    
    ofPoint location;
    ofPoint targetLocation;
    float radius;
    ofColor color;
    vector<CirclePoint*> originalVertexs;
    vector<CirclePoint*> currentVertexs;
    ofPoint offset;
    float velocity;
    State initialState;
    State currentState;
    bool canUpdateShape;
};

#endif /* Circle_hpp */
