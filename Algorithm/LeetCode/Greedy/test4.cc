#include <iostream>
#include <vector>
#include <string>

// Q: 移除K个数字LeetCode402
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        std::vector<int> s;
        std::string res = "";
        for(int i = 0;  i < num.size(); i++){
            int number = num[i] - '0';
            while(s.size() > 0 && s[s.size() - 1] > number && k > 0){
                s.pop_back(); 
                k--;
            }
            if(number != 0 || s.size() != 0){
                s.push_back(number);
            }
        }
        while(s.size() > 0 && k > 0){
            s.pop_back();
            k--;
        }
        for(int i = 0; i < s.size(); i++){
            char c = s[i] + '0';
            res += c;
        }
        if(res == "")
            return "0";
        return res;
    }
};
