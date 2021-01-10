//
//  main.cpp
//  OpenGL Transformations
//


#define GLEW_STATIC

#include <iostream>

#include <GL\glew.h>
#include <GLFW\glfw3.h>

#include <glm/glm.hpp>//core glm functionality
#include <glm/gtc/matrix_transform.hpp>//glm extension for generating common transformation matrices
#include <glm/gtc/type_ptr.hpp>//glm extension for accessing the internal data structure of glm types

#include "Shader.hpp"
#include<stdlib.h>
#include"SerialPort.h"

int glWindowWidth = 800;
int glWindowHeight = 600;
int retina_width, retina_height;
GLFWwindow* glWindow = NULL;

/*
GLfloat vertices[] = {

	0.5f, 0.5f, 0.5f, 1.0f, 1.0f, 0.1f,     //0
	-0.5f, 0.5f, 0.5f, 1.0f, 1.0f, 0.1f,    //1
	-0.5f, 0.5f, -0.5f, 1.0f, 1.0f, 0.1f,   //2
	0.5f, 0.5f, -0.5f, 1.0f, 1.0f, 0.1f,    //3

	-0.5f, 0.5f, 0.5f, 0.0f, 0.55f, 0.0f,   //4
	-0.5f, -0.5f, 0.5f, 0.0f, 0.55f, 0.0f,  //5
	-0.5f, -0.5f, -0.5f, 0.0f, 0.55f, 0.0f, //6
	-0.5f, 0.5f, -0.5f, 0.0f, 0.55f, 0.0f,  //7

	0.5f, -0.5f, 0.5f, 1.0f, 1.0f, 1.0f,	//8
	-0.5f, -0.5f, 0.5f, 1.0f, 1.0f, 1.0f,	//9
	-0.5f, 0.5f, 0.5f, 1.0f, 1.0f, 1.0f,	//10
	0.5f, 0.5f, 0.5f, 1.0f, 1.0f, 1.0f,		//11

	0.5f, 0.5f, 0.5f, 1.0f, 0.5f, 0.0f,		//12
	0.5f, -0.5f, 0.5f, 1.0f, 0.5f, 0.0f,	//13
	0.5f, -0.5f, -0.5f, 1.0f, 0.5f, 0.0f,	//14
	0.5f, 0.5f, -0.5f, 1.0f, 0.5f, 0.0f,	//15

	-0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f,	//16
	0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f,	//17
	0.5f, -0.5f, 0.5f, 1.0f, 0.0f, 0.0f,	//18
	-0.5f, -0.5f, 0.5f, 1.0f, 0.0f, 0.0f,	//19

	-0.5f, 0.5f, -0.5f, 0.0f, 0.0f, 0.8f,	//20
	0.5f, 0.5f, -0.5f, 0.0f, 0.0f, 0.8f,	//21
	0.5f, -0.5f, -0.5f, 0.0f, 0.0f, 0.8f,	//22
	-0.5f, -0.5f, -0.5f, 0.0f, 0.0f, 0.8f	//23
};

GLuint indices[] = {
	0, 1, 2, 0, 2, 3,		// top plane triangles     - yellow -> 1.0f, 1.0f, 0.1f
	4, 5, 6, 4, 6, 7,		// left plane triangles    - green  -> 0.0f, 0.55f, 0.0f
	8, 9, 10, 8, 10, 11,	// front plane triangles   - white  -> 1.0f, 1.0f, 1.0f
	12, 13, 14, 12, 14, 15, // right plane triangles   - orange -> 1.0f, 0.5f, 0.0f
	16, 17, 18, 16, 18, 19, // bottom plane triangles  - red    -> 1.0f, 0.0f, 0.0f
	20, 21, 22, 20, 22, 23	// back plane triangles    - blue   -> 0.0f, 0.0f, 0.8f
};
*/



//vertex data --- position and color
//vertex position data has been duplicated to ensure constant color across each face

