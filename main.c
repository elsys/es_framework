#include <stdio.h>
#include <es_main.h>


int direction_x = 1;
int direction_y = 1;

float x = 300;
float y = 300;

void update(float delta)
{
	if( x > 640 || x < 0 || y > 480 || y < 0) {
		direction_x = -direction_x;
		direction_y = -direction_y;
	}
		
	
	x += direction_x * delta * 100;
	y += direction_y * delta * 100;
    
    printf("%f, %f, %f\n", x, y, delta);
}

void render()
{
	es_draw_circle(x, y, 10);
}

int second_main()
{
    es_set_bgcolor(0, 0, 255);
    es_set_draw_color(255, 255, 255);
	
	char str[] = "Test";
	es_start_with_main_loop(str, 640, 480, render, update);
  
  return 0;
}


int main()
{
    es_set_bgcolor(0, 0, 255);
    es_set_draw_color(255, 255, 255);

    char str[] = "Test 2";
    es_start(str, 640, 480);

    es_start_render();

    es_draw_circle(100, 100, 10);

    es_finish_render();

    es_delay(2000);

    es_destroy();
    return 0;
}
