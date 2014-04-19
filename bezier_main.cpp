#include <vector>
#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <sstream>

#ifdef _WIN32
#include <windows.h>
#else
#include <sys/time.h>
#endif

#ifdef OSX
#include <GLUT/glut.h>
#include <OpenGL/glu.h>
#else
#include <GL/glut.h>
#include <GL/glu.h>
#endif

#include <time.h>
#include <math.h>
#include <stdio.h>

#include "Eigen/Dense"


#include <glm/glm.hpp>

using namespace std;

bool adap_on;
float subdiv_param;
int totalPatchCount;


struct controlPoint
{
	glm::vec3 pixelLocation;
};

struct drawPoint {
	glm::vec3 pixelLocation;
	glm::vec3 pixNormal;

};
struct patch //has 4 control points, each control point has 3 floats
{
	vector <controlPoint> allControlPoints;
	drawPoint** row;

};

vector <patch> allPatches;


void openFile(string file) {

		std::ifstream inpfile(file.c_str());
		int count =0;
		bool getCount=false;
		if(!inpfile.is_open()) {
			std::cout << "Unable to open file" << std::endl;
		} else {
			std::string line;
		//MatrixStack mst;
			vector <controlPoint> tempControlPoints;
			while(!inpfile.eof()) {

				std::vector<std::string> splitline;
				std::string buf;
				std::getline(inpfile,line);
				std::stringstream ss(line);
				while (ss >> buf) {
					splitline.push_back(buf);
				}
			if (!getCount){ // first line
				totalPatchCount = atof(splitline[0].c_str());
 				getCount=true;

			}

			else if(splitline.empty()) { // empty line
				int subd = ceil (1 / subdiv_param) + 1;

				std::cout << count << std::endl;

				patch singlePatch = {};
				singlePatch.allControlPoints = tempControlPoints;


				singlePatch.row = new drawPoint* [subd]; 

				for(int i = 0; i <= ceil (1 / subdiv_param); i++){

					singlePatch.row[i] = new drawPoint[subd];
				}	

				allPatches.push_back(singlePatch);
				tempControlPoints.clear();

			}
			//Ignore comments
			else if(splitline[0][0] == '#') {
				continue;
			}
			else {
								count++;


				controlPoint singleControl = {};
				controlPoint singleControl1 = {};
				controlPoint singleControl2 = {};
				controlPoint singleControl3 = {};


				singleControl.pixelLocation =  glm::vec3(atof(splitline[0].c_str()), atof(splitline[1].c_str()), atof(splitline[2].c_str()));
				
				tempControlPoints.push_back(singleControl);



				singleControl1.pixelLocation =  glm::vec3(atof(splitline[3].c_str()),atof(splitline[4].c_str()),atof(splitline[5].c_str()));;

				
				tempControlPoints.push_back(singleControl1);	



				singleControl2.pixelLocation =  glm::vec3(atof(splitline[6].c_str()),atof(splitline[7].c_str()),atof(splitline[8].c_str()));;;

				tempControlPoints.push_back(singleControl2);	

 
		std::cout << "0: " + splitline[0]+"" << "1: " << splitline[1] << "2: " <<splitline[2] << "3: " << splitline[3] << "4: "  << splitline[4] <<std::endl;

				singleControl3.pixelLocation =  glm::vec3(atof(splitline[9].c_str()),atof(splitline[10].c_str()),atof(splitline[11].c_str()));;;

				
				tempControlPoints.push_back(singleControl3);

			}

			
		}
	}
}



int main(int argc, char *argv[]) {   // first argument is the program running
	cout <<"main"<<endl;
	//This initializes glut
    glutInit(&argc, argv);
    float subdiv_param; 
    adap_on=false;

    //input 1
    string filename = argv[1];
    //input 2
	subdiv_param = atof(argv[2]);
	// input 3: user input whether or not to use adaptive
	if (argv[3]) {
		if ((string)argv[3] == "-a") {
			adap_on = true;
		}
	}
	cout << "opening file" <<endl;
	openFile(filename);
	//if (!adap_on) {
	//	patch_uniform(); 
		
//	}else {
//		patch_adaptive();
//	}
	//later 
	//float tempDivision = 1 / subdivision;
	//numberOfSubdivisions = (int) tempDivision;

/*
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(500, 500); //viewport w and h 
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Bezier Project 184");
	initScene();       
	glutDisplayFunc(myDisplay);                  // function to run when its time to draw something
	glutReshapeFunc(myReshape);                  // function to run when the window gets resized                        

	glutKeyboardFunc(keyPressed);
	glutKeyboardUpFunc(keyPressedUp);
	glutSpecialFunc(keySpecial);
	glutSpecialUpFunc(keySpecialUp);
	glutMainLoop();                              // infinite loop that will keep drawing and resizing and whatever else
*/
	return 0;
	}