#include<graphics.h>
#include<stdio.h>
#include<iostream>
#include<ctime>
#include<cstdlib>
#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")
using namespace std;
char xxx[]="XXX" ;
char xm[] = "ףXXX������֣�";
int w = GetSystemMetrics(SM_CXFULLSCREEN);
int h = GetSystemMetrics(SM_CYFULLSCREEN);
int CurSize = 200;//�Դ�������ÿ����һ������һ������
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
	HWND hwnd = initgraph(w, h, EW_SHOWCONSOLE);//��ȡͼ�δ��ھ��
	HDC Hdc = (HDC)hwnd;
	SetBkMode(Hdc, TRANSPARENT);//���ñ���͸����ȥ�����屳��
	SetWindowLong(hwnd, GWL_STYLE, GetWindowLong(hwnd, GWL_STYLE) - WS_CAPTION);
	SetWindowPos(hwnd, HWND_TOPMOST, 0, 0, w, h, SWP_SHOWWINDOW);
	SetWindowLong(hwnd, GWL_EXSTYLE, GetWindowLong(hwnd, GWL_STYLE) | WS_EX_LAYERED);
	SetLayeredWindowAttributes(hwnd, RGB(0, 0, 0), 0, LWA_COLORKEY);
}
void Scanf() {
	SetConsoleTitle("ɥ�Ĳ���");
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
	settextstyle(80, 0, "�����п�");		
	outtextxy(130, 0, xm);
}
int main()
{  
	srand((unsigned)time(NULL));
	system("mode con cols=45 lines=9");
	CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)Scanf, NULL, NULL, NULL);//WindowLong();
	Scanf(); s[0] = { "�������" };
	 s[1] = { "��ü���á���  ��������" };
	 s[2] = { "���á����ͽ�  ϲ������" };
	 s[3] = { "ǰ���á��ƽ�  ʱ����ת" };
	 s[4] = { "���á�����ת  �����³�" };
	s[5] = { "��ϲ����" };
	s[6] = { "��������"};
	s[7] = { "��չ�ꡰ�á�" };
	s[8] = { "���á�Ȼ����" };
	s[9] = { "���á�������" };
	s[10] = { "���á��͸�" };
	s[11] = { "�¸���" };
	s[12] = { "ƽ��ϲ��" };
	s[13] = { "��������" };
	s[14] = { "�����ѵ�" };
	s[15] = { "���˺�ͨ" };
	s[16] = { "��������" };
	s[17] = { "��������" };
	s[18] = { "�ɻ��ڴ�" };
	s[19] = { "��������" };
	cout << "���"<<xxx<< endl; Sleep(1000);
	cout << "��ĵ��Խ���5���ػ����޷�����" << endl; Sleep(1000); 
	cout << "5" << endl;Sleep(1000);
	cout << "4" << endl;Sleep(1000);
	cout << "3" << endl; Sleep(1000);
	cout << "2" << endl; Sleep(1000);
	cout << "1" << endl; Sleep(1000);
	cout << "������û�ŵ���" << endl;
	SetConsoleTitle("�������");
	BGM();
	system("color 04");
	cout << "������֣�" << endl;	
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
			settextstyle(dm[i].TextH, 0, "����");
				//outtextxy(dm[i].x + i * 300, dm[i].y,s[i].name);				
				outtextxy(dm[i].x + i*300, dm[i].y, s[i%20].name);
		}
		FlushBatchDraw();
		Sleep(10); // �ߣ���ʱ
		for (int i = 0; i < CurSize; i++) {
			dm[i].move();
		}
		cleardevice();
	}EndBatchDraw();
	return 0;
	}