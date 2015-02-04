#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

#ifndef FARNE_USE_CAMERA
    videoSource.loadMovie("Godard.mov");
    videoSource.play();
#endif
#ifdef FARNE_USE_CAMERA
    videoSource.setDesiredFrameRate(30);
    videoSource.initGrabber(640, 480);
#endif

    flowSolver.setup(videoSource.getWidth(), videoSource.getHeight(), 0.35, 5, 5, 1, 3, 2.25, false, false);

    ofEnableAlphaBlending();
    ofSetBackgroundAuto(true);
    ofBackground(0);

    ofSetColor(255,150);
    //ofSetWindowShape(videoSource.getWidth(), videoSource.getHeight());
    ofSetLineWidth(0.8);

}

//--------------------------------------------------------------
void ofApp::update() {
    videoSource.update();
    //if (ofGetElapsedTimeMillis()%2==0) {
        if(videoSource.isFrameNew()) {
            flowSolver.update(videoSource);
        }
    //}
}

//--------------------------------------------------------------
void ofApp::draw() {

    ofSetColor(0);
    ofFill();
    ofRectangle(0,0,ofGetWidth(),ofGetHeight());


    ofSetColor(255, 255, 255);

    if (drawCam) {
            videoSource.draw(videoSource.getWidth()*2, 0, -videoSource.getWidth()*2, videoSource.getHeight()*2);
    }
    //flowSolver.drawColored(videoSource.getWidth(), videoSource.getHeight(), 10, 3);

    if (drawVectors) {
        flowSolver.drawFlipped(videoSource.getWidth()*2, videoSource.getHeight()*2, -3, 4);
    }

    if (drawMesh) {
            mesh = flowSolver.fillMeshFlipped(videoSource.getWidth()*2, videoSource.getHeight()*2, 10);



            easyCam.begin();
            ofPushMatrix();

            ofTranslate(-ofGetWidth()/2 +5, -ofGetHeight()/2 - 115);
            /*
            image.setFromPixels(videoSource.getPixels(),videoSource.getWidth(), videoSource.getHeight(), OF_IMAGE_COLOR);

            for (int i = 0; i < mesh.getVertices().size(); i++) {
                ofVec3f vertexxx = mesh.getVertex(i);
                ofColor c = image.getColor(image.getWidth()-(vertexxx.x)/2, image.getHeight()-(vertexxx.y)/2);
                mesh.addColor(c);
            }
            */

            mesh.draw();
            ofPopMatrix();
            easyCam.end();

    }
    /*
    stringstream m;
    m << "fps " << ofGetFrameRate() << endl
    << "pyramid scale: " << flowSolver.getPyramidScale() << " p/P" << endl
    << "pyramid levels: " << flowSolver.getPyramidLevels() << " l/L" << endl
    << "averaging window size: " << flowSolver.getWindowSize() << " w/W" << endl
    << "iterations per level: " << flowSolver.getIterationsPerLevel() << " i/I" << endl
    << "expansion area: " << flowSolver.getExpansionArea() << " a/A" << endl
    << "expansion sigma: " << flowSolver.getExpansionSigma() << " s/S" << endl
    << "flow feedback: " << flowSolver.getFlowFeedback() << " f/F" << endl
    << "gaussian filtering: " << flowSolver.getGaussianFiltering() << " g/G";

    ofDrawBitmapString(m.str(), 20, 20);*/

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
    /*if(key == 'p') {
        flowSolver.setPyramidScale(ofClamp(flowSolver.getPyramidScale() - 0.01,0.0,1.0));
    } else if(key == 'P') {
        flowSolver.setPyramidScale(ofClamp(flowSolver.getPyramidScale() + 0.01,0.0,1.0));
    } else if(key == 'l') {
        flowSolver.setPyramidLevels(MAX(flowSolver.getPyramidLevels() - 1,1));
    } else if(key == 'L') {
        flowSolver.setPyramidLevels(flowSolver.getPyramidLevels() + 1);
    } else if(key == 'w') {
        flowSolver.setWindowSize(MAX(flowSolver.getWindowSize() - 1,1));
    } else if(key == 'W') {
        flowSolver.setWindowSize(flowSolver.getWindowSize() + 1);
    } else if(key == 'i') {
        flowSolver.setIterationsPerLevel(MAX(flowSolver.getIterationsPerLevel() - 1,1));
    } else if(key == 'I') {
        flowSolver.setIterationsPerLevel(flowSolver.getIterationsPerLevel() + 1);
    } else if(key == 'a') {
        flowSolver.setExpansionArea(MAX(flowSolver.getExpansionArea() - 2,1));
    } else if(key == 'A') {
        flowSolver.setExpansionArea(flowSolver.getExpansionArea() + 2);
    } else if(key == 's') {
        flowSolver.setExpansionSigma(ofClamp(flowSolver.getExpansionSigma() - 0.01,0.0,10.0));
    } else if(key == 'S') {
        flowSolver.setExpansionSigma(ofClamp(flowSolver.getExpansionSigma() + 0.01,0.0,10.0));
    } else if(key == 'f') {
        flowSolver.setFlowFeedback(false);
    } else if(key == 'F') {
        flowSolver.setFlowFeedback(true);
    } else if(key == 'g') {
        flowSolver.setGaussianFiltering(false);
    } else if(key == 'G') {
        flowSolver.setGaussianFiltering(true);
    }
    */
    if  (key == '1') {
        drawCam = !drawCam;
    } else if  (key == '2') {
        drawVectors = !drawVectors;
    } else if  (key == '3') {
        drawMesh = !drawMesh;
    } else if  (key == '4') {
        easyCam.reset();
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

