#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<graphics.h>
#include<stdlib.h>
int main() {
	int n,i,xa[10],ya[10],op,tx,ty,xa1[10],ya1[10],theta,xp,yp,rx,ry,
	    sx,sy,shx,shy,xref,yref;
	char d;
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"C:\\TC\\BGI");
	printf("Enter the no of points:\n");
	scanf("%d",&n);
	for(i=0; i<n; i++) {
		printf("Enter the coordinates:\n");
		scanf("%d%d",&xa[i],&ya[i]);
	}
	printf("Enter the shear value:\n");
	scanf("%d%d",&shx,&shy);
	printf("Enter the reference point:\n");
	scanf("%d%d",&xref,&yref);
	printf("Enter the shear direction x or y:\n");
	scanf("%c",&d);
	if(d=='x') {
		for(i=0; i<n; i++) {
			xa1[i]=xa[i]+shx*(ya[i]-yref);
			ya1[i]=ya[i];
		}
	} else {
		for(i=0; i<n; i++) {
			xa1[i]=xa[i];
			ya1[i]=ya[i]+shy*(xa[i]-xref);
		}
	}
	cleardevice();
	//printf("before shearing:\n");
	for(i=0; i<n; i++) {
		line(xa[i],ya[i],xa[(i+1)%n],ya[(i+1)%n]);
	}
	//printf("after shearing:\n");
	for(i=0; i<n; i++) {
		line(xa1[i],ya1[i],xa1[(i+1)%n],ya1[(i+1)%n]);
	}
	getch();
	cleardevice();
	return(0);
}
