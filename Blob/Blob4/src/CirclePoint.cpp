//
//  CirclePoint.cpp
//  Blob_3
//
//  Created by 新家 亮太 on 2016/10/31.
//
//

#include "CirclePoint.hpp"

CirclePoint::CirclePoint(ofPoint _location, ofPoint _targetLocation) {
    location = _location;
    originalLocation = _location;
    targetLocation = _targetLocation;
}

ofPoint CirclePoint::getLocation() {
    return location;
}

ofPoint CirclePoint::getTargetLocation() {
    return targetLocation;
}

void CirclePoint::setLocation(ofPoint _location) {
    location = _location;
}
