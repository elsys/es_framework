#include <stdio.h>
#include "es_main.h"


int direction_x = 1;
int direction_y = 1;

int x = 300;
int y = 300;

void update(float delta)
{
	if( x > 640 || x < 0 || y > 480 || y < 0) {
		direction_x = -direction_x;
		direction_y = -direction_y;
	}
		
	
	x += direction_x * delta * 100;
	y += direction_y * delta * 100;
    
    printf("%d, %d, %f\n", x, y, delta);
}

void render()
{
	es_draw_circle(x, y, 10);
}

int main()
{
    es_set_bgcolor(0, 0, 255);
    es_set_draw_color(255, 255, 255);
	
	char str[] = "Test";
	es_start(str, 640, 480, render, update);
  
  return 0;
}
