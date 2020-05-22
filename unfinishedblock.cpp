#include<Windows.h>
#include<iostream>
#include<time.h>
using namespace std;
class Player
{

	static int score1;
	static int score2;
};
class Windows;
class Square
{
	
public:
	static int arr_square[2][4];
	static int arr_square2[2][4];
	static int P1_x_square;//方块类型
	static int P1_y_square;//方块横纵坐标
	static int P1_squareId;
	static int P2_x_square;
	static int P2_y_square;
	static int P2_squareId;
public:
	//产生随即块
	int CreatRandomSquare()
	{
		int n = rand() % 7;
		switch (n)
		{
		case 0:
			arr_square[0][0] = 1; arr_square[0][1] = 1; arr_square[0][2] = 0; arr_square[0][3] = 0;
			arr_square[1][0] = 0; arr_square[1][1] = 1; arr_square[1][2] = 1; arr_square[1][3] = 0;
			P1_x_square = 3;
			P1_y_square = 0;
			break;
		case 1:
			arr_square[0][0] = 0; arr_square[0][1] = 1; arr_square[0][2] = 1; arr_square[0][3] = 0;
			arr_square[1][0] = 1; arr_square[1][1] = 1; arr_square[1][2] = 0; arr_square[1][3] = 0;
			P1_x_square = 3;
			P1_y_square = 0;
			break;
		case 2:
			arr_square[0][0] = 1; arr_square[0][1] = 0; arr_square[0][2] = 0; arr_square[0][3] = 0;
			arr_square[1][0] = 1; arr_square[1][1] = 1; arr_square[1][2] = 1; arr_square[1][3] = 0;
			P1_x_square = 3;
			P1_y_square = 0;
			break;
		case 3:
			arr_square[0][0] = 0; arr_square[0][1] = 0; arr_square[0][2] = 1; arr_square[0][3] = 0;
			arr_square[1][0] = 1; arr_square[1][1] = 1; arr_square[1][2] = 1; arr_square[1][3] = 0;
			P1_x_square = 3;
			P1_y_square = 0;
			break;
		case 4:
			arr_square[0][0] = 0; arr_square[0][1] = 1; arr_square[0][2] = 0; arr_square[0][3] = 0;
			arr_square[1][0] = 1; arr_square[1][1] = 1; arr_square[1][2] = 1; arr_square[1][3] = 0;
			P1_x_square = 3;
			P1_y_square = 0;
			break;
		case 5:
			arr_square[0][0] = 0; arr_square[0][1] = 1; arr_square[0][2] = 1; arr_square[0][3] = 0;
			arr_square[1][0] = 0; arr_square[1][1] = 1; arr_square[1][2] = 1; arr_square[1][3] = 0;
			P1_x_square = 4;
			P1_y_square = 0;
			break;
		case 6:
			arr_square[0][0] = 1; arr_square[0][1] = 1; arr_square[0][2] = 1; arr_square[0][3] = 1;
			arr_square[1][0] = 0; arr_square[1][1] = 0; arr_square[1][2] = 0; arr_square[1][3] = 0;
			P1_x_square = 4;
			P1_y_square = 0;
			break;

		}
		P1_squareId = n;
		return n;
	}
	int CreatRandomSquare2()
	{
		int n = rand() % 7;
		switch (n)
		{
		case 0:
			arr_square2[0][0] = 1; arr_square2[0][1] = 1; arr_square2[0][2] = 0; arr_square2[0][3] = 0;
			arr_square2[1][0] = 0; arr_square2[1][1] = 1; arr_square2[1][2] = 1; arr_square2[1][3] = 0;
			P2_x_square = 3;
			P2_y_square = 0;
			break;
		case 1:
			arr_square2[0][0] = 0; arr_square2[0][1] = 1; arr_square2[0][2] = 1; arr_square2[0][3] = 0;
			arr_square2[1][0] = 1; arr_square2[1][1] = 1; arr_square2[1][2] = 0; arr_square2[1][3] = 0;
			P2_x_square = 3;
			P2_y_square = 0;
			break;
		case 2:
			arr_square2[0][0] = 1; arr_square2[0][1] = 0; arr_square2[0][2] = 0; arr_square2[0][3] = 0;
			arr_square2[1][0] = 1; arr_square2[1][1] = 1; arr_square2[1][2] = 1; arr_square2[1][3] = 0;
			P2_x_square = 3;
			P2_y_square = 0;
			break;
		case 3:
			arr_square2[0][0] = 0; arr_square2[0][1] = 0; arr_square2[0][2] = 1; arr_square2[0][3] = 0;
			arr_square2[1][0] = 1; arr_square2[1][1] = 1; arr_square2[1][2] = 1; arr_square2[1][3] = 0;
			P2_x_square = 3;
			P2_y_square = 0;
			break;
		case 4:
			arr_square2[0][0] = 0; arr_square2[0][1] = 1; arr_square2[0][2] = 0; arr_square2[0][3] = 0;
			arr_square2[1][0] = 1; arr_square2[1][1] = 1; arr_square2[1][2] = 1; arr_square2[1][3] = 0;
			P2_x_square = 3;
			P2_y_square = 0;
			break;
		case 5:
			arr_square2[0][0] = 0; arr_square2[0][1] = 1; arr_square2[0][2] = 1; arr_square2[0][3] = 0;
			arr_square2[1][0] = 0; arr_square2[1][1] = 1; arr_square2[1][2] = 1; arr_square2[1][3] = 0;
			P2_x_square = 4;
			P2_y_square = 0;
			break;
		case 6:
			arr_square2[0][0] = 1; arr_square2[0][1] = 1; arr_square2[0][2] = 1; arr_square2[0][3] = 1;
			arr_square2[1][0] = 0; arr_square2[1][1] = 0; arr_square2[1][2] = 0; arr_square2[1][3] = 0;
			P2_x_square = 4;
			P2_y_square = 0;
			break;

		}
		P2_squareId = n;
		return n;
	}
};
class Windows
{
	friend Square;
	//地图背景
	static  int arr_background1[20][10];
	static int arr_background2[20][10];
public:
	//画方框
	void Onpaint(HDC hdc)
	{
		//创建兼容性dc
		HDC hmemdc = CreateCompatibleDC(hdc);
		HBITMAP hbitmap = CreateCompatibleBitmap(hdc, 900, 600);
		SelectObject(hmemdc, hbitmap);
		PaintSquare(hmemdc);
		//传递
		BitBlt(hdc, 0, 0, 900, 600, hmemdc, 0, 0, SRCCOPY);
		DeleteObject(hbitmap);
		DeleteDC(hmemdc);
	}
	//初始化
	void OnCreat(Square & x) 
	{
		srand((unsigned int)time(NULL));
		x.CreatRandomSquare();
		x.CreatRandomSquare2();
		Copy_Square_Back(x);
	}
	//显示方块
	void PaintSquare(HDC hmemdc)
	{
		Rectangle(hmemdc, 0, 0, 300, 600);
		Rectangle(hmemdc, 300, 0, 600, 600);
		Rectangle(hmemdc, 600, 0, 900, 600);
		int i, j;
		for (i = 0; i < 20; i++)
		{
			for (j = 0; j < 10; j++)
			{
				if (arr_background1[i][j] == 1)
				{
					Rectangle(hmemdc, j*30, i*30,j*30+30,i*30+30);
				}
				if (arr_background2[i][j] == 1)
				{
					Rectangle(hmemdc, j * 30 + 600, i * 30, 600 + j * 30 + 30, i * 30+30);
				}
			}
		}
	}
	//显示变2的方块+变色
	//void Showsquare_2(HDC hdc);	
	//把随机块贴进背景
	void Copy_Square_Back(Square&x)
	{
		int i, j;
		for (i = 0; i < 2; i++)
		{
			for (j = 0; j < 4; j++)
			{
				arr_background1[i][j + 3] = x.arr_square[i][j];
			}
		}
		for (i = 0; i < 2; i++)
		{
			for (j = 0; j < 4; j++)
			{
				arr_background2[i][j + 3] = x.arr_square2[i][j];
			}
		}
	}
public:
	//触底方块1变2
	//void Change_1_2();
	//消行函数
	//void DestroyLine();
	//增加行
	//void AddLine();


};
class Engine
{
public:
	//回车开始游戏
	//void Onenter();
	// 向左移
	//void Onleft();
	//向右移
	//void Onright();
	//加速下落
	//void Ondown();
	//变形
	//void Onchange();
	//计时器
	//void Ontimer(HWND hwnd);
public:
	//方块下落
	//void Squaredown();
	//方块右移
	//void Squareright();
	//方块左移
//	void Squareleft();
	//方块变形
	//void Square_change();
	//void SquareL_change();
public:
	//判断是否触底
//	bool Can_Down();
//	bool Can_Down2();
	////判断能否左移
	//bool Can_Left();
	//bool Can_Left2();
	//判断能否右移
	//bool Can_right();
	//bool Can_right2();
	//判断能否变形
	//bool Can_change();
	//bool Can_change_L();
	//判断游戏是否结束
	//bool Can_GameOver();
};
LRESULT CALLBACK Myluosi(HWND hwnd, UINT nMsg, WPARAM wParam, LPARAM lParam);
int Windows::arr_background1[20][10] = { 0 };
int Windows::arr_background2[20][10] = { 0 };
int Square::P1_squareId = -1;
int Square::P1_x_square = -1;
int Square::P1_y_square = -1;
int Square::P2_squareId = -1;
int Square::P2_x_square = -1;
int Square::P2_y_square = -1;
int Square::arr_square[2][4] = { 0 };
int Square::arr_square2[2][4] = { 0 };
int Player::score1 = 0;
int Player::score2 = 0;
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPreInstance, LPTSTR lpCmdLine, int nCmdshow)
{

	//初始化窗口类
	WNDCLASSEX wc;
	HWND hwnd;
	MSG msg;//消息结构体

	wc.cbClsExtra = 0;
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.cbWndExtra = 0;
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wc.hCursor = NULL;
	wc.hIcon = NULL;
	wc.hIconSm = NULL;
	wc.hInstance = hInstance;
	wc.lpfnWndProc = Myluosi;
	wc.lpszClassName = "wls";
	wc.lpszMenuName = NULL;
	wc.style = CS_HREDRAW | CS_VREDRAW;
	//注册窗口类对象
	if (RegisterClassEx(&wc) == 0)
	{
		return 0;
	}
	//创建窗口
	hwnd = CreateWindowEx(WS_EX_TOPMOST, "wls", "我罗斯方块", WS_OVERLAPPEDWINDOW, 100, 30, 950, 650, NULL, NULL, hInstance, NULL);
	//附加属性       窗口类的名字   窗口名字  窗口风格    初始水平垂直位置  宽 高      菜单句柄
	if (NULL == hwnd)		//窗口句柄
	{
		return 0;
	}
	//显示窗口

	ShowWindow(hwnd, SW_SHOWNORMAL);

	//消息循环

	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);//翻译消息

		DispatchMessage(&msg);//分发消息


	}
	return 0;
}
LRESULT CALLBACK Myluosi(HWND hwnd, UINT nMsg, WPARAM wParam, LPARAM lParam)
{
	Windows w;
	Player p;
	Square s;
	Engine e;
	PAINTSTRUCT pt;
	HDC hdc;
	switch (nMsg)
	{
	case WM_CREATE:
		w.OnCreat(s);
		break;
	case WM_TIMER:
		//Ontimer(hwnd);
		break;
	case WM_PAINT:
		hdc = BeginPaint(hwnd, &pt);
		w.Onpaint(hdc);
		EndPaint(hwnd, &pt);
		break;
	case WM_KEYDOWN:
		//	GetLastError();
		switch (wParam)
		{
		case VK_RETURN://回车
			GetLastError();
			//	Onreturn(hwnd);
			break;

		case VK_LEFT://左
		//	Onleft(hwnd);
			break;

		case VK_RIGHT://右
			//Onright(hwnd);
			break;

		case VK_UP://上

		//	Onchange(hwnd);
			break;

		case VK_DOWN://下
		//	Ondown(hwnd);
			break;
		}
		break;
	case WM_DESTROY:
		KillTimer(hwnd, 2);
		PostQuitMessage(0);
		break;
	}
	return DefWindowProc(hwnd, nMsg, wParam, lParam);
}
