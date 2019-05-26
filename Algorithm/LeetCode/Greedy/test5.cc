#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// Q:最优加油方法 (Poj 2431)
// A: 1. 设置一个最大堆，存储经过加油站的汽油量
//    2. 按照从起点到终点的方向，遍历各个加油站之间与加油站到终点的距离
//    3. 每次需要走两个加油站的距离d,如果发现汽油不够走距离d的时候，从
//       最大堆中取出一个油量添加,直到可以足够走距离d
//    4. 如果把最大堆的汽油都添加但仍然不够，则无法到达终点
//    5. 将当前的油量减少d
//    6. 将当前的加油站油量添加至最大堆
bool cmp(const pair<int, int>& p1, const pair<int, int>& p2){
    return p1.first > p2.first;
}
int getMinMunStop(int L, int P, vector<pair<int, int> >& stop){
    // L为起点到终点的距离, P为起点初始的汽油量
    // pair<加油站到终点的距离, 加油站的加油量>
    priority_queue<int> Q; // 存储油量的最大堆
    int res = 0; // 记录最终结果
    stop.push_back(make_pair(0, 0));// 将终点作为停靠点，添加到stop数组
    sort(stop.begin(), stop.end(), cmp);// 默认是升序 less,或者使用函数指针或者仿函数
    for(int i = 0; i < stop.size(); i++){
        int dis = L - stop[i].first; // 当前要走的距离为总长减去加油站到终点的距离
        while(!Q.empty() && P < dis){
            P += Q.top();
            Q.pop();
            res++;
        }
        if(Q.empty() && P < dis){
            return -1;
        }
        P -= dis;
        L = stop[i].first;
        Q.push(stop[i].second);
    }
    return res;
}
int main()
{
    vector<pair<int, int> > stop;
    int N, L, P, distance, fuel;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> distance >> fuel;
        stop.push_back(make_pair(distance, fuel));
    }
    cin >> L >> P;
    cout << getMinMunStop(L, P, stop) << endl;  
    return 0;
}
