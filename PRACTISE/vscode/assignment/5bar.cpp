// DRAW A BAR CHART HAVING ATLEAST THREE BARS

#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>


int main() {
	int gdriver = DETECT, gmode;



	initgraph(&gdriver, &gmode, (char*)"");
	char *p = "0";
	char *y = "Y";
	char *x = "X";


	// axes of the graph
	line(140, 400, 490, 400);	
	
	outtextxy(491,401, x);
	line(140, 400, 140, 100);		// y axis
	outtextxy(141,101, y);
	outtextxy(141, 401, p);
	
	setfillstyle(SOLID_FILL,RED);
	bar(190,180,240,400);
	setfillstyle(SOLID_FILL,YELLOW);
	bar(290,310,340,400);
	setfillstyle(SOLID_FILL,GREEN);
	bar(390,220,440,400);
	
	getch();
	closegraph();
	return 0;
}
