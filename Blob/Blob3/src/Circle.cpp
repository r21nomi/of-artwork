//
//  Circle.cpp
//  Blob2
//
//  Created by 新家 亮太 on 2016/10/25.
//
//

#include "Circle.hpp"

Circle::Circle() {
    location = ofPoint(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));
    radius = 50;
    offset = ofPoint(ofRandom(1000), ofRandom(1000));
    velocity = ofRandom(0.1, 0.5);
}

void Circle::update() {
    float angleStep = 1;
    
    vertexs.clear();
    
    float frame = ofGetFrameNum() * 0.1;
    
    for (float angle = 0, len = 360; angle < 360; angle += angleStep) {
        float radian = ofDegToRad(angle);
        float ex = radius * cos(radian);
        float ey = radius * sin(radian);
        float nr = radius - ofMap(ofNoise(ex * 0.008 + offset.x, ey * 0.008 + offset.y), 0, 1, 0, radius / 5);
//        float nx = nr * cos(radian) + cos(frame) * nr * velocity;
//        float ny = nr * sin(radian) + sin(frame) * nr * velocity;
        float nx = nr * cos(radian);
        float ny = nr * sin(radian);
        vertexs.push_back(new ofPoint(nx, ny));
    }
}

void Circle::draw() {
    ofPushMatrix();
    ofTranslate(location.x, location.y);
    ofRotate(ofGetFrameNum() * 5);
    ofBeginShape();
    
    float angleStep = 1;
    for (ofPoint *vertex : vertexs) {
        ofVertex(vertex->x, vertex->y);
    }
    
    ofEndShape(OF_CLOSE);
    ofPopMatrix();
}

ofPoint Circle::getLocation() {
    return location;
}

float Circle::getRadius() {
    return radius;
}
