//
//  VertexPoint.cpp
//  Transform
//
//  Created by 新家 亮太 on 2016/11/15.
//
//

#include "VertexPoint.hpp"

VertexPoint::VertexPoint(ofPoint _location, ofPoint _targetLocation) {
    location = _location;
    originalLocation = _location;
    targetLocation = _targetLocation;
}

ofPoint VertexPoint::getLocation() {
    return location;
}

ofPoint VertexPoint::getOriginalLocation() {
    return originalLocation;
}

ofPoint VertexPoint::getTargetLocation() {
    return targetLocation;
}

void VertexPoint::setLocation(ofPoint _location) {
    location = _location;
}
