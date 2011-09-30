#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	//just set up the openFrameworks stuff
    ofSetFrameRate(60);
    ofSetVerticalSync(true);
    ofBackground(255);

}

//--------------------------------------------------------------
void testApp::update(){
	//each frame move the points back in z a few units so they appear to 'sink'
}

//--------------------------------------------------------------
void testApp::draw(){
	
    //begin a triangle strip shape
    glBegin(GL_TRIANGLE_STRIP);
	for(int i = 1; i < points.size(); i++){
		
		//find this point and the next point
		
		//get the direction from one to the next. 
		//the ribbon should fan out from this direction

		//get the distance from one point to the next
		
		//get the normalized direction. normalized vectors always have a length of one
		//and are really useful for representing directions as opposed to something with length
		
		//find both directions to the left and to the right 
		
		//use the map function to determine the distance.
		//the longer the distance, the narrower the line. 
		//this makes it look a bit like brush strokes

		//calculate the points to the left and to the right
		//by extending the current point in the direction of left/right by the length
		
		//add these points to the triangle strip
	}
    
	//end the shape
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
	//when the mouse is moved add it as a point
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