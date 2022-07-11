#include<graphics.h>
#define Round(a) (int)(a+0.5)
int xmid,ymid;
void refpoint(int xp1,int yp1,float m,float c)//point
{
	float xp11,yp11;
	xp11=xp1*(1-m*m)/(m*m+1)+yp1*(2*m)/(m*m+1)-(2*c*m)/(m*m+1);
	yp11=xp1*(2*m)/(m*m+1)+yp1*(m*m-1)/(m*m+1)+(2*c)/(m*m+1);
	putpixel(xmid+Round(xp11),ymid-Round(yp11),WHITE);
}
void refline(int xl1,int yl1,int xl2,int yl2,float m,float c)//line
{
	float xl11,yl11,xl22,yl22;
	xl11=xl1*(1-m*m)/(m*m+1)+yl1*(2*m)/(m*m+1)-(2*c*m)/(m*m+1);
	yl11=xl1*(2*m)/(m*m+1)+yl1*(m*m-1)/(m*m+1)+(2*c)/(m*m+1);
	xl22=xl2*(1-m*m)/(m*m+1)+yl2*(2*m)/(m*m+1)-(2*c*m)/(m*m+1);
	yl22=xl2*(2*m)/(m*m+1)+yl2*(m*m-1)/(m*m+1)+(2*c)/(m*m+1);
	line(xmid+Round(xl11),ymid-Round(yl11),xmid+Round(xl22),ymid-Round(yl22));
}

float calc_x(float x, float y, float m, float c){
	return (x*(1-m*m)/(m*m+1)+y*(2*m)/(m*m+1)-(2*c*m)/(m*m+1));
}

float calc_y(float x, float y, float m, float c){
	return (x*(2*m)/(m*m+1)+y*(m*m-1)/(m*m+1)+(2*c)/(m*m+1));
}

