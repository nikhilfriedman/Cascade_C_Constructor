#ifndef __GRAPHICS_MANAGER_H__
#define __GRAPHICS_MANAGER_H__

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include "compile_manager.h"

#define WINDOW_TITLE          "Cascade"
#define DEFAULT_WINDOW_WIDTH  1400
#define DEFAULT_WINDOW_HEIGHT 800

#define DEFAULT_FONT_LOCATION "resources/fonts/DM_Sans/static/DMSans-Light.ttf"

// graphics_main.c
void           graphics_loop  (void);

// manage_SDL.c
void           initialize_SDL (void);
void           initialize_TTF (void);
SDL_Window   * create_window  (void);
SDL_Renderer * create_renderer(SDL_Window * window);
TTF_Font     * create_font    (char * font_location, int size);

// gui_render.c
void render_button(SDL_Renderer * renderer, TTF_Font * font, char * text, int x, int y, int w, int h);
void render_panel (SDL_Renderer * renderer, int x, int y, int w, int h);

#endif