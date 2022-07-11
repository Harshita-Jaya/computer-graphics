// reflect  a trianhle about x axis, y axis, origi, x = y and x = -y
#include<graphics.h>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>

int xmid, ymid;
void refYminusX(int x, int y, int x1, int y1, int x2, int y2){
    int t, t1, t2;
    t = x; x = -y; y = -t;
    t1 = x1; x1 = -y1; y1 = -t1;
    t2 = x2; x2 = -y2; y2 = -t2;
    setcolor(YELLOW);
    line(xmid+x, ymid -y, xmid+x1, ymid-y1);
    line(xmid+x1, ymid -y1, xmid+x2, ymid-y2);
    line(xmid+x2, ymid -y2, xmid+x, ymid-y);
}
void refX_axis(int x, int y, int x1, int y1, int x2, int y2){
    y = -y;
    y1 = -y1; 
    y2 = -y2;
    setcolor(RED);
    line(xmid+x, ymid -y, xmid+x1, ymid-y1);
    line(xmid+x1, ymid -y1, xmid+x2, ymid-y2);
    line(xmid+x2, ymid -y2, xmid+x, ymid-y);    
}
void refY_axis(int x, int y, int x1, int y1, int x2, int y2){
    x = -x;
    x1 = -x1; x2 = -x2;
    setcolor(GREEN);
    line(xmid+x, ymid -y, xmid+x1, ymid-y1);
    line(xmid+x1, ymid -y1, xmid+x2, ymid-y2);
    line(xmid+x2, ymid -y2, xmid+x, ymid-y);  
}

void refYequalX(int x, int y, int x1, int y1, int x2, int y2){
    int t, t1, t2;
    t = x; x = y; y = t;
    t1 = x1; x1 = y1; y1 = t1;
    t2 = x2; x2 = y2; y2 = t2;
    setcolor(BLUE);
    line(xmid+x, ymid -y, xmid+x1, ymid-y1);
    line(xmid+x1, ymid -y1, xmid+x2, ymid-y2);
    line(xmid+x2, ymid -y2, xmid+x, ymid-y);  
}
void refOrigin(int x, int y, int x1, int y1, int x2, int y2){
    x = -x;x1 = -x1; x2 = -x2;
    y = -y;
    y1 = -y1; 
    y2 = -y2;
    setcolor(MAGENTA);
    line(xmid+x, ymid -y, xmid+x1, ymid-y1);
    line(xmid+x1, ymid -y1, xmid+x2, ymid-y2);
    line(xmid+x2, ymid -y2, xmid+x, ymid-y);  
}

int main(void){
    //char driver [] = "";
    int gd = DETECT, gm;


    int x = 100, y = 100, x1 = 200, y1 = 200, x2 = 300, y2 = 100;
    initgraph(&gd, &gm , "C:\\TC\\BGI");
    xmid = getmaxx()/2;
    ymid = getmaxy()/2;
    // line axes
    line(xmid, getmaxy(), xmid, 0);
    line(0, ymid, getmaxx(), ymid);
    printf("Color \t Triangle:\n");
    printf("WHITE \t ORIGINAL\n");
    printf("MAGENTA \t ORIGIN\n");
    printf("RED \t X-AXIS\n");
    printf("GREEN \t Y-AXIS\n");
    printf("YELLOW \t Y = -X\n");
    printf("BLUE \t Y = X\n");
    line(xmid+x, ymid -y, xmid+x1, ymid-y1);
    line(xmid+x1, ymid -y1, xmid+x2, ymid-y2);
    line(xmid+x2, ymid -y2, xmid+x, ymid-y);

    refOrigin(x,y,x1, y1, x2, y2);
    refX_axis(x,y,x1, y1, x2, y2);
    refY_axis(x,y,x1, y1, x2, y2);
    refYequalX(x,y,x1, y1, x2, y2);
    refYminusX(x,y,x1, y1, x2, y2);
    getch();
    closegraph();

    return 1;
}
