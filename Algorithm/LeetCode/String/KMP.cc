#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 子串(子数组):必须连续  子序列:可以连续、可以不连续
// KMP:是包含问题,返回str2在str1中的位置 eg: str1 = "abcd123" str2 = "cd12" ,返回2
// Java中getIndexOf(String s1, String s2)是一个KMP算法

// 方法一:暴力法
// 从str1的第一个位置开始匹配,如果匹配则返回位置，匹配则str1继续向后移动匹配
// 时间复杂度:O(N*M)(N >= M)
// 方法二:KMP
// 思想:利用前边匹配过的信息找后边，为其加速匹配
// 前提:最长前缀和最长后缀的匹配长度
//      eg:str = "abcabcd" 前缀不能包含最后一个字符，后缀不能包含最前一个字符
//         d 位置的信息是 abcabc 的最长前缀和最长后缀的匹配长度为3(abc abc)
// 思路: 1.求的是str2的每个位置的最长前缀和最长后缀的匹配长度
//         eg: ababac [0 1 2 3 4 5]-->[-1 0 0 1 2 3]
//       2.如果str1和str2前边一部分字符串匹配,后边一个位置没有匹配上
//         则将str2推向str1中最长后缀的位置继续匹配，而最长前缀和最
//         长后缀匹配，则只需要跳过它们的长度继续匹配即可
// 实质: i(最长前缀的开始) - j(最长后缀的开始) 这段位置中是无法匹配出来的
// 为什么: 如果从k(i - j中的任意位置) - x(任意位置) 可以匹配
//         那必须要它们的前缀等量相同，但这不可能只有到j开始
//         匹配采用等量的前缀

// 应用:(京东面试题) 原始串 abcabc 可以在原始串后边添加字符串并且要包含两个原始串
//       使得新串的长度最小,abcabcabc 包含两个abcabc并且长度最短
// 解法: 计算整体串(终止位置)的next值,然后将最长前缀和最长后缀叠在一起
// 应用: 两个树T1、T2,判断T1的子树是否和T2相等(子树是指一个结点下的所有到叶节点的树)
// 解法: 将两棵树按照前序的方式序列化为一个字符串,然后判断str2是否匹配在str1
class Solution
{
    public:
        static int KMP(string str, string sub){
            if(str.size() < 1 || str.size() < sub.size()){
                return -1;
            }
            int sr = 0;
            int sb = 0;
            vector<int> next(sub.size());
            getNextArray(sub, next);
            while(sr < str.size() && sb < sub.size()){
                if(str[sr] == sub[sb]){
                    sr++;
                    sb++;
                } else if(next[sb] == -1) {
                    sr++;
                } else{
                    sb = next[sb];
                }
            }
            // 子串匹配完了
            return sb == sub.size() ? sr - sb : -1;
        }
    private:
        static vector<int> getNextArray(string sub, vector<int>& next){
            // 动态规划
            // i位置的next值是i-1位置上的值
            // 如果 i - 1位置上的值等于i - 1最长前缀后一个的字符
            // 则i位置上的next值为i-1位置上的值加1
            // 如果不相等，i-1位置上的最长前缀继续想前跳,知道相等
            // 截止条件有元素可以划分
            if(sub.size() == 1){
                return next;
            }
            next[0] = -1;
            next[1] = 0;
            int i = 2;
            int cn = 0;
            while(i < next.size()){
                if(sub[i - 1] == sub[cn]){
                    next[i++] = ++cn;
                } else if(cn > 0){
                    cn = next[cn];
                } else{
                    next[i++] = 0;
                }
            }
            return next;
        }
};

int main()
{
    string str1("abcdesf");
    string sub("cdesx");
    cout << Solution::KMP(str1, sub) << endl;
    return 0;
}
