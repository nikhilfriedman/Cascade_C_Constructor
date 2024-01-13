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

    double magnification = 1.0; // magnification of graphical elements

    int side_panel_width = DEFAULT_WINDOW_WIDTH / 7;

    // poll positions
    SDL_GetMouseState(&mouse_x, &mouse_y);
    SDL_GetWindowSize(window, &window_w, &window_h);

    while(!quit)
    {
        // poll events
        while(SDL_PollEvent(&event))
        {
            switch(event.type)
            {
                case SDL_QUIT:
                    quit = true;
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    SDL_GetMouseState(&mouse_x, &mouse_y);
                    break;
                case SDL_MOUSEMOTION:
                    SDL_GetMouseState(&mouse_x, &mouse_y);
                    break;
                case SDL_WINDOWEVENT:
                    if(event.window.event == SDL_WINDOWEVENT_RESIZED)
                    {
                        SDL_GetWindowSize(window, &window_w, &window_h);
                        update = true;
                    }
                    break;
            }
        }

        if(abs(mouse_x - side_panel_width) <= 5)
        {
            SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

            render_thick_line(renderer, side_panel_width, 0, side_panel_width, window_h, 5);

            SDL_RenderPresent(renderer);
        } else {
            update = true;
        }

        // update all (window resize, etc)
        if(update)
        {
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            SDL_RenderClear(renderer);

            render_panel(renderer, 0, 0, side_panel_width, window_h);

            // render_grid(renderer, window_w, window_h, 20);

            // render_panel(renderer, 0, 0, (window_w / 6), window_h);
            // render_button(renderer, dmsans, "printf", 40, 40, 180, 80);
            // render_button(renderer, dmsans, "if", 40, 160, 180, 80);
            // render_button(renderer, dmsans, "else", 40, 280, 180, 80);
            // render_button(renderer, dmsans, "return", 40, 400, 180, 80);

            SDL_RenderPresent(renderer);
            update = false;
        }
    }

    SDL_Quit();
}