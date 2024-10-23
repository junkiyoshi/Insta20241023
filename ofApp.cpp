#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(25);
	ofSetWindowTitle("openFrameworks");

	ofBackground(239);
	ofSetColor(0);
	ofSetLineWidth(3);
	ofNoFill();
	ofEnableDepthTest();
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();
	ofRotateX(90);

	auto radius = 250;

	for (int i = 0; i < 20; i++) {

		ofRotateZ(8);

		ofBeginShape();
		for (float theta_deg = 0.5; theta_deg < 180; theta_deg += 0.5) {

			auto phi_deg = ofMap(ofNoise(theta_deg * 0.008 + ofGetFrameNum() * 0.02), 0, 1, -1080, 1080);

			auto location = glm::vec3(
				radius * sin(theta_deg * DEG_TO_RAD) * cos(phi_deg * DEG_TO_RAD),
				radius * sin(theta_deg * DEG_TO_RAD) * sin(phi_deg * DEG_TO_RAD),
				radius * cos(theta_deg * DEG_TO_RAD));

			ofVertex(location);
		}
		ofEndShape();
	}

	this->cam.end();

	/*
	int start = 50;
	if (ofGetFrameNum() > start) {

		ostringstream os;
		os << setw(4) << setfill('0') << ofGetFrameNum() - start;
		ofImage image;
		image.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
		image.saveImage("image/cap/img_" + os.str() + ".jpg");
		if (ofGetFrameNum() - start >= 25 * 20) {

			std::exit(1);
		}
	}
	*/
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}