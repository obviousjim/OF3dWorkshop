#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

	ofBackground(50, 50, 50, 0);

    ofDisableArbTex();
	glEnable(GL_DEPTH_TEST);
	
    //some model / light stuff
    glShadeModel(GL_SMOOTH);
    light.enable();
	model.loadModel("squirrel/NewSquirrel.3ds");
	model.setPosition(ofGetWidth()*.5, ofGetHeight() * 0.75, 0);
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    ofSetColor(255, 255, 255, 255);
	
	//drawWithModel();
	drawWithMesh();
}

void testApp::drawWithModel(){
	ofVec3f sceneCenter = model.getSceneCenter();
	ofVec3f position = model.getPosition();

	ofPushMatrix();
	ofTranslate(position);
	ofRotate(-ofGetMouseX(), 0, 1, 0);
	ofRotate(90,1,0,0);
	ofTranslate(-position);
	
	model.drawFaces();
	
    ofPopMatrix();
	
}

void testApp::drawWithMesh(){

	ofVec3f sceneCenter = model.getSceneCenter();
	ofVec3f scale = model.getScale();
	ofVec3f position = model.getPosition();
	
	float normalizedScale = model.getNormalizedScale();
	
	ofVboMesh mesh = model.getMesh(0);
	ofTexture tex = model.getTextureForMesh(0);
	ofMaterial mat = model.getMaterialForMesh(0);
	
	glPushAttrib(GL_ALL_ATTRIB_BITS);
    glPushClientAttrib(GL_CLIENT_ALL_ATTRIB_BITS);
    glEnable(GL_NORMALIZE);
	
    ofPushMatrix();
	
	//cout << sceneCenter << endl;
	
	ofTranslate(position);
	ofRotate(-mouseX, 0, 1, 0);
	ofRotate(90,1,0,0);
	
	
	ofScale(normalizedScale, normalizedScale, normalizedScale);
	ofScale(scale.x,scale.y,scale.z);
	
	tex.bind();
	mat.begin();
	mesh.drawWireframe();
	mat.end();
	tex.unbind();
	
	ofPopMatrix();
	
	glPopAttrib();
	glPopClientAttrib();
	
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