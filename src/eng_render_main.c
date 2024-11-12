#include <stdint.h>
#include <stdlib.h>

#include <SDL3/SDL_video.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_rect.h>

#include <eng_render_main.h>

struct render_layer {
	SDL_Texture* texture;
	SDL_FRect* texture_rect;

	struct render_layer *next, *prev;
};

static SDL_Renderer* renderer;

static struct render_layer* start_render_layer = NULL;
static struct render_layer* end_render_layer   = NULL;

void render_main__init(SDL_Window* window)
{
	renderer = SDL_CreateRenderer(window, "render_main");
}

void render_main__finit(void)
{
	struct render_layer* layer = start_render_layer;
	while (layer != NULL) {
		struct render_layer* next = layer->next;
		free(layer);
		layer = next;
	}

	SDL_DestroyRenderer(renderer);
}

void render_main__present_frame(void)
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);	

	for (struct render_layer* i = start_render_layer; i != NULL; i = i->next) {
		SDL_RenderTexture(renderer, i->texture, NULL, i->texture_rect);
	}

	SDL_RenderPresent(renderer);
}

void render_main__add_layer(SDL_Texture* texture, SDL_FRect* texture_rect)
{
	struct render_layer* layer = malloc(sizeof(struct render_layer));

	layer->texture      = texture;
	layer->texture_rect = texture_rect;

	if (start_render_layer == NULL) start_render_layer = layer;
	if (end_render_layer != NULL) end_render_layer->next = layer;
	
	layer->prev      = end_render_layer;
	end_render_layer = layer;
}
