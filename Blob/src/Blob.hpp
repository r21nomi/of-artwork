//
//  Blob.hpp
//  Blob
//
//  Created by 新家 亮太 on 2016/09/22.
//
//

#ifndef Blob_hpp
#define Blob_hpp

#define STEP 30

#include "ofMain.h"
#include "BlobPoint.hpp"

class Blob {
public:
    Blob(ofPoint _pos, ofColor _color, float _radius, float _blobVelocity);
    void update();
    void draw();
    
    ofPoint pos;
    ofColor color;
    float radius;
    float blobVelocity;
    vector<BlobPoint*> points;
};

#endif /* Blob_hpp */
