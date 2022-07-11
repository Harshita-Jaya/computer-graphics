#include<graphics.h>
#define Round(x)(int)(x+0.5)
//structure to represent end point of line
typedef struct endpoint
{
	int x,y;
	int code[4];
}PT;
int xmin,ymin,xmax,ymax,xmid,ymid;
float m;//slope of line
PT setcode(PT);
int BothZero(PT,PT);
int andOp(PT,PT);
PT L_intersect(PT);
PT R_intersect(PT);
PT T_intersect(PT);
PT B_intersect(PT);
void cohen(PT,PT);
int main(void)
{
	int gdriver=DETECT,gmode,errorcode;
	int x1,y1,x2,y2;
	PT p1,p2,ptemp;
	initgraph(&gdriver,&gmode,"c:\\tc\\bgi");
	errorcode=graphresult();
	if(errorcode!=grOk)
	{
		printf("graphics error:%s\n",grapherrormsg(errorcode));
		printf("press any key to halt");
		getch();
		exit();

	}
	xmid=getmaxx()/2;
	ymid=getmaxy()/2;
	//quadrants
	line(0,ymid,getmaxx(),ymid);
	line(xmid,0,xmid,getmaxy());
	//creating clipping window
	printf("enter the (xmin,ymin) and (xmax,ymax) corner of the window : ");
	scanf("%d%d%d%d",&xmin,&ymin,&xmax,&ymax);
	rectangle(xmid+xmin,ymid-ymin,xmid+xmax,ymid-ymax);
	//draw line to be clipped
	printf("enter the end points of line:\n");
	scanf("%d%d%d%d",&p1.x,&p1.y,&p2.x,&p2.y);
	line(xmid+p1.x,ymid-p1.y,xmid+p2.x,ymid-p2.y);
	//calculate slope of line
	m=(float)(p2.y-p1.y)/(p2.x-p1.x);
	printf("before clipping: ...press enter\n");
	getch();
	cohen(p1,p2);
	getch();
	closegraph();
	return 0;
}
//To assign 4bit region code
PT setcode(PT p)
{
	PT ptemp;
	int i;
	for(i=0;i<4;i++)
		ptemp.code[i]=0;
	if(p.x<xmin)//left side
		ptemp.code[0]=1;
	if(p.x>xmax)//right side
		ptemp.code[1]=1;
	if(p.y<ymin)//bottom side
		ptemp.code[2]=1;
	if(p.y>ymax)//top side
		ptemp.code[3]=1;
	ptemp.x=p.x;
	ptemp.y=p.y;
	return ptemp;
}
//check region code of both end points is 0 or not
int BothZero(PT p1,PT p2)
{
	if ((p1.code[0]==0)&&(p1.code[1]==0)&&(p1.code[2]==0)&&(p1.code[3]==0)&&(p2.code[0]==0)&&(p2.code[1]==0)&&(p2.code[2]==0)&&(p2.code[3]==0))
	return 1;
	else
	return 0;
}
//perform "and operation" to check 1 is at the same place in region codes or not
int andOp(PT p1,PT p2)
{
	int i,a[4];
	for(i=0;i<4;i++)
		a[i]=p1.code[i]&&p2.code[i];
	if((a[0]==0)&&(a[1]==0)&&(a[2]==0)&&(a[3]==0))
	return 0;
	else
	return 1;

}
//functions for the intersection of the line with the edges of the clipping window
PT L_intersect(PT p)
{
	p.y=Round(p.y+m*(xmin-p.x));
	p.x=xmin;
	return p;
}
PT R_intersect(PT p)
{
	p.y=Round(p.y+m*(xmax-p.x));
	p.x=xmax;
	return p;
}
PT T_intersect(PT p)
{
	p.x=Round(p.x+(ymax-p.y)/m);
	p.y=ymax;
	return p;
}
PT B_intersect(PT p)
{
	p.x=Round(p.x+(ymin-p.y)/m);
	p.y=ymin;
	return p;
}
void cohen(PT p11,PT p22)
{
	int flag=0;
	p11=setcode(p11);
	p22=setcode(p22);
	while(1)
	{
		if(BothZero(p11,p22))
		{
			if(flag==0)
			{
				printf("line is completely visible and not a clipping candidate");
				getch();
				exit(0);
			}
			else
			{
				cleardevice();
				line(0,ymid,getmaxx(),ymid);
				line(xmid,0,xmid,getmaxy());
				//window
				rectangle(xmid+xmin,ymid-ymin,xmid+xmax,ymid-ymax);
				printf("the visible portion of line\n");
				setcolor(GREEN);
				line(xmid+p11.x,ymid-p11.y,xmid+p22.x,ymid-p22.y);
				getch();
				exit(1);

			}
		}
		flag=1;
		if(andOp(p11,p22))
		{
			printf("line is completely outside:discard it\n");
			getch();
			exit(2);
		}
		//find intersection points start from first end point
		if(p11.code[0]==1)//left side
		{
			p11=L_intersect(p11);
			p11=setcode(p11);
			continue;
		}
		if(p11.code[1]==1)//right side
		{
			p11=R_intersect(p11);
			p11=setcode(p11);
			continue;
		}
		if(p11.code[2]==1)//bottom side
		{
			p11=B_intersect(p11);
			p11=setcode(p11);
			continue;
		}
		if(p11.code[3]==1)//top side
		{
			p11=T_intersect(p11);
			p11=setcode(p11);
			continue;
		}
		if(p22.code[0]==1)
		{
			p22=L_intersect(p22);
			p22=setcode(p22);
			continue;
		}
		if(p22.code[1]==1)
		{
			p22=R_intersect(p22);
			p22=setcode(p22);
			continue;
		}
		if(p22.code[2]==1)
		{
			p22=B_intersect(p22);
			p22=setcode(p22);
			continue;
		}
		if(p22.code[3]==1)
		{
			p22=T_intersect(p22);
			p22=setcode(p22);
			continue;
		}
	}//end of while
}
