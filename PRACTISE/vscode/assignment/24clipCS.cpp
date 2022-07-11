#include<graphics.h>
#include<math.h>
#include<dos.h>
#define PI 3.14
#define Round(a) (int)(a+0.5)

typedef struct coord{
    int x, y;
    int code[4];

} PT;

int xmid, ymid, xmin, ymin, xmax, ymax;
float m;

void cohen(PT, PT);
PT setcode(PT);
int both_zero(PT, PT);
int and_op(PT, PT);
PT L_intersect(PT);
PT R_intersect(PT);
PT B_intersect(PT);
PT T_intersect(PT);


int main(){
    int gdriver = DETECT, gmode;
    int i, x1, y1, x2, y2, flag;
    PT p1, p2, temp;

    initgraph(&gdriver, &gmode, (char*)"");

    line(0,ymid,getmaxx(),ymid);
    line(xmid,0,xmid,getmaxy());
    printf(" Enter the window coordinates xmin, ymin and xmax, ymax  :\n ");
    scanf("%d%d%d%d",&xmin,&ymin,&xmax,&ymax);
    rectangle(xmid+xmin, ymid-ymax, xmid+xmin, ymid-ymin);

    printf(" Enter the coordinates for line x1, y1 and x2, y2  :\n ");
    scanf("%d%d%d%d",&p1.x,&p1.y,&p2.x,&p2.y);

    line(xmid+p1.x,ymid-p1.y,xmid+p2.x,ymid-p2.y);
    m = (float)(p2.y-p1.y)/(p2.x - p1.x);
    cohen(p1, p2);
    getch();
    closegraph();
    return 0;
    }

void cohen(PT p11, PT p22){
    int flag = 0;
    p11 = setcode(p11);
}