GLfloat vertices[] = { 

	// ------------------------------------------------------------- top face
	-1.5f,  1.5f, -1.5f,	0.0f, 0.0f, 0.8f, // back left
	-0.5f,  1.5f, -1.5f,	0.0f, 0.0f, 0.8f,
	-0.5f,  1.5f, -0.5f,	0.0f, 0.0f, 0.8f,
	-1.5f,  1.5f, -0.5f,	0.0f, 0.0f, 0.8f,

	-0.5f,  1.5f, -1.5f,	0.0f, 0.0f, 0.8f, // back middle
	 0.5f,  1.5f, -1.5f,	0.0f, 0.0f, 0.8f,
	 0.5f,  1.5f, -0.5f,	0.0f, 0.0f, 0.8f,
	-0.5f,  1.5f, -0.5f,	0.0f, 0.0f, 0.8f,

	 0.5f,  1.5f, -1.5f,	0.0f, 0.0f, 0.8f, // back right
	 1.5f,  1.5f, -1.5f,	0.0f, 0.0f, 0.8f,
	 1.5f,  1.5f, -0.5f,	0.0f, 0.0f, 0.8f,
	 0.5f,  1.5f, -0.5f,	0.0f, 0.0f, 0.8f,

	-1.5f,  1.5f, -0.5f,	0.0f, 0.0f, 0.8f, // middle left
	-0.5f,  1.5f, -0.5f,	0.0f, 0.0f, 0.8f,
	-0.5f,  1.5f,  0.5f,	0.0f, 0.0f, 0.8f,
	-1.5f,  1.5f,  0.5f,	0.0f, 0.0f, 0.8f,

	-0.5f,  1.5f, -0.5f,	0.0f, 0.0f, 0.8f, // middle middle
	 0.5f,  1.5f, -0.5f,	0.0f, 0.0f, 0.8f,
	 0.5f,  1.5f,  0.5f,	0.0f, 0.0f, 0.8f,
	-0.5f,  1.5f,  0.5f,	0.0f, 0.0f, 0.8f,

	 0.5f,  1.5f, -0.5f,	0.0f, 0.0f, 0.8f, // middle right
	 1.5f,  1.5f, -0.5f,	0.0f, 0.0f, 0.8f,
	 1.5f,  1.5f,  0.5f,	0.0f, 0.0f, 0.8f,
	 0.5f,  1.5f,  0.5f,	0.0f, 0.0f, 0.8f,

	-1.5f,  1.5f,  0.5f,	0.0f, 0.0f, 0.8f, // front left
	-0.5f,  1.5f,  0.5f,	0.0f, 0.0f, 0.8f,
	-0.5f,  1.5f,  1.5f,	0.0f, 0.0f, 0.8f,
	-1.5f,  1.5f,  1.5f,	0.0f, 0.0f, 0.8f,

	-0.5f,  1.5f,  0.5f,	0.0f, 0.0f, 0.8f, // front middle
	 0.5f,  1.5f,  0.5f,	0.0f, 0.0f, 0.8f,
	 0.5f,  1.5f,  1.5f,	0.0f, 0.0f, 0.8f,
	-0.5f,  1.5f,  1.5f,	0.0f, 0.0f, 0.8f,

	 0.5f,  1.5f,  0.5f,	0.0f, 0.0f, 0.8f, // front right
	 1.5f,  1.5f,  0.5f,	0.0f, 0.0f, 0.8f,
	 1.5f,  1.5f,  1.5f,	0.0f, 0.0f, 0.8f,
	 0.5f,  1.5f,  1.5f,	0.0f, 0.0f, 0.8f,

	 // ------------------------------------------------------------- left face
	- 1.5f,  1.5f, -1.5f,	1.0f, 0.5f, 0.0f, // up back
	-1.5f,  1.5f, -0.5f,	1.0f, 0.5f, 0.0f,
	-1.5f,  0.5f, -0.5f,	1.0f, 0.5f, 0.0f,
	-1.5f,  0.5f, -1.5f,	1.0f, 0.5f, 0.0f,

	-1.5f,  1.5f, -0.5f,	1.0f, 0.5f, 0.0f, // up middle
	-1.5f,  1.5f,  0.5f,	1.0f, 0.5f, 0.0f,
	-1.5f,  0.5f,  0.5f,	1.0f, 0.5f, 0.0f,
	-1.5f,  0.5f, -0.5f,	1.0f, 0.5f, 0.0f,

	-1.5f,  1.5f,  0.5f,	1.0f, 0.5f, 0.0f, // up front
	-1.5f,  1.5f,  1.5f,	1.0f, 0.5f, 0.0f,
	-1.5f,  0.5f,  1.5f,	1.0f, 0.5f, 0.0f,
	-1.5f,  0.5f,  0.5f,	1.0f, 0.5f, 0.0f,

	-1.5f,  0.5f, -1.5f,	1.0f, 0.5f, 0.0f, // middle back
	-1.5f,  0.5f, -0.5f,	1.0f, 0.5f, 0.0f,
	-1.5f, -0.5f, -0.5f,	1.0f, 0.5f, 0.0f,
	-1.5f, -0.5f, -1.5f,	1.0f, 0.5f, 0.0f,

	-1.5f,  0.5f, -0.5f,	1.0f, 0.5f, 0.0f, // middle middle
	-1.5f,  0.5f,  0.5f,	1.0f, 0.5f, 0.0f,
	-1.5f, -0.5f,  0.5f,	1.0f, 0.5f, 0.0f,
	-1.5f, -0.5f, -0.5f,	1.0f, 0.5f, 0.0f,

	-1.5f,  0.5f,  0.5f,	1.0f, 0.5f, 0.0f, // middle front
	-1.5f,  0.5f,  1.5f,	1.0f, 0.5f, 0.0f,
	-1.5f, -0.5f,  1.5f,	1.0f, 0.5f, 0.0f,
	-1.5f, -0.5f,  0.5f,	1.0f, 0.5f, 0.0f,

	-1.5f, -0.5f, -1.5f,	1.0f, 0.5f, 0.0f, // down back
	-1.5f, -0.5f, -0.5f,	1.0f, 0.5f, 0.0f,
	-1.5f, -1.5f, -0.5f,	1.0f, 0.5f, 0.0f,
	-1.5f, -1.5f, -1.5f,	1.0f, 0.5f, 0.0f,

	-1.5f, -0.5f, -0.5f,	1.0f, 0.5f, 0.0f, // down middle
	-1.5f, -0.5f,  0.5f,	1.0f, 0.5f, 0.0f,
	-1.5f, -1.5f,  0.5f,	1.0f, 0.5f, 0.0f,
	-1.5f, -1.5f, -0.5f,	1.0f, 0.5f, 0.0f,

	-1.5f, -0.5f,  0.5f,	1.0f, 0.5f, 0.0f, // down front
	-1.5f, -0.5f,  1.5f,	1.0f, 0.5f, 0.0f,
	-1.5f, -1.5f,  1.5f,	1.0f, 0.5f, 0.0f,
	-1.5f, -1.5f,  0.5f,	1.0f, 0.5f, 0.0f,

	// ------------------------------------------------------------- front face
	-1.5f,  1.5f,  1.5f,	1.0f, 0.0f, 0.0f, // up left
	-0.5f,  1.5f,  1.5f,	1.0f, 0.0f, 0.0f,
	-0.5f,  0.5f,  1.5f,	1.0f, 0.0f, 0.0f,
	-1.5f,  0.5f,  1.5f,	1.0f, 0.0f, 0.0f,

	-0.5f,  1.5f,  1.5f,	1.0f, 0.0f, 0.0f, // up middle
	 0.5f,  1.5f,  1.5f,	1.0f, 0.0f, 0.0f,
	 0.5f,  0.5f,  1.5f,	1.0f, 0.0f, 0.0f,
	-0.5f,  0.5f,  1.5f,	1.0f, 0.0f, 0.0f,
	
	 0.5f,  1.5f,  1.5f,	1.0f, 0.0f, 0.0f, // up right
	 1.5f,  1.5f,  1.5f,	1.0f, 0.0f, 0.0f,
	 1.5f,  0.5f,  1.5f,	1.0f, 0.0f, 0.0f,
	 0.5f,  0.5f,  1.5f,	1.0f, 0.0f, 0.0f,

	
	-1.5f,  0.5f,  1.5f,	1.0f, 0.0f, 0.0f, // middle left
	-0.5f,  0.5f,  1.5f,	1.0f, 0.0f, 0.0f,
	-0.5f, -0.5f,  1.5f,	1.0f, 0.0f, 0.0f,
	-1.5f, -0.5f,  1.5f,	1.0f, 0.0f, 0.0f,

	-0.5f,  0.5f,  1.5f,	1.0f, 0.0f, 0.0f, // middle middle
	 0.5f,  0.5f,  1.5f,	1.0f, 0.0f, 0.0f,
	 0.5f, -0.5f,  1.5f,	1.0f, 0.0f, 0.0f,
	-0.5f, -0.5f,  1.5f,	1.0f, 0.0f, 0.0f,
	
	 0.5f,  0.5f,  1.5f,	1.0f, 0.0f, 0.0f, // middle right
	 1.5f,  0.5f,  1.5f,	1.0f, 0.0f, 0.0f,
	 1.5f, -0.5f,  1.5f,	1.0f, 0.0f, 0.0f,
	 0.5f, -0.5f,  1.5f,	1.0f, 0.0f, 0.0f,

	
	-1.5f, -0.5f,  1.5f,	1.0f, 0.0f, 0.0f, // down left
	-0.5f, -0.5f,  1.5f,	1.0f, 0.0f, 0.0f,
	-0.5f, -1.5f,  1.5f,	1.0f, 0.0f, 0.0f,
	-1.5f, -1.5f,  1.5f,	1.0f, 0.0f, 0.0f,

	-0.5f, -0.5f,  1.5f,	1.0f, 0.0f, 0.0f, // down middle
	 0.5f, -0.5f,  1.5f,	1.0f, 0.0f, 0.0f,
	 0.5f, -1.5f,  1.5f,	1.0f, 0.0f, 0.0f,
	-0.5f, -1.5f,  1.5f,	1.0f, 0.0f, 0.0f,
	
	 0.5f, -0.5f,  1.5f,	1.0f, 0.0f, 0.0f, // down right
	 1.5f, -0.5f,  1.5f,	1.0f, 0.0f, 0.0f,
	 1.5f, -1.5f,  1.5f,	1.0f, 0.0f, 0.0f,
	 0.5f, -1.5f,  1.5f,	1.0f, 0.0f, 0.0f,

	// ------------------------------------------------------------- right face
	 1.5f,  1.5f,  1.5f,	1.0f, 1.0f, 0.1f, // up front
	 1.5f,  1.5f,  0.5f,	1.0f, 1.0f, 0.1f,
	 1.5f,  0.5f,  0.5f,	1.0f, 1.0f, 0.1f,
	 1.5f,  0.5f,  1.5f,	1.0f, 1.0f, 0.1f,
		
	 1.5f,  1.5f,  0.5f,	1.0f, 1.0f, 0.1f, // up middle
	 1.5f,  1.5f, -0.5f,	1.0f, 1.0f, 0.1f,
	 1.5f,  0.5f, -0.5f,	1.0f, 1.0f, 0.1f,
	 1.5f,  0.5f,  0.5f,	1.0f, 1.0f, 0.1f,
		
	 1.5f,  1.5f, -0.5f,	1.0f, 1.0f, 0.1f, // up back
	 1.5f,  1.5f, -1.5f,	1.0f, 1.0f, 0.1f,
	 1.5f,  0.5f, -1.5f,	1.0f, 1.0f, 0.1f,
	 1.5f,  0.5f, -0.5f,	1.0f, 1.0f, 0.1f,
		
	 1.5f,  0.5f,  1.5f,	1.0f, 1.0f, 0.1f, // middle front
	 1.5f,  0.5f,  0.5f,	1.0f, 1.0f, 0.1f,
	 1.5f, -0.5f,  0.5f,	1.0f, 1.0f, 0.1f,
	 1.5f, -0.5f,  1.5f,	1.0f, 1.0f, 0.1f,
		
	 1.5f,  0.5f,  0.5f,	1.0f, 1.0f, 0.1f, // middle middle
	 1.5f,  0.5f, -0.5f,	1.0f, 1.0f, 0.1f,
	 1.5f, -0.5f, -0.5f,	1.0f, 1.0f, 0.1f,
	 1.5f, -0.5f,  0.5f,	1.0f, 1.0f, 0.1f,
		
	 1.5f,  0.5f, -0.5f,	1.0f, 1.0f, 0.1f, // middle back
	 1.5f,  0.5f, -1.5f,	1.0f, 1.0f, 0.1f,
	 1.5f, -0.5f, -1.5f,	1.0f, 1.0f, 0.1f,
	 1.5f, -0.5f, -0.5f,	1.0f, 1.0f, 0.1f,
		
	 1.5f, -0.5f,  1.5f,	1.0f, 1.0f, 0.1f, // down front
	 1.5f, -0.5f,  0.5f,	1.0f, 1.0f, 0.1f,
	 1.5f, -1.5f,  0.5f,	1.0f, 1.0f, 0.1f,
	 1.5f, -1.5f,  1.5f,	1.0f, 1.0f, 0.1f,
		
	 1.5f, -0.5f,  0.5f,	1.0f, 1.0f, 0.1f, // down middle
	 1.5f, -0.5f, -0.5f,	1.0f, 1.0f, 0.1f,
	 1.5f, -1.5f, -0.5f,	1.0f, 1.0f, 0.1f,
	 1.5f, -1.5f,  0.5f,	1.0f, 1.0f, 0.1f,
		
	 1.5f, -0.5f, -0.5f,	1.0f, 1.0f, 0.1f, // down back
	 1.5f, -0.5f, -1.5f,	1.0f, 1.0f, 0.1f,
	 1.5f, -1.5f, -1.5f,	1.0f, 1.0f, 0.1f,
	 1.5f, -1.5f, -0.5f,	1.0f, 1.0f, 0.1f,

	// ------------------------------------------------------------- below face
	-1.5f, -1.5f,  1.5f,	0.0f, 0.55f, 0.0f, // front left
	-0.5f, -1.5f,  1.5f,	0.0f, 0.55f, 0.0f,
	-0.5f, -1.5f,  0.5f,	0.0f, 0.55f, 0.0f,
	-1.5f, -1.5f,  0.5f,	0.0f, 0.55f, 0.0f,
		
	-0.5f, -1.5f,  1.5f,	0.0f, 0.55f, 0.0f, // front middle
	 0.5f, -1.5f,  1.5f,	0.0f, 0.55f, 0.0f,
	 0.5f, -1.5f,  0.5f,	0.0f, 0.55f, 0.0f,
	-0.5f, -1.5f,  0.5f,	0.0f, 0.55f, 0.0f,
		
		
	 0.5f, -1.5f,  1.5f,	0.0f, 0.55f, 0.0f, // front right
	 1.5f, -1.5f,  1.5f,	0.0f, 0.55f, 0.0f,
	 1.5f, -1.5f,  0.5f,	0.0f, 0.55f, 0.0f,
	 0.5f, -1.5f,  0.5f,	0.0f, 0.55f, 0.0f,
		 
	-1.5f, -1.5f,  0.5f,	0.0f, 0.55f, 0.0f, // middle left
	-0.5f, -1.5f,  0.5f,	0.0f, 0.55f, 0.0f,
	-0.5f, -1.5f, -0.5f,	0.0f, 0.55f, 0.0f,
	-1.5f, -1.5f, -0.5f,	0.0f, 0.55f, 0.0f,
		
	-0.5f, -1.5f,  0.5f,	0.0f, 0.55f, 0.0f, // middle middle
	 0.5f, -1.5f,  0.5f,	0.0f, 0.55f, 0.0f,
	 0.5f, -1.5f, -0.5f,	0.0f, 0.55f, 0.0f,
	-0.5f, -1.5f, -0.5f,	0.0f, 0.55f, 0.0f,
		
		
	 0.5f, -1.5f,  0.5f,	0.0f, 0.55f, 0.0f, // middle right
	 1.5f, -1.5f,  0.5f,	0.0f, 0.55f, 0.0f,
	 1.5f, -1.5f, -0.5f,	0.0f, 0.55f, 0.0f,
	 0.5f, -1.5f, -0.5f,	0.0f, 0.55f, 0.0f,
		 
		 
	-1.5f, -1.5f, -0.5f,	0.0f, 0.55f, 0.0f, // back left
	-0.5f, -1.5f, -0.5f,	0.0f, 0.55f, 0.0f,
	-0.5f, -1.5f, -1.5f,	0.0f, 0.55f, 0.0f,
	-1.5f, -1.5f, -1.5f,	0.0f, 0.55f, 0.0f,
		
	-0.5f, -1.5f, -0.5f,	0.0f, 0.55f, 0.0f, // back middle
	 0.5f, -1.5f, -0.5f,	0.0f, 0.55f, 0.0f,
	 0.5f, -1.5f, -1.5f,	0.0f, 0.55f, 0.0f,
	-0.5f, -1.5f, -1.5f,	0.0f, 0.55f, 0.0f,
		
		
	 0.5f, -1.5f, -0.5f,	0.0f, 0.55f, 0.0f, // back right
	 1.5f, -1.5f, -0.5f,	0.0f, 0.55f, 0.0f,
	 1.5f, -1.5f, -1.5f,	0.0f, 0.55f, 0.0f,
	 0.5f, -1.5f, -1.5f,	0.0f, 0.55f, 0.0f,

	// ------------------------------------------------------------- back face
	-1.5f, -1.5f, -1.5f,	1.0f, 1.0f, 1.0f, // down left
	-0.5f, -1.5f, -1.5f,	1.0f, 1.0f, 1.0f,
	-0.5f, -0.5f, -1.5f,	1.0f, 1.0f, 1.0f,
	-1.5f, -0.5f, -1.5f,	1.0f, 1.0f, 1.0f,
		 
	-0.5f, -1.5f, -1.5f,	1.0f, 1.0f, 1.0f, // down middle
	 0.5f, -1.5f, -1.5f,	1.0f, 1.0f, 1.0f,
	 0.5f, -0.5f, -1.5f,	1.0f, 1.0f, 1.0f,
	-0.5f, -0.5f, -1.5f,	1.0f, 1.0f, 1.0f,
		 
	 0.5f, -1.5f, -1.5f,	1.0f, 1.0f, 1.0f, // down right
	 1.5f, -1.5f, -1.5f,	1.0f, 1.0f, 1.0f,
	 1.5f, -0.5f, -1.5f,	1.0f, 1.0f, 1.0f,
	 0.5f, -0.5f, -1.5f,	1.0f, 1.0f, 1.0f,
		 
	-1.5f, -0.5f, -1.5f,	1.0f, 1.0f, 1.0f, // middle left
	-0.5f, -0.5f, -1.5f,	1.0f, 1.0f, 1.0f,
	-0.5f,  0.5f, -1.5f,	1.0f, 1.0f, 1.0f,
	-1.5f,  0.5f, -1.5f,	1.0f, 1.0f, 1.0f,
		 
	-0.5f, -0.5f, -1.5f,	1.0f, 1.0f, 1.0f, // middle middle
	 0.5f, -0.5f, -1.5f,	1.0f, 1.0f, 1.0f,
	 0.5f,  0.5f, -1.5f,	1.0f, 1.0f, 1.0f,
	-0.5f,  0.5f, -1.5f,	1.0f, 1.0f, 1.0f,
		 
	 0.5f, -0.5f, -1.5f,	1.0f, 1.0f, 1.0f, // middle right
	 1.5f, -0.5f, -1.5f,	1.0f, 1.0f, 1.0f,
	 1.5f,  0.5f, -1.5f,	1.0f, 1.0f, 1.0f,
	 0.5f,  0.5f, -1.5f,	1.0f, 1.0f, 1.0f,
		 
	-1.5f,  0.5f, -1.5f,	1.0f, 1.0f, 1.0f, // up left
	-0.5f,  0.5f, -1.5f,	1.0f, 1.0f, 1.0f,
	-0.5f,  1.5f, -1.5f,	1.0f, 1.0f, 1.0f,
	-1.5f,  1.5f, -1.5f,	1.0f, 1.0f, 1.0f,
		 
	-0.5f,  0.5f, -1.5f,	1.0f, 1.0f, 1.0f, // up middle
	 0.5f,  0.5f, -1.5f,	1.0f, 1.0f, 1.0f,
	 0.5f,  1.5f, -1.5f,	1.0f, 1.0f, 1.0f,
	-0.5f,  1.5f, -1.5f,	1.0f, 1.0f, 1.0f,
		 
	 0.5f,  0.5f, -1.5f,	1.0f, 1.0f, 1.0f, // up right
	 1.5f,  0.5f, -1.5f,	1.0f, 1.0f, 1.0f,
	 1.5f,  1.5f, -1.5f,	1.0f, 1.0f, 1.0f,
	 0.5f,  1.5f, -1.5f,	1.0f, 1.0f, 1.0f
};

