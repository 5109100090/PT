#include <allegro.h>
//#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void init();
void deinit();

int main() {
	init();
	
	int ntitik, *idxBelum, *idxSudah, nsudah, *hub1, *hub2;
	float *xtitik, *ytitik;
	double *distance,*distance2,dist,a,b;
	int i,j,k,l;
	int black = makecol(0,0,0);

	BITMAP *Bmp = create_bitmap(640, 480);
    clear_to_color(Bmp, makecol(255, 255, 255)); 
	
	//scanf("%d",&ntitik);
	ntitik=5;

	idxBelum=(int*)malloc(ntitik*(sizeof(int)));
	idxSudah=(int*)malloc(ntitik*(sizeof(int)));
	hub1=(int*)malloc(ntitik*(sizeof(int)));
	hub2=(int*)malloc(ntitik*(sizeof(int)));
	xtitik=(float*)malloc(ntitik*(sizeof(float)));
	ytitik=(float*)malloc(ntitik*(sizeof(float)));

        	
	srand((unsigned)time(NULL));
	
	for(i=0; i<ntitik; i++)
	{
             xtitik[i]=rand()%600+20;
             ytitik[i]=rand()%440+20;
             idxBelum[i]=i;
             
             textprintf_ex(Bmp, font, (int)xtitik[i]-2, (int)ytitik[i]-10, black, -1, "%d", i);
             circlefill(Bmp,(int)xtitik[i],(int)ytitik[i],2, black);
    }
    
	while (!key[KEY_ESC]) {
		/* put your code here */
		
    	distance=(double*)malloc(ntitik*(sizeof(double)));
    distance2=(double*)malloc(ntitik*(sizeof(double)));
    
    for(i=0; i<ntitik; i++)
    {
             for(j=0,b=640, k=0; j<ntitik; j++)
                      a=sqrt((pow((xtitik[i]-xtitik[j]),2))+(pow((ytitik[i]-ytitik[j]),2)));
                      if(a>b)
                      b=a;
             
             distance[i]=b;
    }	
    hub1[0]=0;
    dist=distance2[0];
    for(i=0; i<ntitik; i++)
    {
             if(dist>distance[i])
             dist=distance[i];
             hub2[0]=i;
    }
    
    /*for(i=0; i<ntitik; i++)
    {
             hub1[i]=i;
             //hitung jarak
             for(j=0, k=0; j<ntitik; j++,k++)
             {
                 if(j!=i)
                 distance[k]=sqrt((pow((xtitik[i]-xtitik[j]),2))+(pow((ytitik[i]-ytitik[j]),2)));
                 else
                 distance[k]=1000.00;
             }
                //cari jarak yg paling dekat
                dist=distance[0];
                
                hub2[i]=0;
                
                for(k=0; k<ntitik; k++)
                {
                            if(k!=i && dist>distance[k])
                            {
                                                          hub2[i]=k;
                                                          dist=distance[k];
                            }
                }
             
    }*/
                         
    for(i=0; i<ntitik; i++)
    line (Bmp, (int)xtitik[hub1[i]], (int)ytitik[hub1[i]], (int)xtitik[hub2[i]], (int)ytitik[hub2[i]], black);
    
    draw_sprite(screen, Bmp, 0, 0);
    
    free(distance2);
    free(distance);
	}
    free(idxBelum);
    free(idxSudah);
    free(hub1);
    free(hub2);
    free(xtitik);
    free(ytitik);

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
