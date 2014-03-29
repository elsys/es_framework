#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include "es_main.h"

#include <stdio.h>

void es_p_handle_event();
void es_p_main_loop();
void es_p_destroy();

static SDL_Window   *s_window;
static SDL_Renderer *s_renderer;

static render_func_t render_func;
static update_func_t update_func;

static struct color bg_color = {0, 0, 0, 255};
static struct color current_color = {0, 0, 0, 255};

static int is_running = 1;

void es_start(char* name,
	   unsigned int width, 
	   unsigned int height, 
	  render_func_t render, 
	  update_func_t update)
{
	
    if( SDL_Init(SDL_INIT_EVERYTHING) >= 0 ) {
      s_window = SDL_CreateWindow(name, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN );
      
      if( s_window == 0 ) {
         //TODO error handling
      }

      s_renderer = SDL_CreateRenderer( s_window, -1, 0 );

      if( s_renderer == 0 ) {
        //TODO error handling
      }
    } else {
        //TODO error handling
    }
  
    // bg_color.r = 0;
    // bg_color.g = 0;
    // bg_color.b = 0;
    // bg_color.a = 255;
    //   
    // current_color.r = 0;
    // current_color.g = 0;
    // current_color.b = 0;
    // current_color.a = 255;
    //   
    render_func = render;
    update_func = update;
	
	es_p_main_loop();
	es_p_destroy();
}  

void es_p_destroy()
{   
    SDL_DestroyRenderer( s_renderer );
    SDL_DestroyWindow( s_window );
    SDL_Quit();
}

void es_p_main_loop()
{
	is_running = 1;
    unsigned int old_time = SDL_GetTicks();
    unsigned int new_time = old_time;
  	while( is_running ) {
        old_time = new_time;
        new_time = SDL_GetTicks();
          
  		es_p_handle_event();
  		
      	update_func( (new_time - old_time) / 1000.0 );

  		SDL_SetRenderDrawColor(s_renderer, bg_color.r, bg_color.g, bg_color.b, bg_color.a);
  		SDL_RenderClear(s_renderer);

  		render_func();

  		SDL_RenderPresent(s_renderer);
  	}
}

void es_p_handle_event()
{
	SDL_Event event;
	while( SDL_PollEvent( &event ) ) {
		switch( event.type ) {
			case SDL_KEYUP:
				if( event.key.keysym.sym == SDLK_ESCAPE) {
					es_stop();
        }
				break;
      case SDL_QUIT:
        es_stop();
        break;
		}
	}
}

void es_stop()
{
	is_running = 0;
}

void es_delay(int seconds)
{
  SDL_Delay(seconds);
}

void es_set_bgcolor(int red, int green, int blue)
{
  bg_color.r = red;
  bg_color.g = green;
  bg_color.b = blue;
}

void es_update_callback(update_func_t update)
{
  update_func = update;
}

void es_render_callback(render_func_t render)
{
  render_func = render;
}

void es_set_draw_color(int red, int green, int blue)
{
	current_color.r = red;
	current_color.g = green;
	current_color.b = blue;
}

void es_draw_circle(float x, float y, int radius)
{
	filledCircleRGBA( s_renderer, 
						x, 
						y, 
						radius, 
						current_color.r, 
						current_color.g, 
						current_color.b, 
						current_color.a);
}
