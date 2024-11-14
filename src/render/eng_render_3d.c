#include <stddef.h>

#include <SDL3/SDL_render.h>

#include <render/eng_render_3d.h>
#include <eng_util.h>

static vec4 plane[] = {
	{1.0, 0.0, 0.0, 1.0},
	{0.0, 0.0, 0.0, 1.0},
	{0.0, 1.0, 0.0, 1.0},

	{1.0, 0.0, 0.0, 1.0},
	{1.0, 1.0, 0.0, 1.0},
	{0.0, 1.0, 0.0, 1.0}
};

const struct render_vertex_group geo_plane = (struct render_vertex_group) {
	.points      = plane,
	.point_count = array_size(plane),
	.texture     = NULL,
};

static SDL_Renderer* renderer;

void render3d_init(SDL_Window* window)
{
	renderer = SDL_CreateRenderer(window, "render_3d");
}

void render3d_geometry(const struct render_vertex_group* vertex_group)
{
	SDL_Vertex vert[32];

	for (size_t i = 0; i < vertex_group->point_count; i++) {
		const vec4* cur_vec = &vertex_group->points[i];
		SDL_Vertex* cur_vert = &vert[i];

		cur_vert->position.x = cur_vec->x;
		cur_vert->position.y = cur_vec->y;

		cur_vert->color.g = 255;
	}

	SDL_RenderGeometry(renderer, vertex_group->texture,
			vert, vertex_group->point_count, NULL, 0);
}
