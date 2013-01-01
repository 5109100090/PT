#include <allegro.h>
#include <math.h>

void init();
void deinit();

void draw(BITMAP *Bmp, int x1,int y1, int x2,int y2, int sdt, int pjg, int lvl)
{
     double pi=M_PI;
     int black = makecol(0,0,0);
     int i,j,k;
     if (lvl==1)
     line(Bmp, x1, y1, x2, y2, black);
     else
     {
         i = (int)(sin(1/3*pi)*(x2-x1)*1/3)-(int)(cos(1/3*pi)*(x2-x1)*1/3)+x1+(x2-x1)*1/3;
         j = (int)(sin(1/3*pi)*(y2-y1)*1/3)+(int)(cos(1/3*pi)*(y2-y1)*1/3)+y1+(y2-y1)*1/3;
         draw(Bmp, x1, y1, x1+(x2-x1)/3, y1+(y2-y1)/3, sdt, pjg, lvl-1);
         draw(Bmp, x1+(x2-x1)/3, y1+(y2-y1)/3, i, j, sdt, pjg, lvl-1);
         draw(Bmp, i, j, x1+(x2-x1)*2/3, y1+(y2-y1)*2/3, sdt, pjg, lvl-1);
         draw(Bmp, x1+(x2-x1)*2/3, y1+(y2-y1)*2/3, x2, y2, sdt, pjg, lvl-1);
     }   
}

int main() {
	init();

    int i,j,k,sdt,pjg;
    double x,y,pi=M_PI;
	BITMAP *Bmp = create_bitmap(640, 480);
    clear_to_color(Bmp, makecol(255, 255, 255));
    pjg=200;
	while (!key[KEY_ESC]) {
		/* put your code here */
		
                x=sin(30*pi/180)*pjg+320;
                y=cos(30*pi/180)*pjg+240;             
                draw(Bmp, 320, 240, (int)x, (int)y, sdt, pjg, 3);
                x=sin(150*pi/180)*pjg+320;
                y=cos(150*pi/180)*pjg+240;             
                draw(Bmp, 320, 240, (int)x, (int)y, sdt, pjg, 3);
                x=sin(90*pi/180)*pjg+320;
                y=cos(90*pi/180)*pjg+240;             
                draw(Bmp, 320, 240, (int)x, (int)y, sdt, pjg, 3);
                            
                
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
