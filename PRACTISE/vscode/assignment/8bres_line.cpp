#include<graphics.h>
#include<stdio.h>
#include<math.h>
#define round(a) (int)(a+0.5)

void bres(int,int,int,int);
int xc, yc;

int main(){
    int gd = DETECT, gm ;//, x1, y1, x2, y2;
    int x1=100, x2=300, y1=250, y2=200;

    initgraph(&gd, &gm, "C:\\TC\\BGI");
    setcolor(getmaxcolor());
    xc = getmaxx()/2;
    yc = getmaxy()/2;


    line(0,yc,getmaxx(),yc);
    line(xc,0,xc,getmaxy());
    //  printf(" Enter the (x1,y1), (x2,y2) for line :\n ");
    //  scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
    bres(x1,y1,x2,y2);
    getch();
    closegraph();
    return 0;
}

void bres(int x0, int y0, int x1, int y1)
{
    int dx, dy, p, x, y;
 
dx=x1-x0;
dy=y1-y0;
 
x=x0;
y=y0;
 
p=2*dy-dx;
 
while(x<x1)
{
if(p>=0)
{
putpixel(x,y,7);
y=y+1;
p=p+2*dy-2*dx;
}
else
{
putpixel(x,y,7);
p=p+2*dy;
}
x=x+1;
}
}