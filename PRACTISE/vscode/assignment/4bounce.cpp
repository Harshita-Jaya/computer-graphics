// DRAW A BOUNCING BALL

#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <dos.h>

int main(){
	int x, y;
	int gd = DETECT, gm, flag = 0;

	initgraph(&gd, &gm, (char*)"");
	
	x = getmaxx()/2;
	y = 30;
	
	while(!kbhit()){
		if(y>=getmaxy()-30 || y<=30)
			flag = !flag;
		setcolor(YELLOW);
		setfillstyle(SOLID_FILL, YELLOW);
		circle(x, y, 30);
		floodfill(x,y,YELLOW);
		delay(5);
		cleardevice();
		if(flag){
			y+=5;
		} else {
			y-=5;
		}
	}
	
	getch();
	closegraph();
	return 0;
	
}
