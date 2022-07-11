#include<graphics.h>
#include<conio.h>
#include<stdio.h>
#include<math.h>
#include<dos.h>
int main() {
	int start[4]= {0,0,0,0},end[4]= {0,0,0,0},code[4];
	int W_xmax,W_ymax,W_xmin,W_ymin;
	int flag=0;
	float slope;
	int x,y,x1,y1,i;
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"C:\\TC\\BGI");
	printf("\nEnter XMin,YMin:");
	scanf("%d%d",&W_xmin,&W_ymin);
	printf("\nEnter XMax,YMax:");
	scanf("%d%d",&W_xmax,&W_ymax);
	printf("\nEnter intial point x and y:");
	scanf("%d%d",&x,&y);
	printf("\nEnter final point x1 and y1:");
	scanf("%d%d",&x1,&y1);
	cleardevice();
	rectangle(W_xmin,W_ymin,W_xmax,W_ymax);
	line(x,y,x1,y1);
	outtextxy(500,140,"Beforeclipping");
	if(y>W_ymax) {
		start[0]=1;//Top
		flag=1;
	}
	if(y<W_ymin) {
		start[1]=1;//Bottom
		flag=1;
	}
	if(x>W_xmax) {
		start[2]=1;//Right
		flag=1;
	}
	if(x<W_xmin) {
		start[3]=1;//Left
		flag=1;
	}
//endpointofLine
	if(y1>W_ymax) {
		end[0]=1;//Top
		flag=1;
	}
	if(y1<W_ymin) {
		end[1]=1;//Bottom
		flag=1;
	}
	if(x1>W_xmax) {
		end[2]=1;//Right
		flag=1;
	}
	if(x1<W_xmin) {
		end[3]=1;//Left
		flag=1;
	}
	if(flag==0) {
		setcolor(RED);
		outtextxy(50,70,"No need of clipping as it is already in window");
		getch();
		closegraph();
	}
	flag=1;
	for(i=0; i<4; i++) {
		code[i]=start[i]&&end[i];
		if(code[i]==1)
			flag=0;
	}
	if(flag==0) {
		setcolor(RED);
		outtextxy(50,70,"No need of clipping as line is completely outside the window");
	} else {
		slope=(float)(y1-y)/(x1-x);
		if(start[2]==0&&start[3]==1) { //left
			y=y+(float)(W_xmin-x)*slope;
			x=W_xmin;
		}
		if(start[2]==1&&start[3]==0) { //right
			y=y+(float)(W_xmax-x)*slope;
			x=W_xmax;
		}
		if(start[0]==1&&start[1]==0) { //top
			x=x+(float)(W_ymax-y)/slope;
			y=W_ymax;
		}
		if(start[0]==0&&start[1]==1) { //bottom
			x=x+(float)(W_ymin-y)/slope;
			y=W_ymin;
		}
		//endpoints
		if(end[2]==0&&end[3]==1) { //left
			y1=y1+(float)(W_xmin-x1)*slope;
			x1=W_xmin;
		}
		if(end[2]==1&&end[3]==0) { //right
			y1=y1+(float)(W_xmax-x1)*slope;
			x1=W_xmax;
		}
		if(end[0]==1&&end[1]==0) { //top
			x1=x1+(float)(W_ymax-y1)/slope;
			y1=W_ymax;
		}
		if(end[0]==0&&end[1]==1) { //bottom
			x1=x1+(float)(W_ymin-y1)/slope;
			y1=W_ymin;
		}
		delay(1500);
		clearviewport();
		rectangle(W_xmin,W_ymin,W_xmax,W_ymax);
		setcolor(RED);
		line(x,y,x1,y1);
		outtextxy(500,120,"Afterclipping");
	}
	getch();
	closegraph();
	return(0);
}

