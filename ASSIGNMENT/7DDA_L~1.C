
#include<graphics.h>
#include<stdio.h>
#include<math.h>
#define round(a) (int)(a+0.5)

void dda_line(int,int,int,int);
int xc, yc;

int main(){
    int gd = DETECT, gm ;//, x1, y1, x2, y2;
     int x1=50, x2=150, y1=125, y2=100;

    initgraph(&gd, &gm, "C:\\TC\\BGI");
    setcolor(getmaxcolor());
    xc = getmaxx()/2;
    yc = getmaxy()/2;


    line(0,yc,getmaxx(),yc);
    line(xc,0,xc,getmaxy());
    //  printf(" Enter the (x1,y1), (x2,y2) for line :\n ");
    //  scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
    dda_line(x1,y1,x2,y2);
    getch();
    closegraph();
    return 0;
}


void dda_line(int x11, int y11, int x22, int y22){
    int dx, dy, steps, i;
    float x, y, b, c;
    dx = x22 - x11;
    dy = y22 - y11;
    b = x11; c = y11;
    putpixel((xc+round(b)), (yc-round(c)), YELLOW);
    if(abs(dx)>abs(dy)){
        steps = abs(dx);
    } else {
        steps = abs(dy);
    }

    x = dx/(float) steps;
    y = dy/(float) steps;

    for(i = 1; i <= steps; i++){
        b+=x;
        c+=y;
         putpixel((xc+round(b)), (yc-round(c)), YELLOW);
    }
}
