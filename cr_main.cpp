#include <stdio.h>

#include <cr.h>
#include <glad.h>
#include <glfw3.h>

CR_EXPORT int cr_main(struct cr_plugin *ctx, enum cr_op operation)
{
    if (operation == CR_STEP)
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(1.f, 1.f, 1.f, 1.f);
        return 0;
    }
    else if (operation == CR_LOAD)
    {
        //Note: To be honest, to this date I can't understand why GL needs to be reloaded every time, 
        //probably because of a need to reload the current context. Idk. But it works. 
        gladLoadGL();
    }

    return 0;
}
