#include<graphics.h>
#include<stdio.h>

void floodFill(int x, int y, int fill_color, int boundary_color){
    if(boundary_color == getpixel(x,y)){
        delay(1);
        putpixel(x, y, fill_color);
        floodFill(x+1, y, fill_color, boundary_color);
        floodFill(x-1, y, fill_color, boundary_color);
        floodFill(x, y+1, fill_color, boundary_color);
        floodFill(x, y-1, fill_color, boundary_color);
    }

    
}


int main(){
    int gd = DETECT, gm, x, y, r;
    initgraph(&gd, &gm, (char*)"");
    x = getmaxx()/2; y=getmaxy()/2; r = 20;
    circle(x, y, r);
    floodFill(x, y, 10, 0);
    getch();
    closegraph();
    return 1;
}