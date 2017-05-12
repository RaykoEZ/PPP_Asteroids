#ifndef SDLOPENGL_H
#define SDLOPENGL_H
#include <SDL.h>
#include <string>

///\file SDLOpenGL.h
class SDLOpenGL
{
  public :
    ///\brief Constructor for window object
    /// @param[in] _name - title name of window
    /// @param[in] _x - x position of the window
    /// @param[in] _y - y position of the window
    /// @param[in] _width - width of window
    /// @param[in] _height - hieght of window
    SDLOpenGL(const std::string &_name, int _x, int _y, int _width, int _height);

    ///\brief Making updated window the current one
    void makeCurrent() { SDL_GL_MakeCurrent(m_window,m_glContext);}
    ///\brief Swapping between the previous window update to the other
    void swapWindow() { SDL_GL_SwapWindow(m_window); }

    ///\brief update events on inputs
    /// @param[in] _event - stores the update
    void pollEvent(SDL_Event &_event);


  private :
    /// @brief width of screen
    int m_width;
    /// @brief height of screen
    int m_height;
    // xpos of window
    int m_x;
    // ypos of window
    int m_y;
    // name of window
    std::string m_name;

    ///\brief initialize OpenGL_SDL
    void init();
    ///\brief creating GL context
    void createGLContext();
    SDL_GLContext m_glContext;

    ///\brief Error report
    void ErrorExit(const std::string &_msg) const;

    SDL_Window *m_window;

};
#endif // SDLOPENGL_H
