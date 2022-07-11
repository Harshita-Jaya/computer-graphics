//18.	Write a C program to shear a square about origin.
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
int x1,y1,x2,y2,midx,midy;
void axis() {
	midx=getmaxx() / 2;
	midy=getmaxy() / 2;
	line(0,midy,midx*2,midy);
	line(midx,0,midx,midy*2);
	rectangle(x1,y1,x2,y2);
}
void get() {
	// printf("\n Enter the coordinates x1,y1,x2,y2");
	// scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
    x1 = 0; y1 = 50; x2 = 50; y2 = 0;

	x1= getmaxx() / 2-x1;
	y1= getmaxy() / 2-y1;
	x2 = getmaxx() / 2+x2;
	y2 = getmaxy() / 2+y2;
	axis();
}
void shearing() {
	float sh;
	float xn1,yn1,xn2,yn2,x1n1,y1n1,x2n2,y2n2;
	printf("\n Enter the value for shearing:\n");
	//scanf("%f",&sh);
    sh = 0.75;
	cleardevice();
	xn1=x1+sh*y1;
	yn1=y1;
	xn2=x2;
	yn2=y2;
	x1n1=x2+sh*y1;
	y1n1=y1;
	x2n2=x1;
	y2n2=y2;
	axis();
	line(xn1,yn1,x1n1,y1n1);
	line(x1n1,y1n1,xn2,yn2);
	line(xn2,yn2,x2n2,y2n2);
	line(x2n2,y2n2,xn1,yn1);
}

int main() {
	int ch,gd=DETECT,gm;
	initgraph(&gd,&gm,"C:\\TC\\BGI");
	get();
	shearing();
	getch();
	return 1;
}
