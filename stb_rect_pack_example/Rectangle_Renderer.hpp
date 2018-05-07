#pragma once

#include <GLES2/gl2.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


typedef struct{
    GLuint vbo_id;
    glm::vec4 colour;
    glm::mat4 projection;
    glm::mat4 view;
    glm::mat4 model;
} DE_Rectangle;

void DE_initRectangle(DE_Rectangle * rectangle, glm::vec4  & colour, GLfloat width, GLfloat height, GLfloat z);
void DE_initRectangle(DE_Rectangle * rectangle, glm::vec4 colour, GLfloat x_top_left, GLfloat y_top_left, GLfloat x_bottom_right, GLfloat y_bottom_right, GLfloat z = 0.0f);


void DE_setColourRectangle(DE_Rectangle * rectangle, glm::vec4 colour);
void DE_setDimRectangle(DE_Rectangle * rectangle,float x, float y, float width, float height);
void DE_drawRectangle(DE_Rectangle * rectangle);

void DE_deleteRectangle(DE_Rectangle * rectangle);



