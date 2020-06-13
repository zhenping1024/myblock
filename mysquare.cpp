#include<Windows.h>
#include<iostream>
#include<time.h>
using namespace std;
class Player
{
public:
	static int score1;
	static int score2;
	void showscore(HDC hmemdc)
	{
		
			char str_score1[10] = { 0 };
			char str_score1_P[10] = { "玩家1：" };
			char str_score2[10] = { 0 };
			char str_score2_P[10] = { "玩家2：" };
			Rectangle(hmemdc, 300, 0, 600, 600);
			_itoa_s(score1, str_score1, 10);//转换函数
			_itoa_s(score2, str_score2, 10);
			TextOut(hmemdc, 380, 80, str_score1_P, strlen(str_score1_P));
			TextOut(hmemdc, 400, 100, str_score1, strlen(str_score1));//打印分数
			TextOut(hmemdc, 480, 80, str_score2_P, strlen(str_score2_P));
			TextOut(hmemdc, 500, 100, str_score2, strlen(str_score2));//打印分数
		
	}
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
	friend Player;
	friend Square;
	//地图背景
public:
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
		Showsquare_2(hmemdc);
		//传递
		Player p;
		p.showscore(hmemdc);
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
		Copy_Square_Back_P1(x);
		Copy_Square_Back_P2(x);

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
					Square s;
					HGDIOBJ old,hnewbrush;
					switch (s.P1_squareId)
					{
					case 0:
						hnewbrush = CreateSolidBrush(RGB(230, 30, 30));
						old = SelectObject(hmemdc, hnewbrush);
						Rectangle(hmemdc, j * 30 -1, i * 30 -1, j * 30 -1 + 30, i * 30 -1 + 30);
						hnewbrush = SelectObject(hmemdc, old);
						DeleteObject(hnewbrush);
						break;
					case 1:
						
						hnewbrush = CreateSolidBrush(RGB(245, 230, 39));
						old = SelectObject(hmemdc, hnewbrush);
						Rectangle(hmemdc, j * 30 -1, i * 30 -1, j * 30 -1 + 30, i * 30 -1+ 30);
						hnewbrush = SelectObject(hmemdc, old);
						DeleteObject(hnewbrush);
						break;
					case 2:
						hnewbrush = CreateSolidBrush(RGB(93, 156, 245));
						old = SelectObject(hmemdc, hnewbrush);
						Rectangle(hmemdc, j * 30 -1, i * 30 -1, j * 30 + 30-1, i * 30 + 30-1);
						hnewbrush = SelectObject(hmemdc, old);
						DeleteObject(hnewbrush);
						break;
					case 3:
						
						hnewbrush = CreateSolidBrush(RGB(40, 155, 240));
						old = SelectObject(hmemdc, hnewbrush);
						Rectangle(hmemdc, j * 30-1, i * 30-1, j * 30 + 30-1, i * 30 + 30-1);
						hnewbrush = SelectObject(hmemdc, old);
						DeleteObject(hnewbrush);
						break;
					case 4:
						hnewbrush = CreateSolidBrush(RGB(70, 107, 240));
						old = SelectObject(hmemdc, hnewbrush);
						Rectangle(hmemdc, j * 30-1, i * 30-1, j * 30 + 30-1, i * 30 + 30-1);
						hnewbrush = SelectObject(hmemdc, old);
						DeleteObject(hnewbrush);
						break;
					case 5:
						hnewbrush = CreateSolidBrush(RGB(220, 30, 210));
						old = SelectObject(hmemdc, hnewbrush);
						Rectangle(hmemdc, j * 30-1, i * 30-1, j * 30 + 30-1, i * 30 + 30-1);
						hnewbrush = SelectObject(hmemdc, old);
						DeleteObject(hnewbrush);
						break;
					case 6:
					hnewbrush = CreateSolidBrush(RGB(80, 30, 220));
						old = SelectObject(hmemdc, hnewbrush);
						Rectangle(hmemdc, j * 30-1, i * 30-1, j * 30 + 30-1, i * 30 + 30-1);
						hnewbrush = SelectObject(hmemdc, old);
						DeleteObject(hnewbrush);
						break;
					}
				}
				if (arr_background2[i][j] == 1)
				{
					Square s;
					HGDIOBJ old, hnewbrush;
					switch (s.P2_squareId)
					{
					case 0:
						hnewbrush = CreateSolidBrush(RGB(230, 30, 30));
						old = SelectObject(hmemdc, hnewbrush);
						Rectangle(hmemdc, j * 30 + 600-1, i * 30-1, 600 + j * 30 + 30-1, i * 30 + 30-1);
						hnewbrush = SelectObject(hmemdc, old);
						DeleteObject(hnewbrush);
						break;
					case 1:

						hnewbrush = CreateSolidBrush(RGB(245, 230, 39));
						old = SelectObject(hmemdc, hnewbrush);
						Rectangle(hmemdc, j * 30 + 600-1, i * 30-1, 600 + j * 30 + 30-1, i * 30 + 30-1);
						hnewbrush = SelectObject(hmemdc, old);
						DeleteObject(hnewbrush);
						break;
					case 2:
						hnewbrush = CreateSolidBrush(RGB(93, 156, 245));
						old = SelectObject(hmemdc, hnewbrush);
						Rectangle(hmemdc, j * 30 + 600-1, i * 30-1, 600 + j * 30 + 30-1, i * 30 + 30-1);
						hnewbrush = SelectObject(hmemdc, old);
						DeleteObject(hnewbrush);
						break;
					case 3:

						hnewbrush = CreateSolidBrush(RGB(40, 155, 240));
						old = SelectObject(hmemdc, hnewbrush);
						Rectangle(hmemdc, j * 30 + 600-1, i * 30-1, 600 + j * 30 + 30-1, i * 30 + 30-1);
						hnewbrush = SelectObject(hmemdc, old);
						DeleteObject(hnewbrush);
						break;
					case 4:
						hnewbrush = CreateSolidBrush(RGB(70, 107, 240));
						old = SelectObject(hmemdc, hnewbrush);
						Rectangle(hmemdc, j * 30 + 600-1, i * 30-1, 600 + j * 30 + 30-1, i * 30-1 + 30);
						hnewbrush = SelectObject(hmemdc, old);
						DeleteObject(hnewbrush);
						break;
					case 5:
						hnewbrush = CreateSolidBrush(RGB(220, 30, 210));
						old = SelectObject(hmemdc, hnewbrush);
						Rectangle(hmemdc, j * 30 + 600-1, i * 30-1, 600 -1+ j * 30 + 30, i * 30 -1 + 30);
						hnewbrush = SelectObject(hmemdc, old);
						DeleteObject(hnewbrush);
						break;
					case 6:
						hnewbrush = CreateSolidBrush(RGB(80, 30, 220));
						old = SelectObject(hmemdc, hnewbrush);
						Rectangle(hmemdc, j * 30 + 600-1, i * 30-1, 600 + j * 30 + 30-1, i * 30 + 30-1);
						hnewbrush = SelectObject(hmemdc, old);
						DeleteObject(hnewbrush);
						break;
					}
					//Rectangle(hmemdc, j * 30 + 600, i * 30, 600 + j * 30 + 30, i * 30+30);
				}
			}
		}
		
	}
	//显示变2的方块+变色
	void Showsquare_2(HDC hmemdc)
	{
		int i, j;
		HGDIOBJ old;
		HGDIOBJ hnewbrush = CreateSolidBrush(RGB(50, 170, 30));
		old=SelectObject(hmemdc, hnewbrush);
		
		for (i = 0; i < 20; i++)
		{
			for (j = 0; j < 10; j++)
			{
				if (arr_background1[i][j] == 2)
				{
					Rectangle(hmemdc, j * 30-1, i * 30-1, j * 30 + 30-1, i * 30 + 30-1);
				}
				if (arr_background2[i][j] == 2)
				{
					Rectangle(hmemdc, j * 30 + 600-1, i * 30-1, 600 + j * 30 + 30-1, i * 30 -1 + 30);
				}
			}
		}
		hnewbrush=SelectObject(hmemdc, old);
		DeleteObject(hnewbrush);
	}
	//把随机块贴进背景
	void Copy_Square_Back_P1(Square&x)
	{
		int i, j;
		for (i = 0; i < 2; i++)
		{
			for (j = 0; j < 4; j++)
			{
				arr_background1[i][j + 3] = x.arr_square[i][j];
			}
		}
		
	}
	void Copy_Square_Back_P2(Square& x)
	{
		int i, j;
		
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
	void Change_1_2_P1()
	{
		for (int i = 0; i < 20; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				if (1 == arr_background1[i][j])
				{
					arr_background1[i][j] = 2;
				}
				
			}
		}
	}
	void Change_1_2_P2()
	{
		for (int i = 0; i < 20; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				
				if (1 == arr_background2[i][j])
				{
					arr_background2[i][j] = 2;
				}
			}
		}
	}
	//消行函数
	void DestroyLine_P1(Player&p)
	{
		int i, j;
		int sum = 0;
		int temp = 0;
		for (i = 19; i >= 0; i--)
		{
			for (j = 0; j < 10; j++)
			{
				sum += arr_background1[i][j];
			}
			if (sum == 20)
			{
				//消除一行
				AddLine_P2();
				for (temp = i - 1; temp >= 0; temp--)
				{
					for (j = 0; j < 10; j++)
					{
						arr_background1[temp + 1][j] = arr_background1[temp][j];
					}
				}
				p.score1++;
				i = 20;
				//i+=1;//第二种思路
			}
			sum = 0;
		}
	}
	void DestroyLine_P2(Player& p)
	{
		int i, j;
		int sum = 0;
		int temp = 0;
		for (i = 19; i >= 0; i--)
		{
			for (j = 0; j < 10; j++)
			{
				sum += arr_background2[i][j];
			}
			if (sum == 20)
			{
				AddLine_P1();
				//消除一行
				for (temp = i - 1; temp >= 0; temp--)
				{
					for (j = 0; j < 10; j++)
					{
						arr_background2[temp + 1][j] = arr_background2[temp][j];
					}
				}
				p.score2++;
				i = 20;
				//i+=1;//第二种思路
			}
			sum = 0;
		}
	}
	//增加行
	void AddLine_P1()
	{
		if (Can_MoveUp_1())
		{
			Square s;
			s.P1_y_square--;
			for (int i = 1; i < 20; i++)
			{
				for (int j = 0; j < 10; j++)
				{
					//if (Can_MoveUp_1())
					//{
						arr_background1[i - 1][j] = arr_background1[i][j];
						//arr_background1[i][j] = 0;
						//arr_background1[i][j] = 0;

					//}
				}
			}
		}
		else 
		{
			for (int i = 3; i < 20; i++)
			{
				for (int j = 0; j < 10; j++)
				{
					arr_background1[i - 1][j] = arr_background1[i][j];
				}
			}
		}
		for (int i = 0; i < 10; i++)
		{
				int n = rand() % 2;
				if (n == 0) arr_background1[19][i] = 0;
				if (n == 1) arr_background1[19][i] = 2;
		}
		
	}
	void AddLine_P2()
	{
		if (Can_MoveUp_2())
		{
			Square s;
			s.P2_y_square--;
			for (int i = 1; i < 20; i++)
			{
				for (int j = 0; j < 10; j++)
				{
					//if (Can_MoveUp_2())
					//{

						arr_background2[i - 1][j] = arr_background2[i][j];
						//arr_background2[i][j] = 0;
						//arr_background2[i][j] = 0;

					//}
				}
			}
		}
		else
		{
			for (int i = 3; i < 20; i++)
			{
				for (int j = 0; j < 10; j++)
				{
					arr_background2[i-1][j] = arr_background2[i][j];
				}
			}
		}
		for (int i = 0; i < 10; i++)
		{
				int n = rand() % 2;
				if (n == 0) arr_background2[19][i] = 0;
				if (n == 1) arr_background2[19][i] = 2;
		}
	}
	bool Can_MoveUp_1()
	{
		bool a=true/*, b=true*/;
			for (int j = 0; j < 10; j++)
			{
				if (arr_background1[0][j] == 1)
				{
					a= false;
					break;
				}
			}
			/*for (int i = 1; i < 10; i++)
			{
				if (arr_background1[1][i] == 1)
				{
					b = false;
					break;
				}
			}*/
			if (!a)
			{
				return false;
			}
			else
			{
				return true;
			}
	}
	bool Can_MoveUp_2()
	{
		bool a = true;
		/*bool b = true;*/
		
			for (int j = 0; j < 10; j++)
			{
				if (arr_background2[0][j] == 1)
				{
					a = false;
					break;
				}
			}
			/*for (int i = 0; i < 10; i++)
			{
				if (arr_background2[1][i] == 1)
				{
					b = false;
					break;
				}
			}*/

			if (!a )
			{
				return false;
			}
			else
			{
				return true;
			}
	}
};
class Engine
{
public://按键消息
	//回车开始游戏
	friend Square;
	void Onenter(HWND hwnd)
	{
		SetTimer(hwnd, 2,500,NULL);
	}
	// 向左移
	void Onleft_P1(HWND hwnd,Windows&w,Square&s)
	{
		
		//方块左移
		if (Can_Left_P1(w)&&Can_Left2_P1(w))
		{
		HDC hdc = GetDC(hwnd);
		Squareleft_P1(w);
		s.P1_x_square--;
		//显示方块
		
		w.Onpaint(hdc);
		ReleaseDC(hwnd, hdc);
		}
		
		
	}
	void Onleft_P2(HWND hwnd,Windows&w,Square&s)
	{
		if (Can_Left_P2(w)&&Can_Left2_P2(w))
		{
		HDC hdc = GetDC(hwnd);
		Squareleft_P2(w);
		s.P2_x_square--;
		w.Onpaint(hdc);
		ReleaseDC(hwnd, hdc);
		}
		
	}
	//向右移
	void Onright_P1(HWND hwnd,Windows&w,Square&s)
	{
		if (Can_right_P1(w) && Can_right2_P1(w))
		{
			HDC hdc = GetDC(hwnd);
			Squareright_P1(w);
			s.P1_x_square++;
			w.Onpaint(hdc);
			ReleaseDC(hwnd, hdc);
		}
	}
	void Onright_P2(HWND hwnd,Windows&w,Square&s)
	{
		if (Can_right_P2(w) && Can_right2_p2(w))
		{
			HDC hdc = GetDC(hwnd);
			Squareright_P2(w);
			s.P2_x_square++;
			w.Onpaint(hdc);
			ReleaseDC(hwnd, hdc);
		}
	}
	//加速下落
	void Ondown_P1(HWND hwnd,Windows&w,Square&s)
	{
		if (Can_Down_1(w) && Can_Down2_1(w))
		{
			Squaredown_1(w);
			s.P1_y_square++;
			HDC hdc = GetDC(hwnd);
			w.Onpaint(hdc);
			ReleaseDC(hwnd, hdc);
		}
	}
	void Ondown_P2(HWND hwnd, Windows& w,Square&s)
	{
		if (Can_Down_2(w) && Can_Down2_2(w))
		{
			Squaredown_2(w);
			s.P2_y_square++;
			HDC hdc = GetDC(hwnd);
			w.Onpaint(hdc);
			ReleaseDC(hwnd, hdc);
		}
	}
	//变形
	void Onchange_P1(HWND hwnd,Windows&w,Square&s)
	{
		HDC hdc = GetDC(hwnd);
		switch (s.P1_squareId)
		{
		case 0:
		case 1:
		case 2:
		case 3:
		case 4:
			//普通变形
			if (Can_change_P1(w,s))
			{
				Square_change_P1(hwnd, w, s);
			}
			else
			{
				return;
			}
			break;
		case 5:
			//方块
			return;
		case 6:
			if ( Can_change_L_P1(w,s))
			{
				SquareL_change_P1(hwnd, w, s);
				
				//长条
			}

			break;
		}
		w.Onpaint(hdc);
		ReleaseDC(hwnd, hdc);
	}
	void Onchange_P2(HWND hwnd,Windows&w,Square&s)
	{
		HDC hdc = GetDC(hwnd);
		switch (s.P2_squareId)
		{
		case 0:
		case 1:
		case 2:
		case 3:
		case 4:
			//普通变形
			if (Can_change_P2(w, s))
			{
				Square_change_P2(hwnd, w, s);
			}
			else
			{
				return;
			}
			break;
		case 5:
			//方块
			return;

		case 6:
			if (Can_change_L_P2(w, s))
			{
				SquareL_change_P2(hwnd, w, s);

				//长条
			}

			break;
		}
		w.Onpaint(hdc);
		ReleaseDC(hwnd, hdc);
	}
	//计时器
	void Ontimer(HWND hwnd,Windows&w,Square&s,Player&p)
	{
		if (Can_Down_1(w)&&Can_Down2_1(w))
		{
			Squaredown_1(w);
			s.P1_y_square++;
			/*bool a = false;
			for (int i = 0; i < 20; i++)
			{
				for (int j = 0; j < 10; j++)
				{
					if (w.arr_background1[i][j] == 1)
					{
						a = true;
						break;
					}
				}
			}
			if (!a)
			{
				s.CreatRandomSquare();
				w.Copy_Square_Back_P1(s);
			}*/
		}
		else
		{
			w.Change_1_2_P1();
			w.DestroyLine_P1(p);
			if (!Can_GameOver_P1(hwnd, w))
			{
				KillTimer(hwnd, 2);
				return;
			}
			s.CreatRandomSquare();
			w.Copy_Square_Back_P1(s);
		}
		if (Can_Down_2(w)&&Can_Down2_2(w))
		{
			Squaredown_2(w);
			s.P2_y_square++;
			/*bool a = false;
			for (int i = 0; i < 20; i++)
			{
				for (int j = 0; j < 10; j++)
				{
					if (w.arr_background2[i][j] == 1)
					{
						a = true;
						break;
					}
				}
			}
			if (!a)
			{
				s.CreatRandomSquare2();
				w.Copy_Square_Back_P2(s);
			}*/
		}
		else
		{
			w.Change_1_2_P2();
			w.DestroyLine_P2(p);
			if (!Can_GameOver_P2(hwnd, w))
			{
				KillTimer(hwnd, 2);
				return;
			}
			s.CreatRandomSquare2();
			w.Copy_Square_Back_P2(s);
		}
		//显示
		HDC hdc = GetDC(hwnd);
		w.Onpaint(hdc);
		ReleaseDC(hwnd, hdc);
	}
public:
	//方块下落
	friend Windows;
	void Squaredown_1(Windows&w)
	{
		int i, j;
		for (i = 19; i >= 0; i--)
		{
			for (j = 0; j < 10; j++)
			{
				if (1 == w.arr_background1[i][j])
				{
					w.arr_background1[i + 1][j] = w.arr_background1[i][j];
					w.arr_background1[i][j] = 0;
				}
				
			}
		}
	}
	void Squaredown_2(Windows& w)
	{
		int i, j;
		for (i = 19; i >= 0; i--)
		{
			for (j = 0; j < 10; j++)
			{
				
				if (1 == w.arr_background2[i][j])
				{
					w.arr_background2[i + 1][j] = w.arr_background2[i][j];
					w.arr_background2[i][j] = 0;
				}
			}
		}
	}
	//方块右移
	void Squareright_P1(Windows& w)
	{
		for (int i = 0; i < 20; i++)
		{
			for (int j = 9; j >= 0; j--)
			{
				if (w.arr_background1[i][j] == 1)
				{
					w.arr_background1[i][j + 1] = w.arr_background1[i][j];
					w.arr_background1[i][j] = 0;
				}
			}
		}
	}
	void Squareright_P2(Windows& w)
	{
		for (int i = 0; i < 20; i++)
		{
			for (int j = 9; j >= 0; j--)
			{
				if (w.arr_background2[i][j] == 1)
				{
					w.arr_background2[i][j + 1] = w.arr_background2[i][j];
					w.arr_background2[i][j] = 0;
				}
			}
		}
	}
	//方块左移
	void Squareleft_P1(Windows&w)
	{
		for (int i = 0; i < 20; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				if (w.arr_background1[i][j] == 1)
				{
					w.arr_background1[i][j - 1] = w.arr_background1[i][j];
					w.arr_background1[i][j] = 0;
				}
			}
		}
	}
	void Squareleft_P2(Windows&w)
	{
		for (int i = 0; i < 20; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				if (w.arr_background2[i][j] == 1)
				{
					w.arr_background2[i][j - 1] = w.arr_background2[i][j];
					w.arr_background2[i][j] = 0;
				}
			}
		}
	}
	//方块变形
	void Square_change_P1(HWND hwnd,Windows&w,Square&s)
	{
		int arrsquare[3][3] = { 0 };
		int i, j;
		int temp = 2;
		//背景块复制
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				arrsquare[i][j] = w.arr_background1[s.P1_y_square + i][s.P1_x_square + j];
			}
		}
		//变形复制回去
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				w.arr_background1[s.P1_y_square + i][s.P1_x_square + j] = arrsquare[temp][i];
				temp--;
			}
			temp = 2;
		}
	}
	void Square_change_P2(HWND hwnd,Windows&w,Square&s)
	{
		int arrsquare[3][3] = { 0 };
		int i, j;
		int temp = 2;
		//背景块复制
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				arrsquare[i][j] = w.arr_background2[s.P2_y_square + i][s.P2_x_square + j];
			}
		}
		//变形复制回去
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				w.arr_background2[s.P2_y_square + i][s.P2_x_square + j] = arrsquare[temp][i];
				temp--;
			}
			temp = 2;
		}
	}
	void SquareL_change_P1(HWND hwnd, Windows& w, Square& s)
	{
		if (w.arr_background1[s.P1_y_square][s.P1_x_square - 1] == 1)//横着
		{
			//清零
			w.arr_background1[s.P1_y_square][s.P1_x_square - 1] = 0;
			w.arr_background1[s.P1_y_square][s.P1_x_square + 1] = 0;
			w.arr_background1[s.P1_y_square][s.P1_x_square + 2] = 0;
			if (w.arr_background1[s.P1_y_square + 1][s.P1_x_square] == 2)
			{
				w.arr_background1[s.P1_y_square - 1][s.P1_x_square] = 1;
				w.arr_background1[s.P1_y_square - 2][s.P1_x_square] = 1;
				w.arr_background1[s.P1_y_square - 3][s.P1_x_square] = 1;
			}
			else if (w.arr_background1[s.P1_y_square + 2][s.P1_x_square] == 2)
			{
				w.arr_background1[s.P1_y_square - 1][s.P1_x_square] = 1;
				w.arr_background1[s.P1_y_square + 1][s.P1_x_square] = 1;
				w.arr_background1[s.P1_y_square - 2][s.P1_x_square] = 1;
			}
			else
			{
				//赋值
				w.arr_background1[s.P1_y_square - 1][s.P1_x_square] = 1;
				w.arr_background1[s.P1_y_square + 1][s.P1_x_square] = 1;
				w.arr_background1[s.P1_y_square + 2][s.P1_x_square] = 1;
			}
		}
		else //竖着
		{
			w.arr_background1[s.P1_y_square - 1][s.P1_x_square] = 0;
			w.arr_background1[s.P1_y_square + 1][s.P1_x_square] = 0;
			w.arr_background1[s.P1_y_square + 2][s.P1_x_square] = 0;
			if (w.arr_background1[s.P1_y_square][s.P1_x_square + 1] == 2 || s.P1_x_square == 9)
			{
				w.arr_background1[s.P1_y_square][s.P1_x_square - 1] = 1;
				w.arr_background1[s.P1_y_square][s.P1_x_square - 2] = 1;
				w.arr_background1[s.P1_y_square][s.P1_x_square - 3] = 1;
				//改变标记
				s.P1_x_square -= 2;
			}
			else if (w.arr_background1[s.P1_y_square][s.P1_x_square + 2] == 2 || s.P1_x_square == 8)
			{
				w.arr_background1[s.P1_y_square][s.P1_x_square - 1] = 1;
				w.arr_background1[s.P1_y_square][s.P1_x_square - 2] = 1;
				w.arr_background1[s.P1_y_square][s.P1_x_square + 1] = 1;
				//改变标记
				s.P1_x_square -= 1;
			}
			else if (w.arr_background1[s.P1_y_square][s.P1_x_square - 1] == 2 || s.P1_x_square == 0)
			{
				w.arr_background1[s.P1_y_square][s.P1_x_square + 1] = 1;
				w.arr_background1[s.P1_y_square][s.P1_x_square + 2] = 1;
				w.arr_background1[s.P1_y_square][s.P1_x_square + 3] = 1;
				//改变标记
				s.P1_x_square += 1;
			}

			else
			{
				w.arr_background1[s.P1_y_square][s.P1_x_square - 1] = 1;
				w.arr_background1[s.P1_y_square][s.P1_x_square + 2] = 1;
				w.arr_background1[s.P1_y_square][s.P1_x_square + 1] = 1;
			}
		}
	}
	void SquareL_change_P2(HWND hwnd, Windows& w, Square& s)
	{
		if (w.arr_background2[s.P2_y_square][s.P2_x_square - 1] == 1)//横着
		{
			//清零
			w.arr_background2[s.P2_y_square][s.P2_x_square - 1] = 0;
			w.arr_background2[s.P2_y_square][s.P2_x_square + 1] = 0;
			w.arr_background2[s.P2_y_square][s.P2_x_square + 2] = 0;
			if (w.arr_background2[s.P2_y_square + 1][s.P2_x_square] == 2)
			{
				w.arr_background2[s.P2_y_square - 1][s.P2_x_square] = 1;
				w.arr_background2[s.P2_y_square - 2][s.P2_x_square] = 1;
				w.arr_background2[s.P2_y_square - 3][s.P2_x_square] = 1;
			}
			else if (w.arr_background2[s.P2_y_square + 2][s.P2_x_square] == 2)
			{
				w.arr_background2[s.P2_y_square - 1][s.P2_x_square] = 1;
				w.arr_background2[s.P2_y_square + 1][s.P2_x_square] = 1;
				w.arr_background2[s.P2_y_square - 2][s.P2_x_square] = 1;
			}
			else
			{
				//赋值
				w.arr_background2[s.P2_y_square - 1][s.P2_x_square] = 1;
				w.arr_background2[s.P2_y_square + 1][s.P2_x_square] = 1;
				w.arr_background2[s.P2_y_square + 2][s.P2_x_square] = 1;
			}
		}
		else //竖着
		{
			w.arr_background2[s.P2_y_square - 1][s.P2_x_square] = 0;
			w.arr_background2[s.P2_y_square + 1][s.P2_x_square] = 0;
			w.arr_background2[s.P2_y_square + 2][s.P2_x_square] = 0;
			if (w.arr_background2[s.P2_y_square][s.P2_x_square + 1] == 2 || s.P2_x_square == 9)
			{
				w.arr_background2[s.P2_y_square][s.P2_x_square - 1] = 1;
				w.arr_background2[s.P2_y_square][s.P2_x_square - 2] = 1;
				w.arr_background2[s.P2_y_square][s.P2_x_square - 3] = 1;
				//改变标记
				s.P2_x_square -= 2;
			}
			else if (w.arr_background2[s.P2_y_square][s.P2_x_square + 2] == 2 || s.P2_x_square == 8)
			{
				w.arr_background2[s.P2_y_square][s.P2_x_square - 1] = 1;
				w.arr_background2[s.P2_y_square][s.P2_x_square - 2] = 1;
				w.arr_background2[s.P2_y_square][s.P2_x_square + 1] = 1;
				//改变标记
				s.P2_x_square -= 1;
			}
			else if (w.arr_background2[s.P2_y_square][s.P2_x_square - 1] == 2 || s.P2_x_square == 0)
			{
				w.arr_background2[s.P2_y_square][s.P2_x_square + 1] = 1;
				w.arr_background2[s.P2_y_square][s.P2_x_square + 2] = 1;
				w.arr_background2[s.P2_y_square][s.P2_x_square + 3] = 1;
				//改变标记
				s.P2_x_square += 1;
			}

			else
			{
				w.arr_background2[s.P2_y_square][s.P2_x_square - 1] = 1;
				w.arr_background2[s.P2_y_square][s.P2_x_square + 2] = 1;
				w.arr_background2[s.P2_y_square][s.P2_x_square + 1] = 1;
			}
		}
	}