GLuint indices[] = {

	// top plane triangles
	0, 1, 2, 0, 2, 3,
	4, 5, 6, 4, 6, 7,
	8, 9, 10, 8, 10, 11,
	12, 13, 14, 12, 14, 15,
	16, 17, 18, 16, 18, 19,
	20, 21, 22, 20, 22, 23,
	24, 25, 26, 24, 26, 27,
	28, 29, 30, 28, 30 ,31,
	32, 33, 34, 32, 34, 35,

	// left plane triangles
	36, 37, 38, 36, 38, 39,
	40, 41, 42, 40, 42, 43,
	44, 45, 46, 44, 46, 47,
	48, 49, 50, 48, 50, 51,
	52, 53, 54, 52, 54, 55, 
	56, 57, 58, 56, 58, 59,
	60, 61, 62, 60, 62, 63,
	64, 65, 66, 64, 66, 67,
	68, 69, 70, 68, 70, 71,

	// front face triangles
	72, 73, 74, 72, 74, 75,
	76, 77, 78, 76, 78, 79,
	80, 81, 82, 80, 82, 83,
	84, 85, 86, 84, 86, 87,
	88, 89, 90, 88, 90, 91,
	92, 93, 94, 92, 94, 95,
	96, 97, 98, 96, 98, 99,
	100, 101, 102, 100, 102, 103,
	104, 105, 106, 104, 106, 107,

	// right face triagles
	108, 109, 110, 108, 110, 111,
	112, 113, 114, 112, 114, 115,
	116, 117, 118, 116, 118, 119,
	120, 121, 122, 120, 122, 123,
	124, 125, 126, 124, 126, 127,
	128, 129, 130, 128, 130, 131,
	132, 133, 134, 132, 134, 135,
	136, 137, 138, 136, 138, 139,
	140, 141, 142, 140, 142, 143,

	// down face triangles
	144, 145, 146, 144, 146, 147,
	148, 149, 150, 148, 150, 151,
	152, 153, 154, 152, 154, 155,
	156, 157, 158, 156, 158, 159,
	160, 161, 162, 160, 162, 163,
	164, 165, 166, 164, 166, 167,
	168, 169, 170, 168, 170, 171,
	172, 173, 174, 172, 174, 175,
	176, 177 ,178, 176, 178, 179,

	// back face triangles
	180, 181, 182, 180, 182, 183,
	184, 185, 186, 184, 186, 187,
	188, 189, 190, 188, 190, 191,
	192, 193, 194, 192, 194, 195,
	196, 197, 198, 196, 198, 199,
	200, 201, 202, 200, 202, 203,
	204, 205, 206, 204, 206, 207,
	208, 209, 210, 208, 210, 211,
	212, 213, 214, 212, 214, 215
};



