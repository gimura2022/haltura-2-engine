#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3/SDL_events.h>
#include <SDL3/SDL_init.h>
#include <SDL3/SDL_render.h>

#include <eng_math.h>

struct qsp_node {
	// |---------|
	// | n0 | n1 |
	// |----|----|
	// | n2 | n3 |
	// |---------|
	struct qsp_node *n0, *n1, *n2, *n3;
	struct qsp_node* parent;

	double floor_w, cell_w;

	bool is_solid;
};

#define array_size(x) sizeof(x) / sizeof(x[0])

static const vec4 plane[] = {
	{1.0, 0.0, 0.0, 1.0},
	{0.0, 0.0, 0.0, 1.0},
	{0.0, 1.0, 0.0, 1.0},

	{1.0, 0.0, 0.0, 1.0},
	{1.0, 1.0, 0.0, 1.0},
	{0.0, 1.0, 0.0, 1.0}
};

static mat4x4 mat_perspective;

static void qbp_render_geometry(SDL_Renderer* renderer, const vec4* geometry, const size_t geometry_num)
{
	SDL_Vertex vert[32];

	for (int i = 0; i < geometry_num; i++) {
		vec4 vec = geometry[i];

		vert[i].position.x = vec.x;
		vert[i].position.y = vec.y;

		vert[i].color.r = rand() % 255;
		vert[i].color.g = rand() % 255;
		vert[i].color.b = rand() % 255; 
	}

	SDL_RenderGeometry(renderer, NULL, vert, geometry_num, NULL, 0);
}

void qbp_render_node(SDL_Renderer* renderer, struct qsp_node* node, const vec4* pos)
{
	qbp_render_geometry(renderer, plane, array_size(plane));
}

int main(int argc, char* argv[])
{
	SDL_Window* window     = SDL_CreateWindow("Trianglic", 800, 600, 0);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, NULL);

	mat4x4_create_prespective_matrix(90, 0.1, 100, &mat_perspective);

	double theta = 0.0;

	vec4 pos = { 100, 100, 0, 1 };
	mat4x4 mat_pos;
	mat4x4_create_transform_matrix(&pos, &mat_pos);

	bool quit = false;
	while (!quit) {
		SDL_Event ev;
		while (SDL_PollEvent(&ev)) {
			switch (ev.type) {
			case SDL_EVENT_QUIT:	
				quit = true;
				break;
			}	
		}

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);

		theta += 0.001;
		
		vec4 new_plane[array_size(plane)];
		memcpy(new_plane, plane, sizeof(plane));

		vec4 size = { 100, 100, 100, 1 };
		mat4x4 mat_scale;
		mat4x4_create_size_matrix(&size, &mat_scale);
		mat4x4_apply_to_vec4_array(&mat_scale, new_plane, array_size(new_plane));

		mat4x4_apply_to_vec4_array(&mat_pos, new_plane, array_size(new_plane));

		vec4 rot0 = { 1, 0, 0, 0 };
		vec4 rot1 = { 0, 1, 0, 0 };
		mat4x4 mat_rot0, mat_rot1;
		mat4x4_create_rotation_matrix(theta, &rot0, &mat_rot0);
		mat4x4_create_rotation_matrix(theta, &rot1, &mat_rot1);
		mat4x4_apply_to_vec4_array(&mat_rot0, new_plane, array_size(new_plane));
		mat4x4_apply_to_vec4_array(&mat_rot1, new_plane, array_size(new_plane));

		mat4x4_apply_to_vec4_array(&mat_perspective, new_plane, array_size(new_plane));

		qbp_render_geometry(renderer, new_plane, array_size(new_plane));

		SDL_RenderPresent(renderer);
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}
