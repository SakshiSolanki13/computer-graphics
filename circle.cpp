#include<iostream>
#include<conio.h>
#include<graphics.h>
int main()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,(char*)"C:\\Program Files (x86)\\Dev-Cpp\\MinGW64\\lib\\libbgi.a");
	circle(300,200,150);
	circle(230,158,30);
	circle(370,158,30);
	getch();
	closegraph();
	return 0;
}