GLuint verticesVBO;
GLuint verticesEBO;
GLuint objectVAO;

gps::Shader myCustomShader;

glm::mat4 model;
GLint modelLoc;
glm::mat4 view;
GLint viewLoc;
glm::mat4 projection;
GLint projLoc;

float angle1 = 0;
float angle2 = 0;

// codificare culori primite din arduino prin interfata seriala, versus codificare rgb:
// COLOR    -  RECEIVED  -         RGB
// blue     -     0      -   0.0f, 0.0f, 0.8f
// orange   -     1      -   1.0f, 0.5f, 0.0f
// red      -     2      -   1.0f, 0.0f, 0.0f
// yellow   -     3      -   1.0f, 1.0f, 0.1f
// green    -     4      -   0.0f, 0.55f, 0.0f
// white    -     5      -   1.0f, 1.0f, 1.0f
const GLfloat RGB[6][3] = {
	{0.0f, 0.0f, 0.8f},   // blue
	{1.0f, 0.5f, 0.0f},   // orange
	{1.0f, 0.0f, 0.0f},   // red
	{1.0f, 1.0f, 0.1f},   // yellow
	{ 0.0f, 0.55f, 0.0f}, // green
	{1.0f, 1.0f, 1.0f}    // white
};

void updateVertices(char colors[54]) {  // the function receives as parameter a matrix formed by overlaping the 6 matrices corresponding 
										// to each face of the cube, in this order: top, left, front, right, below, back; top being on top
										// and back being on bottom. 
	const int VERTICES_ELEMENTS_FOR_ONE_CELL  = 4 * 6; //4 vertexes and 6 elements(vertex coordinates and color) for each cell
	for (int i = 0; i < 54; i++) { // number of elements = no. of rows (6 x 3) x no. of columns (3) = 54
		GLfloat color[3] = { RGB[colors[i]-'0'][0], RGB[colors[i]-'0'][1], RGB[colors[i]-'0'][2] };
		vertices[i * VERTICES_ELEMENTS_FOR_ONE_CELL + 0 * 6 + 3] = color[0];
		vertices[i * VERTICES_ELEMENTS_FOR_ONE_CELL + 0 * 6 + 4] = color[1];
		vertices[i * VERTICES_ELEMENTS_FOR_ONE_CELL + 0 * 6 + 5] = color[2];
		vertices[i * VERTICES_ELEMENTS_FOR_ONE_CELL + 1 * 6 + 3] = color[0];
		vertices[i * VERTICES_ELEMENTS_FOR_ONE_CELL + 1 * 6 + 4] = color[1];
		vertices[i * VERTICES_ELEMENTS_FOR_ONE_CELL + 1 * 6 + 5] = color[2];
		vertices[i * VERTICES_ELEMENTS_FOR_ONE_CELL + 2 * 6 + 3] = color[0];
		vertices[i * VERTICES_ELEMENTS_FOR_ONE_CELL + 2 * 6 + 4] = color[1];
		vertices[i * VERTICES_ELEMENTS_FOR_ONE_CELL + 2 * 6 + 5] = color[2];
		vertices[i * VERTICES_ELEMENTS_FOR_ONE_CELL + 3 * 6 + 3] = color[0];
		vertices[i * VERTICES_ELEMENTS_FOR_ONE_CELL + 3 * 6 + 4] = color[1];
		vertices[i * VERTICES_ELEMENTS_FOR_ONE_CELL + 3 * 6 + 5] = color[2];
	}
}


