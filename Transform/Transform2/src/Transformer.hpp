//
//  Transformer.hpp
//  Transform
//
//  Created by 新家 亮太 on 2016/11/15.
//
//

#ifndef Transformer_hpp
#define Transformer_hpp

#include "ofMain.h"
#include "VertexPoint.hpp"

class Transformer {
public:
    Transformer(ofPoint pos, float radius, int vertexCount, ofColor color);
    vector<VertexPoint*> points;
    void update();
    void draw();
    
private:
    float radius;
    ofPoint pos;
    int vertexCount;
    ofColor color;
    vector<VertexPoint*> vertexPoints;
};

#endif /* Transformer_hpp */
