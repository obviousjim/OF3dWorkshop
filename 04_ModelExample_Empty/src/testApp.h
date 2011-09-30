#pragma once

#include "ofMain.h"
#include "ofxAssimpModelLoader.h"

class testApp : public ofBaseApp{

  public:
	void setup();
	void update();
	void draw();

	void keyPressed  (int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);
	
	//this is our model we'll draw	
	ofxAssimpModelLoader model;
	
	ofLight light;
	
	//we added these functions to make it easier to switch between the two methods of drawing
	void drawWithModel();
	void drawWithMesh();
};
