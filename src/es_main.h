#ifndef __ES_MAIN_H__
#define __ES_MAIN_H__

struct color
{
	int r;
	int g;
	int b;
	int a;
};

typedef void (*update_func_t) (float delta);
typedef void (*render_func_t) ();

void es_start(char* name,
	   unsigned int width, 
	   unsigned int height, 
	  render_func_t render, 
	  update_func_t update);

void es_stop();

void es_delay(int seconds);

void es_set_bgcolor(int red, int green, int blue);

void es_set_draw_color(int red, int green, int blue);
void es_draw_circle(int x, int y, int radius);

#endif
