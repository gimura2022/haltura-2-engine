#ifndef _eng_render_h
#define _eng_render_h

#include <stddef.h>

#include <SDL3/SDL_video.h>
#include <SDL3/SDL_render.h>

#include <eng_math.h>

struct render_vertex_group {
	vec4* points;
	size_t point_count;

	SDL_Texture* texture;
};

extern const struct render_vertex_group geo_plane;

void render3d_init(SDL_Window* window);
void render3d_geometry(const struct render_vertex_group* vertex_group);

#endif
