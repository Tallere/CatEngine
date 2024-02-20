#include <cstdio>

#include "rendering/cWindow.h"
#include "rendering/cRenderer.h"
#include <cmath>

int main()
{
	cWindow window;
	cRenderer renderer;

	window.create( 800, 600, "Catengine.exe" );
	renderer.create( window );

	float vertices[] = 
	{
		 0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,
		-0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,   
		 0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f
	};
	unsigned int indices[] = 
	{ 
		0, 1, 2
	};

	

	unsigned int VBO, VAO, EBO;
	glGenVertexArrays( 1, &VAO );
	glGenBuffers( 1, &VBO );
	glGenBuffers( 1, &EBO );

	glBindVertexArray( VAO );

	glBindBuffer( GL_ARRAY_BUFFER, VBO );
	glBufferData( GL_ARRAY_BUFFER, sizeof( vertices ), vertices, GL_STATIC_DRAW );

	glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, EBO );
	glBufferData( GL_ELEMENT_ARRAY_BUFFER, sizeof( indices ), indices, GL_STATIC_DRAW );

	glVertexAttribPointer( 0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof( float ), ( void* ) 0 );
	glEnableVertexAttribArray( 0 );

	glVertexAttribPointer( 1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof( float ), ( void* ) ( 3 * sizeof( float ) ) );
	glEnableVertexAttribArray( 1 );

	glBindBuffer(GL_ARRAY_BUFFER, 0);

	 glBindVertexArray(0); 


	while ( !window.shouldClose() )
	{
		window.startFrame();
		renderer.clear( 0x000000FF );

		glClearColor( 0.2f, 0.3f, 0.3f, 1.0f );
		glClear( GL_COLOR_BUFFER_BIT );

		float timeValue = glfwGetTime();
		float greenValue = ( std::sin( timeValue ) / 2.0f ) + 0.5f;
		int vertexColorLocation = glGetUniformLocation( renderer.getDefaultShader(), "ourColor" );

		glUseProgram( renderer.getDefaultShader() );
		glBindVertexArray( VAO );
		glDrawElements( GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0 );
		glBindVertexArray( 0 );


		window.endFrame();
	}

	glfwTerminate();
}