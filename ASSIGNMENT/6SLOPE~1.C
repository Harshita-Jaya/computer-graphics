
#include <graphics.h>
#define PI 3.141
#include <math.h>
# define Round(a) (int)(a+0.5)
 int  xmid,ymid;
void Slope(int,int,int,int);
int main(void)
{
   
   int gdriver = DETECT, gmode;
//   int x1=50, x2=150, y1=125, y2=100;
   int x1 = -50,y1 = -100, x2 = 300, y2 = 400;
   initgraph(&gdriver, &gmode, "C:\\TC\\BGI");
  

   setcolor(getmaxcolor());
   xmid = getmaxx()/2;
   ymid = getmaxy()/2;
   

   line(0,ymid,getmaxx(),ymid);
    line(xmid,0,xmid,getmaxy());
    //  printf(" Enter the (x1,y1), (x2,y2) for line :\n ");
    //  scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
   Slope(x1,y1,x2,y2);
   getch();
   closegraph();
   return 0;
}

void Slope(int xs,int ys, int  xe,int ye)
{
	float x11,y11,x22,y22,m,c;
	int dx,dy,i,signx,signy;
	dx=xe-xs;
	dy=ye-ys;
	m=(float)dy/dx;
	c= ys - m * xs;
	if(dx>=0)
	{
		signx=1;
	}
	else
	{
		signx=-1;
	}
	if(dy>=0)
	{
		signy=1;
	}
	else
	{
		signy=-1;
	}
	x11=xs; y11=ys;
	putpixel(xmid+xs,ymid-ys,YELLOW);
	if(abs(dx)>=abs(dy))
	{
		i=1;
		while(i<=dx*signx)
		{
			x11=x11+signx;
			y11=m*x11+c;
			putpixel(xmid+Round(x11),ymid-Round(y11),YELLOW);	
			i++;
		}
	}
	else
	{
		i=1;
		while(i<=dy*signy)
		{
			y11=y11+signy;
			x11=(y11-c)/m;
			putpixel(xmid+Round(x11),ymid-Round(y11),YELLOW);	
			i++;
		}
	}
	
}


/*

#include<graphics.h>
#include<stdio.h>
#include<stdlib.h>

int main(){
	float m, x1=100, x2=300, y1=250, y2=200;
	int x, y, gm, gd = DETECT;

	initgraph(&gd, &gm, "C:\\TC\\BGI");

	// printf("Enter x1, y1, x2, y2");
	// scanf("%f%f%f%f", &x1, &y1, &x2, &y2)	;

	m = (y2-y1)/(x2-x1);
	for(x=1;x<=x2;x++){
		y = m*(x-x1)+y1;
		putpixel(x, y, WHITE);
		delay(10);

	}
	getch();
	closegraph();
}
*/
