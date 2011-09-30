#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

	ofSetVerticalSync(true);
	ofSetFrameRate(60);
	ofBackground(66,66,66);
	
	//initialize the video grabber
	vidGrabber.setVerbose(true);
	vidGrabber.initGrabber(320,240);

	//store the width and height for convenience
	int width = vidGrabber.getWidth();
	int height = vidGrabber.getHeight();
	
	//add one vertex and one color point to the mesh for each pixel
	
	//set the indecies of the triangles. this can be tricky!
	
	//this is an annoying thing that is used to flip the camera
	cam.setScale(1,-1,1);
	
	//this determines how much we push the meshes out
	extrusionAmount = 300.0;
}

//--------------------------------------------------------------
void testApp::update(){
	//grab a new frame
	vidGrabber.grabFrame();
	
	//update the mesh if we have a new frame
	if (vidGrabber.isFrameNew()){
		
		// Pseudocode:
		
		// for every pixel in the camera image
		// 		get the brightness of the pixel
		//		get the corresponding mesh vertex
		// 		update the vertexes' z-value using the pixel's brightness value, 
		// 		scale this value by extrusionAmount
		// 		update the colour of the mesh vertex using the sampled pixel colour
	}
}

//--------------------------------------------------------------
void testApp::draw(){
	//we have to disable depth testing to draw the video frame
	glDisable(GL_DEPTH_TEST);	
	vidGrabber.draw(20,20);
	
	//but we want to enable it to show the mesh
	glEnable(GL_DEPTH_TEST);
	
	cam.begin();		

	//You can either draw the mesh or the wireframe
	// mainMesh.drawWireframe();
	mainMesh.drawFaces();
	cam.end();
	
	//draw framerate for fun
	ofSetColor(255);
	string msg = "fps: " + ofToString(ofGetFrameRate(), 2);
	ofDrawBitmapString(msg, 10, 20);
	
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
	switch(key) {
		case 'f':
			ofToggleFullscreen();
			break;
	}

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
	
	//alot like the previous example...
	
	//let's move the camera when you move the mouse
	float rotateAmount = ofMap(ofGetMouseY(), 0, ofGetHeight(), 0, 360);

	//move the camera around the mesh
	ofVec3f camDirection(0,0,1);
	ofVec3f centre(vidGrabber.getWidth()/2.f,vidGrabber.getHeight()/2.f, 255/2.f);
	ofVec3f camDirectionRotated = camDirection.rotated(rotateAmount, ofVec3f(1,0,0));
	ofVec3f camPosition = centre + camDirectionRotated * extrusionAmount;
	
	cam.setPosition(camPosition);
	cam.lookAt(centre);
	
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