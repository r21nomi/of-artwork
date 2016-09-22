//
//  BlobGroup.cpp
//  BlobGroup
//
//  Created by 新家 亮太 on 2016/09/22.
//
//

#include "BlobGroup.hpp"

BlobGroup::BlobGroup(vector<Blob*> _blobs) {
    blobs = _blobs;
    
//    Blob *blob = new Blob(pos, ofColor(255, 0, 0, 180), radius);
//    blobs.push_back(blob);
//    Blob *blob2 = new Blob(pos, ofColor(0, 0, 255, 180), radius);
//    blobs.push_back(blob2);
}

void BlobGroup::update() {
    for (Blob *blob : blobs) {
        blob->update();
    }
}

void BlobGroup::draw() {
    for (Blob *blob : blobs) {
        blob->draw();
    }
}