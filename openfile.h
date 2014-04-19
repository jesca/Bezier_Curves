#include <math.h>
#include <stdio.h>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iostream>
#include "Eigen/Dense"

#include <glm/glm.hpp>
using namespace std;
#define vec3f Eigen::Vector3f



 
int openFile(string file){
	/*Your program will take two command line arguments with a third option parameter. 
	These are: 
	1. the input file name
	2. the subdivision parameter
	3. a flag which determines if a subdivision should be adaptive or uniform. 

	An example command: % myprogram3 inputfile.bez 0.1 -a  
	*/

//open file specified by command line -- Taken from example parser on Piazza post
  	cout <<"opening file 2"<<endl;
    bool getCount = false;

  std::ifstream inpfile(file.c_str());
  if(!inpfile.is_open()) {
    cout << "Unable to open file" << std::endl;
  } 
  else {
  	int numdiv = ceil (1 / subdiv_param);
	int numdivpo = ceil (1 / subdiv_param) + 1;
  	cout <<"opening file 3"<<endl;
  	//totalPatchCount=0;
  	string line;
    vector <controlPoint> initial_control; //vector of controlPoints

    while(inpfile.good()) {
      vector<string> splitline;
      string buf;
      getline(inpfile,line);
      stringstream ss(line);

      while (ss >> buf) {
        splitline.push_back(buf);
      }
      if (!getCount) {
      	totalPatchCount=atof(splitline[0].c_str()); //first line of file -- tells you how many patches there are for this image
      	getCount=true;
      }


      

      /*code here: 
      Remember: control points are vectors, each patch has 4 control points
      */

      else if (splitline.empty()) { 
      	cout <<"reached empty" <<endl;

	
	//create new patch and push initial_control to this
      		patch middlePatch;
			middlePatch.patchPoints = initial_control;
			middlePatch.p = new pixInfo* [numdivpo]; 
			for(int i = 0; i <= numdiv; i++){
				middlePatch.p[i] = new pixInfo[numdivpo];
			}	
			finalPatch.push_back(middlePatch);
			initial_control.clear();      	
		}

      else {

      	cout <<"here" <<endl;
		controlPoint ctrOne, ctrTwo, ctrThree, ctrFour;

		ctrOne.pt =  vec3f(atof(splitline[0].c_str()),atof(splitline[1].c_str()),atof(splitline[2].c_str()));
		initial_control.push_back(ctrOne);

	    ctrTwo.pt =  vec3f(atof(splitline[3].c_str()),atof(splitline[4].c_str()),atof(splitline[5].c_str()));;
	    initial_control.push_back(ctrTwo);	

	    ctrThree.pt =  vec3f(atof(splitline[6].c_str()),atof(splitline[7].c_str()),atof(splitline[8].c_str()));;
	    initial_control.push_back(ctrThree);	

	    ctrFour.pt =  vec3f(atof(splitline[9].c_str()),atof(splitline[10].c_str()),atof(splitline[11].c_str()));;
		initial_control.push_back(ctrFour);
		
	}
  }
}
}

 