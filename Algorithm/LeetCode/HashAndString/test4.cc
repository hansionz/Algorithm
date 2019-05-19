/**
 * Q:无重复字符的最长子串
 *   LeetCode 3
 */
#include <iostream>
#include <string>
#include <map>

// 子序列:不连续
// 子串:连续
// Eg:abcde 子序列:abd 子串:abc

using namespace std;

// 方法一: 1.枚举该字符串所有的子串
//         2.找出满足无重复字符的条件
//         3.取最长的作为结果输出
//         复杂度O(N*N)
// 方法二: 1.设置一个记录字符数量的字符哈希char_map
//         2.设置一个记录当前满足条件的最长子串变量word
//         3.设置两个指针i和begin, begin < i ,i指针指向结尾结束
//         4.设置最长满足条件子串的长度res
//         5.i指针向后逐个扫描字符串的字符，在这个过程中，使用char_map记录字符数量
//           如果word中没出现过该字符,对eord尾部添加字符并检查res是否需要更新
//           否则begin指针向前移动，更新char_map中的字符数量,直到字符s[i]的数量为1
//           更新word,将word赋值为begin和i之间的子串
//         6.整个过程，使用begin维护一个窗口，该窗口中的子串满足
//           题目条件，窗口线性向前滑动，整体时间复杂度为O(n)
class Solution 
{
    public:
        int lengthOfLongestSubstring(string s){
            int begin = 0;
            size_t res = 0;
            string word = "";
            int char_map[128] = {0};
            for(size_t i = 0; i < s.size(); i++){
                char_map[s[i]]++;
                if(char_map[s[i]] == 1){// word中没出现过该字符
                    word += s[i];
                    if(res < word.length()){
                        res = word.length();
                    }
                }
                else{
                    // 删除重复的字符
                    while((begin < i) && (char_map[s[i]] > 1)){
                        char_map[s[begin]]--;
                        begin++;
                    }
                    word = "";
                    // 重新更新word
                    for(size_t j = begin; j <= i; j++){
                        word += s[j];
                    }
                }
            }
            return res;
        }
};

int main()
{
    Solution so;
    string s("abcdadab");
    cout << so.lengthOfLongestSubstring(s) << endl;
    return 0;
}

