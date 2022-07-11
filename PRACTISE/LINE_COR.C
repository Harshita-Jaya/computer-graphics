#include <graphics.h>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>

int main(void){
	int gdriver = DETECT, gm, ec;
	int xmax, ymax, x1, y1, x2, y2, xmid, ymid;
	char buffer[80];


	initgraph(&gdriver, &gm, "C:\\TC\\BGI");

	ec = graphresult();
	if(ec != grOk){
		printf("ERROR");
		getch();
		exit(1);
	}

	setcolor(getmaxcolor());

	xmax = getmaxx();
	ymax = getmaxy();

	xmid = xmax /2;
	ymid = ymax/2;
	 // horizontal axis
   line(0,ymid,xmax, ymid);

   // vertical axis
      line(xmid, 0, xmid,ymax);
   
	printf("Enter x1, y1, x2, y2\n");
	scanf("%d%d%d%d", &x1, &x2, &y1,&y2);

	line(xmid + x1,ymid - y1,xmid + x2, ymid - y2);
	sprintf(buffer,"(%d,%d)",x1,y1);
	outtextxy(xmid+x1, ymid-y1, buffer);
	sprintf(buffer,"(%d,%d)",x2, y2);
	outtextxy(xmid+x2, ymid-y2, buffer);
	
	getch();
	closegraph();
	return 0;
}
