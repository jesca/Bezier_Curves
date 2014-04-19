using namespace std;
#include "Eigen/Dense"

#define vec3f Eigen::Vector3f


bool adap_on;
float subdiv_param;
int totalPatchCount;

struct controlPoint
{
	vec3f pt;
};

struct pixInfo {
	vec3f calcNorm;
	vec3f calcPix;

};
struct patch //has 4 control points, each control point has 3 floats
{
	vector <controlPoint> patchPoints;
	pixInfo** p;

};



