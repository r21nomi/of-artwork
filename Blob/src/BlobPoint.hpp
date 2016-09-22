//
//  BlobPoint.hpp
//  Blob
//
//  Created by 新家 亮太 on 2016/09/22.
//
//

#ifndef BlobPoint_hpp
#define BlobPoint_hpp

#include "ofMain.h"

class BlobPoint {
public:
    BlobPoint(ofPoint pos, float velocityX, float velocityY);
    void update();
    ofPoint getPoint();
    void setPoint(ofPoint pos);
    
private:
    ofPoint pos;
    float velocityX;
    float velocityY;
};

#endif /* BlobPoint_hpp */
