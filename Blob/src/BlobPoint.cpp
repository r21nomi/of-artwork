//
//  BlobPoint.cpp
//  Blob
//
//  Created by 新家 亮太 on 2016/09/22.
//
//

#include "BlobPoint.hpp"

BlobPoint::BlobPoint(ofPoint _pos, float _velocityX, float _velocityY) {
    pos = _pos;
    velocityX = _velocityX;
    velocityY = _velocityY;
}

void BlobPoint::update() {
    pos.x += velocityX * cos(ofGetElapsedTimeMillis() * 0.005) * ofNoise(ofRandom(-10, 10));
    pos.y += velocityY * sin(ofGetElapsedTimeMillis() * 0.005) * ofNoise(ofRandom(-10, 10));
}

ofPoint BlobPoint::getPoint() {
    return pos;
}

void BlobPoint::setPoint(ofPoint _pos) {
    pos = _pos;
}