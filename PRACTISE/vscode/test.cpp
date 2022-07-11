#include<graphics.h>
#include<stdio.h>

int main(int argc, char const *argv[])
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");
    circle(320,240,200);
    rectangle(100, 100, 400, 300);
    getch();
    closegraph();
    return 0;
}

