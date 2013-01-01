#include <allegro.h>
#include <math.h>

void init();
void deinit();

int length(int lvl)
{
    int i,j=9;
    
    if(lvl==1) j=10;
    else
    {
        if(lvl>2)
        for(i=0; i<lvl-2; i++)
        j=j*2+9;
    
        j=j+(10*(int)pow(2,lvl-1));
    }

    return j;
}

void draw(BITMAP *bmp,int x1,int y1,int x2,int y2, int lvl)
{
     int black = makecol(0,0,0);
     int a,b,c,i,j,k;

     rect(bmp, x1,y1, x2,y2, black);

     for(k=0;k<lvl-1;k++)
         for(i=1; i<=2; i++)
             for(j=1; j<=2; j++)
             {
                 b=j*3+(j-1)*length(lvl-1);
                 c=i*3+(i-1)*length(lvl-1);
                 draw(bmp, x1+b,y1+c, x1+b+length(lvl-1),y1+c+length(lvl-1), lvl-1);
             }

}

int main() {
	init();

    int lvl=1,x1,y1;
	
    x1=3;
	y1=3;    

        
	while (!key[KEY_ESC]) {
		/* put your code here */
		
	BITMAP *Bmp = create_bitmap(640, 480);
    clear_to_color(Bmp, makecol(255, 255, 255)); 
    
	if(key[KEY_UP]) lvl++;
    if(key[KEY_DOWN]) { lvl--; if(lvl<1)lvl=1; }
    rest(70);	
                 
    draw(Bmp, x1,y1, x1+length(lvl),y1+length(lvl), lvl);
    	
	draw_sprite(screen, Bmp, 0, 0);
	
	clear_bitmap(Bmp);
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
