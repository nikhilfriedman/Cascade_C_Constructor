#include "graphics_manager.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

void render_grid(SDL_Renderer * renderer, int width, int height, int grid_size)
{
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

    for(int i = 0; i < width; i += grid_size)
    {
        SDL_RenderDrawLine(renderer, i, 0, i, height);
    }

    for(int i = 0; i < height; i += grid_size)
    {
        SDL_RenderDrawLine(renderer, 0, i, width, i);
    }
}

void render_thick_line(SDL_Renderer * renderer, int x1, int y1, int x2, int y2, int thickness)
{
    if(thickness > 0) SDL_RenderDrawLine(renderer, x1, y1, x2, y2);

    int line_width = thickness >> 1;

    if(y1 == y2)
    {
        for(int i = 1; i < line_width; i++)
        {
            SDL_RenderDrawLine(renderer, x1, y1 - i, x2, y2 - i);
            SDL_RenderDrawLine(renderer, x1, y1 + i, x2, y2 + i);
        }
    } else {
        for(int i = 0; i < line_width; i++)
        {
            SDL_RenderDrawLine(renderer, x1 - i, y1, x2 - i, y2);
            SDL_RenderDrawLine(renderer, x1 + i, y1, x2 + i, y2);
        }
    }
}

void render_button(SDL_Renderer * renderer, TTF_Font * font, char * text, int x, int y, int w, int h)
{
    SDL_Color white  = {255, 255, 255};
    SDL_Rect  button = {x, y, w, h};

    SDL_SetRenderDrawColor(renderer, 95, 175, 255, 255); // grey
    SDL_RenderFillRect(renderer, &button);

    SDL_Surface * text_surf = TTF_RenderText_Blended(font, text, white);
    SDL_Texture * text_text = SDL_CreateTextureFromSurface(renderer, text_surf);
    SDL_Rect      text_rect = {x + ((w - text_surf -> w) >> 1), // x = x + (button width - text width) / 2
                               y + ((h - text_surf -> h) >> 1), 
                               text_surf -> w, text_surf -> h};

    SDL_RenderCopy(renderer, text_text, NULL, &text_rect);

    SDL_FreeSurface(text_surf);
    SDL_DestroyTexture(text_text);
}

void render_panel(SDL_Renderer * renderer, int x, int y, int w, int h)
{
    SDL_Rect panel = {x, y, w, h};

    SDL_SetRenderDrawColor(renderer, 80, 80, 80, 255);
    SDL_RenderFillRect(renderer, &panel);
}