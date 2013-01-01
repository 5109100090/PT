#include <allegro.h>
#include <stdlib.h>
#include <math.h>

void init();
void deinit();


int main() {
	init();
	
     double i,pi=M_PI,x,y,x1,y1,r=10,c1=100,c2=25;
     double d,w;
     int j;
     int black = makecol(0,0,0);
     int red = makecol(255,0,0);

	BITMAP *Bmp = create_bitmap(640, 480);
    clear_to_color(Bmp, makecol(255, 255, 255));

	while (!key[KEY_ESC]) {
		/* put your code here */
	for(w=0; w<=pi; w+=pi/5)
	{
        x=320; y=240;
        for(i=0,j=0; i<=48*pi; i+=pi/100,j++)
        {
                 x1=x;
                 y1=y;
                 r=c1+c2*cos(16*i+w);
                 x=r*cos(i)+320;
                 y=r*sin(i)+240;
                 
                 if(i!=0)
                 //if(j%2==0)
                 line(Bmp, (int)x1, (int)y1, (int)x, (int)y, black);
                 //else
                 //line(Bmp, (int)x1, (int)y1, (int)x, (int)y, red);
        }
}

    draw_sprite(screen, Bmp, 0, 0);
    }

	deinit();
	return 0;
}
END_OF_MAIN()

void init() {
	int depth, res;
	allegro_init();
	depth = desktop_color_depth();
	if (depth == 0) depth = 32;
	set_color_depth(depth);
	res = set_gfx_mode(GFX_AUTODETECT_WINDOWED, 640, 480, 0, 0);
	if (res != 0) {
		allegro_message(allegro_error);
		exit(-1);
	}

	install_timer();
	install_keyboard();
	install_mouse();
	/* add other initializations here */
}

void deinit() {
	clear_keybuf();
	/* add other deinitializations here */
}
