// draw circle by polynimial equation 
// with 8-WAY Symmetry method

#include<graphics.h>
#include<stdio.h>
#include<conio.h>
#include<math.h>
# define Round(a) (int)(a+0.5)

int xmid, ymid;


void PlotPoints(int x1, int y1, int xc1, int yc1){
		

	putpixel(xmid + (x1+xc1), ymid - (y1+yc1), YELLOW);		//second
	putpixel(xmid + (y1+xc1), ymid - (x1+yc1), YELLOW);		//first
	putpixel(xmid + (-x1+xc1), ymid - (y1+yc1), YELLOW);	//third
	putpixel(xmid + (-y1+xc1), ymid - (x1+yc1), YELLOW);	//fourth
	putpixel(xmid + (-y1+xc1), ymid - (-x1+yc1), YELLOW);	//fifth
	putpixel(xmid + (-x1+xc1), ymid - (-y1+yc1), YELLOW);	//sixth
	putpixel(xmid + (x1+xc1), ymid - (-y1+yc1), YELLOW);	//seventh
	putpixel(xmid + (y1+xc1), ymid - (-x1+yc1), YELLOW);	//eigth
}

void PolyCir(int xc, int yc, int r){
	double x, y;

	// circle from second octant
	x =0; y = r;
	do{
		PlotPoints(Round(x),Round(y),xc,yc);
		//putpixel(xmid+(Round(x)+xc), ymid - (Round(y)+yc), YELLOW);
		//putpixel(xmid+(Round(x)+xc), ymid - (-Round(y)+yc), YELLOW);
		x++;
		y=sqrt((double)(r*r-x*x));
	}while(Round(x) < Round(y));
}

int main(){
	int xc, yc, r;
	
	int gd = DETECT, gm;
	
	initgraph(&gd, &gm, "C:\\TC\\BGI");
	xmid = getmaxx()/2;
	ymid = getmaxy()/2;
	
	line(xmid, 0, xmid, getmaxy());
	line(0, ymid, getmaxx(), ymid);
	
	// printf("Enter xc, yc, r: ");
	// scanf("%d%d%d", &xc, &yc, &r);
    xc = 100; yc=100; r=100;
	PolyCir(xc, yc, r);
	
	getch();
	closegraph();
	return 0;
	
}