#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Q:分糖果问题(LeetCode455)
// 贪心思想:使用更小的糖果满足孩子,则没必要使用更大的,保留更大的糖果
// 满足需求更多的孩子,优先从需求小的孩子满足能得到正确的结果
class Solution
{
public:
    int findContentChildren(vector<int>& g, vector<int>& s)
    {
        // 1.对需求g和糖果s数组排序
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int child = 0;// 代表已经满足几个孩子
        int cookie = 0;// 代表已经尝试几个糖果
        // 当孩子没有被完全满足并且糖果没有尝试完时
        while(child < g.size() && cookie < s.size())
        {
            // 孩子的需求小于等于糖果大小,说明该孩子可以被满足
            // 换下一个孩子
            if(g[child] <= s[cookie])
            {
                ++child;
            }
            // 无论该糖果能不能满足孩子,都切换到下一个
            ++cookie;
        }
        // 下标正好为孩子的个数
        return child;
    }
};
int main()
{
    vector<int> g;
    vector<int> s;
    g.push_back(5);
    g.push_back(10);
    g.push_back(2);
    g.push_back(9);
    g.push_back(15);
    g.push_back(9);
    s.push_back(6);
    s.push_back(1);
    s.push_back(20);
    s.push_back(3);
    s.push_back(8);

    Solution so;
    cout << so.findContentChildren(g, s) << endl;
    
    return 0;
}
