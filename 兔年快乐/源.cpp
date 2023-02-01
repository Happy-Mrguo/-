#include<graphics.h>
#include<stdio.h>
#include<iostream>
#include<ctime>
#include<cstdlib>
#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")
using namespace std;
char xxx[]="XXX" ;
char xm[] = "祝XXX新年快乐！";
int w = GetSystemMetrics(SM_CXFULLSCREEN);
int h = GetSystemMetrics(SM_CYFULLSCREEN);
int CurSize = 200;//显存数量，每输入一次增加一次数量
struct DM {
	int x = w;
	int y = rand() % (h -50) ;
	int TextH = rand() % h / 16 + h / 30;
	COLOR16 textColor = RGB(rand() % 256, rand() % 256, rand() % 256);
	int speed = rand() %5 + 4;
	void move() {
		x -= speed;
	}
}dm[1024];
struct D
{
	char name[199];
}s[20];
		
void WindowLong() {
	HWND hwnd = initgraph(w, h, EW_SHOWCONSOLE);//获取图形窗口句柄
	HDC Hdc = (HDC)hwnd;
	SetBkMode(Hdc, TRANSPARENT);//设置背景透明，去掉字体背景
	SetWindowLong(hwnd, GWL_STYLE, GetWindowLong(hwnd, GWL_STYLE) - WS_CAPTION);
	SetWindowPos(hwnd, HWND_TOPMOST, 0, 0, w, h, SWP_SHOWWINDOW);
	SetWindowLong(hwnd, GWL_EXSTYLE, GetWindowLong(hwnd, GWL_STYLE) | WS_EX_LAYERED);
	SetLayeredWindowAttributes(hwnd, RGB(0, 0, 0), 0, LWA_COLORKEY);
}
void Scanf() {
	SetConsoleTitle("丧心病狂");
	system("color 02");
}
void BGM()
{
	for (int a = 0; a < 100; a++)
	{
mciSendString("open 1.mp3", 0, 0, 0);
	mciSendString("play 1.mp3", 0, 0, 0);
	}
}
void hanzi()
{
	settextcolor(RGB(216,162,73));
	settextstyle(80, 0, "华文行楷");		
	outtextxy(130, 0, xm);
}
int main()
{  
	srand((unsigned)time(NULL));
	system("mode con cols=45 lines=9");
	CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)Scanf, NULL, NULL, NULL);//WindowLong();
	Scanf(); s[0] = { "新年快乐" };
	 s[1] = { "扬眉‘兔’气  事事如意" };
	 s[2] = { "“兔”飞猛进  喜事齐来" };
	 s[3] = { "前“兔”似锦  时来运转" };
	 s[4] = { "“兔”来运转  心想事成" };
	s[5] = { "恭喜发财" };
	s[6] = { "万事如意"};
	s[7] = { "大展宏“兔”" };
	s[8] = { "“兔”然暴富" };
	s[9] = { "“兔”步青云" };
	s[10] = { "金“兔”送福" };
	s[11] = { "嘎嘎猛" };
	s[12] = { "平安喜乐" };
	s[13] = { "蒸蒸日上" };
	s[14] = { "早日脱单" };
	s[15] = { "财运亨通" };
	s[16] = { "吉祥如意" };
	s[17] = { "步步高升" };
	s[18] = { "飞黄腾达" };
	s[19] = { "鹏程万里" };
	cout << "你好"<<xxx<< endl; Sleep(1000);
	cout << "你的电脑将在5秒后关机并无法启动" << endl; Sleep(1000); 
	cout << "5" << endl;Sleep(1000);
	cout << "4" << endl;Sleep(1000);
	cout << "3" << endl; Sleep(1000);
	cout << "2" << endl; Sleep(1000);
	cout << "1" << endl; Sleep(1000);
	cout << "哈哈，没吓到吧" << endl;
	SetConsoleTitle("兔年快乐");
	BGM();
	system("color 04");
	cout << "新年快乐！" << endl;	
	Sleep(1000);
	initgraph(900, 900);
	setbkcolor(RGB(255, 51, 60));
	
	cleardevice();hanzi();
	IMAGE A1, A2, A3, A4, A5;
	loadimage(&A1, "6.jpg", 530, 600);
	loadimage(&A2, "5.jpg", 530, 600);
	loadimage(&A3, "3.jpg", 550, 115);
	loadimage(&A4, "4.jpg", 550, 115);
	putimage(200, 190, &A1, SRCPAINT);
	putimage(200, 190, &A2, SRCAND);
	putimage(210, 80, &A3, SRCPAINT);
	putimage(210, 80, &A4, SRCAND);
	Sleep(2500);
	WindowLong();
BeginBatchDraw();
	while (1) {
		
		outtextxy(0,h-50 ,"GYX");
		for (int i = 0; i < 1024; i++) {
			settextcolor(dm[i].textColor);
			settextstyle(dm[i].TextH, 0, "楷体");
				//outtextxy(dm[i].x + i * 300, dm[i].y,s[i].name);				
				outtextxy(dm[i].x + i*300, dm[i].y, s[i%20].name);
		}
		FlushBatchDraw();
		Sleep(10); // 眠，延时
		for (int i = 0; i < CurSize; i++) {
			dm[i].move();
		}
		cleardevice();
	}EndBatchDraw();
	return 0;
	}