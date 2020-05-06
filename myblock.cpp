#include<Windows.h>
#include<iostream>
#include<time.h>
using namespace std;
int arr_background[20][10] = { 0 };
int arr_square[2][4] = { 0 };
LRESULT CALLBACK Myluosi(HWND hwnd, UINT nMsg, WPARAM wParam, LPARAM lParam);
void Onpaint(HDC hdc);//画方框
void Oncreat();//初始化
void paintsquare(HDC hmendc);//显示方块
int creatrandomsquare();//产生随机块
void copysquaretoback();//把随即快贴近背景
void Onreturn(HWND hwnd);//按回车下落
void Onleft(HWND hwnd);//按左左移
void Onright(HWND hwnd);//按右右移
void Ondown(HWND hwnd);//按下加速
void squaredown();//方块下落
void squareleft();//方块左移；
void squareright();//方块右移
void Ontimer(HWND hwnd);//计时器相关函数
int cansquaredown();//判断方块停住
int cansquareleft();//判断方块左移
int cansquareleft2();
int cansquareright();//判断方块右移
int cansquareright2();
void change1to2();//落到将底层的1变成2
int cansquaredown2();//判断方块停住2
void showsquare2(HDC hdc);//显示值为2的方块+染色
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
	hwnd = CreateWindowEx(WS_EX_TOPMOST, "wls", "我罗斯方块", WS_OVERLAPPEDWINDOW, 100, 30, 900, 650, NULL, NULL, hInstance, NULL);
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
	PAINTSTRUCT pt;
	HDC hdc;
	switch (nMsg)
	{
	case WM_CREATE:
		Oncreat();
		break;
	case WM_TIMER:
		Ontimer(hwnd);
		break;
	case WM_PAINT:
		hdc = BeginPaint(hwnd, &pt);
		Onpaint(hdc);
		EndPaint(hwnd, &pt);
		break;
	case WM_KEYDOWN:
		//	GetLastError();
		switch (wParam)
		{
		case VK_RETURN://回车
			GetLastError();
			Onreturn(hwnd);
			break;

		case VK_LEFT://左
			Onleft(hwnd);
			break;

		case VK_RIGHT://右
			Onright(hwnd);
			break;

		case VK_UP://上
			break;

		case VK_DOWN://下
			Ondown(hwnd);
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
void Onpaint(HDC hdc)
{
	HDC hmemdc = CreateCompatibleDC(hdc);
	HBITMAP hbitmapback = CreateCompatibleBitmap(hdc, 500, 600);
	SelectObject(hmemdc, hbitmapback);
	paintsquare(hmemdc);
	showsquare2(hmemdc);
	BitBlt(hdc, 0, 0, 300, 600, hmemdc, 0, 0, SRCCOPY);
	DeleteObject(hbitmapback);
	DeleteDC(hmemdc);
}
void Oncreat()
{
	srand((unsigned int)time(NULL));
	creatrandomsquare();
	copysquaretoback();
}
void paintsquare(HDC hmemdc)
{
	int i = 0, j = 0;
	//画大方框
	Rectangle(hmemdc, 0, 0, 300, 600);
	HBRUSH hnewbrush = CreateSolidBrush(RGB(50, 150, 50));
	//HBRUSH holdbrush;
	SelectObject(hmemdc, hnewbrush);
	for (i = 0; i < 20; i++)
	{
		for (j = 0; j < 10; j++)
		{
			if (arr_background[i][j] == 1)
			{
				Rectangle(hmemdc, 30 * j, 30 * i, 30 + j * 30, 30 + i * 30);
			}
		}
	}
	DeleteObject(hnewbrush);
}
int creatrandomsquare()
{

	int n = rand() % 7;
	switch (n)
	{
	case 0:
		arr_square[0][0] = 1; arr_square[0][1] = 1; arr_square[0][2] = 0; arr_square[0][3] = 0;
		arr_square[1][0] = 0; arr_square[1][1] = 1; arr_square[1][2] = 1; arr_square[1][3] = 0;
		break;
	case 1:
		arr_square[0][0] = 0; arr_square[0][1] = 1; arr_square[0][2] = 1; arr_square[0][3] = 0;
		arr_square[1][0] = 1; arr_square[1][1] = 1; arr_square[1][2] = 0; arr_square[1][3] = 0;
		break;
	case 2:
		arr_square[0][0] = 1; arr_square[0][1] = 0; arr_square[0][2] = 0; arr_square[0][3] = 0;
		arr_square[1][0] = 1; arr_square[1][1] = 1; arr_square[1][2] = 1; arr_square[1][3] = 0;
		break;
	case 3:
		arr_square[0][0] = 0; arr_square[0][1] = 0; arr_square[0][2] = 1; arr_square[0][3] = 0;
		arr_square[1][0] = 1; arr_square[1][1] = 1; arr_square[1][2] = 1; arr_square[1][3] = 0;
		break;
	case 4:
		arr_square[0][0] = 0; arr_square[0][1] = 1; arr_square[0][2] = 0; arr_square[0][3] = 0;
		arr_square[1][0] = 1; arr_square[1][1] = 1; arr_square[1][2] = 1; arr_square[1][3] = 0;
		break;
	case 5:
		arr_square[0][0] = 1; arr_square[0][1] = 1; arr_square[0][2] = 0; arr_square[0][3] = 0;
		arr_square[1][0] = 1; arr_square[1][1] = 1; arr_square[1][2] = 0; arr_square[1][3] = 0;
		break;
	case 6:
		arr_square[0][0] = 1; arr_square[0][1] = 1; arr_square[0][2] = 1; arr_square[0][3] = 1;
		arr_square[1][0] = 0; arr_square[1][1] = 0; arr_square[1][2] = 0; arr_square[1][3] = 0;
		break;

	}
	return n;
}
void copysquaretoback()
{
	int i, j;
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 4; j++)
		{
			arr_background[i][j + 3] = arr_square[i][j];
		}
	}

}
void Onreturn(HWND hwnd)
{
	//打开定时器
	SetTimer(hwnd, 2, 500, NULL);
}
void squaredown()
{
	int i, j;
	for (i = 18; i >= 0; i--)
	{

		for (j = 0; j < 10; j++)
		{
			if (1 == arr_background[i][j])
			{
				arr_background[i + 1][j] = arr_background[i][j];
				arr_background[i][j] = 0;
			}
		}

	}
}
void Ontimer(HWND hwnd)
{

	//squaredown();
	HDC hdc = GetDC(hwnd);
	if (1 == cansquaredown()&&1==cansquaredown2())
	{
		squaredown();
	}
	else
	{
		change1to2();
		creatrandomsquare();
		copysquaretoback();
	}
	Onpaint(hdc);
	ReleaseDC(hwnd, hdc);
}
int cansquaredown()
{
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		if (1 == arr_background[19][i])
		{
			return 0;//不可以下落
		}
	}
	return 1;//可以下落
}
void change1to2()
{
	int i, j;
	for (i = 0; i < 20; i++)
	{
		for (j = 0; j < 10; j++)
		{
			if (1 == arr_background[i][j])
			{
				arr_background[i][j] = 2;
			}
		}
	}
}
int cansquaredown2()
{
	int i, j;
	for (i = 19; i >= 0; i--)
	{
		for (j = 0; j < 10; j++)
		{
			if (1 == arr_background[i][j])
			{
				if (2 == arr_background[i + 1][j])
					return 0;
			}
		}
	}
	return 1;
}
void showsquare2(HDC hdc)
{
	HBRUSH hnewbrush = CreateSolidBrush(RGB(100, 100, 500));
	//HBRUSH holdbrush;
	SelectObject(hdc, hnewbrush);
	int i, j;
	for (i = 0; i < 20; i++)
	{
		for (j = 0; j < 10; j++)
		{
			if (2 == arr_background[i][j])
			{
				Rectangle(hdc, 30 * j, 30 * i, 30 + j * 30, 30 + i * 30);
			}
		}
	}
	//SelectObject(hdc, holdbrush);
	DeleteObject(hnewbrush);
}
void Onleft(HWND hwnd)
{
	//方块左移
	HDC hdc = GetDC(hwnd);
	if (1 == cansquareleft()&&1==cansquareleft2())
	{
		squareleft();
		//显示方块
		Onpaint(hdc);
		ReleaseDC(hwnd, hdc);
	}
	
}
void Onright(HWND hwnd)
{
	HDC hdc = GetDC(hwnd);
	if (1 == cansquareright() && 1 == cansquareright2())
	{
		squareright();
		//显示方块
		Onpaint(hdc);
		ReleaseDC(hwnd, hdc);
	}
}
void Ondown(HWND hwnd)
{
	Ontimer(hwnd);
}
void squareleft()
{
	int i, j;
	for (i = 0; i < 20; i++)
	{
		for (j = 0; j < 10; j++)
		{
			if (1 == arr_background[i][j])
			{
				arr_background[i][j - 1] = arr_background[i][j];
				arr_background[i][j] = 0;
			}
		}
	}
}
int cansquareleft()
{
	int i;
	for (i = 0; i < 20; i++)
	{
		if (1 == arr_background[i][0])
		{
			return 0;
		}
	}
	return 1;
}
int cansquareleft2()
{
	int i, j;
	for (i = 0; i < 20; i++)
	{
		for (j = 0; j < 10; j++)
		{
			if (arr_background[i][j] == 1)
			{
				if (arr_background[i][j - 1] == 2)
				{
					return 0;
				}
			}
		}
	}
	return 1;
}
void squareright()
{
	int i, j;
	for (i = 0; i < 20; i++)
	{
		for (j = 9; j >= 0; j--)
		{
			if (1 == arr_background[i][j])
			{
				arr_background[i][j + 1] = arr_background[i][j];
				arr_background[i][j] = 0;
			}
		}
	}
}
int cansquareright()
{
	int i;
	for (i = 0; i < 20; i++)
	{
		if (1 == arr_background[i][19])
		{
			return 0;
		}
	}
	return 1;
}
int cansquareright2()
{
	int i, j;
	for (i = 0; i < 20; i++)
	{
		for (j = 0; j < 10; j++)
		{
			if (arr_background[i][j] == 1)
			{
				if (arr_background[i][j + 1] == 2)
				{
					return 0;
				}
			}
		}
	}
	return 1;
}
