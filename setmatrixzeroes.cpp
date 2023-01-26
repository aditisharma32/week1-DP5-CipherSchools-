#include <bits/stdc++.h>
using namespace std;
void setZeroes(vector<vector<int>> &v)
{
    unordered_set<int> rowset, colset;
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            if (v[i][j] == 0)
            {
                rowset.insert(i);
                colset.insert(j);
            }
        }
    }
    for (auto i : rowset)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            v[i][j] = 0;
        }
    }
    for (auto i : colset)
    {
        for (int j = 0; j < v.size(); j++)
        {
            v[j][i] = 0;
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
    setZeroes(v);
    for (auto i : v)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}