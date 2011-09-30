#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	
	//setup oF stuff
	ofSetFrameRate(60);
	ofSetVerticalSync(true);
	ofBackground(50, 50, 50, 0);

	//we need to call this for textures to work on models
	
	//this makes sure that the back of the model doesn't show through the front

	//now we load our model
	
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    ofSetColor(255, 255, 255, 255);
	
	//first let's just draw the model with the model object
	drawWithModel();
	
	//then we'll learn how to draw it manually so that we have more control over the data
	drawWithMesh();
}

//draw the model the built-in way
void testApp::drawWithModel(){
	
	//get the position of the model

	//save the current view
	
	//center ourselves there
	
	//draw the model
	
	//restore the view position
}

//draw the model manually
void testApp::drawWithMesh(){

	//get the model attributes we need
	ofVec3f scale, position;
	float normalizedScale;
	ofVboMesh mesh;
	ofTexture texture;
	ofMaterial material;
	
	//translate and scale based on the positioning. 
	
	//modify mesh
	float liquidness = 5;
	float amplitude = 2;
	float speedDampen = 5;		
		
	//draw the model manually

	//restore the view

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