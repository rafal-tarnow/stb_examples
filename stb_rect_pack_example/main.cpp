#include <iostream>
#include <stdio.h>
#include <cstdlib>
#define GLFW_INCLUDE_ES3
#include <GLFW/glfw3.h>
#include "stb_rect_pack.h"
#include "Rectangle_Renderer.hpp"

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

void errorCallback(int e, const char *d)
{
    printf("Error %d: %s\n", e, d);
}

void framebufferSizeCallback(GLFWwindow * , int width, int height)
{
    int fb_width = width*scale_x;
    int fb_height = height*scale_y;
}


DE_Rectangle rectangle;

void Render()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.3f, 0.3f, 0.3f, 1.0f);



    float rand_0_1 = float(rand() % 1001)/1000.0f;         // v1 in the range 0 to 1000
    glm::vec4 color(float(rand() % 1001)/1000.0f,float(rand() % 1001)/1000.0f,float(rand() % 1001)/1000.0f,1.0f);


    static int i =  0;
    i++;
    if(!(i % 15))
    {
        rectangle.colour = color;
    }


    DE_drawRectangle(&rectangle);

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
    //    glfwSetScrollCallback(win, scrollCallback);
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


//int main()
//{
//    stbrp_context context;

//    struct stbrp_rect rects[100];

//    for (int i=0; i< 100; i++)
//    {
//        rects[i].id = i;
//        rects[i].w = 100+i;
//        rects[i].h = 100+i;
//        rects[i].x = 0;
//        rects[i].y = 0;
//        rects[i].was_packed = 0;
//    }

//    int rectsLength = sizeof(rects)/sizeof(rects[0]);

//    int nodeCount = 4096*2;
//    struct stbrp_node nodes[nodeCount];


//    stbrp_init_target(&context, 4096, 4096, nodes, nodeCount);
//    stbrp_pack_rects(&context, rects, rectsLength);

//    for (int i=0; i< 100; i++)
//    {
//        printf("rect %i (pos.x = %hu, pos.y = %hu) (height = %hu, width = %hu) was_packed=%i\n", rects[i].id, rects[i].x, rects[i].y, rects[i].h, rects[i].w, rects[i].was_packed);
//    }
//    return 0;
//}
