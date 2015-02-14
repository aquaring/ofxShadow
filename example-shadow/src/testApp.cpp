#include "ofMain.h"
#include "ofxShadow.h"

class ofApp : public ofBaseApp
{
    ofEasyCam cam;
    ofVec3f light_pos;
    ofxShadow simple_shadow;
    
public:
    
    void setup()
    {
        ofBackground(255);
        simple_shadow.setup(&cam);
    }
    
    void update()
    {
        // updating shadow color using mouse position
        simple_shadow.setShadowColor(ofFloatColor(0., 0., 0., 1));
        
        // updating light position
        light_pos = ofVec3f(0, 0, 200);
        simple_shadow.setLightPosition(light_pos);
    }
    
    void draw()
    {
        cam.begin();
        {
            glEnable(GL_DEPTH_TEST);
            float light_moving_speed = 0.1;
            float light_moving_radius = 100.;
            
            // axis
            ofDrawAxis(300);
            ofDrawBitmapString("x", 300, 0, 0);
            ofDrawBitmapString("y", 0, 300, 0);
            ofDrawBitmapString("z", 0, 0, 300);
            
            
            // light pos
            ofSetColor(255, 0, 255);
            ofDrawBox(light_pos, 3);
            ofDrawBitmapString("light", light_pos+10);
            
            
            // red box
            ofSetColor(255, 0, 0);
            ofSphere(sin(2.0 * M_PI * (ofGetElapsedTimef()*light_moving_speed)) * light_moving_radius, sin(2.0 * M_PI * (ofGetElapsedTimef()*light_moving_speed)) * light_moving_radius, 100, 10);
            
            
            // shadow
            simple_shadow.begin();
            ofSphere(sin(2.0 * M_PI * (ofGetElapsedTimef()*light_moving_speed)) * light_moving_radius * 2, sin(2.0 * M_PI * (ofGetElapsedTimef()*light_moving_speed)) * light_moving_radius * 2, 100, 10);
            simple_shadow.end();
            
            glDisable(GL_DEPTH_TEST);
        }
        cam.end();
    }
};



#pragma mark -
#pragma mark main
int main(){
    ofSetupOpenGL(1600, 900, OF_WINDOW);
    ofRunApp(new ofApp());
}
