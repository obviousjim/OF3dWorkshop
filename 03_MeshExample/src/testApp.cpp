#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

	ofSetVerticalSync(true);
	ofSetFrameRate(60);
	
	// this uses depth information for occlusion
	// rather than always drawing things on top of each other
	// glEnable(GL_DEPTH_TEST);
	
	// this sets the camera's distance from the object

	
	bNewFrame = false;
	
	vidGrabber.setVerbose(true);
	vidGrabber.initGrabber(320,240);

	

	// dots
	
	// todo: just add the points.
	
	// wireframes
	

	
	int width = vidGrabber.getWidth();
	int height = vidGrabber.getHeight();

	
	
	for (int y = 0; y < height; y++){
		for (int x = 0; x<width; x++){
			mainMesh.addVertex(ofPoint(x,y,0));						// mesh index = x + y*width
																		// this replicates the pixel array within the camera bitmap...
		}
	}
	
	for (int y = 0; y<height-1; y++){
		for (int x=0; x<width-1; x++){
			mainMesh.addIndex(x+y*width);				// 0
			mainMesh.addColor(ofFloatColor());			// placeholder for colour data
			mainMesh.addIndex((x+1)+y*width);			// 1
			mainMesh.addColor(ofFloatColor());			// placeholder for colour data
			mainMesh.addIndex(x+(y+1)*width);			// 10
			mainMesh.addColor(ofFloatColor());			// placeholder for colour data
			
			mainMesh.addIndex((x+1)+y*width);			// 1
			mainMesh.addColor(ofFloatColor());			// placeholder for colour data
			mainMesh.addIndex(x+(y+1)*width);			// 10
			mainMesh.addColor(ofFloatColor());			// placeholder for colour data
			mainMesh.addIndex((x+1)+(y+1)*width);		// 11
			mainMesh.addColor(ofFloatColor());			// placeholder for colour data
		}
	}
	
	
	cam.setScale(1,-1,1);
}

//--------------------------------------------------------------
void testApp::update(){
	vidGrabber.grabFrame();
	bNewFrame = vidGrabber.isFrameNew();
	
	float depth = 300;
	
	if (bNewFrame){
		
		for (int i=0; i<vidGrabber.getWidth()*vidGrabber.getHeight(); i++){

			ofFloatColor sampleColor(vidGrabber.getPixels()[i*3]/255.f,				// r
									 vidGrabber.getPixels()[i*3+1]/255.f,			// g
									 vidGrabber.getPixels()[i*3+2]/255.f);			// b
			
			
			ofVec3f tmpVec = mainMesh.getVertex(i);
			tmpVec.z = sampleColor.getBrightness() * depth;
			mainMesh.setVertex(i, tmpVec);

			mainMesh.setColor(i, sampleColor);
		}
	
	}

	
}

//--------------------------------------------------------------
void testApp::draw(){
	ofClear(66,66,66);
	
	glDisable(GL_DEPTH_TEST);	
	vidGrabber.draw(20,20);

	glEnable(GL_DEPTH_TEST);
	cam.begin();		
		
	// mainMesh.drawWireframe();
	mainMesh.drawFaces();
	cam.end();
	
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
	float rotateAmount = ofMap(ofGetMouseY(), 0, ofGetHeight(), 0, 360);
	float distance =300.f;
	
	
	ofVec3f camDirection(0,0,1);
	
	ofVec3f centre(vidGrabber.getWidth()/2.f,vidGrabber.getHeight()/2.f, 255/2.f);
	
	
	ofVec3f camDirectionRotated = camDirection.rotated(rotateAmount, ofVec3f(1,0,0));
	ofVec3f camPosition = centre + camDirectionRotated * distance;
	
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