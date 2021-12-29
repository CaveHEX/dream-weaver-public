#pragma once

#include "ofMain.h"
#include "scene.h"

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// ofApp class : Open Framework boilerplate

class ofApp : public ofBaseApp
{

public:
	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);

	void reset();
	void screenshot();
	void record();

private:
	// Rendering
	bool                     m_recording = false;
	int                      m_frame{0};

	// Current scene
	std::unique_ptr<scene_t> m_scene;
};
