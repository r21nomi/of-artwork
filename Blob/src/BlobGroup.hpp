//
//  BlobGroup.hpp
//  BlobGroup
//
//  Created by 新家 亮太 on 2016/09/22.
//
//

#ifndef BlobGroup_hpp
#define BlobGroup_hpp

#include "ofMain.h"
#include "Blob.hpp"

class BlobGroup{
public:
    BlobGroup(vector<Blob*> _blobs);
    void update();
    void draw();
    
    vector<Blob*> blobs;
};

#endif /* BlobGroup_hpp */
