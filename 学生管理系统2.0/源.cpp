#include<stdio.h>
#include<graphics.h>
#include<string.h>
#include<conio.h>
char name[20];
char nember[20];
char major[20];
char math[20];
char english[20];
IMAGE publicimg(1000, 618);
IMAGE Tabimg(600, 418);//表格大小
void tabimg();//表格
void Tab();
void textmiddle(int x, int y, int a, int b,int lotx_1,const char *test,int z);
void Textmiddle(int q, int w, int e, int r,int lotx,const char *text);
void gohome(int q_1,int w_1, int e_1, int r_1,int v);
void windows();
void Adduserimg();//信息添加窗口
void Lookuser();//信息查看窗口
void Lookupuser();//查找用户信息
void Deleteuser();//删除用户
void Modifyuser();//修改用户信息
void outport();//信息导出
void Away();//退出系统
void tabimg()
{

}
void Tab()
{
	int temp,k=0;
	int i=200;
	while (i != 500)
	{
		setfillcolor(WHITE);
		fillrectangle(150, i, 240, i+50);
		Textmiddle(150, i, 240, i + 50, 30, "");
		fillrectangle(250, i, 740, i+50);
		Textmiddle(250, i, 740, i + 50, 30, "看这里");
		fillrectangle(750, i, 850, i+50);
		Textmiddle(750, i, 850, i + 50, 30,"增添");
		i += 60;
	}
	i = 200;
	while(i!=500)
	{
		Textmiddle(150, i, 240, i + 50, 30, "姓名");
		i += 60;
		Textmiddle(150, i, 240, i + 50, 30, "学号");
		i += 60;
		Textmiddle(150, i, 240, i + 50, 30, "专业");
		i += 60;
		Textmiddle(150, i, 240, i + 50, 30, "数学");
		i += 60;
		Textmiddle(150, i, 240, i + 50, 30, "英语");
		i += 60;
	}
		ExMessage m;		// 定义消息变量

		while (k!=5)
		{
			// 获取一条鼠标或按键消息
			m = getmessage(EM_MOUSE | EM_KEY);

			switch (m.message)
			{
			case WM_LBUTTONDOWN:
					if (m.x > 750 && m.y > 200 && m.x < 850 && m.y < 250)
					{
						InputBox(name, 20, "请输入你的名字");
						//strcpy(stu[temp].stduentname, name);
						Textmiddle(250, 200, 740, 250, 30, name);
						// 将用户输入转换为数字
						//int r = _wtoi(stu[temp]);
						k = k + 1;

					}
					if (m.x > 750 && m.y > 260 && m.x < 850 && m.y < 310)
					{
						InputBox(nember, 20, "请输入你的学号");
						//int r = _wtoi(nember);
						//stu[temp].stduentnember = r;
						Textmiddle(250, 260, 740, 310, 30, nember);
						k = k + 1;
					}
					if (m.x > 750 && m.y > 320 && m.x < 850 && m.y < 370)
					{
						InputBox(major, 20, "请输入你的专业");
						//int r = _wtoi(nember);
						//stu[temp].stduentnember = r;
						Textmiddle(250, 320, 740, 370, 30, major);
						k = k + 1;
					}
					if (m.x > 750 && m.y > 380 && m.x < 850 && m.y < 430)
					{
						InputBox(math, 20, "请输入你的数学成绩");
						//int r = _wtoi(nember);
						//stu[temp].stduentnember = r;
						Textmiddle(250, 380, 740, 430, 30, math);
						k = k + 1;
					}
					if (m.x > 750 && m.y > 440 && m.x < 850 && m.y < 490)
					{
						InputBox(english, 20, "请输入你的英语");
						//int r = _wtoi(nember);
						//stu[temp].stduentnember = r;
						Textmiddle(250, 440, 740, 490, 30, english);
						k = k + 1;
					}
				break;
			}
		}
	}
