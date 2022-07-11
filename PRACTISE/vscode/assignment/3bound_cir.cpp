#include<graphics.h>
#include<stdlib.h>
#include<stdio.h>

int main(void){
	int gd = DETECT, gmode;
	int x, y, xmin = 30, ymin = 20, xmax = 560, ymax = 460, r = 20;
	initgraph(&gd, &gmode, (char*)"");

	while(!kbhit()){
		for(x = xmin, y = ymin; x<xmax ; x+=10){
			if(kbhit())	exit(1);
			circle(x, y, r);
			delay(100);
			cleardevice();
		}
		for(x = xmax, y = ymin; y<ymax ; y+=10){
			if(kbhit())	exit(1);
			circle(x, y, r);
			delay(100);
			cleardevice();
		}
		for(x = xmax, y = ymax; x>xmin ; x-=10){
			if(kbhit())	exit(1);
			circle(x, y, r);
			delay(100);
			cleardevice();
		}
		for(x = xmin, y = ymax; y>ymin ; y-=10){
			if(kbhit())	exit(1);
			circle(x, y, r);
			delay(100);
			cleardevice();
		}
	}

	getch();
	closegraph();
	return 0;
}

