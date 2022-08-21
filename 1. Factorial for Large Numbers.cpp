#include <bits/stdc++.h>
using namespace std;
void fact(deque<int> &vv, int num)
{
	int carry = 0;

	//updating fixed cells
	for (int i = vv.size() - 1; i >= 0; i--)
	{
		int temp = (num - 1) * vv[i];
		vv[i] = (temp + carry) % 10;
		carry = (temp + carry) / 10;
	}

	//adding new cells in front
	while (carry)
	{
		vv.push_front(carry % 10);
		carry /= 10;
	}
}
int main()
{
	int num;
	cin >> num;

	// deque = num
	deque<int> vv;
	int temp = num;
	while (temp)
	{
		vv.push_front(temp % 10);
		temp /= 10;
	}

	// updating deque by multiplying num with num-1
	while (num > 2)
	{
		fact(vv, num);
		num--;
	}

	// printing deque
	for (int i = 0; i < vv.size(); i++)
	{
		cout << vv[i];
	}
}
