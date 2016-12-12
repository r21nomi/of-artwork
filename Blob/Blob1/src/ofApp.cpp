#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255);
    
    margin = MARGIN;
    radius = (ofGetWidth() - margin * (HORIZONTAL_BLOB_COUNT + 1)) / HORIZONTAL_BLOB_COUNT / 2;
    
    createBlobGroup();
}

//--------------------------------------------------------------
void ofApp::update(){
    for (BlobGroup *blobGroup : blobGroups) {
        blobGroup->update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    for (BlobGroup *blobGroup : blobGroups) {
        blobGroup->draw();
    }
}

void ofApp::createBlobGroup() {
    blobGroups.clear();
    
    ofColor color1 = ofColor(ofRandom(255), ofRandom(255), ofRandom(255), 160);
    ofColor color2 = ofColor(ofRandom(255), ofRandom(255), ofRandom(255), 160);
    
    for (int x = radius + margin, width = ofGetWidth() + radius; x < width; x += radius * 2 + margin) {
        for (int y = radius + margin, height = ofGetHeight() + radius; y < height; y += radius * 2 + margin) {
            Blob *blob1 = new Blob(ofPoint(x, y), color1, radius, ofRandom(1, 2));
            Blob *blob2 = new Blob(ofPoint(x, y), color2, radius, ofRandom(1, 2));
            vector<Blob*> blobs;
            blobs.push_back(blob1);
            blobs.push_back(blob2);
            
            BlobGroup *blobGroup = new BlobGroup(blobs);
            blobGroups.push_back(blobGroup);
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch (key) {
        case ' ':
            createBlobGroup();
            break;
            
        default:
            break;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
