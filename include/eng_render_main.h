#ifndef _eng_render_main
#define _eng_render_main

#include <stdint.h>

#include <SDL3/SDL_video.h>
#include <SDL3/SDL_render.h>

void render_main__init(SDL_Window* window);
void render_main__finit(void);

void render_main__present_frame(void);

void render_main__add_layer(int16_t index, SDL_Texture* texture, SDL_FRect* texture_rect);

#endif
