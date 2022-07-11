#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
int xc,yc;
void bresL(int xs, int ys, int xe, int ye);
int main()
{
  int gdriver = DETECT, gmode;
  int x1=200, x2=100, y1=200, y2=100;

  initgraph(&gdriver, &gmode, "C:\\TURBOC3\\BGI");
  xc = getmaxx()/2;
  yc = getmaxy()/2;
  line(0, yc, getmaxx(), yc);
  line(xc, 0, xc, getmaxy());
  // printf("Enter starting and ending co-ordinates of line:");
  // scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
  bresL(x1,y1,x2,y2);
  getch();
  closegraph();
  return 1;
}
void bresL(int xs, int ys, int xe, int ye)
{
  int x,y,dx,dy,i,p,signx,signy;
  dx=xe-xs;
  dy=ye-ys;
  if(dx >= 0)
    signx =+1;
  else
    signx =-1;
  if(dy >= 0)
    signy =+1;
  else
    signy =-1;
  x=xs;
  y=ys;
  putpixel(xc+xs, yc+ys, YELLOW);
  if(abs(dx) >= abs(dy))     //slope of the line |m|<1
  {
    i=1;
    p = 2*dy*signy-dx*signx;
    while(i<=dx*signx)
    {
      x=x+signx;
      if(p<0)
	p=p+2*dy*signy;
      else
      {
	y=y+signy;
	p=p+2*dy*signy-2*dx*signx;
      }
      putpixel(xc+x, yc-y, YELLOW);
      i++;
    }
  }
  else
  {
    i=1;
    p=2*dx*signx-dy*signy;
    while(i<=dy*signy)
    {
      y=y+signy;
      if(p<0)
	p=p+2*dx*signx;
      else
      {
	x=x+signx;
	p=p+2*dx*signx-2*dy*signy;
      }
      putpixel(xc+x, yc-y, YELLOW);
      i++;
    }
  }
}
