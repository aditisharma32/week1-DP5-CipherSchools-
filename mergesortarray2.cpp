#include <bits/stdc++.h>
using namespace std;
int firstOccurencce(vector<int> &nums, int start, int end, int target)
{
    if (start > end)
    {
        return -1;
    }
    else if (start == end)
    {
        return nums[start] == target ? start : -1;
    }
    else
    {
        int mid = start + (end - start) / 2;
        if (nums[mid] < target)
        {
            return firstOccurencce(nums, mid + 1, end, target);
        }
        else if (nums[mid] > target)
        {
            return firstOccurencce(nums, start, mid - 1, target);
        }
        else
        {
            if (mid == 0 || ((mid >= 1) && nums[mid - 1] < nums[mid]))
            {
                return mid;
            }
            else
            {
                return firstOccurencce(nums, start, mid - 1, target);
            }
        }
    }
}
int lastOccurencce(vector<int> &nums, int start, int end, int target)
{
    if (start > end)
    {
        return -1;
    }
    else if (start == end)
    {
        return nums[start] == target ? start : -1;
    }
    else
    {
        int mid = start + (end - start) / 2;
        if (nums[mid] < target)
        {
            return lastOccurencce(nums, mid + 1, end, target);
        }
        else if (nums[mid] > target)
        {
            return lastOccurencce(nums, start, mid - 1, target);
        }
        else
        {
            if ((mid == end) || (mid + 1) <= end && nums[mid] < nums[mid + 1])
            {
                return mid;
            }
            else
            {
                return lastOccurencce(nums, mid + 1, end, target);
            }
        }
    }
}
vector<int> firstAndLastOccurence(vector<int> &nums, int target)
{
    vector<int> ans;
    ans.push_back(firstOccurencce(nums, 0, nums.size() - 1, target));
    ans.push_back(lastOccurencce(nums, 0, nums.size() - 1, target));
    return ans;
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
    int num;
    cin >> num;
    vector<int> ans = firstAndLastOccurence(v, num);
    cout << ans[0] << " " << ans[1] << endl;

    return 0;
}