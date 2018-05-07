#include <iostream>
#include <stdio.h>
#include <cstdlib>
#define GLFW_INCLUDE_ES3
#include <GLFW/glfw3.h>
#include "stb_rect_pack.h"
#include "Rectangle_Renderer.hpp"
#include <map>

using namespace std;

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

GLFWwindow *win;
int window_width = 0;
int window_height = 0;
int framebuffer_width=0;
int framebuffer_height=0;
float scale_x;
float scale_y;
float aspacet = 1.0f;
float zoom = 1.0f;

void errorCallback(int e, const char *d)
{
    printf("Error %d: %s\n", e, d);
}

void framebufferSizeCallback(GLFWwindow * , int width, int height)
{
    int fb_width = width*scale_x;
    int fb_height = height*scale_y;
    aspacet = (float)width/(float)height;

    glViewport(0,0,width, height);
}

void scrollCallback(GLFWwindow*,double x, double y)
{
    if(y > 0)
    {
        zoom *= 1.1f;
    }else{
        zoom /= 1.1f;
    }
}

glm::vec4 randomColour()
{
    glm::vec4 color(float(rand() % 1001)/1000.0f,float(rand() % 1001)/1000.0f,float(rand() % 1001)/1000.0f,1.0f);
    return color;
}

DE_Rectangle rectangle;


#define RECTS_COUNT 35
int TARGET_DIM = 1;


stbrp_context context;
struct stbrp_rect rects[RECTS_COUNT];
map<int, glm::vec4> rects_colors;

void initStbRectangles()
{
    for (int i=0; i< RECTS_COUNT; i++)
    {
        rects[i].id = i;
        rects[i].w = 100+i;
        rects[i].h = 100 + 2*i;//
        rects[i].x = 0;
        rects[i].y = 0;
        rects[i].was_packed = 0;
        rects_colors[i] = randomColour();
    }

    int rectsLength = sizeof(rects)/sizeof(rects[0]);


    int ret;

    do{
        TARGET_DIM = TARGET_DIM*2;

    int nodeCount = TARGET_DIM*2;
    struct stbrp_node * ptr_nodes = (struct stbrp_node *)malloc(sizeof(stbrp_node)*nodeCount);

    stbrp_init_target(&context, TARGET_DIM, TARGET_DIM, ptr_nodes, nodeCount);
    ret = stbrp_pack_rects(&context, rects, rectsLength);

    free(ptr_nodes);

    }while(ret != 1);


    for (int i=0; i< RECTS_COUNT; i++)
    {
        printf("rect %i (pos.x = %hu, pos.y = %hu) (height = %hu, width = %hu) was_packed=%i\n", rects[i].id, rects[i].x, rects[i].y, rects[i].h, rects[i].w, rects[i].was_packed);
    }


    printf("TARGET_DIM = %d\n", TARGET_DIM);
    fflush(stdout);
}

void Render()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.3f, 0.3f, 0.3f, 1.0f);

    float projection_width = 8000.0f * zoom;
    float projection_height = projection_width/aspacet;
    glm::mat4 P = glm::ortho(-projection_width,projection_width,-projection_height,projection_height);
    glm::mat4 V = glm::lookAt(glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    glm::mat4 M = glm::mat4(1.0f);

    rectangle.projection = P;
    rectangle.view = V;
    rectangle.model = M;


    //BACKGROUND
    DE_setColourRectangle(&rectangle, glm::vec4(1.0f,1.0f,1.0f,1.0f));
    DE_setDimRectangle(&rectangle,0.0f , 0.0f, TARGET_DIM, TARGET_DIM);
    DE_drawRectangle(&rectangle);



    for (int i=0; i< RECTS_COUNT; i++)
    {
        DE_setColourRectangle(&rectangle, rects_colors[rects[i].id]);
        DE_setDimRectangle(&rectangle,rects[i].x , rects[i].y, rects[i].w, rects[i].h);
        DE_drawRectangle(&rectangle);
    }


    glFlush();
}

int main(int , char** )
{
    glfwSetErrorCallback(errorCallback);
    if (!glfwInit())
    {
        fprintf(stdout, "[GFLW] failed to init!\n");
        exit(EXIT_FAILURE);
    }
    // OPEN GL ES
    glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_ES_API);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

    win = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, __FILE__, NULL, NULL);
    glfwSetWindowPos(win, 1920/2 - WINDOW_WIDTH/2, 1080/2 - WINDOW_HEIGHT/2);
    glfwMakeContextCurrent(win);

    //GLFW CALLBACK
    //    glfwSetMouseButtonCallback(win, mouseButtonCallback);
    //    glfwSetCursorPosCallback(win, cursorPosCallback);
    //    glfwSetCharCallback(win, charCallback);
    //    glfwSetKeyCallback(win, keyCallback);
    glfwSetScrollCallback(win, scrollCallback);
    glfwSetFramebufferSizeCallback(win, framebufferSizeCallback);

    glfwMakeContextCurrent(win);
    glfwSwapInterval(1);

    //SCALE FAMEBUFFER TO WINDOW SIZE
    glfwGetWindowSize(win, &window_width, &window_height);
    glfwGetFramebufferSize(win, &framebuffer_width, &framebuffer_height);
    scale_x = (float)framebuffer_width/(float)window_width;
    scale_y = (float)framebuffer_height/(float)window_height;


    framebufferSizeCallback(win,WINDOW_WIDTH,WINDOW_HEIGHT);

    printf("GL_VERSION  : %s\n", glGetString(GL_VERSION) );
    printf("GL_RENDERER : %s\n", glGetString(GL_RENDERER) );

    DE_initRectangle(&rectangle, glm::vec4(0,1,0,1), -0.5f, 0.5f, 0.5f, -0.5f, 0.0f);

    initStbRectangles();

    while (!glfwWindowShouldClose(win))
    {
        //cout << "FPS = "  << calculateFPS() << endl;

        glfwPollEvents();
        {
            Render();
        }
        glfwSwapBuffers(win);
    }

    DE_deleteRectangle(&rectangle);
    glfwTerminate();
    return EXIT_SUCCESS;
}

