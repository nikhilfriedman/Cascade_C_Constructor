#include "graphics_manager.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include "compile_manager.h"

void graphics_loop(void)
{
    initialize_SDL();
    initialize_TTF();

    SDL_Window   * window   = create_window();
    SDL_Renderer * renderer = create_renderer(window);
    TTF_Font     * dmsans   = create_font(DEFAULT_FONT_LOCATION, 40);
    SDL_Event      event;

    bool quit   = false;
    bool update = true;

    int mouse_x; // current mouse x position
    int mouse_y; // current mouse y position

    int window_w; // current window width
    int window_h; // current window height

    int mouse_icon = 0; // current mouse icon

    while(!quit)
    {
        // poll positions
        SDL_GetMouseState(&mouse_x, &mouse_y);
        SDL_GetWindowSize(window, &window_w, &window_h);

        // poll events
        while(SDL_PollEvent(&event)) 
        {
            switch(event.type)
            {
                case SDL_QUIT:
                    quit = true;
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    break;
            }
        }

        // update all (window resize, etc)

        if(update)
        {
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            SDL_RenderClear(renderer);

            render_panel(renderer, 0, 0, (window_w / 6), window_h);
            render_button(renderer, dmsans, "printf", 40, 40, 180, 80);
            render_button(renderer, dmsans, "if", 40, 160, 180, 80);
            render_button(renderer, dmsans, "else", 40, 280, 180, 80);
            render_button(renderer, dmsans, "return", 40, 400, 180, 80);

            SDL_RenderPresent(renderer);
            // update = false;
        }
    }

    SDL_Quit();
}