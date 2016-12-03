#pragma once

#include "ofMain.h"
#include "Cross.hpp"
#include "Circle.hpp"
#include "Rhombus.hpp"
#include "SmallCrosses.hpp"
#include "Ball.hpp"
#include "Line.hpp"
#include "PatternContainer.hpp"

class ofApp : public ofBaseApp{

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
		
private:
    int count;
    float marginRatio;
    vector<PatternContainer*> items;
};
