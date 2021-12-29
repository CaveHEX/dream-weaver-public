#include "ofMain.h"
#include "ofApp.h"

#if (_MSC_VER >= 1915)
#define no_init_all deprecated
#endif

#define BOOST_CONFIG_SUPPRESS_OUTDATED_MESSAGE

//========================================================================
int main( ){
	ofGLFWWindowSettings settings;
	settings.setGLVersion(3, 2);
	settings.setSize(1000, 1000);
	ofCreateWindow(settings);
	// ofSetupOpenGL(1000, 1000, OF_WINDOW);

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new ofApp());
}
