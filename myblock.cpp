#include<Windows.h>
#include<iostream>
#include<time.h>
using namespace std;
//WINAPI :调用约定
/*
参数一：当前窗口实例句柄
参数二：应用程序的前一个事例的句柄。
参数三：指定传递给应用程序的命令行参数
参数四：指定窗口的显示方式（隐藏，最大化最小化。。。）。
*/
//方块类
class block
{
public:
	//void Block_falling();       //      方块下落函数
	//void Block_speed();         //      方块加速函数函数
	//void Block_move();          //      方块左右移动函数
	//void Block_changeshape();   //      方块变形控制函数
	int block_shape1[2][4] = { 1,1,0,0,
							   0,1,1,0 };
	int block_shape2[2][4] = { 0,1,1,0,
							   1,1,0,0 };
	int block_shape3[2][4] = { 0,0,1,0,
							   1,1,1,0 };
	int block_shape4[2][4] = { 1,0,0,0,
							   1,1,1,0 };
	int block_shape5[2][4] = { 0,1,0,0,
							   1,1,1,0 };
	int block_shape6[2][4] = { 1,1,0,0,
							   1,1,0,0 };
	int block_shape7[2][4] = { 1,1,1,1,
							  0,0,0,0 };


};
//       游戏界面类
class gamewindow                  
{
public:
	//void Map_initialize();         //       地图初始化函数
	//画方框
	void Map_frame(HDC hdc)			
	{
		HDC Fhdc = CreateCompatibleDC(hdc);	//创建兼容性DC
		HBITMAP hbitmap=CreateCompatibleBitmap(hdc, 900, 650);//创建一张纸
		SelectObject(Fhdc, hbitmap);//关联起来
		Rectangle(Fhdc, 140, 0, 440, 600);
		Rectangle(Fhdc, 460, 0, 760, 600);
		Rectangle(Fhdc, 0, 0, 140, 600);
		Rectangle(Fhdc, 440, 0, 460, 600);
		Rectangle(Fhdc, 760, 0, 900, 600);
		BitBlt(hdc, 0, 0, 900, 650, Fhdc, 0, 0, SRCCOPY);
		DeleteObject(hbitmap); 
		DeleteDC(Fhdc);//释放dc；
	}
	int window_size1[20][10] = { 0 };//      游戏界面的尺寸
	int window_size2[20][10] = { 0 };
	//绘制方块
	void Print_block1(HDC Fhdc,int a[][10])
	{
		int i = 0, j = 0;
		for (i = 0; i < 20; i++)
		{
			for (j = 0; j < 10; j++)
			{
				if (a[i][j] == 1)
				{
					Rectangle(Fhdc, 140+30*j, 30*i, 140+30*j+30, 30*i+30);
				}
			}
		}
	}
	void Print_block2(HDC Fhdc, int a[][10])
	{
		int i = 0, j = 0;
		for (i = 0; i < 20; i++)
		{
			for (j = 0; j < 10; j++)
			{
				if (a[i][j] == 1)
				{
					Rectangle(Fhdc, 460 + 30 * j, 30 * i, 460 + 30 * j + 30, 30 * i + 30);
				}
			}
		}
	}
	//创建随即块
	void Block_CR()
	{
		srand((unsigned int)time(NULL));
		int n = rand() % 7;
		 block block1;
		int i = 0, j = 0;
		switch (n)
		{
		case 0:
			for (i = 0; i < 2; i++)
			{
				for (j = 0; j < 4; j++)
				{
					window_size1[i][j + 3] = block1.block_shape1[i][j];
				}
			}
			for (i = 0; i < 2; i++)
			{
				for (j = 0; j < 4; j++)
				{
					window_size2[i][j + 3] = block1.block_shape1[i][j];
				}
			}
			break;
		case 1:
			for (i = 0; i < 2; i++)
			{
				for (j = 0; j < 4; j++)
				{
					window_size1[i][j + 3] = block1.block_shape2[i][j];
				}
			}
			for (i = 0; i < 2; i++)
			{
				for (j = 0; j < 4; j++)
				{
					window_size2[i][j + 3] = block1.block_shape2[i][j];
				}
			}
			break;
		case 2:
			for (i = 0; i < 2; i++)
			{
				for (j = 0; j < 4; j++)
				{
					window_size1[i][j + 3] = block1.block_shape3[i][j];
				}
			}
			for (i = 0; i < 2; i++)
			{
				for (j = 0; j < 4; j++)
				{
					window_size2[i][j + 3] = block1.block_shape3[i][j];
				}
			}
			break;
		case 3:
			for (i = 0; i < 2; i++)
			{
				for (j = 0; j < 4; j++)
				{
					window_size1[i][j + 3] = block1.block_shape4[i][j];
				}
			}
			for (i = 0; i < 2; i++)
			{
				for (j = 0; j < 4; j++)
				{
					window_size2[i][j + 3] = block1.block_shape4[i][j];
				}
			}
			break;
		case 4:
			for (i = 0; i < 2; i++)
			{
				for (j = 0; j < 4; j++)
				{
					window_size1[i][j + 3] = block1.block_shape5[i][j];
				}
			}
			for (i = 0; i < 2; i++)
			{
				for (j = 0; j < 4; j++)
				{
					window_size2[i][j + 3] = block1.block_shape5[i][j];
				}
			}
			break;
		case 5:
			for (i = 0; i < 2; i++)
			{
				for (j = 0; j < 4; j++)
				{
					window_size1[i][j + 3] = block1.block_shape6[i][j];
				}
			}
			for (i = 0; i < 2; i++)
			{
				for (j = 0; j < 4; j++)
				{
					window_size2[i][j + 3] = block1.block_shape6[i][j];
				}
			}
			break;
		case 6:
			for (i = 0; i < 2; i++)
			{
				for (j = 0; j < 4; j++)
				{
					window_size1[i][j + 3] = block1.block_shape7[i][j];
				}
			}
			for (i = 0; i < 2; i++)
			{
				for (j = 0; j < 4; j++)
				{
					window_size2[i][j + 3] = block1.block_shape7[i][j];
				}
			}
			break;
		}
	}
private:
}; 
/*
//玩家类
class player                    
{
public:
	int score;                  //玩家分数
	void player_initialize();   //玩家初始化函数；
private:
	string name;                //玩家名称
};
*/

