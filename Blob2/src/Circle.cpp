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
}

void Circle::update() {
    ofPoint offset = ofPoint(ofRandom(1000), ofRandom(1000));
    float angleStep = 1;
    
    vertexs.clear();
    for (float angle = 0, len = 360; angle < 360; angle += angleStep) {
        float radian = ofDegToRad(angle);
        float ex = radius * cos(radian);
        float ey = radius * sin(radian);
        float nr = radius - ofMap(ofNoise(ex * 0.01 + offset.x, ey * 0.01 + offset.y), 0, 1, 0, radius / 2);
        float nx = nr * cos(radian);
        float ny = nr * sin(radian);
        vertexs.push_back(new ofPoint(nx, ny));
    }
}

void Circle::draw() {
    ofPushMatrix();
    ofTranslate(location.x, location.y);
    ofBeginShape();
    
    float angleStep = 1;
    for (ofPoint *vertex : vertexs) {
        ofVertex(vertex->x, vertex->y);
    }
    
    ofEndShape(OF_CLOSE);
    ofPopMatrix();
}
