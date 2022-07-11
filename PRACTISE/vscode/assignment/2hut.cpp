#include<graphics.h>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>

int main(){
	int gd = DETECT, gmode;
	int x, y, xmid, ymid;
	initgraph(&gd, &gmode, (char*)"");
	xmid = getmaxx()/2;
	ymid = getmaxy()/2;
	
	// hut
	rectangle(xmid-100,ymid-100, xmid+100, ymid+100);
	line(xmid-100, ymid-100, xmid, ymid-200);
	line(xmid, ymid-200, xmid+100, ymid-100);
	
	// windows
	rectangle(xmid-80, ymid-80, xmid-20, ymid-20);
	rectangle(xmid+20, ymid-80, xmid+80, ymid-20);
	
	getch();
	closegraph();
	return 1;

}
