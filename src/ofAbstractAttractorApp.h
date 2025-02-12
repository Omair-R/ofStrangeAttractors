#pragma once
#include "ofMain.h"
#include "Artists.h"
#include "Attractors.h"
#include "Common/AttUtils.h"
class ofAbstractAttractorApp : public ofBaseApp{

public:
	virtual void setup() =0;
	virtual void update() = 0;
	virtual void draw() = 0;

	void keyPressed(int key) {
		ofImage  img;
		if (key == 'x') {
			img.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
			img.save(att::generate_random_string(14)+".png");
		}
	}
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

