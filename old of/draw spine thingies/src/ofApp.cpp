#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofEnableAntiAliasing();
    ofEnableAlphaBlending();
    ofEnableBlendMode(OF_BLENDMODE_ADD);
}

//--------------------------------------------------------------
void ofApp::update(){
    if (leftMouseButtonPressed) {
        ofVec2f mousePos(mouseX, mouseY);
        if (lastPoint.distance(mousePos) >= minDifference) {
            currentPolyline.curveTo(mousePos);
            lastPoint = mousePos;
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    ofSetLineWidth(0.5);
    ofSetColor(0);
    for (int i=0; i <polylines.size(); i++) {
        ofPolyline polyline = polylines[i];
        polyline.draw();

        ofSetColor(255,50);
        /*float numPoints = polyline.size();
        float normalLength = 50;
        for (int p=0; p <500; p+=1) {
            ofVec3f point = polyline.getPointAtPercent(p/500.0);
            float floatIndex = p/100.0 * (numPoints-1);
            ofVec3f normal = polyline.getNormalAtIndexInterpolated(floatIndex) * normalLength;
            ofLine(point-normal/2, point+normal/2);
        }*/

        vector<ofVec3f> vertices = polyline.getVertices();
        float numPoints = polyline.size();
        float tangentLength = 300;
        for (int p=0; p<500; p+=1){
            ofVec3f point = polyline.getPointAtPercent(p/500.0);
            float floatIndex = p/500.0 * (numPoints-1);
            ofVec3f tangent = polyline.getTangentAtIndexInterpolated(floatIndex) * tangentLength;
            ofLine(point-tangent/2, point+tangent/2);
        }
    }
    ofSetColor(255,100,0);
    currentPolyline.draw();
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
    if (button == OF_MOUSE_BUTTON_LEFT) {
        leftMouseButtonPressed = true;
        currentPolyline.curveTo(x,y);
        currentPolyline.curveTo(x,y);
        lastPoint.set(x,y);
    }

    if (button == OF_MOUSE_BUTTON_RIGHT) {
        polylines.clear();
    }
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    leftMouseButtonPressed = false;
    currentPolyline.curveTo(x,y);
    polylines.push_back(currentPolyline);
    currentPolyline.clear();
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
