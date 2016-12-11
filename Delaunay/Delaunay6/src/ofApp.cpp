#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofEnableSmoothing();
    
    camera.setDesiredFrameRate(30);
    camera.initGrabber(ofGetWidth(), ofGetHeight());
    
    vertexPoints.push_back(new VertexPoint(ofVec2f(0, 0), ofColor(ofRandom(255), ofRandom(255), ofRandom(255)), false));
    vertexPoints.push_back(new VertexPoint(ofVec2f(ofGetWidth(), 0), ofColor(ofRandom(255), ofRandom(255), ofRandom(255)), false));
    vertexPoints.push_back(new VertexPoint(ofVec2f(ofGetWidth(), ofGetHeight()), ofColor(ofRandom(255), ofRandom(255), ofRandom(255)), false));
    vertexPoints.push_back(new VertexPoint(ofVec2f(0, ofGetHeight()), ofColor(ofRandom(255), ofRandom(255), ofRandom(255)), false));
    
    for (int i = 0, len = 1400; i < len; i++) {
        ofColor color = ofColor(ofRandom(255), ofRandom(255), ofRandom(255));
        vertexPoints.push_back(new VertexPoint(ofVec2f(ofRandom(ofGetWidth()), ofRandom(ofGetHeight())), color, true));
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    camera.update();
    
    if (camera.isFrameNew()) {
        ofPixels* pixels = &camera.getPixels();
        
        delaunay.reset();
        mesh.clear();
        
        // Add point
        for (VertexPoint* point : vertexPoints) {
            point->update(mouseX, mouseY);
            delaunay.addPoint(point->getLocation());
        }
        delaunay.triangulate();
        
        // Add color
        // Referenced this article https://www.honeycomb-lab.co.jp/lab/blog/?p=1030
        for (int i = 0; i < delaunay.triangleMesh.getNumIndices() / 3; i++) {
            int idx1 = delaunay.triangleMesh.getIndex(i * 3);
            int idx2 = delaunay.triangleMesh.getIndex(i * 3 + 1);
            int idx3 = delaunay.triangleMesh.getIndex(i * 3 + 2);
            
            ofVec2f v1 = delaunay.triangleMesh.getVertex(idx1);
            ofVec2f v2 = delaunay.triangleMesh.getVertex(idx2);
            ofVec2f v3 = delaunay.triangleMesh.getVertex(idx3);
            
            ofVec2f gp = (v1 + v2 + v3) / 3.0;
            ofColor color = pixels->getColor((int)gp.x, (int)gp.y);
            
            mesh.addVertex(v1);
            mesh.addVertex(v2);
            mesh.addVertex(v3);
            
            mesh.addColor(color);
            mesh.addColor(color);
            mesh.addColor(color);
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofFill();
    mesh.draw();
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
    ofColor color = ofColor(ofRandom(255), ofRandom(255), ofRandom(255));
    vertexPoints.push_back(new VertexPoint(ofVec2f(x, y), color, true));
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
