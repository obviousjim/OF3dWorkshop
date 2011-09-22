#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

	ofSetVerticalSync(true);
	
	// this uses depth information for occlusion
	// rather than always drawing things on top of each other
	// glEnable(GL_DEPTH_TEST);
	
	// this sets the camera's distance from the object
	cam.setDistance(100);

	
	bNewFrame = false;
	
#ifdef _USE_LIVE_VIDEO
	vidGrabber.setVerbose(true);
	vidGrabber.initGrabber(320,240);
#else
	vidPlayer.loadMovie("fingers.mov");
	vidPlayer.play();
#endif

    colorImg.allocate(320,240);
	grayImage.allocate(320,240);
	

	// dots
	
	// todo: just add the points.
	
	// wireframes
	

	
	int width = 320;
	int height = 240;

	for (int y = 0; y < height; y++){
		for (int x = 0; x<width; x++){
			mainMesh.addVertex(ofPoint(x*2,y*2,0));						// mesh index = x + y*width
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
	
}

//--------------------------------------------------------------
void testApp::update(){
#ifdef _USE_LIVE_VIDEO
	vidGrabber.grabFrame();
	bNewFrame = vidGrabber.isFrameNew();
#else
	vidPlayer.update();
	bNewFrame = vidPlayer.isFrameNew();
#endif
	
	if (bNewFrame){
		
	#ifdef _USE_LIVE_VIDEO
			colorImg.setFromPixels(vidGrabber.getPixels(), 320,240);
			
	#else
			colorImg.setFromPixels(vidPlayer.getPixels(), 320,240);
	#endif
		
	grayImage = colorImg;
	
	}

	for (int i=0; i<320*240; i++){
		ofVec3f tmpVec = mainMesh.getVertex(i);
		tmpVec.z = grayImage.getPixels()[i];
		mainMesh.setVertex(i, tmpVec);
		ofColor tmpColor = ofFloatColor(colorImg.getPixels()[i*3]/255.f,colorImg.getPixels()[i*3+1]/255.f,colorImg.getPixels()[i*3+2]/255.f);
		mainMesh.setColor(i, tmpColor);
	}
	
}

//--------------------------------------------------------------
void testApp::draw(){
	ofClear(66,66,66);
	
	glDisable(GL_DEPTH_TEST);	
	colorImg.draw(20,20);
	grayImage.draw(20+320+20,20);

	glEnable(GL_DEPTH_TEST);
	cam.begin();		
	ofRotateX(ofRadToDeg(.5));
	ofRotateY(ofRadToDeg(-.5));
	
	mainMesh.drawWireframe();
	// mainMesh.drawFaces();
	cam.end();
	
	ofSetColor(255);
	string msg = string("Using mouse inputs to navigate ('m' to toggle): ") + (cam.getMouseInputEnabled() ? "YES" : "NO");
	msg += "\nfps: " + ofToString(ofGetFrameRate(), 2);
	ofDrawBitmapString(msg, 10, 20);
	
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
	switch(key) {
		case 'M':
		case 'm':
			if(cam.getMouseInputEnabled()) cam.disableMouseInput();
			else cam.enableMouseInput();
			break;
			
		case 'F':
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