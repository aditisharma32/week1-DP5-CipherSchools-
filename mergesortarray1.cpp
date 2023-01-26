#include <bits/stdc++.h>
using namespace std;
void mergeSortedArrays(vector<int> &a, int m, vector<int> &b, int n)
{
    int i = m - 1, j = n - 1, k = m + n - 1;
    while (i >= 0 && j >= 0)
    {
        if (a[i] > b[j])
        {
            a[k] = a[i];
            i--;
        }
        else
        {
            a[k] = b[j];
            j--;
        }
        k--;
    }
    while (j >= 0)
    {
        a[k] = b[j];
        j--;
        k--;
    }
}
int main()
{

    int m, n;
    cin >> m >> n;
    vector<int> v1(m + n), v2(n);
    for (int i = 0; i < m; i++)
    {
        cin >> v1[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> v2[i];
    }
    mergeSortedArrays(v1, m, v2, n);
    for (auto i : v1)
    {
        cout << i << " ";
    }

    return 0;
}