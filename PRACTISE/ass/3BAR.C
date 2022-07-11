// DRAW A BAR CHART HAVING ATLEAST THREE BARS

#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>


void main() {
	int gdriver = DETECT, gmode;



	initgraph(&gdriver, &gmode, "C:\\TC\\BGI");
	


	// axes of the graph
	line(140, 400, 490, 400);		// x axis
	outtextxy(491,401, "X");
	line(140, 400, 140, 100);		// y axis
	outtextxy(141,101, "Y");
	outtextxy(141, 401, "0");
	
	setfillstyle(SOLID_FILL,RED);
	bar(190,180,240,400);
	setfillstyle(SOLID_FILL,YELLOW);
	bar(290,310,340,400);
	setfillstyle(SOLID_FILL,GREEN);
	bar(390,220,440,400);
	
	getch();
	closegraph();
}
