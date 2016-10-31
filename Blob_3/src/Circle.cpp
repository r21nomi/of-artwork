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
    
    float angleStep = 1;
    
    for (float angle = 0, len = 360; angle < 360; angle += angleStep) {
        float radian = ofDegToRad(angle);
        float ex = radius * cos(radian);
        float ey = radius * sin(radian);
        float nr = radius - ofMap(ofNoise(ex * 0.008 + offset.x, ey * 0.008 + offset.y), 0, 1, 0, radius / 5);
        float nx = nr * cos(radian);
        float ny = nr * sin(radian);
        originalVertexs.push_back(new CirclePoint(ofPoint(nx, ny), ofPoint(0, 0)));
    }
    
//    currentVertexs.emplace_back(originalVertexs);
}

void Circle::update() {
    for (CirclePoint *vertex : currentVertexs) {
        
    }
}

void Circle::draw() {
    ofPushMatrix();
    ofTranslate(location.x, location.y);
    ofBeginShape();
    
    float angleStep = 1;
    for (CirclePoint *vertex : originalVertexs) {
        ofVertex(vertex->getLocation().x, vertex->getLocation().y);
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