void gohome(int q_1, int w_1, int e_1, int r_1, int v)
{
	int k = 0;
	ExMessage m;// 定义消息变量
	while (k == 0)
	{
		// 获取一条鼠标或按键消息
		m = getmessage(EM_MOUSE | EM_KEY);

		switch (m.message)
		{
		case WM_LBUTTONDOWN:
			// 如果点左键的同时按下了 Ctrl 键
			if (m.x > q_1 && m.y > w_1 && m.x < e_1 && m.y < r_1)
			{
				textmiddle(q_1, w_1, e_1, r_1, v, "返回", 1);
				k = 1;
			}
			break;
		}
	}
}
struct Butto
{
	int x1;
	int y1;
	int x2;
	int y2;
	char butto[20];
	int z = 0;//默认按钮状态
};
struct STDUENT
{
	char stduentname[20];
	long long int stduentnember;
	char majorname[20];
	int math;
	int english;
}stu[100];//学生的信息
void windows()
{
	HWND hwd = GetHWnd();
	SetWindowText(hwd, "学生管理系统");
	MessageBox(hwd, "成功录入", "提示", MB_OKCANCEL);
}
void Textmiddle(int q, int w, int e, int r, int lotx, const char* text)//标题居中,lotx控制字体大小（长度)
{
	int xm, ym;
	setfillcolor(RGB(159, 195, 5));
	fillrectangle(q, w, e, r);
	
	settextstyle(lotx, 0, "黑体");
	char arr_2[100] = "";
	strcpy(arr_2, text);
	xm = q+ (e - q) / 2 - textwidth(arr_2) / 2;
	ym = w + (r - w) / 2 - textheight(arr_2) / 2;
	settextcolor(BLACK);
	outtextxy(xm, ym, arr_2);
}
void textmiddle(int x, int y, int a, int b,int lotx_1, const char* test,int z)//文字居中函数+按钮效果
{
	int xm, ym;
	settextcolor(BLACK);
	setbkmode(TRANSPARENT);
	if (z == 0)//z判断按钮是否被点击
	{
		setfillcolor(RGB(159, 195, 5));
	}
	else
	{
		setfillcolor(RGB(80, 195, 0));
	}
	fillrectangle(x,y,a,b);
	settextstyle(lotx_1, 0, "楷体");
	char arr_1[20] = "";
	strcpy(arr_1, test);
	xm = x + (a - x) / 2 - textwidth(arr_1) / 2;
	ym = y + (b - y) / 2 - textheight(arr_1) / 2;
	outtextxy(xm, ym, arr_1);
}
void Adduserimg()//学生信息录入
{
	
	SetWorkingImage(&publicimg);
	setbkcolor(RGB(159, 195, 5));
	cleardevice();
	SetWorkingImage();
	putimage(0, 0, &publicimg);
	Textmiddle(50, 0, 130, 40, 30, "返回");
	Textmiddle(382, 0, 618, 150, 50, "信息录入");
	
	Tab();
	gohome(50, 0, 130, 40, 30);
}
void Lookuser()
{
	SetWorkingImage(&publicimg);
	setbkcolor(RGB(159, 195, 5));
	cleardevice();
	SetWorkingImage();
	putimage(0, 0, &publicimg);
	Textmiddle(50, 0, 130, 40, 30, "返回");
	Textmiddle(382, 0, 618, 150, 50, "信息查看");
	gohome(50, 0, 130, 40, 30);
}
void Lookupuser()
{
	SetWorkingImage(&publicimg);
	setbkcolor(RGB(159, 195, 5));
	cleardevice();
	SetWorkingImage();
	putimage(0, 0, &publicimg);
	Textmiddle(50, 0, 130, 40, 30, "返回");
	Textmiddle(382, 0, 618, 150, 50, "信息查找");
	gohome(50, 0, 130, 40, 30);
}
void Deleteuser()
{
	SetWorkingImage(&publicimg);
	setbkcolor(RGB(159, 195, 5));
	cleardevice();
	SetWorkingImage();
	putimage(0, 0, &publicimg);
	Textmiddle(50, 0, 130, 40, 30, "返回");
	Textmiddle(382, 0, 618, 150, 50, "信息删除");
	gohome(50, 0, 130, 40, 30);
}
void Modifyuser()
{
	SetWorkingImage(&publicimg);
	setbkcolor(RGB(159, 195, 5));
	cleardevice();
	SetWorkingImage();
	putimage(0, 0, &publicimg);
	Textmiddle(50, 0, 130, 40, 30, "返回");
	Textmiddle(382, 0, 618, 150, 50, "信息修改");
	gohome(50, 0, 130, 40, 30);
}
void outport()
{
	SetWorkingImage(&publicimg);
	setbkcolor(RGB(159, 195, 5));
	cleardevice();
	SetWorkingImage();
	putimage(0, 0, &publicimg);
	Textmiddle(50, 0, 130, 40, 30, "返回");
	Textmiddle(382, 0, 618, 150, 50, "信息导出");
	gohome(50, 0, 130, 40, 30);
}
////void Away()
//{
//	SetWorkingImage(&publicimg);
//	setbkcolor(RGB(159, 195, 5));
//	cleardevice();
//	SetWorkingImage();
//	putimage(0, 0, &publicimg);
//	Textmiddle(50, 0, 130, 40, 30, "返回");
//	Textmiddle(309, 0, 618, 150, 50, "退出系统");
//	gohome(50, 0, 130, 40, 30);
//}
int main()
{
	s:int i;
	struct Butto but[8] = {
		{250, 0, 750, 168, "学生管理系统",0},
		{300,168,700,222,"信息录入",0},
		{300,222,700,276,"信息查看",0},
		{300,276,700,330,"信息查找",0},
		{300,330,700,384,"信息删除",0},
		{300,384,700,442,"信息导出",0},
		{300,442,700,500,"信息修改",0},
		{300,500,700,558,"退出系统",0}
	};
	initgraph(1000, 618);
	setbkcolor(RGB(159, 195, 5));
	cleardevice();

	for (i = 0; i < 8; i++)
	{
		textmiddle(but[i].x1, but[i].y1, but[i].x2, but[i].y2, 45, but[i].butto, but[i].z);
	}//显示菜单
	i = 0;
	
	int n;//判断鼠标的行为
	ExMessage m;
		while (i!=8)
		{
			
			// 获取一条鼠标或按键消息
			m = getmessage(EM_MOUSE | EM_KEY);
			switch (m.message)
			{
			case WM_LBUTTONDOWN:
				for (i = 1; i < 8; i++)
				{
					if (m.x > but[i].x1 && m.y > but[i].y1 && m.x < but[i].x2 && m.y < but[i].y2&&i==1)//判断鼠标是否在按钮区域
					{
						n = 1;
						textmiddle(but[i].x1, but[i].y1, but[i].x2, but[i].y2,45, but[i].butto, n);
						Adduserimg();
						goto s;//迫不得已啊
						//windows();
					}
					if (m.x > but[i].x1 && m.y > but[i].y1 && m.x < but[i].x2 && m.y < but[i].y2 && i == 2)//判断鼠标是否在按钮区域
					{
						n = 1;
						textmiddle(but[i].x1, but[i].y1, but[i].x2, but[i].y2, 45, but[i].butto, n);
						Lookuser();
						goto s;//迫不得已啊
						//windows();
					}
					if (m.x > but[i].x1 && m.y > but[i].y1 && m.x < but[i].x2 && m.y < but[i].y2 && i == 3)//判断鼠标是否在按钮区域
					{
						n = 1;
						textmiddle(but[i].x1, but[i].y1, but[i].x2, but[i].y2, 45, but[i].butto, n);
						Lookupuser();
						goto s;//迫不得已啊
						//windows();
					}
					if (m.x > but[i].x1 && m.y > but[i].y1 && m.x < but[i].x2 && m.y < but[i].y2 && i == 4)//判断鼠标是否在按钮区域
					{
						n = 1;
						textmiddle(but[i].x1, but[i].y1, but[i].x2, but[i].y2, 45, but[i].butto, n);
						Deleteuser();
						goto s;//迫不得已啊
						//windows();
					}
					if (m.x > but[i].x1 && m.y > but[i].y1 && m.x < but[i].x2 && m.y < but[i].y2 && i == 5)//判断鼠标是否在按钮区域
					{
						n = 1;
						textmiddle(but[i].x1, but[i].y1, but[i].x2, but[i].y2, 45, but[i].butto, n);
						Modifyuser();
						goto s;//迫不得已啊
						//windows();
					}
					if (m.x > but[i].x1 && m.y > but[i].y1 && m.x < but[i].x2 && m.y < but[i].y2 && i == 6)//判断鼠标是否在按钮区域
					{
						n = 1;
						textmiddle(but[i].x1, but[i].y1, but[i].x2, but[i].y2, 45, but[i].butto, n);
						outport();
						goto s;//迫不得已啊
						//windows();
					}
					if (m.x > but[i].x1 && m.y > but[i].y1 && m.x < but[i].x2 && m.y < but[i].y2 && i == 7)//判断鼠标是否在按钮区域
					{
						n = 1;
						textmiddle(but[i].x1, but[i].y1, but[i].x2, but[i].y2, 45, but[i].butto, n);

						//windows();
					}
				}
				break;
			case WM_KEYDOWN:
				if (m.vkcode == VK_ESCAPE)
					return 0;	// 按 ESC 键退出程序
			}
		}
		
	//getchar();//等待用户输入，保持界面
	closegraph();
	return 0;
}