#include "display.h"

/*
* The constructor takes width and height of the Window and a title. It then creates the window.
*/
Display::Display(int width, int height,const std::string& title)
{
    //Initializing SDL, it will take care of creating our window
    SDL_Init(SDL_INIT_EVERYTHING);

    // Setting some parameters for exercise purposes
    SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);

    // We use double buffering, so we never draw in the currently shown buffer
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

    //m_window will hold the window, we create it by giving it a title, position, size and the mode. SDL_WINDOW_OPENGL says we want to use OpenGl to draw inside the window.
    m_window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL);

    //m_glContext will give OpenGl the possiblity to draw inside the window
    m_glContext = SDL_GL_CreateContext(m_window);


    GLenum status = glewInit();

    if(status != GLEW_OK)
    {
        std::cerr << "Glew failed to initialize!" << std::endl;
    }
    m_isClosed = false;
}

Display::~Display()
{
    // Detach OpenGL from the window
    SDL_GL_DeleteContext(m_glContext);
    // Kill the window
    SDL_DestroyWindow(m_window);
    //Close SDL
    SDL_Quit();

}
// getter for m_isClosed
bool Display::isClosed()
{
    return m_isClosed;
}
// Clear the buffer and fill it with the color.
void Display::Clear(float r, float g, float b, float a)
{

    glClearColor(r,g,b,a);
    glClear(GL_COLOR_BUFFER_BIT);
}

void Display::Update()
{
    // This swaps the newly drawn buffer into the window
    SDL_GL_SwapWindow(m_window);

    //Checking if the window should be closed
    SDL_Event e;

    while(SDL_PollEvent(&e))
    {
        if(e.type == SDL_QUIT)
        {
            m_isClosed = true;
        }
    }

}
