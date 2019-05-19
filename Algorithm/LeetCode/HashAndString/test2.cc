/**
 * Q:词语模式
 * LeetCode 290
 */
#include <iostream>
#include <string>
#include <map>

using namespace std;

// 思路:1.设置单词(字符串)到pattern的映射(哈希),使用数组used[128]记录pattern字符是否使用
//      2.遍历str,按照空格拆分单词，同时对应的向前移动指向pattern字符的指针，没拆分出一个单词
//        判断: 如果该单词从未出现在哈希表中:
//                  如果当前的pattern字符已被使用，则返回false
//                  将单词与当前指向pattern字符做映射
//                  标记当前pattern字符已经使用
//              否则
//                  如果当前单词在哈希表中的映射字符不是当前执行的pattern字符返回false
//      3.如果单词个数和pattern字符个数不匹配，返回false
class Solution
{
    public:
        bool wordPattern(string pattern, string str){
            map<string, char> word_map;
            char used[128] = {0};
            string word; // 临时保存拆分出来的单词
            size_t pos = 0; // 当前指向的pattern字符
            str.push_back(' ');// 在str尾部插入一个空格，遇到空格既拆分单词
            for(size_t i = 0; i < str.length(); i++){
                if(str[i] == ' '){// 拆分新单词
                    if(pos == pattern.length()){
                        return false;
                    }
                    if(word_map.find(word) == word_map.end()){// 单词没有出现在哈希映射中
                        if(used[pattern[pos]] != 0){
                            return false;
                        }
                        word_map[word] = pattern[pos];
                        used[pattern[pos]] = 1;
                    }
                    else{
                        if(word_map[word] != pattern[pos]){
                            return false;
                        }
                    }
                    word = "";
                    pos++;
                }
                else{
                    word += str[i];
                }
            }
            if(pos != pattern.length()){
                return false;
            }
            return true;
        }
};
int main()
{
    Solution so;
    string pattern("abba");
    string str("dog cat cat dog");
    cout << so.wordPattern(pattern, str) << endl;
    return 0;
}
