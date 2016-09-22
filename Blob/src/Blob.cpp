//
//  Blob.cpp
//  Blob
//
//  Created by 新家 亮太 on 2016/09/22.
//
//

#include "Blob.hpp"

Blob::Blob(ofPoint _pos, ofColor _color, float _radius, float _blobVelocity) {
    pos = _pos;
    color = _color;
    radius = _radius;
    blobVelocity = _blobVelocity;
    
    for (int i = 0, len = 360 + STEP * 3; i < len; i += STEP) {
        BlobPoint *p = new BlobPoint(
                                     ofPoint(radius * cos(ofDegToRad(i)), radius * sin(ofDegToRad(i))),
                                     ofRandom(-abs(blobVelocity), abs(blobVelocity)),
                                     ofRandom(-abs(blobVelocity), abs(blobVelocity))
                                     );
        points.push_back(p);
    }
}

void Blob::update() {
    int index = 0;
    for (BlobPoint *bp : points) {
        if (index == points.size() - 2) {
            bp->setPoint(points[1]->getPoint());
        } else {
            bp->update();
        }
        index++;
    }
}

void Blob::draw() {
    ofPushMatrix();
    ofTranslate(pos.x, pos.y);
    
    ofPath path;
    
    for (BlobPoint *pt : points) {
        path.curveTo(pt->getPoint());
    }
    
    path.close();
    path.setFilled(true);
    path.setFillColor(color);
    path.setStrokeColor(ofColor(0, 0));
    path.setStrokeWidth(1);
    path.draw();
    
    ofPopMatrix();
}