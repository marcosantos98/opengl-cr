#include <glad.h>
#include <glfw3.h>

#define CR_HOST
#include <cr.h>

int main(void)
{

    if (!glfwInit())
    {
        printf("glfwInit: Couldn't initialize GLFW.\n");
        return 1;
    }

    GLFWwindow* window;
    if (!(window = glfwCreateWindow(1280, 720, "GLFWWindow", NULL, NULL)))
    {
        printf("glfwCreateWindow: Couldn't create window!\n");
        glfwTerminate();
        return 1;
    }

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    cr_plugin ctx;
    cr_plugin_open(ctx, "./build/game_code.dll");
    
    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();

        if(cr_plugin_update(ctx) != 0)
        {
            printf("cr_plugin_update: Return non 0.\n");
            glfwSetWindowShouldClose(window, GLFW_TRUE);
            continue;
        }

        glfwSwapBuffers(window);
    }

    cr_plugin_close(ctx);

    glfwTerminate();

    return 0;
}
