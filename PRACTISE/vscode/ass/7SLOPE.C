
#include <graphics.h>
#define PI 3.141
#include <math.h>
# define Round(a) (int)(a+0.5)
 int  xmid,ymid;
void Slope(int,int,int,int);
int main(void)
{
   /* request auto detection */
   int gdriver = DETECT, gmode, errorcode;
   int x1,y1,x2,y2;

   /* initialize graphics and local variables */
   initgraph(&gdriver, &gmode, "C:\\TC\BGI");

   /* read result of initialization */
   errorcode = graphresult();
   /* an error occurred */
   if (errorcode != grOk)
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1);
   }

   setcolor(getmaxcolor());
   xmid = getmaxx()/2;
   ymid = getmaxy()/2;

   /* draw a diagonal line */
   /*line(0, 0, xmax, ymax);  */
   line(0,ymid,getmaxx(),ymid);
    line(xmid,0,xmid,getmaxy());
     printf(" Enter the (x1,y1), (x2,y2) for line :\n ");
     scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
   Slope(x1,y1,x2,y2);
   /* clean up */
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
