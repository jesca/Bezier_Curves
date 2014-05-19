Bezier_Curves
=============
A C++ program that takes an input file containing a list of patches and a sudivision parameter. 
The subidivison parameter should be interpreted as the step size in U and V for uniform subdivision, or as an error measure
for adaptive subdivision. Adaptive or uniform tesselationmay be specified through a command line flag. (If -a is present, 
then the adaptive subdivision should be used, otherwise unfirom.) The input file contains the control points
for the pathes and an output file name. 

For uniform tessellation, quadrilateral polygons should be formed by taking parameter-sized
steps in the U and V direction. For adaptive triangulation, the error between the actual surface and the quadrilateral polygon
should be less than the parameter. The error should be distance evaluated at the midpoints
of the polygon edges and the center of each quadrilateral.

To run the program, type "make" into the command line. Then, ./as3 to open the program. In the command line, an example command looks like: ./as3 teapot.bez 0.1 -a 
