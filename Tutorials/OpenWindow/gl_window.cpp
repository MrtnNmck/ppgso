//
// Created by Martin on 30. 9. 2015.
//

#include <stdio.h>
#include <stdlib.h>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include "gl_window.h"

using namespace glm;

int main ()
{
    if (!glfwInit())
    {
        fprintf(stderr, "Failed to initialize GLFW");
        return -1;
    }

    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    auto window = glfwCreateWindow(512, 512, "Tutorial 01", NULL, NULL);
    if (window == NULL)
    {
        fprintf(stderr, "Failed to open a window.");
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glewExperimental = true;

    if (glewInit() != GLEW_OK)
    {
        fprintf(stderr, "Failed to initialize GLEW.");
        return -1;
    }

    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

    do
    {
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    while(glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(window) == 0);
}