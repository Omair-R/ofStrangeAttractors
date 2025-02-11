#pragma once
#include "ofMain.h"
#include "Artists.h"
#include "Attractors.h"

class ofAbstractAttractorApp : public ofBaseApp{

public:
	virtual void setup() =0;
	virtual void update() = 0;
	virtual void draw() = 0;

	void keyPressed(int key) {}
	void keyReleased(int key) {}
	void mouseMoved(int x, int y) {}
	void mouseDragged(int x, int y, int button) {}
	void mousePressed(int x, int y, int button) {}
	void mouseReleased(int x, int y, int button) {}
	void mouseEntered(int x, int y) {}
	void mouseExited(int x, int y) {}
	void windowResized(int w, int h) {}
	void dragEvent(ofDragInfo dragInfo) {}
	void gotMessage(ofMessage msg) {}

};

