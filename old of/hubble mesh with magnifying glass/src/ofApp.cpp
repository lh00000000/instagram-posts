#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
    image.loadImage("stars.png");
    image.resize(200,200);

    mesh.setMode(OF_PRIMITIVE_LINES);

    float intensityThreshold = 150.0;
    int w = image.getWidth();
    int h = image.getHeight();

    for (int x=0; x<w; ++x) {
        for (int y=0; y<h; ++y) {
            ofColor c = image.getColor(x,y);
            float intensity = c.getLightness();
            if (intensity >= intensityThreshold) {
                float saturation = c.getSaturation();
                float z = ofMap(saturation, 0, 255, -100,100);
                ofVec3f pos(x*4, y*4, z);
                mesh.addVertex(pos);
                mesh.addColor(c);
            }
        }
    }

    float connectionDistance = 30;
    int numVerts = mesh.getNumVertices();
    for (int a = 0; a<numVerts; ++a) {
        ofVec3f verta = mesh.getVertex(a);
        for ( int b=a+1; b <numVerts; ++b) {
            ofVec3f vertb = mesh.getVertex(b);
            float distance = verta.distance(vertb);
            if (distance <= connectionDistance) {
                mesh.addIndex(a);
                mesh.addIndex(b);
            }
        }
    }

    mouseDisplacement = false;
    meshCopy = mesh;

}

//--------------------------------------------------------------
void ofApp::update() {
    if (mouseDisplacement) {
        ofVec3f mouse(mouseX, ofGetWidth()-mouseY, 0);
        for (int i = 0; i<mesh.getNumVertices(); ++i) {
            ofVec3f vertex = meshCopy.getVertex(i);
            float distanceToMouse = mouse.distance(vertex);

            float displacement = ofMap(distanceToMouse, 0, 400, 300.0, 0, true);
            ofVec3f direction = vertex - mouse;
            direction.normalize();
            ofVec3f displacedVertex = vertex + displacement*direction;
            mesh.setVertex(i, displacedVertex);
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw() {
    ofBackground(0);
    easyCam.begin();
    ofPushMatrix();

    ofTranslate(-ofGetWidth()/3, -ofGetHeight()/2);
    //ofRotateX(2*PI);
    mesh.draw();
    ofPopMatrix();
    easyCam.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
    if (key == 'm') {
        mouseDisplacement = !mouseDisplacement;
        mesh = meshCopy;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}
