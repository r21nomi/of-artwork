//
//  Line.cpp
//  Pattern7
//
//  Created by Ryota Takemoto on 2016/12/03.
//
//

#include "Line.hpp"

Line::Line(ofPoint _position, float _radius, ofColor _color, ofColor _maskColor, int _bold, float _speed) : PatternItem(_position, ofPoint(0, 0)) {
    radius = _radius;
    lineRadius = radius * 2;
    color = _color;
    maskColor = _maskColor;
    bold = _bold;
    margin = bold * 8;
    speed = _speed;
    
    // FIXME: GL_RGBAだとofApp.cppで設定した背景と色が異なってしまうので、別のcolorModeに変更する
    fbo.allocate(_radius * 2, _radius * 2, GL_RGBA);
    
    int x = 0;
    for (int y = 0, height = lineRadius * 2; y < height; y += (bold + margin)) {
        points.push_back(new ofPoint(x, y));
    }
}

void Line::update() {
    float y = lineRadius * 2;
    for (ofPoint *point : points) {
        if (point->y < y) {
            y = point->y;
        }
    }
    for (ofPoint *point : points) {
        point->y += speed;
        
        if (point->y > lineRadius * 2) {
            point->y = y - margin;
        }
    }
}

void Line::draw() {
    ofPushMatrix();
    ofTranslate(currentPosition.x, currentPosition.y);
    
    ofSetColor(maskColor);
    ofFill();
    fbo.begin();
    // 0からにしないとうまくmaskされない
    ofDrawRectangle(0, 0, radius * 2, radius * 2);
    
    ofSetColor(color);
    for (ofPoint *point : points) {
        ofPushMatrix();
        ofTranslate(point->x, point->y);
        // FIXME: 角度を変えると描画sれる位置がずれてしまうので修正
        ofRotate(-45);
        ofDrawRectangle(0, 0, lineRadius * 2, bold);
        ofPopMatrix();
    }
    
    fbo.end();
    fbo.draw(-radius, -radius);
    ofPopMatrix();
}

void Line::setMaskColor(ofColor color) {
    maskColor = color;
}
