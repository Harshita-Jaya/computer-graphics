#include<graphics.h>
#include<stdio.h>

void boundaryFill(int x, int y, int fill_color, int boundary_color){
    if(boundary_color != getpixel(x,y) && fill_color != getpixel(x, y)){
        putpixel(x, y, fill_color);
        boundaryFill(x+1, y, fill_color, boundary_color);
        boundaryFill(x, y+1, fill_color, boundary_color);
        boundaryFill(x-1, y, fill_color, boundary_color);
        boundaryFill(x, y-1, fill_color, boundary_color);
    }

    
}


int main(){
    int gd = DETECT, gm, x, y, r;
    initgraph(&gd, &gm, (char*)"");
    // x = getmaxx()/2; y=getmaxy()/2; r = 50;
    x = 200; y=200; r = 50;
    circle(x, y, r);
    boundaryFill(x, y, 6, 15);
    delay(10000);
    getch();
    closegraph();
    return 1;
}