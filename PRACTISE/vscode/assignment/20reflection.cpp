#include<graphics.h>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>

int xmid, ymid;

void refPoint(int px, int py, int ax, int ay, int bx, int by){
    int tx, ty, rx, ry;
    setcolor(RED);
    circle(px, py, 10);
    setcolor(YELLOW);
    // translation shifting origin at A
    tx = px - ax;
    ty = py - ay;
    bx = bx - ax;
    by = by - ay;

    // Performing rotation in clockwise direction
    rx = px/bx;
    ry = py/by;

    // conjugate
    ry = (-1)*ry;

    // reflection
    px = rx*bx+ax;
    py = rx*bx+ax;

    // draw
    circle(px, py, 10);

}
void refLine();
void refSquare();
void refCircle();
void refTriangle();

int main(void){
    //char driver [] = "";
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");
    // let line be AB with point ax, ay, bx, by
    int ax = 100, ay = 100, bx = 300, by = 300;
    xmid = getmaxx()/2;
    ymid = getmaxy()/2; 

    // line(xmid, getmaxy(), xmid, 0);
    // line(0, ymid, getmaxx(), ymid);

    setcolor(BLUE);
    line(ax,ay,bx,by);
    
    refPoint(50, 50, ax, ay, bx, by);
/*     refLine();
    refSquare();
    refCircle();
    refTriangle();
 */

    getch();
    closegraph();
}