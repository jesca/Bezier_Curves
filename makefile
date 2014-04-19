CC = g++
EIGEN_PATH=/usr/local/include/Eigen/Dense

ifeq ($(shell sw_vers 2>/dev/null | grep Mac | awk '{ print $$2}'),Mac)
	CFLAGS = -g -DGL_GLEXT_PROTOTYPES -I./include/ -I/usr/X11/include -DOSX
	LDFLAGS = -framework GLUT -framework OpenGL \
    	-L"/System/Library/Frameworks/OpenGL.framework/Libraries" \
    	-lGL -lGLU -lm -lstdc++
else
	CFLAGS = -g -DGL_GLEXT_PROTOTYPES -Iglut-3.7.6-bin
	LDFLAGS = -lglut -lGLU
endif

	
RM = /bin/rm -f 
all: main 
main: bezier_main.o
	$(CC) -g  $(CFLAGS) -o as3 bezier_main.o $(LDFLAGS) 
bezier_main.o: bezier_main.cpp bez.h
	$(CC) -g $(CFLAGS) -I./glm-0.9.4.2 -c bezier_main.cpp

clean: 
	$(RM) *.o as3
 

