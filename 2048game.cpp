#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <ctime>
#include <algorithm>
#include <conio.h>
using namespace std;
const int MAXN = 4;
int a[MAXN][MAXN];
int moveleft()
{
	int score = 0;
	for (int i = 0;i < MAXN;i++)
		for (int j = 0;j < MAXN;j++)
		{
			int t = j;
			while (t > 0 && a[i][t - 1] == 0)
			{
				swap(a[i][t - 1], a[i][t]);
				t--;
			}
			if (t > 0 && a[i][t - 1] == a[i][t])
			{
				a[i][t - 1] += a[i][t];
				a[i][t] = 0;
				score += a[i][t - 1];
			}
		}
	return score;
}
int movedown()
{
	int score = 0;
	for (int i = MAXN - 1;i >= 0;i--)
		for (int j = 0;j < MAXN;j++)
		{
			int t = i;
			while (t < MAXN - 1 && a[t + 1][j] == 0)
			{
				swap(a[t + 1][j], a[t][j]);
				t++;
			}
				
			if (t < MAXN - 1 && a[t + 1][j] == a[t][j])
			{
				a[t + 1][j] += a[t][j];
				a[t][j] = 0;
				score += a[t + 1][j];
			}
		}
	return score;
}
int moveright()
{
	int score = 0;
	for (int i = 0;i < MAXN;i++)
		for (int j = MAXN - 1;j >= 0;j--)
		{
			int t = j;
			while (t < MAXN - 1 && a[i][t + 1] == 0)
			{
				swap(a[i][t + 1], a[i][t]);
				t++;
			}
				
			if (t < MAXN - 1 && a[i][t + 1] == a[i][t])
			{
				a[i][t + 1] += a[i][t];
				a[i][t] = 0;
				score += a[i][t + 1];
			}
		}
	return score;
}
int moveup()
{
	int score = 0;
	for (int i = 0;i < MAXN;i++)
		for (int j = 0;j < MAXN;j++)
		{
			int t = i;
			while (t > 0 && a[t - 1][j] == 0)
			{
				swap(a[t - 1][j], a[t][j]);
				t--;
			}
				
			if (t > 0 && a[t - 1][j] == a[t][j])
			{
				a[t - 1][j] += a[t][j];
				a[t][j] = 0;
				score += a[t - 1][j];
			}
		}
	return score;
}
bool judge()
{
	for (int i = 0;i < MAXN;i++)
		for (int j = 0;j < MAXN;j++)
			if (a[i][j] == 0)
				return true;
			else if (a[i][j] == 2048)
				return false;
	int tmp[MAXN][MAXN];
	for (int i = 0;i < MAXN;i++)
		for (int j = 0;j < MAXN;j++)
			tmp[i][j] = a[i][j];
	if (moveleft() || moveup() || moveright() || movedown())
	{
		for (int i = 0;i < MAXN;i++)
			for (int j = 0;j < MAXN;j++)
				a[i][j] = tmp[i][j];
		return true;
	}
	return false;
}
int main()
{
	srand(unsigned(time(NULL)));
	int x1 = rand() % MAXN, y1 = rand() % MAXN, x2 = rand() % MAXN, y2 = rand() % MAXN;
	while (x1 == y1 && x2 == y2)
		x1 = rand() % MAXN, y1 = rand() % MAXN, x2 = rand() % MAXN, y2 = rand() % MAXN;
	a[x1][y1] = a[x2][y2] = 2;
	printf("©°©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©´\n");
	printf("©¦          2048  GAME          ©¦\n");
	printf("©¦  Join the numbers and reach  ©¦\n");
	printf("©¦         number 2048!         ©¦\n");
	printf("©¸©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¼\n");
	printf("Press W,S,A,D to move\n");
	printf("Now,press Enter to continue...\n");
	getchar();
	int score = 0;
	while (judge())
	{
		system("cls");
		printf("©°©¤©¤©¤©¤©Ð©¤©¤©¤©¤©Ð©¤©¤©¤©¤©Ð©¤©¤©¤©¤©´\n");
		for (int i = 0;i < 4;i++)
			if (a[0][i])
				printf("©¦%4d", a[0][i]);
			else
				printf("©¦    ");
		printf("©¦\n");
		printf("©À©¤©¤©¤©¤©à©¤©¤©¤©¤©à©¤©¤©¤©¤©à©¤©¤©¤©¤©È\n");
		for (int i = 0;i < 4;i++)
			if (a[1][i])
				printf("©¦%4d", a[1][i]);
			else
				printf("©¦    ");
		printf("©¦\n");
		printf("©À©¤©¤©¤©¤©à©¤©¤©¤©¤©à©¤©¤©¤©¤©à©¤©¤©¤©¤©È\n");
		for (int i = 0;i < 4;i++)
			if (a[2][i])
				printf("©¦%4d", a[2][i]);
			else
				printf("©¦    ");
		printf("©¦\n");
		printf("©À©¤©¤©¤©¤©à©¤©¤©¤©¤©à©¤©¤©¤©¤©à©¤©¤©¤©¤©È\n");
		for (int i = 0;i < 4;i++)
			if (a[3][i])
				printf("©¦%4d", a[3][i]);
			else
				printf("©¦    ");
		printf("©¦\n");
		printf("©¸©¤©¤©¤©¤©Ø©¤©¤©¤©¤©Ø©¤©¤©¤©¤©Ø©¤©¤©¤©¤©¼\n");
		printf("score:%d\n", score);
		char c = getch();
//		int x2 = rand() % 4;
//		switch(x2)
//		{
//			case 0:
//				c = 'w';
//				break;
//			case 1:
//				c = 's';
//				break;
//			case 2:
//				c = 'a';
//				break;
//			case 3:
//				c = 'd';
//				break;
//		}
		switch (c)
		{
			case 'w':
				score += moveup();
				break;
			case 's':
				score += movedown();
				break;
			case 'a':
				score += moveleft();
				break;
			case 'd':
				score += moveright();
				break;
		}
		bool flag = false;
		for (int i = 0;i < MAXN;i++)
		{
			for (int j = 0;j < MAXN;j++)
				if (a[i][j] == 0)
				{
					flag = true;
					break;
				}
			if (flag)
				break;
		}
		if (!flag)
			continue;
		int x = rand() % MAXN, y = rand() % MAXN;
		while (a[x][y])
			x = rand() % MAXN, y = rand() % MAXN;
		a[x][y] = 2;
	}
	system("cls");
	printf("Game over!Your score is %d\n", score);
	printf("Now, try to compete with your rival - Zenvo!\n");
	printf("Zenvo doing the game...");
	int score2 = 0;
	memset(a, 0, sizeof(a));
	x1 = rand() % MAXN, y1 = rand() % MAXN, x2 = rand() % MAXN, y2 = rand() % MAXN;
	while (x1 == y1 && x2 == y2)
		x1 = rand() % MAXN, y1 = rand() % MAXN, x2 = rand() % MAXN, y2 = rand() % MAXN;
	a[x1][y1] = a[x2][y2] = 2;
	int k = 0;
	string s = "wasd";
	while (judge())
	{
		int tmp[MAXN][MAXN];
		for (int i = 0;i < MAXN;i++)
			for (int j = 0;j < MAXN;j++)
				tmp[i][j] = a[i][j];
		char select = s[k];
		k++;
		k %= 4;
		switch (select)
		{
			case 'w':
				score2 += moveup();
				break;
			case 's':
				score2 += moveleft();
				break;
			case 'a':
				score2 += movedown();
				break;
			case 'd':
				score2 += moveright();
				break;
		}
		bool flag = false;
		for (int i = 0;i < MAXN;i++)
		{
			for (int j = 0;j < MAXN;j++)
				if (a[i][j] == 0)
				{
					flag = true;
					break;
				}
			if (flag)
				break;
		}
		if (!flag)
			continue;
		int x = rand() % MAXN, y = rand() % MAXN;
		while (a[x][y])
			x = rand() % MAXN, y = rand() % MAXN;
		a[x][y] = 2;
	}
	printf("Zenvo complete the game!He get score %d\n", score2);
	printf("Final result:\n");
	if (score > score2)
		printf("You win!\n");
	else if (score < score2)
		printf("Zenvo win!\n");
	else
		printf("Tie!\n");
	while (1);
	return 0;
}

