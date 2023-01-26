#include <bits/stdc++.h>
using namespace std;
void print(vector<vector<int>> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
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
    int low = 0, high = v[0].size() - 1;
    for (int i = 0; i < m; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            swap(v[i][j], v[j][i]);
        }
    }
    while (low < high)
    {

        for (int i = 0; i < v[low].size(); i++)
        {
            swap(v[i][low], v[i][high]);
        }
        low++, high--;
    }

    print(v);
    return 0;
}