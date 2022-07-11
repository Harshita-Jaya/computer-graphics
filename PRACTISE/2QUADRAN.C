
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

int main(void)
{
   /* request auto detection */
   int gdriver = DETECT, gmode, errorcode;
   int xmax, ymax, xmid, ymid, x1, y1, x2,y2;

   /* initialize graphics and local variables */
   initgraph(&gdriver, &gmode, "C:\\TC\\BGI");

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
   xmax = getmaxx();
   ymax = getmaxy();
   
   /* center of screen, origin shift */
   xmid = getmaxx()/2; 
   ymid = getmaxy()/2; 
   
   // horizontal axis
   line(0, ymax/2,xmax, ymax/2);
   
   // vertical axis
   line(xmax/2, 0, xmax/2,ymax);
   
   // custom line
   printf("enter x1, y1, x2, y2");
   scanf("%d%d%d%d", &x1, &y1, &x2, &y2); 
   
   // custom line on shifted origin   
   line(xmid+x1, ymid-y1, xmid+x2,ymid-y2);

   /* clean up */
   getch();
   closegraph();
   return 0;
}

