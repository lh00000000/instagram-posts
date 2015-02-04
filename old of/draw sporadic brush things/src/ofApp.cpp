#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    ofEnableAntiAliasing();
    ofSetBackgroundAuto(false);
    ofBackground(0);
    ofSetFrameRate(60);
    ofEnableAlphaBlending();

}

//--------------------------------------------------------------
void ofApp::update()
{

}

//--------------------------------------------------------------
void ofApp::draw()
{
    if (button)
    {
        ofBackground(0);
    }

    float randomColor = ofRandom(50, 255);
    ofSetColor(randomColor);

    if (isLeftMousePressed)
    {
        ofVec2f mousePos(mouseX, mouseY);

        int numTriangles = 10;
        int minOffset = 5;
        int maxOffset = 170;
        int alpha = 150;

        for (int t=0; t<numTriangles; ++t)
        {
            float offsetDistance = ofRandom(minOffset, maxOffset);

            ofVec2f p1(0, 5.0);
            ofVec2f p2(30,0);
            ofVec2f p3(0, -5.0);

            float rotation = ofRandom(360);
            p1.rotate(rotation);
            p2.rotate(rotation);
            p3.rotate(rotation);

            ofVec2f triangleOffset(offsetDistance, 0.0);
            triangleOffset.rotate(rotation);


            p1 += mousePos + triangleOffset;
            p2 += mousePos + triangleOffset;
            p3 += mousePos + triangleOffset;



            ofSetColor(255, ofRandom(0,150));
            ofTriangle(p1,p2,p3);
        }

    }


}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
    if (key == 's')
    {
        ofSaveScreen("savedscridsaopdfj"+ofGetTimestampString()+".png");
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y )
{

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button)
{

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{
    if (button == OF_MOUSE_BUTTON_LEFT) isLeftMousePressed = true;
    if (button == OF_MOUSE_BUTTON_RIGHT) button = true;

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button)
{
    if (button == OF_MOUSE_BUTTON_LEFT) isLeftMousePressed = false;
    if (button == OF_MOUSE_BUTTON_RIGHT) button = false;
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h)
{

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg)
{

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo)
{

}
