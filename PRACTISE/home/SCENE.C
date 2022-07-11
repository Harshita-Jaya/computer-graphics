#include<graphics.h>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

int main(){
	int gd = DETECT, gm;
	int xmid, ymid;
	initgraph(&gd, &gm,"C:\\TC\\BGI");
	xmid = getmaxx()/2;
	ymid = getmaxy()/2;
	// coordinate axes
//	line(xmid, 0, xmid, getmaxy());
//	line(0, ymid, getmaxx(), ymid);

	// mountain
	line(0,ymid-40,xmid -140, ymid-140);
	line(xmid-140,ymid-140,xmid+40,ymid-40);
	line(xmid, ymid-60,xmid+ 160, ymid-160);
	line(xmid+160, ymid-160, getmaxx(),ymid -60);

	// sun
	circle(xmid, ymid-160, 40);

	// hut 1
	rectangle(xmid+60,ymid+60, xmid+160, ymid+160);
	line(xmid+60, ymid+60, xmid+110, ymid-10);
	line(xmid+110, ymid-10, xmid+160, ymid+60);

	// hut 2
	rectangle(xmid-200, ymid+120,xmid-100,ymid+220);
	line(xmid-200,ymid+120,xmid-150,ymid+50);
	line(xmid-150, ymid+50, xmid-100, ymid+120);

	getch();
	closegraph();
	return 1;
}