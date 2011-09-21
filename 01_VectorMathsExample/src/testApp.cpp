#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	//just set up the openFrameworks stuff
    
    ofSetFrameRate(60);
    ofSetVerticalSync(true);
    ofBackground(255);
    points.clear();
}

//--------------------------------------------------------------
void testApp::update(){
	//TODO: do the 3d stuff
    for(int i = 0; i < points.size(); i++){
    	points[i].z -= 4;
    }
}

//--------------------------------------------------------------
void testApp::draw(){
	
    
    glBegin(GL_TRIANGLE_STRIP);
    
    glColor3f(0,0,0);
    
    if(points.size() > 2){
        for(int i = 0; i < points.size(); i++){
            ofVec3f thisPoint = points[i];
            ofVec3f nextPoint = points[i+1];
            ofVec3f direction = (nextPoint - thisPoint);
            float distance = direction.length();
            ofVec3f unitDirection = direction.normalized();
            ofVec3f toTheLeft = unitDirection.getRotated(-90, ofVec3f(0,0,1));
            ofVec3f toTheRight = unitDirection.getRotated(90, ofVec3f(0,0,1));
            float thickness = ofMap(distance, 0, 50, 20, 2, true);
            ofVec3f leftPoint = thisPoint+toTheLeft*thickness;
            ofVec3f rightPoint = thisPoint+toTheRight*thickness;
            glVertex3f(leftPoint.x, leftPoint.y, leftPoint.z);
            glVertex3f(rightPoint.x, rightPoint.y, rightPoint.z);
        }
    }
    
    glEnd();
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
	
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
	ofVec3f mousePoint(x,y,0);
    points.push_back(mousePoint);
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}