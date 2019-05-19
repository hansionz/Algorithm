/**
 * Q:同字符词语分组
 * LeetCode 49
 */ 
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

// 核心思路:设计哈希表一什么为key,什么为value,才能让
//          anagram数组中所有字符串映射在同一个地方

// 方法一
class Solution1
{
    public:
        vector<vector<string> > groupAnagrams(vector<string>& strs){
            map<string, vector<string> > anagram;
            // 内部排序各个单词为key,字符串向量(vector<string>)为value
            // 存储各个字符数量相同的字符串
            vector<vector<string> > res; // 存储最终的结果
            for(size_t i = 0; i < strs.size(); i++){
                string str = strs[i];
                sort(str.begin(), str.end());// 内部排序
                if(anagram.find(str) == anagram.end()){// map中没有str，则插入即可
                    vector<string> item;
                    anagram[str] = item;// 排序后的str作为key
                }
                // 如果map中有str,则将对应的strs插入进去
                anagram[str].push_back(strs[i]);
            }
            map<string, vector<string> >::iterator it;
            for(it = anagram.begin(); it != anagram.end(); it++){
                res.push_back((*it).second);
            }
            return res;
        }
};

// 方法二
class Solution2
{
    public:
        vector<vector<string> > groupAnagrams(vector<string>& strs){
            // 以一个统计26个字母数量的vector作为key,value依然是vector<string>
            // 需要一个临时vetcor来保存strs中每一个单词字母出现的个数和key比较
            
            map<vector<int>, vector<string> > anagram;
            vector<vector<string> > res;
            for(size_t i = 0; i < strs.size(); i++){
                vector<int> tmp(26, 0);
                change_to_vector(strs[i], tmp);
                if(anagram.find(tmp) == anagram.end()){
                    vector<string> item;
                    anagram[tmp] = item;
                }
                anagram[tmp].push_back(strs[i]);
            }
            map<vector<int>, vector<string> >::iterator it;
            for(it = anagram.begin(); it != anagram.end(); it++){
                res.push_back((*it).second);
            }
            return res;
        }
    private:
        static void change_to_vector(string& str, vector<int>& vec){
            for(size_t i = 0; i< str.size(); i++){
                vec[str[i] - 'a']++;
            }
        }
};
int main()
{
    vector<string> vs1;
    vs1.push_back("eat");
    vs1.push_back("ate");
    vs1.push_back("tae");
    vs1.push_back("tan");
    vs1.push_back("ant");

    vector<vector<string> > vvs;
    Solution1 so1;
    vvs = so1.groupAnagrams(vs1);
    for(size_t i = 0; i < vvs.size(); i++){
        for(size_t j = 0; j < vvs[i].size(); j++){
            cout << vvs[i][j] << " ";
        }
        cout << endl;
    }
    Solution2 so2;
    vvs = so2.groupAnagrams(vs1);
    for(size_t i = 0; i < vvs.size(); i++){
        for(size_t j = 0; j < vvs[i].size(); j++){
            cout << vvs[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
