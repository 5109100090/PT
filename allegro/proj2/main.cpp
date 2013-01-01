#include <allegro.h>
#include <stdlib.h>
#include <math.h>

void init();
void deinit();

int main() {
	init();
    
    int *a,sdt,i,j,k=3,l=2,rad;
    double pi=M_PI,x,y;
    int black = makecol(0,0,0);
    
	while (!key[KEY_ESC]) {
		/* put your code here */
	
	BITMAP *Bmp = create_bitmap(640, 480);
    clear_to_color(Bmp, makecol(255, 255, 255));
	
	if(key[KEY_SPACE]) l++;
	
    if(key[KEY_UP]) k++;
    
    if(key[KEY_DOWN]) { k--; if(k<3)k=3; }
    rest(70);
    
	a=(int*)malloc(2*k*sizeof(int)+4);
    
    textprintf_ex(Bmp, font, 20, 20, black, -1, "Press UP or DOWN to change level, and SPACE to change mode.");
    textprintf_ex(Bmp, font, 20, 35, black, -1, "Mode = %d, Level = %d", l%2+1, k);
    
    rad=200;
    sdt=360/k;
    
	for(i=180,j=2; j<2*k+2; i+=sdt,j+=2)
	{             
               x=sin(i*pi/180)*rad+320;
               y=cos(i*pi/180)*rad+240;
               
               a[j]=(int)x; a[j+1]=(int)y;
               
               circlefill(Bmp,a[j],a[j+1],2, black);
    }
    a[0]=320;a[1]=240-rad;
    for(i=0; i<2*k; i+=2)
    {
             for(j=2; j<2*k+2; j+=2)
             {
                      if(l%2==0)    line (Bmp, a[j-2], a[j-1], a[j], a[j+1], black);
                      else          line (Bmp, a[i], a[i+1], a[j], a[j+1], black);
             }
             line (Bmp, a[j-2], a[j-1], a[0], a[1], black);
    }
	
	draw_sprite(screen, Bmp, 0, 0);
    clear_bitmap(Bmp);
    free(a);
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
