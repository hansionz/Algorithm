/**
 * Q:重复的DNA序列
 * LeetCode 187
 */ 
#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

// 方法一
class Solution1
{
    public:
        vector<string> findRepeatedDnaSequences(string s){
            // 枚举DNA字符串中所有长度为10的字符串插入到map中
            // 将出现次数大于1次的子串push到vector中返回
            map<string, int> word_map;
            vector<string> res;
            for(size_t i = 0; i < s.size(); i++){
                string word = s.substr(i, 10);
                if(word_map.find(word) != word_map.end()){
                    word_map[word]++;
                }
                else{
                    word_map[word] = 1;
                }
            }
            map<string, int>::iterator it;
            for(it = word_map.begin(); it != word_map.end(); it++){
                if(it->second > 1){
                    res.push_back(it->first);
                }
            }
            return res;
        }
};
// 方法二
int g_hash_map[1048576] = {0};// 数组太大，需要在全局区
class Solution2
{
    public:
        vector<string> findRepeatedDnaSequences(string s){
            // 1.设置全局整数哈希int g_hash_map[1048576]; 1048576 = 2的2次方
            //   表示索引长度为10的DNA序列
            // 2.将DNA字符串的前10个字符使用左移位运算转换为整数key,g_hash_map[key]++
            // 3.从DNA的11个字符开始，按顺序遍历各个字符，遇到1个字符即将key右移2位，
            //   并且将新的DNA字符s[i]转换为整数后或到最高位(第19位、20位)，g_hash_map[key]++
            // 4.遍历哈希表g_hash_map,若g_hash_map[i] > 1,将i从低到高位转换为10个字符的DNA序列,push到结果中
           vector<string> res;
           if(s.length() < 10){
               return res;
           }
           for(int i = 0; i < 1048576; i++){
               g_hash_map[i] = 0;
           }
           int char_map[128] = {0};
           char_map['A'] = 0;
           char_map['C'] = 1;
           char_map['G'] = 2;
           char_map['T'] = 3;
           int key = 0;
           for(int i = 9; i >= 0; i--){
               key = (key << 2) + char_map[s[i]];
           }
           g_hash_map[key] = 1;
           for(int i = 10; i < s.length(); i++){
               key = key >> 2;
               key = key | (char_map[s[i]] << 18);
               g_hash_map[key]++;
           }
           for(int i = 0; i < 1048576; i++){
               if(g_hash_map[i] > 1){
                   res.push_back(change_int_to_DNA(i));
               }
           }
           return res;
        }
    private:
        static string change_int_to_DNA(int DNA){
            static const char DNA_CHAR[] = {'A', 'C', 'G', 'T'};
            string str;
            for(int i = 0; i < 10; i++){
                str += DNA_CHAR[DNA & 3];
                DNA = DNA >> 2;
            }
            return str;
        }
};
int main()
{
    Solution1 so1;
    string vs("AAAAACCCCTAAAAACCCCT");
    vector<string> res;
    res = so1.findRepeatedDnaSequences(vs);
    for(size_t i = 0; i < res.size(); i++){
        cout << res[i] << " ";
    }
    cout << endl;
    Solution2 so2;
    res = so2.findRepeatedDnaSequences(vs);
    for(size_t i = 0; i < res.size(); i++){
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}
