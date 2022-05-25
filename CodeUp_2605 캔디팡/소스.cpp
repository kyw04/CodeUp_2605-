#include <iostream>
#include <stack>
using namespace std;

int arr[9][9];
void check(int x, int y, int key, int *cnt)
{
	if (arr[x][y] != key || !arr[x][y])
		return;

	arr[x][y] = 0;
	(*cnt)++;

	check(x - 1, y, key, cnt);
	check(x + 1, y, key, cnt);
	check(x, y - 1, key, cnt);
	check(x, y + 1, key, cnt);
}
int main()
{
	int cnt = 0, result = 0;
	for (int i = 1; i < 8; i++)
		for (int j = 1; j < 8; j++)
			cin >> arr[i][j];

	for (int i = 1; i < 8; i++)
	{
		for (int j = 1; j < 8; j++)
		{
			if (arr[i][j])
			{
				cnt = 0;
				check(i, j, arr[i][j], &cnt);
				if (cnt >= 3)
					result++;
			}
		}
	}
	cout << result;
	return 0;
}