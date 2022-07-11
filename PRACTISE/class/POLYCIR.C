// draw circle by polynimial equation 
// without 8-WAY Symmetry method
// 31-01-22
#include<graphics.h>
#include<stdio.h>
#include<conio.h>
# define Round(a) (int)(a+0.5)
void PolyCir(int xc, int yc, int r){
	double x, y;
	
	int xmid = getmaxx()/2;
	int ymid = getmaxy()/2;
	// circle from -r to r
	x =-r; y = 0.0;
	do{
		putpixel(xmid+(Round(x)+xc), ymid - (Round(y)+yc), YELLOW);
		putpixel(xmid+(Round(x)+xc), ymid - (-Round(y)+yc), YELLOW);
		x++;
		y=sqrt((double)(r*r-x*x));
	}while(Round(x) < r);
}



int main(){
	int xc, yc, r;
	
	int gd = DETECT, gm;
	
	initgraph(&gd, &gm, "C:\\TC\\BGI");
	
	line(getmaxx()/2, 0, getmaxx()/2, getmaxy());
	line(0, getmaxy()/2, getmaxx(), getmaxy()/2);
	
	printf("Enter xc, yc, r: ");
	scanf("%d%d%d", &xc, &yc, &r);
	PolyCir(xc, yc, r);
	
	getch();
	closegraph();
	return 0;
	
}
