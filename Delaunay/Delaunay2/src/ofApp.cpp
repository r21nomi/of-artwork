#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofEnableSmoothing();
    ofBackground(0);
    
    vertexPoints.push_back(new VertexPoint());
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofNoFill();
    ofSetLineWidth(4);
    
    vertexPoints[0]->update(mouseX, mouseY);
    
    for (int i = 0; i < delaunay.triangleMesh.getNumIndices(); i++) {
        int id = delaunay.triangleMesh.getIndex(i);
        ofVec2f v1 = delaunay.triangleMesh.getVertex(id);
        
//        if (ofDist(v1.x, v1.y, mouseX, mouseY) < 200) {
        if (i == 0) {
//            vertexPoints[i]->update(mouseX, mouseY);
            ofVec2f v = vertexPoints[0]->getVec2f(mouseX, mouseY);
            delaunay.setPointAtIndex(ofPoint(v.x, v.y), id);
        }
    }
    
    delaunay.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
    delaunay.addPoint(ofPoint(x, y));
    delaunay.triangulate();
//    vertexPoints.push_back(new VertexPoint());
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
