#pragma once
#include "../engine.h"

class cWindow;

class cRenderer
{
public:
	cRenderer();
	~cRenderer();
	
	bool create( cWindow& _window );

	void clear( unsigned char _color );

	unsigned int getDefaultShader( void ) const { return m_shader_default; }

private:

	void createDefaultShader( void );

	const char* m_vertex_shader_default_source = 
		"#version 330 core\n"
		"layout (location = 0) in vec3 aPos;"
		"layout (location = 1) in vec3 aColor;\n"
		"layout (location = 2) in vec2 aTexCoord;\n"
		"out vec3 ourColor;"
		"out vec2 TexCoord;"
		"void main()\n"
		"{\n"
		"   gl_Position = vec4(aPos, 1.0);\n"
			"ourColor = aColor;"
		"TexCoord = aTexCoord;"
		"}\0";

	const char* m_fragment_shader_default_source =
		"#version 330 core\n"
		"in vec3 ourColor;\n"
		"in vec2 TexCoord;\n"
		"uniform sampler2D outTexture;\n"
		"void main()\n"
		"{\n"
		"	FragColor = vec4(ourTexture, TexCoord);"
		"}\0";

	unsigned int m_shader_default = 0;
};
