#include "ofApp.h"

#include <boost/filesystem.hpp>
#include <iostream>

//--------------------------------------------------------------
void ofApp::setup()
{
	ofSetFrameRate(24);

	reset();
}

//--------------------------------------------------------------
void ofApp::update()
{
	++m_frame;
	m_scene->update();
}

//--------------------------------------------------------------
void ofApp::draw()
{
	ofBackground(ofColor::black);

	m_scene->render();

	record();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
	std::cout << key << "\n";
	switch ( key )
	{
	case 0x72: reset();                    break; // R
	case 0x73: screenshot();               break; // S
	case 0x6D: m_recording = !m_recording; break; // M
	default:                               break;
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y )
{

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button)
{

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button)
{

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y)
{

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y)
{

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h)
{

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg)
{

}

void ofApp::reset()
{
	m_scene = std::make_unique<scene_t>();
}

void ofApp::screenshot()
{
	auto base_path = boost::filesystem::path{".\\out\\screenshots\\"};
	auto name = "weaved_" + std::to_string(10000 + rand() % 80000) + ".png";
	base_path += name;

	ofImage screen;
	screen.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
	screen.saveImage(ofFilePath::getAbsolutePath(base_path, false));
}

void ofApp::record()
{
	if ( m_recording == false )
		return;

	auto name = std::to_string(m_frame);
	name = std::string(5 - name.length(), '0') + name;

	auto base_path = boost::filesystem::path{ ".\\out\\movie\\" };
	name = "frm" + name + ".png";
	base_path += name;

	ofImage screen;
	screen.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
	screen.saveImage(ofFilePath::getAbsolutePath(base_path, false));
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo)
{

}
