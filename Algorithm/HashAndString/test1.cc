/**
 * Q:最长回文串
 * LeetCode 409
 */ 
#include <iostream>
#include <string>

using namespace std;

// 思路:1.利用字符哈希思想，统计字符串中所有的字符数量
//      2.设置最长回文串偶数字符长度为max_length = 0
//      3.设置是否有中心点标记(处理奇数)flag = 0
//      4.遍历每一个字符，字符数为count,若count为欧式，max_length += count
//        若count为奇数，max_length += count - 1,flag = 1
//      5.最终最长回文子串长度为max_length + flag;
class Solution
{
    public:
        int longestPalindrome(string s){
            int char_map[128] = {0};
            int max_length = 0;
            int flag = 0;
            for(int i = 0; i < s.length(); i++){
                char_map[s[i]]++;
            }
            for(int i = 0; i < 128; i++){
                if((char_map[i] & 1) == 0){
                    max_length += char_map[i];
                }
                else{
                    max_length += char_map[i] - 1;
                    flag = 1;
                }
            }
            return max_length += flag;
        }
};
int main()
{
    Solution so;
    string s("abccccddaa");
    cout << so.longestPalindrome(s) << endl;
    return 0;
}
