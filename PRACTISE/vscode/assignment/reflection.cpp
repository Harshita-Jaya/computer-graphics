// DATE  27/02/2022

#include<graphics.h>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>

int xmid, ymid;
void refYminusX(int xc, int yc, int r){
    int xc1 = -yc;
    int yc1 = -xc;
    setcolor(YELLOW);
    circle(xmid+xc1,ymid-yc1, r );
}
void refX_axis(int xc, int yc, int r){
    int xc1 = xc;
    int yc1 = -yc;
    setcolor(RED);
    circle(xmid+xc1,ymid-yc1, r );    
}
void refY_axis(int xc, int yc, int r){
    int xc1 = -xc;
    int yc1 = yc;
    setcolor(GREEN);
    circle(xmid+xc1,ymid-yc1, r );  
}

void refYequalX(int xc, int yc, int r){
    int xc1 = yc;
    int yc1 = xc;
    setcolor(BLUE);
    circle(xmid+xc1,ymid-yc1, r );  
}
void refOrigin(int xc, int yc, int r){
    int xc1 = -xc;
    int yc1 = -yc;
    setcolor(MAGENTA);
    circle(xmid+xc1,ymid-yc1, r );  
}

int main(void){
    //char driver [] = "";
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");
    
    int x = 50, y = 60, r = 25;
    xmid = getmaxx()/2;
    ymid = getmaxy()/2; 
    // line axes
    line(xmid, getmaxy(), xmid, 0);
    line(0, ymid, getmaxx(), ymid);
    printf("Color \t Circle:\n");
    printf("WHITE \t ORIGINAL");
    printf("MAGENTA \t ORIGIN");
    printf("RED \t X-AXIS");
    printf("GREEN \t Y-AXIS");
    printf("YELLOW \t Y = -X");
    printf("BLUE \t Y = X");
    setfillstyle(SOLID_FILL, RED);
    circle(xmid+x, ymid -y, r);

    refOrigin(x,y,r);
    refX_axis(x,y,r);
    refY_axis(x,y,r);
    refYequalX(x,y,r);
    refYminusX(x,y,r);
    getch();
    closegraph();

    return 1;
}