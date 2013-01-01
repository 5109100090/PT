#include <allegro.h>
#include <math.h>

void init();
void deinit();

int main() {
	init();

int i,j,k,s,t, x1, y1, x2, y2, x3, y3,dist1;
double x,y,pi=M_PI;

BITMAP *Bmp = create_bitmap(640, 480); //membuat canvas untuk tempat menggambar objek 
clear_to_color(Bmp, makecol(255, 255, 255)); //mengganti warna background jadi putih 

s=400;

t=(int)sqrt(s*s-s/2*s/2);

	while (!key[KEY_ESC]) {
		/* put your code here */
int black = makecol(0,0,0); //membuat warna merah 


    x1=320; x2=320-s/2; x3=320+s/2;
    y1=10; y2=10+t; y3=10+t; 
    
    dist1=(int)sqrt((pow(x1-x2,2))+(pow(y1-y2,2)))/3;

    for(i=0,j=1; i<360; i+=60,j++){
    x=sin(i*pi/180)*dist1+320;
    y=cos(i*pi/180)*dist1+240;
    textprintf_ex(Bmp, font, (int)x,(int)y-20, black, -1, "i=%d",i);
    circlefill(Bmp, (int)x, (int)y, 2, black);
    }
    
    line(Bmp, x1, y1, x2, y2, black);
    line(Bmp, x1, y1, x3, y3, black);
    line(Bmp, x2, y2, x3, y3, black);    
  //line (Bmp, 150, 200, 250, 200, makecol(0,255,0)); //membuat garis horizontal dengan warna hijau 
  draw_sprite(screen, Bmp, 0, 0); //menampilkan *Bmp ke layar 		
  		
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
