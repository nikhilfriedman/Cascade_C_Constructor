#include "graphics_manager.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

void initialize_SDL(void)
{
    if(SDL_Init(SDL_INIT_VIDEO) != 0) 
    {
        fprintf(stderr, "SDL_Init initialization error: %s\n", SDL_GetError());
    }
}

void initialize_TTF(void)
{
    if(TTF_Init() < 0) 
    {
        printf("SDL_ttf initialization error: %s\n", TTF_GetError());
    }
}

SDL_Window * create_window(void)
{
    SDL_Window * window = SDL_CreateWindow(WINDOW_TITLE, 
                                           SDL_WINDOWPOS_CENTERED,
                                           SDL_WINDOWPOS_CENTERED,
                                           DEFAULT_WINDOW_WIDTH, DEFAULT_WINDOW_HEIGHT, 
                                           SDL_WINDOW_RESIZABLE
                                          );
    if(!window) 
    {
        fprintf(stderr, "Error SDL creating window: %s\n", SDL_GetError());
        SDL_Quit();
    }

    return window;
}

SDL_Renderer * create_renderer(SDL_Window * window)
{
    SDL_Renderer * renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    
    if(!renderer) 
    {
        fprintf(stderr, "Error creating SDL renderer: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
    }

    return renderer;
}

TTF_Font * create_font(char * font_location, int size)
{
    TTF_Font * font = TTF_OpenFont(DEFAULT_FONT_LOCATION, size);

    TTF_SetFontHinting(font, TTF_HINTING_NORMAL);
    TTF_SetFontStyle(font, TTF_STYLE_NORMAL);

    return font;
}