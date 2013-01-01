#include <stdio.h>
#include <allegro.h>

void init();
void deinit();

int main() {
	init();
	
	int b,c,i,j,k,n, grs=0;
	float a,x[1000],y[1000],x1[1000],y1[1000],x2[1000],y2[1000],x3[3],y3[3];
	int black=makecol(0,0,0);
	int blue=makecol(0,0,255);
	int white=makecol(255,255,255);
	int red=makecol(255,0,0);
	int green=makecol(0,255,0);
	
	/*--read input--*/
	FILE *f = fopen("testpoint/p1000n.txt", "r");
	
	fscanf(f, "%d", &n);
	
	for(i=0; i<n; i++)
	  fscanf(f, "%f %f", &x[i], &y[i]);
	
	fclose(f);
	/*--read input--*/
	
	/*--sort y--*/
	for(i=0; i<n; i++)
	{
      x1[i]=x[i];
      y1[i]=y[i];
    }
	
	for(i=0; i<n-1; i++)
	  for(j=i+1; j<n; j++)
	  if(y1[i]>y1[j])
	  {
        a=y1[i];
        y1[i]=y1[j];
        y1[j]=a;
        
        a=x1[i];
        x1[i]=x1[j];
        x1[j]=a;
      }
	/*--sort y--*/

	/*--sort x--*/
    for(i=0; i<n; i++)
	{
      x2[i]=x[i];
      y2[i]=y[i];
    }

	for(i=0; i<n-1; i++)
	  for(j=i+1; j<n; j++)
	  if(x2[i]>x2[j])
	  {
        a=x2[i];
        x2[i]=x2[j];
        x2[j]=a;
        
        a=y2[i];
        y2[i]=y2[j];
        y2[j]=a;
      }
	/*--sort x--*/

	BITMAP *bmp = create_bitmap(500, 520);
    clear_to_color(bmp, black);	

	while (!key[KEY_ESC]) {
		/* put your code here */
    grs=0;
	  
	for(i=0; i<n-1; i++)
	{
      line(bmp, (int)x1[i], (int)y1[i], (int)x1[i+1], (int)y1[i+1], blue);
      grs++;
    }
    
    for(i=0; i<n-2; i+=3)
    {
      for(j=i, k=0; j<i+3 && j<n-1; j++, k++)
        {
          x3[k]=x1[j];
          y3[k]=y1[j];
        }
      
      for(j=0; j<2; j++)
        for(k=j+1; k<3; k++)
          if(x3[j]<x3[k])
          {
            a=x3[j];
            x3[j]=x3[k];
            x3[k]=a;
            
            a=y3[j];
            y3[j]=y3[k];
            y3[k]=a;
          }
      
      for(j=0; j<2; j++)
      {
    	line(bmp, (int)x3[j], (int)y3[j], (int)x3[j+1], (int)y3[j+1], blue);
    	grs++;
      }

      for(j=0; j<2; j++)
        for(k=i; k<i+2 && k<n-1; k++)
          if(x3[j]==x1[k] && y3[j]==y1[k] && x3[j+1]==x1[k+1] && y3[j+1]==y1[k+1])
            grs--;
    }
    
	for(i=0; i<n-1; i++)
	{
      if(i==0 || i==n-2)
	  {
        line(bmp, (int)x2[i], (int)y2[i], (int)x2[i+1], (int)y2[i+1], blue);
	    grs++;
      }
    }

    for(i=0; i<n; i++)
	  circlefill(bmp, (int)x[i], (int)y[i], 2, white);

	textprintf_ex(bmp, font, 5, 510, white, 1, "titik = %d",n);
	textprintf_ex(bmp, font, 400, 510, white, 1, "garis = %d",grs);
    draw_sprite(screen, bmp, 0, 0);
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
	res = set_gfx_mode(GFX_AUTODETECT_WINDOWED, 500, 520, 0, 0);
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
