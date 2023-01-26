#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> height(n);
    for (int i = 0; i < n; i++)
    {
        cin >> height[i];
    }
    int water = 0, left = 0, right = n - 1, lmax = 0, rmax = 0;
    while (left < right)
    {
        if (height[left] <= height[right])
        {
            if (height[left] >= lmax)
            {
                lmax = height[left];
                left++;
            }
            else
            {
                water += lmax - height[left];
                left++;
            }
        }
        else
        {
            if (height[right] >= rmax)
            {
                rmax = height[right];
                right--;
            }
            else
            {
                water += rmax - height[right];
                right--;
            }
        }
    }
    cout << water << endl;
    return 0;
}