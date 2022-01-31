#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#define WIDTH 1000
#define HIGHT 618
IMAGE leftimg(160, 618);
IMAGE rightimg(840, 618);
struct bunt {
	int x, y;
	char funtion_Name[20];
}btNode;
 struct bunt leftmen[7] = {
	 {5,5,"信息录入"},
	 {5,15,"信息查找"},
	 {5,25,"信息删除"},
	 {5,35,"信息导出"},
	 {5,45,"信息查看"},
	 {5,55,"退出修改"},
	 {5,65,"退出系统"}

 };
 void lfetmen()
 {
	 setfillcolor(BLUE);
	 fillrectangle(20, 0, 100, 10);
}

void drwleft()//左侧功能区
{
	SetWorkingImage(&leftimg);
	setbkcolor(RED);
	cleardevice();
	SetWorkingImage();
	putimage(0, 0, &leftimg);
}
void drwright()//右侧功能区
{
	SetWorkingImage(&rightimg);
	setbkcolor(YELLOW);
	cleardevice();
	SetWorkingImage();
	putimage(161, 0, &rightimg);
}
int main()
{
	initgraph(WIDTH, HIGHT);//设置窗口的大小
	drwleft();
	drwright();
	leftmen();
	_getch();
	closegraph();
	return 0;
}