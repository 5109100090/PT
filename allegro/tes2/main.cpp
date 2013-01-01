#include <allegro.h>
#include <stdlib.h>
#include <time.h>

void init();
void deinit();

int main() {
	init();
	
	int black = makecol(0,0,0);
	int blue = makecol(0,0,255);

      int i,a,c=0,PjgStr=0,random,salah=0;
      char B[15],input,
      A[10][15]={"purwodadi","pekalongan","magelang","rembang","blora","cilacap","karanganyar","purwokerto","jepara","brebes"};
      
      srand((unsigned)time(NULL));
      
      PALETTE palette;
      FONT *font1=load_font("fonts/ex05.pcx", palette, NULL);
      FONT *font2=load_font("font/ExpoBlackSSi48B.pcx", palette, NULL);
      
      random=rand()%10;

      //length of string
      while(A[random][PjgStr]!='\0')
      PjgStr++;
      
      for(i=0; i<PjgStr; i++)
        B[i]=' ';

	while (!key[KEY_ESC]) {
		/* put your code here */

	BITMAP *bmp = create_bitmap(640, 480);
    clear_to_color(bmp, makecol(255, 255, 255));	

	input = readkey();
	
	textprintf_ex(bmp, font1, 10, 10, makecol(255,0,0), -1 , "guess = %c", input);	
                     
    for(i=0, a=0; i<PjgStr; i++)
    {
      if(input==A[random][i])
      {
        B[i]=A[random][i];
        c++;
        textout_ex(bmp, font1, "[correct]", 20, 70, blue, -1);
      }	
      else
      {
        if(input>='a' && input <='z' || input>='A' && input <='Z')
        {
          a++;
          //textout_ex(bmp, font1, "[wrong]", 20, 70, blue, -1);
        }
      }
    }
    
    if(a==PjgStr)
       salah++;
       
    textprintf_ex(bmp, font1, 400, 100, makecol(255,100,255), -1 , "salah = %d", salah);

	for(i=0; i<PjgStr; i++)
	  textprintf_ex(bmp, font1, (i+1)*20, 30, makecol(100,255,100), -1 , "%c", B[i]);

	for(i=0; i<PjgStr; i++)
	  line(bmp, (i+1)*20, 50, (i+1)*20+10, 50, black);
	
    if(c>=PjgStr)
      textout_ex(bmp, font2, "you win!!", 50, 100, black, -1);
    else
      textout_ex(bmp, font2, "[guess letter]", 50, 100, black, -1);
	
    draw_sprite(screen, bmp, 0, 0);
    clear_bitmap(bmp);
    }
    destroy_font(font1);
    destroy_font(font2);
	
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