void windowResizeCallback(GLFWwindow* window, int width, int height)
{
	fprintf(stdout, "window resized to width: %d , and height: %d\n", width, height);
	//TODO
}


void initObjects()
{
	glGenVertexArrays(1, &objectVAO);
	glBindVertexArray(objectVAO);

	glGenBuffers(1, &verticesVBO);
	glBindBuffer(GL_ARRAY_BUFFER, verticesVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glGenBuffers(1, &verticesEBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, verticesEBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	//vertex position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);

	//vertex colour attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	glBindVertexArray(0);
}

bool initOpenGLWindow()
{
	if (!glfwInit()) {
		fprintf(stderr, "ERROR: could not start GLFW3\n");
		return false;
	}

	// window hints
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// for multisampling/antialising
	glfwWindowHint(GLFW_SAMPLES, 4);

	glWindow = glfwCreateWindow(glWindowWidth, glWindowHeight, "OpenGL Transformations", NULL, NULL);
	if (!glWindow) {
		fprintf(stderr, "ERROR: could not open window with GLFW3\n");		
		return false;
	}

	glfwSetWindowSizeCallback(glWindow, windowResizeCallback);
	glfwMakeContextCurrent(glWindow);	

	// start GLEW extension handler
	glewExperimental = GL_TRUE;
	glewInit();

	// get version info
	const GLubyte* renderer = glGetString(GL_RENDERER); // get renderer string
	const GLubyte* version = glGetString(GL_VERSION); // version as a string
	printf("Renderer: %s\n", renderer);
	printf("OpenGL version supported %s\n", version);

	//for RETINA display
	glfwGetFramebufferSize(glWindow, &retina_width, &retina_height);

	return true;
}

void renderScene()
{
	glClearColor(0.8, 0.8, 0.8, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glViewport(0, 0, retina_width, retina_height);

	if (glfwGetKey(glWindow, GLFW_KEY_ESCAPE)) {
		glfwSetWindowShouldClose(glWindow, GLFW_TRUE);
	}

	if (glfwGetKey(glWindow, GLFW_KEY_Q)) {
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	}

	if (glfwGetKey(glWindow, GLFW_KEY_E)) {
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	}

	model = glm::mat4(1.0f);

	if (glfwGetKey(glWindow, GLFW_KEY_D)) { 
		angle1 += 0.0015f;
	}
	if (glfwGetKey(glWindow, GLFW_KEY_A)) {
		angle1 -= 0.0015f;
	}

	if (glfwGetKey(glWindow, GLFW_KEY_S)) {
		angle2 += 0.002f;
	}
	if (glfwGetKey(glWindow, GLFW_KEY_W)) {
		angle2 -= 0.002f;
	}

	// create rotation matrix
	model = glm::rotate(model, angle1, glm::vec3(0, 1, 0));
	model = glm::rotate(model, angle2, glm::vec3(1, 0, 0));
	// send matrix data to vertex shader
	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

	myCustomShader.useShaderProgram();
	glBindVertexArray(objectVAO);
	glDrawElements(GL_TRIANGLES, 324, GL_UNSIGNED_INT, 0);
}

void cleanup() {
	glfwDestroyWindow(glWindow);
	//close GL context and any other GLFW resources
	glfwTerminate();
}

int main(int argc, const char * argv[]) {

	if (!initOpenGLWindow()) {
		glfwTerminate();
		return 1;
	}


	glEnable(GL_DEPTH_TEST);

	myCustomShader.loadShader("shaders/shaderStart.vert", "shaders/shaderStart.frag");
	myCustomShader.useShaderProgram(); 

	// initialize the model matrix
	model = glm::mat4(1.0f);
	// send matrix data to shader
	modelLoc = glGetUniformLocation(myCustomShader.shaderProgram, "model");
	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

	// initialize the view matrix
	view = glm::lookAt(glm::vec3(0.0f, 2.0f, 10.0f), glm::vec3(0.0f, 0.0f, -10.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	// send matrix data to shader
	viewLoc = glGetUniformLocation(myCustomShader.shaderProgram, "view");
	glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));

	// initialize the projection matrix
	projection = glm::perspective(70.0f, (float)glWindowWidth / (float)glWindowHeight, 0.1f, 1000.0f);
	// send matrix data to shader
	projLoc = glGetUniformLocation(myCustomShader.shaderProgram, "projection");
	glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));
	
	char s[55] = "000010000111121111222232222333343333444454444555505555";
	updateVertices(s);
	initObjects();

	//arduino serial communication
	char port[] = "COM3"; // "\\\\.\\"
	char matrix[55];
	SerialPort arduino(port);
	if (arduino.isConnected()) {
		printf("\n\n\nARDUINO CONNECTION ESTABLISHED.\n\n");
	}
	else {
		printf("\n\n\nERROR IN PORT NAME!\n\n");
	}

	char output[54];
	char buffer[10];
	int counter = 0;
	while (!glfwWindowShouldClose(glWindow) && arduino.isConnected()) {

		buffer[0] = '\0';
		arduino.readSerialPort(buffer, 9);
		buffer[9] = '\0';
		if (buffer[0] != '\0') {
			if (buffer[0] == 't' && buffer[1] == 'r' && buffer[2] == 'a' && buffer[3] == 'n' && buffer[4] == 's' && buffer[5] == 'm' && buffer[6] == 'i' && buffer[7] == 's' && buffer[8] == 'i') {
				printf("\n\n");
				counter = 0;
				printf("\n");
			}
			else {
				if (counter < 7) {
					printf("%s\n");
					for (int i = 0; i < 9; i++) {
						output[counter * 9 + i] = buffer[i];
					}
				}
				counter++;
			}
			if (counter == 6) {
				updateVertices(output);
				initObjects();
			}
		}

		/*matrix[0] = '\0';
		arduino.readSerialPort(matrix, MAX_DATA_LENGTH);
		if (matrix[0] != '\0') {
			updateVertices(matrix);
			initObjects();
		}*/
	
		renderScene();

		glfwPollEvents();
		glfwSwapBuffers(glWindow);
	}

	cleanup();

	return 0;
}
