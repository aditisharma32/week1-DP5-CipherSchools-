#include <bits/stdc++.h>
using namespace std;
int leftArray(vector<int> v, int start, int end, int target)
{
    int res = -1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (v[mid] == target)
        {
            res = mid;
            break;
        }
        else if (v[mid] > target)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return res;
}
int rightArray(vector<int> v, int start, int end, int target)
{
    int res = -1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (v[mid] == target)
        {
            res = mid;
            break;
        }
        else if (v[mid] > target)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return res;
}
int main()
{

    int n, target;
    cin >> n >> target;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int start = 0, end = n - 1;
    while (start < end)
    {
        int mid = start + (end - start) / 2;
        if (v[mid] < v[end])
        {
            end = mid;
        }
        else
        {
            start = mid + 1;
        }
    }
    // now we have the index of minimum element and so we can now check for which side our elment is present--
    int leftStart = 0, leftEnd = end - 1;
    int rightStart = end, rightEnd = n - 1;
    // cout << leftStart << " " << leftEnd << endl;
    // cout << rightStart << " " << rightEnd << endl;
    int left = leftArray(v, leftStart, leftEnd, target);
    int right = rightArray(v, rightStart, rightEnd, target);
    // cout << left << " " << right << endl;
    if (left != -1)
    {
        cout << left << endl;
    }
    else
    {
        cout << right << endl;
    }
    return 0;
}