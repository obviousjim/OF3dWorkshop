#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

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
			mainMesh.addColor(ofFloatColor());
			mainMesh.addIndex((x+1)+y*width);			// 1
			mainMesh.addColor(ofFloatColor());
			mainMesh.addIndex(x+(y+1)*width);			// 10
			mainMesh.addColor(ofFloatColor());
			
			mainMesh.addIndex((x+1)+y*width);			// 1
			mainMesh.addColor(ofFloatColor());
			mainMesh.addIndex(x+(y+1)*width);			// 10
			mainMesh.addColor(ofFloatColor());
			mainMesh.addIndex((x+1)+(y+1)*width);		// 11
			mainMesh.addColor(ofFloatColor());
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
		tmpVec.z = - grayImage.getPixels()[i];
		mainMesh.setVertex(i, tmpVec);
		ofColor tmpColor = ofFloatColor(colorImg.getPixels()[i*3]/255.f,colorImg.getPixels()[i*3+1]/255.f,colorImg.getPixels()[i*3+2]/255.f);
		mainMesh.setColor(i, tmpColor);
	}
	
}

//--------------------------------------------------------------
void testApp::draw(){
	ofClear(66,66,66);
	
	colorImg.draw(20,20);
	grayImage.draw(20+320+20,20);

	ofPushMatrix();
	glTranslatef(100, 100, 0);
	ofPushStyle();
	ofSetColor(255, 255, 255);
	mainMesh.drawWireframe();
	ofPopStyle();
	ofPopMatrix();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

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