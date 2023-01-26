#include <bits/stdc++.h>
using namespace std;
bool searchMatrix(vector<vector<int>> &v, int number)
{
    int x = 0;
    int y = v[0].size() - 1;
    while (x < v.size() && y >= 0)
    {
        // cout<<"x : "<<x<<" y : "<<y<<endl;
        // cout<<v[x][y]<<endl;
        if (v[x][y] == number)
        {
            return true;
        }
        else if (v[x][y] > number)
        {
            y--;
        }
        else
        {
            x++;
        }
    }
    return false;
}
int main()
{

    int m, n;
    cin >> m >> n;
    vector<vector<int>> v;
    for (int i = 0; i < m; i++)
    {
        vector<int> row;
        for (int j = 0; j < n; j++)
        {
            int num;
            cin >> num;
            row.push_back(num);
        }
        v.push_back(row);
    }
    int number;
    cin >> number;
    cout << searchMatrix(v, number) << endl;
    return 0;
}