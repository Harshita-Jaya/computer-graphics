#include<graphics.h>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>

int main(){
	int gd = DETECT, gmode;
	int x1, y1, x2, y2, xmid, ymid;
	char array[80];
	initgraph(&gd, &gmode, "C:\\TC\\BGI");
	xmid = getmaxx()/2;
	ymid = getmaxy()/2;


    line(0, ymid, getmaxx(), ymid);
    line(xmid, 0, xmid, getmaxy());

    x1 = 50; y1 = 100;
    x2 = 140; y2 = 158;

    line(xmid+x1, ymid-y1, xmid+x2, ymid-y2);
    sprintf(array, "(%d, %d)", x1, y1);
    outtextxy(xmid+x1, ymid-y1, array);
    sprintf(array, "(%d, %d)", x2, y2);
    outtextxy(xmid+x2, ymid-y2, array);
	
	getch();
	closegraph();
	return 1;

}
