#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
void main()
{
  int gdriver = DETECT, gmode,e,ymax,poly[22],n,i,option=908,x1,y1,x2,y2;
  int xc,yc,r;
  initgraph(&gdriver, &gmode, "C:\\TC\\BGI");
  e=graphresult();
  if(e!=grOk)
  {
   printf("Graphics error: %s\n",grapherrormsg(e));
   printf("Press any key to halt:");
   getch();
   exit(1);
  }
  ymax=getmaxy();
  while(1)
  {
    printf("\n1.Line");
    printf("\n2.Circle");
    printf("\n3.Polygon");
    printf("\n4.Exit");
    printf("\nEnter your choice:");
    scanf("%d",&option);
    switch(option)
    {
      case 1:printf("\nEnter (x1,y1) and (x2,y2):");
	     scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
	     clrscr();
	     cleardevice();
	     line(x1,y1,x2,y2);
	     getch();
	     break;
      case 2:printf("\nEnter (xc,yc) and radius:");
	     scanf("%d%d%d",&xc,&yc,&r);
	     clrscr();
	     cleardevice();
	     circle(xc,yc,r);
	     getch();
	     break;
      case 3:printf("Enter number of sides on polygon:");
	     scanf("%d",&n);
	     for(i=0;i<2*n;i+=2)
	     {
	      printf("Enter vertices(x,y):");
	      scanf("%d",&poly[i]);
	      scanf("%d",&poly[i+1]);
	      poly[i]=poly[i];
	      poly[i+1]=ymax-poly[i+1];
	     }
	     poly[i]=poly[0];
	     poly[i+1]=poly[1];
	     clrscr();
	     cleardevice();
	     drawpoly(n+1,poly);
	     getch();
	     break;
      case 4:closegraph();
	     return;
      default:printf("Invalid choice");
    }
    cleardevice();
  }
}