public:
	//判断是否触底
	bool Can_Down_1(Windows & w)
	{
		int i;
		for (i = 0; i < 10; i++)
		{
			if (1 == w.arr_background1[19][i])
			{
				return false;
			}
		}
		return true;
	}
	bool Can_Down_2(Windows & w)
	{
		int i;
		for (i = 0; i < 10; i++)
		{
			if (1 == w.arr_background2[19][i])
			{
				return false;
			}
		}
		return true;
	}
	bool Can_Down2_1(Windows & w)
	{
		for (int i = 19; i >= 0; i--)
		{
			for (int j = 0; j < 10; j++)
			{
				if (w.arr_background1[i][j] == 1)
				{
					if ((i==19)||(w.arr_background1[i + 1][j] == 2&&i!=19))
					{
						return false;
					}
				}
			}
		}
		return true;
	}
	bool Can_Down2_2(Windows& w)
	{
		for (int i = 19; i >= 0; i--)
		{
			for (int j = 0; j < 10; j++)
			{
				if (w.arr_background2[i][j] == 1)
				{
					if ((i==19)||(w.arr_background2[i + 1][j] == 2&&i!=19))
					{
						return false;
					}
				}
			}
		}
		return true;
	}
	////判断能否左移
	bool Can_Left_P1(Windows&w)
	{
		for (int i = 0; i < 20; i++)
		{
			if (w.arr_background1[i][0] == 1)
			{
				return false;
			}
		}
		return true;
	}
	bool Can_Left_P2(Windows& w)
	{
		for (int i = 0; i < 20; i++)
		{
			if (w.arr_background2[i][0] == 1)
			{
				return false;
			}
		}
		return true;
	}
	bool Can_Left2_P1(Windows& w) 
	{
		for (int i = 0; i < 20; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				if (w.arr_background1[i][j] == 1)
				{
					if (w.arr_background1[i][j - 1] == 2)
					{
						return false;
					}
				}
			}
		}
		return true;
	}
	bool Can_Left2_P2(Windows& w)
	{
		for (int i = 0; i < 20; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				if (w.arr_background2[i][j] == 1)
				{
					if (w.arr_background2[i][j - 1] == 2)
					{
						return false;
					}
				}
			}
		}
		return true;
	}
	//判断能否右移
	bool Can_right_P1(Windows&w)
	{
		for (int i = 0; i < 20; i++)
		{
			if (w.arr_background1[i][9] == 1)
			{
				return false;
			}
		}
		return true;
	}
	bool Can_right_P2(Windows& w)
	{
		for (int i = 0; i < 20; i++)
		{
			if (w.arr_background2[i][9] == 1)
			{
				return false;
			}
		}
		return true;
	}
	bool Can_right2_P1(Windows&w)
	{
		for (int i = 0; i < 20; i++)
		{
			for (int j = 9; j >=0; j--)
			{
				if (w.arr_background1[i][j] == 1)
				{
					if (2 == w.arr_background1[i][j + 1])
					{
						return false;
					}
				}
			}
		}
		return true;
	}
	bool Can_right2_p2(Windows&w)
	{
		for (int i = 0; i < 20; i++)
		{
			for (int j = 9; j >= 0; j--)
			{
				if (w.arr_background2[i][j] == 1)
				{
					if (2 == w.arr_background2[i][j + 1])
					{
						return false;
					}
				}
			}
		}
		return true;
	}
	//判断能否变形
	bool Can_change_P1(Windows&w,Square&s)
	{
		int i, j;
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				if (w.arr_background1[s.P1_y_square + i][s.P1_x_square + j] == 2)
				{
					return false;
				}
			}
		}
		if (s.P1_x_square < 0)
		{
			s.P1_x_square = 0;
		}
		else if (s.P1_x_square + 2 > 9)
		{
			s.P1_x_square = 7;
		}
		else if (s.P1_y_square + 2 > 19)
		{
			s.P1_y_square = 17;
		}
		return true;
	}
	bool Can_change_P2(Windows& w, Square& s)
	{
		int i, j;
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				if (w.arr_background2[s.P2_y_square + i][s.P2_x_square + j] == 2)
				{
					return false;
				}
			}
		}
		if (s.P2_x_square < 0)
		{
			s.P2_x_square = 0;
		}
		else if (s.P2_x_square + 2 > 9)
		{
			s.P2_x_square = 7;
		}
		else if (s.P2_y_square + 2 > 19)
		{
			s.P2_y_square = 17;
		}
		return true;
	}
	bool Can_change_L_P1(Windows& w, Square& s)
	{
		int i = 0;
		int j = 0;
		for (i = 1; i < 4; i++)
		{
			if (w.arr_background1[s.P1_y_square][s.P1_x_square + 1] == 2 || (s.P1_x_square + i) > 9)
			{
				break;
			}
		}
		for (j = 1; j < 4; j++)
		{
			if (w.arr_background1[s.P1_y_square][s.P1_x_square - j] == 2 || (s.P1_x_square - j) < 0)
			{
				break;
			}
		}
		if ((i - 1 + j - 1) < 3)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	bool Can_change_L_P2(Windows& w, Square& s)
	{
		int i = 0;
		int j = 0;
		for (i = 1; i < 4; i++)
		{
			if (w.arr_background2[s.P2_y_square][s.P2_x_square + 1] == 2 || (s.P2_x_square + i) > 9)
			{
				break;
			}
		}
		for (j = 1; j < 4; j++)
		{
			if (w.arr_background2[s.P2_y_square][s.P2_x_square - j] == 2 || (s.P2_x_square - j) < 0)
			{
				break;
			}
		}
		if ((i - 1 + j - 1) < 3)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	//判断游戏是否结束
	bool Can_GameOver_P1(HWND hwnd,Windows&w)
	{
		int i;
		for (i = 0; i < 10; i++)
		{
			if (w.arr_background1[0][i] == 2)
			{
				//游戏结束
				MessageBox(hwnd, "Gameover,玩家2赢了", "提示", MB_OK);
				return false;
			}
			
		}
		return true;
	}
	bool Can_GameOver_P2(HWND hwnd, Windows& w)
	{
		int i;
		for (i = 0; i < 10; i++)
		{
			
			if (w.arr_background2[0][i] == 2)
			{
				//游戏结束
				MessageBox(hwnd, "Gameover,玩家1赢了", "提示", MB_OK);
				return false;
			}
		}
		return true;
	}
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
		MessageBox(hwnd, "按回车开始游戏", "提示", MB_OK);
		break;
	case WM_TIMER:
		e.Ontimer(hwnd,w,s,p);
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
			e.Onenter(hwnd);
			break;
		case VK_LEFT://左
			e.Onleft_P2(hwnd,w,s);
			break;
		case 65://A左
			e.Onleft_P1(hwnd, w,s);
			break;
		case VK_RIGHT://右
			e.Onright_P2(hwnd,w,s);
			break;
		case 68://D右
			e.Onright_P1(hwnd, w,s);
			break;
		case VK_UP://上
			e.Onchange_P2(hwnd, w, s);
			break;
		case 87://W上
			e.Onchange_P1(hwnd, w, s);
			break;
		case VK_DOWN://下
			e.Ondown_P2(hwnd,w,s);
			break;
		case 83://S下
			e.Ondown_P1(hwnd, w,s);
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
