//
//  Transformer.cpp
//  Transform
//
//  Created by 新家 亮太 on 2016/11/15.
//
//

#include "Transformer.hpp"

Transformer::Transformer(ofPoint _pos, float _radius, int _vertexCount, ofColor _color) {
    pos = _pos;
    radius = _radius;
    vertexCount = _vertexCount;
    color = _color;
}

void Transformer::update() {
    
}

void Transformer::draw() {
    ofPath path;
    path.setColor(color);
    
    ofPushMatrix();
    ofTranslate(pos.x, pos.y);
    
    int vertex = vertexCount;
    for (int i = 0, len = 360; i < len; i += len / vertex) {
        path.lineTo(radius * cos(ofDegToRad(i)), radius * sin(ofDegToRad(i)));
    }
    
    path.draw();
    ofPopMatrix();
}
