#include <bits/stdc++.h>
using namespace std;
void print(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}
void mergetwosorted(vector<int> &v, int low, int mid, int high)
{
    int n = mid - low + 1;
    int m = high - mid;
    vector<int> v1(n), v2(m);
    for (int i = 0; i < n; i++)
    {
        v1[i] = v[i + low];
    }
    for (int i = 0; i < m; i++)
    {
        v2[i] = v[mid + 1 + i];
    }
    int k = low;
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if ((v1[i] <= v2[j]))
        {
            v[k] = v1[i];
            i++;
            k++;
        }
        else
        {
            v[k] = v2[j];
            k++;
            j++;
        }
    }
    while (i < n)
    {
        v[k] = v1[i];
        k++;
        i++;
    }
    while (j < m)
    {
        v[k] = v2[j];
        j++;
        k++;
    }
}

void mergesort(vector<int> &v, int low, int high)
{
    if (low < high)
    {
        int mid = low + (high - low) / 2;
        mergesort(v, low, mid);
        mergesort(v, mid + 1, high);
        mergetwosorted(v, low, mid, high);
    }
}
int main()
{

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int low = 0, high = n - 1;
    mergesort(v, low, high);
    print(v);
    return 0;
}