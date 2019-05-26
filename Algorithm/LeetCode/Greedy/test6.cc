#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// Q:射击气球(LeetCode 452)
// 贪心规律: 对于某个气球，至少需要1个射手，在将这个气球射穿的同时，尽可能
//           的击穿其他的气球
// A: 1.对各个气球进行排序，按照气球的左端点进行从小到大的排序
//    2.遍历气球数组，同时维护一个射击区间，在满足可以将当前气球击穿的情况下
//      尽可能的击穿其他气球，每击穿的一个新的气球，更新一次射击区间(保证射击区间可以将新气球也击穿)
//    3.如果新气球没有被击穿，则需要增加一名新的弓箭手，既维护一个新的设计区间，随后继续遍历气球数组
bool cmp(const pair<int, int>& p1, const pair<int, int>& p2){
    return p1.first < p2.first;
}
int findMinArrowShots(vector<pair<int, int> >& points){
    if(points.size() == 0){
        return 0;
    }
    sort(points.begin(), points.end(), cmp);
    int shoot_num = 1;
    // 初始射击区间为第一个气球的两端点
    int shoot_begin = points[0].first;
    int shoot_end = points[0].second;
    for(int i = 0; i < points.size(); i++){
        if(points[i].first <= shoot_end){
            shoot_begin = points[i].first;
            if(shoot_end > points[i].second){
                shoot_end = points[i].second;
            }
        }
        else{
            shoot_num++;
            shoot_begin = points[i].first;
            shoot_end = points[i].second;
        }
    }
    return shoot_num;
}
int main()
{
    vector<pair<int, int > > points;
    points.push_back(make_pair(10,16));
    points.push_back(make_pair(2,8));
    points.push_back(make_pair(1,6));
    points.push_back(make_pair(7,12));
    cout << findMinArrowShots(points) << endl;
    return 0;
}