LRESULT CALLBACK Myluosi(HWND hwnd, UINT nMsg, WPARAM wParam, LPARAM lParam);
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
	wc.lpfnWndProc =Myluosi ;//回调函数地址
	wc.lpszClassName = "wls";
	wc.lpszMenuName = NULL;
	wc.style = CS_HREDRAW | CS_VREDRAW;
	//注册窗口类对象
	if (RegisterClassEx(&wc) == 0)
	{
		return 0;
	}
	//创建窗口
	hwnd = CreateWindowEx(WS_EX_TOPMOST,"wls","我罗斯方块",WS_OVERLAPPEDWINDOW,100,100,900,650,NULL,NULL,hInstance,NULL);
	if(NULL==hwnd)		//窗口句柄
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
	class gamewindow gamewindow1;
	class block block1;
	PAINTSTRUCT pt;
	HDC hdc;
	switch (nMsg)
	{
	case WM_CREATE://窗口创建初期只产生一次
		/*初始化数据的地方*/
		break;

	case WM_PAINT:
		hdc = BeginPaint(hwnd, &pt);//画窗口上的内容
		/*我罗斯方块内容*/
		gamewindow1.Map_frame(hdc);  //画框
		gamewindow1.Block_CR();
		gamewindow1.Print_block1(hdc, gamewindow1.window_size1);
		gamewindow1.Print_block2(hdc, gamewindow1.window_size2);
		EndPaint(hwnd, &pt);        

		break;
	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_RETURN://回车

				break;

		case VK_LEFT://左
			break;

		case VK_RIGHT://右
			break;

		case VK_UP://上
			break;

		case VK_DOWN://下
			break;

		case 0x41://A
			break;

		case 0x44://D
			break;

		case 0x53://S
			break;

		case 0x57://W
			break;

		}
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}

	return DefWindowProc(hwnd, nMsg, wParam, lParam);  
}
