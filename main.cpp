#include<iostream>
#include"head1.h"
using namespace std;
int main() {
	int a[4][4] = { 0 };
	int t = rand() % 4;
	int state = 2;
	cout << "Input a char to start." << endl;
	cout << "w�ϣ�a��d��,s��������ĸΪ��" << endl;
	cout << "һ��������������ĸ��ֱ��ִ�����Σ�������ø���" << endl;
	char haha; cin >> haha;
	while (check_have_zero(a))
	{
		output(a);
		char input = 0; cin >> input;
		move(a, input);
		int i, j;
		do {
			i = rand() % 4, j = rand() % 4;
		} while (a[i][j] != 0);
		a[i][j] = state;
		state = (state == 2) ? 4 : 2;
	}
	output(a);
	int goal = 0;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			goal += *(*(a + i) + j);
	cout << "��ĵ÷�Ϊ" << goal << endl;
	cout << "����һ�������˳�" << endl;
	int kk = 0;
	cin >> kk;
	return 0;

}
