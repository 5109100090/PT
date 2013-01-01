#include <allegro.h>
#include <stdlib.h>
#include <math.h>

void init();
void deinit();

void draw(BITMAP *Bmp, int x1,int y1, int x2,int y2, int x3,int y3, int lvl)
{
    int A[5],i,j,k,s,t,dist1,dist2,dist3;
    double x,y,X,Y,pi=M_PI;
    int black = makecol(0,0,0);
    s=400;
    
    line(Bmp, x1, y1, x2, y2, black);
    line(Bmp, x1, y1, x3, y3, black);
    line(Bmp, x2, y2, x3, y3, black);
    
    for(j=0; j<lvl; j++)
    {
             dist1=(int)sqrt((pow(x1-x2,2))+(pow(y1-y2,2)))/3;
                for(i=330,j=0; i<=390; i+=60,j+=2){
                x=sin(i*pi/180)*dist1+x1;
                y=cos(i*pi/180)*dist1+y1;
                textprintf_ex(Bmp, font, (int)x,(int)y-20, black, -1, "i=%d",i);
                A[j]=(int)x; A[j+1]=(int)y;
                circlefill(Bmp, A[j], A[j+1], 2, black);
                }
                
                for(i=90,j=1; i<=150; i+=60,j++){
                x=sin(i*pi/180)*dist1+x2;
                y=cos(i*pi/180)*dist1+y2;
                textprintf_ex(Bmp, font, (int)x,(int)y-20, black, -1, "i=%d",i);
                circlefill(Bmp, (int)x, (int)y, 2, black);
                
                x=sin(i-90*pi/180)*dist1+x;
                y=cos(i-90*pi/180)*dist1+y;
                
                //draw(Bmp, x1,y1, x2,y2, x3,y3, lvl-1);
                circlefill(Bmp, (int)x, (int)y, 2, black);
                }
                
                for(i=210,j=1; i<=270; i+=60,j++){
                x=sin(i*pi/180)*dist1+x3;
                y=cos(i*pi/180)*dist1+y3;
                textprintf_ex(Bmp, font, (int)x,(int)y-20, black, -1, "i=%d",i);
                circlefill(Bmp, (int)x, (int)y, 2, black);
                }
             
    }
}

int main() {
	init();
	
	int x1,x2,x3,y1,y2,y3;
	int i,j,k,n=2,s,t;
	
	BITMAP *Bmp = create_bitmap(640, 480);
    clear_to_color(Bmp, makecol(255, 255, 255));	
	while (!key[KEY_ESC]) {
		/* put your code here */

    s=400;
    t=(int)sqrt(s*s-s/2*s/2);

    x1=320; x2=320-s/2; x3=320+s/2;
    y1=10; y2=10+t; y3=10+t; 

    draw(Bmp, x1,y1, x2,y2, x3,y3, 1);
    
	draw_sprite(screen, Bmp, 0, 0);
//	clear_bitmap(Bmp);

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
