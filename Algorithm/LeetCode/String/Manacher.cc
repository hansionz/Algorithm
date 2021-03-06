#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Manacher算法
// 解决问题:一个字符串中找到最长回文串

// 方法一: 暴力法(O(N*N))
// 分为奇数回文和偶数回文(不好搞定)
// 解决方法: 向每两个字符间和两头添加特殊字符(这个字符是什么字符都可以)
//           把它们都确定为奇回文 eg:11311 ---> #1#1#3#1#1# 算出每一个地方的最大回文
//           最终结果为最大的个数除以2

// 方法二: Manacher算法(O(N))
// 回文直径: 回文串的长度
// 回文半径: 扩出来回文串长度的一半
// 回文半径数组: 每一个位置的回文半径存在数组里
// 回文最右边界: 每一个点扩展出来回文串最右边的边界在源字符串的位置
// 回文右边界中心: 只要回文右边界没有更新,就记录回文串的中心,回文右边界不更新中心不更新
// 解决方法: 1.如果回文右边界在i位置的左边，暴力扩展
//           2.i位置在回文右边界内:
//                 a.知道回文右边界,当然知道回文左边界(因为知道中心)
//                 b.

class Solution
{
    public:

};
int main()
{

    return 0;
}
