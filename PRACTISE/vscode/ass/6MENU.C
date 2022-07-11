#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>


int main() {
	int gdriver = DETECT, gmode, errorcode;
	int xmax, ymax, xmid, ymid, x1, x2, y1, y2;
	int radius, choice;
	initgraph(&gdriver, &gmode, "C:\\TC\\BGI");
	errorcode = graphresult();
	if(errorcode != grOk){
		printf("Error: %s\n");
		printf("Press any key to halt");
		getch();
		exit(1);
	}
	
	setcolor(getmaxcolor());
	xmax = getmaxx();
	ymax = getmaxy();
	xmid = xmax / 2;
	ymid = ymax / 2;
	
	// MENU START
	
	do{
		printf("What do you want to draw?\n");
		printf("1. Line\n2. Circle\n3. Exit\nEnter your choice: ");
		scanf("%d", &choice);
		switch(choice){
			case 1:
				printf("Enter x1, x2, y1, y2: ");
				scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
				line(x1, y1, x2, y2);
		  //		cleardevice();
				break;
			case 2:
				printf("Enter radius: ");
				scanf("%d", &radius);
				circle(xmid, ymid, radius);
		//		cleardevice();
				break;
			case 3:
				exit(1);
			default:
				printf("Wrong choice entered, try again.");
		}
	      //	cleardevice();
	}while(1);

	getch();
	closegraph();
	return 0;
}
