#include<iostream>
using namespace std;
bool check_have_zero(int a[][4])
{
	bool result = false;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			if (*(*(a + i) + j) == 0)result = true;
	return result;
}
void move(int a[][4],char b)
{
	void left(int* a);
	void right(int* a);
	void up(int a[][4]);
	void down(int a[][4]);
	if (b == 'a')
		for (int j = 0; j < 4; j++)left(*(a + j));
	else if (b == 'd')
		for (int j = 0; j < 4; j++)right(*(a + j));
	else if (b == 'w') up(a);
	else down(a);
}
void left(int* a) { 
	for (int i = 0; i < 3; i++)
	{
		for (int j = 1; i + j < 4; j++)
		{
			if (*(a + i) != 2048 && *(a + i) == *(a + i + j)) { *(a + i) = *(a + i) * 2, * (a + i + j) = 0; break; }
			else if (a[i + j] != 0)break;
		}
	}
	for (int i = 0, j = 0; j < 4; j++)
	{
		if (*(a + j) != 0) { int temp = a[i]; a[i] = a[j]; a[j] = temp; i++; }
	}
}
void right(int* a) {
	for (int i = 3; i > 0; i--)
		for (int j = -1; i + j >= 0; j--)
		{
			if (*(a + i) != 2048 && *(a + i) == *(a + i + j)) { *(a + i) = *(a + i) * 2, * (a + i + j) = 0; break; }
			else if (a[i + j] != 0)break;
		}
	for (int i = 3, j = 3; j >= 0; j--)if (a[j] != 0) { int temp = a[i]; a[i] = a[j]; a[j] = temp; i--; }
}
void up(int a[][4]) {
	for (int k = 0; k < 4; k++) {
		{
			for (int i = 0; i < 3; i++)
				for (int j = 1; i + j < 4; j++)
				{
					if (a[i][k] != 2048 && a[i][k] == a[i + j][k]) { a[i][k] *= 2, a[i + j][k] = 0; break; }
					else if (a[i + j][k] != 0)break;
				}
			for (int i = 0, j = 0; j < 4; j++)
			{
				if (a[j][k] != 0) {
					int temp = a[i][k]; a[i][k] = a[j][k], a[j][k] = temp; i++;
				}
			}
		}
}
}
void down(int a[][4]) { 
	for (int k = 0; k < 4; k++)
	{
		for (int i = 3; i > 0; i--)
			for (int j = -1; i + j >= 0; j--)
			{
				if (a[i][k] != 2048 && a[i][k] == a[i + j][k]) { a[i][k] *= 2, a[i + j][k] = 0; break; }
				else if (a[i + j][k] != 0)break;
			}
		for (int i = 3, j = 3; j >= 0; j--)if (a[j][k] != 0) {
			int temp = a[i][k]; a[i][k] = a[j][k], a[j][k] = temp, i--;
		}
	}
}
void output(int a[][4]) {
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << "    " << *(*(a + i) + j);
		}
		cout << endl;
	}
}
