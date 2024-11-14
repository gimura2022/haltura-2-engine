#include <stdbool.h>
#include <stddef.h>
#include <stdbool.h>

#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3/SDL_events.h>
#include <SDL3/SDL_init.h>
#include <SDL3/SDL_render.h>

#include <math/eng_math.h>
#include <eng_util.h>
#include <eng_render_3d.h>
#include <eng_render_main.h>

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


int main(int argc, char* argv[])
{
	SDL_Window* window = SDL_CreateWindow("Trianglic", 800, 600, 0);
	render_main__init(window);

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

		render_main__present_frame();
	}

	render_main__finit();

	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}