void refsqu(int xs1,int ys1,int xs2,int ys2,int xs3,int ys3,int xs4,int ys4,float m,float c)//square
{
	float xs11,ys11,xs22,ys22,xs33,ys33,xs44,ys44;
	xs11 = calc_x(xs1,ys1,m,c);
	//xs11=xs1*(1-m*m)/(m*m+1)+ys1*(2*m)/(m*m+1)-(2*c*m)/(m*m+1);
	ys11=xs1*(2*m)/(m*m+1)+ys1*(m*m-1)/(m*m+1)+(2*c)/(m*m+1);
	xs22=xs2*(1-m*m)/(m*m+1)+ys2*(2*m)/(m*m+1)-(2*c*m)/(m*m+1);
	ys22=xs2*(2*m)/(m*m+1)+ys2*(m*m-1)/(m*m+1)+(2*c)/(m*m+1);
	xs33=xs3*(1-m*m)/(m*m+1)+ys3*(2*m)/(m*m+1)-(2*c*m)/(m*m+1);
	ys33=xs3*(2*m)/(m*m+1)+ys3*(m*m-1)/(m*m+1)+(2*c)/(m*m+1);
	xs44=xs4*(1-m*m)/(m*m+1)+ys4*(2*m)/(m*m+1)-(2*c*m)/(m*m+1);
	ys44=xs4*(2*m)/(m*m+1)+ys4*(m*m-1)/(m*m+1)+(2*c)/(m*m+1);
	line(xmid+Round(xs11),ymid-Round(ys11),xmid+Round(xs22),ymid-Round(ys22));
	line(xmid+Round(xs22),ymid-Round(ys22),xmid+Round(xs33),ymid-Round(ys33));
	line(xmid+Round(xs33),ymid-Round(ys33),xmid+Round(xs44),ymid-Round(ys44));
	line(xmid+Round(xs44),ymid-Round(ys44),xmid+Round(xs11),ymid-Round(ys11));
}
void reftri(int xt1,int yt1,int xt2,int yt2,int xt3,int yt3,float m,float c)//triangle
{
	float xt11,yt11,xt22,yt22,xt33,yt33;
	xt11=xt1*(1-m*m)/(m*m+1)+yt1*(2*m)/(m*m+1)-(2*c*m)/(m*m+1);
	yt11=xt1*(2*m)/(m*m+1)+yt1*(m*m-1)/(m*m+1)+(2*c)/(m*m+1);
	xt22=xt2*(1-m*m)/(m*m+1)+yt2*(2*m)/(m*m+1)-(2*c*m)/(m*m+1);
	yt22=xt2*(2*m)/(m*m+1)+yt2*(m*m-1)/(m*m+1)+(2*c)/(m*m+1);
	xt33=xt3*(1-m*m)/(m*m+1)+yt3*(2*m)/(m*m+1)-(2*c*m)/(m*m+1);
	yt33=xt3*(2*m)/(m*m+1)+yt3*(m*m-1)/(m*m+1)+(2*c)/(m*m+1);
	line(xmid+Round(xt11),ymid-Round(yt11),xmid+Round(xt22),ymid-Round(yt22));
	line(xmid+Round(xt22),ymid-Round(yt22),xmid+Round(xt33),ymid-Round(yt33));
	line(xmid+Round(xt33),ymid-Round(yt33),xmid+Round(xt11),ymid-Round(yt11));
}
void refcir(int xc,int yc,int r,float m,float c)//circle
{
	float xc1,yc1;
	xc1=xc*(1-m*m)/(m*m+1)+yc*(2*m)/(m*m+1)-(2*c*m)/(m*m+1);
	yc1=xc*(2*m)/(m*m+1)+yc*(m*m-1)/(m*m+1)+(2*c)/(m*m+1);
	circle(xmid+xc1,ymid-yc1,r);
}
void main()
{
	int gdriver=DETECT,gmode;

	int xp1,yp1;//point
	int xl1,yl1,xl2,yl2;//line
	int xs1,ys1,xs2,ys2,xs3,ys3,xs4,ys4;//square
	int xt1,yt1,xt2,yt2,xt3,yt3;//triangle
	int xc,yc,r;//circle
	int x1,y1,x2,y2;//line
	int l;
	float m,c;

	initgraph(&gdriver,&gmode,"c://tc//bgi");
	xmid=getmaxx()/2;
	ymid=getmaxy()/2;
	line(0,ymid,getmaxx(),ymid);
	line(xmid,0,xmid,getmaxy());

	printf("Enter (x1,y1) and (x2,y2) for reference line:");
	scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
	line(xmid+Round(x1),ymid-Round(y1),xmid+Round(x2),ymid-Round(y2));

	m=(float)(y2-y1)/(x2-x1);
	c=(float)y1-(float)m*x1;

	printf("Enter the point cordinates :");
	scanf("%d%d",&xp1,&yp1);
	putpixel(xmid+Round(xp1),ymid-Round(yp1),WHITE);

	printf("Enter the cordinates of square and length :");
	scanf("%d%d%d",&xs1,&ys1,&l);
	xs2=xs1+l;
	ys2=ys1;
	xs3=xs1+l;
	ys3=ys1+l;
	xs4=xs1;
	ys4=ys1+l;
	line(xmid+Round(xs1),ymid-Round(ys1),xmid+Round(xs2),ymid-Round(ys2));
	line(xmid+Round(xs2),ymid-Round(ys2),xmid+Round(xs3),ymid-Round(ys3));
	line(xmid+Round(xs3),ymid-Round(ys3),xmid+Round(xs4),ymid-Round(ys4));
	line(xmid+Round(xs4),ymid-Round(ys4),xmid+Round(xs1),ymid-Round(ys1));
	
	printf("Enter (x1,y1) and (x2,y2) for line :");
	scanf("%d%d%d%d",&xl1,&yl1,&xl2,&yl2);
	line(xmid+Round(xl1),ymid-Round(yl1),xmid+Round(xl2),ymid-Round(yl2));


	printf("Enter the cordinates of triangle :");
	scanf("%d%d%d%d%d%d",&xt1,&yt1,&xt2,&yt2,&xt3,&yt3);
	line(xmid+Round(xt1),ymid-Round(yt1),xmid+Round(xt2),ymid-Round(yt2));
	line(xmid+Round(xt2),ymid-Round(yt2),xmid+Round(xt3),ymid-Round(yt3));
	line(xmid+Round(xt3),ymid-Round(yt3),xmid+Round(xt1),ymid-Round(yt1));

	printf("Enter center and radius of circle :");
	scanf("%d%d%d",&xc,&yc,&r);
	circle(xmid+xc,ymid-yc,r);

	refpoint(xp1,yp1,m,c);//point
	refline(xl1,yl1,xl2,yl2,m,c);//line
	refsqu(xs1,ys1,xs2,ys2,xs3,ys3,xs4,ys4,m,c);//square
	reftri(xt1,yt1,xt2,yt2,xt3,yt3,m,c);//triangle
	refcir(xc,yc,r,m,c);//circle

	getch();
	closegraph();
}
