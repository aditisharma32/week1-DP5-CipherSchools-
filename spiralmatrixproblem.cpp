#include <bits/stdc++.h>
using namespace std;
void printSpiral(vector<vector<int>> &mat, int n, int m)
{
    int top = 0, left = 0, bottom = n - 1, right = m - 1;

    while (top <= bottom && left <= right)
    {
        for (int i = left; i <= right; i++)
            cout << mat[top][i] << " ";

        top++;

        for (int i = top; i <= bottom; i++)
            cout << mat[i][right] << " ";

        right--;

        if (top <= bottom)
        {
            for (int i = right; i >= left; i--)
                cout << mat[bottom][i] << " ";

            bottom--;
        }

        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
                cout << mat[i][left] << " ";

            left++;
        }
    }
}
int main()
{

    int n, m;
    cin >> n >> m;
    vector<vector<int>> v;
    for (int i = 0; i < n; i++)
    {
        vector<int> row;
        for (int j = 0; j < m; j++)
        {
            int num;
            cin >> num;
            row.push_back(num);
        }
        v.push_back(row);
    }
    printSpiral(v, n, m);

    return 0;
}