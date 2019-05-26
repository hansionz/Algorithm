/**
 * 实现并查集
 */ 
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Q:朋友圈（LeetCode 547）
void DFS(int u, 
        vector<vector<int> > graph, vector<int> visit){
    visit[u] = 1;// 搜过的标记为1
    for(int i = 0; i < graph[u].size(); i++){
        if(visit[0] && graph[u][i] == 1){
            DFS(i, graph, visit);
        }
    }
}
// M为一个二维数组 [i,j] = 1说明i 和 j认识, 为0说明不认识
int findCircleNum(vector<vector<int> >& M){
    vector<int> visit(M.size(), 0);
    int count = 0;
    for(int i = 0; i < M.size(); i++){
        if(visit[i] == 0){
            DFS(i, M, visit);
            count++;
        }
    }
    return count;
}
// 数组实现一个简单的并查集
class DisjoinSet{
    public:
        DisjoinSet(int n){
            for(int i = 0; i < n; i++){
                _id.push_back(i);
            }
        }
        int find(int p){
            return _id[p];
        }
        // O(N) 太高
        void Union(int p, int q){
            int pid = find(p);
            int qid = find(q);
            if(pid == qid){
                return;
            }
            for(int i = 0; i < _id.size(); i++){
                if(_id[i] == pid){
                    _id[i] = qid;
                }
            }
        }
    private:
        vector<int> _id;
};
// 森林实现并查集
class DisjoinSet2{

    public:
        DisjoinSet2(int n){
            for(int i = 0; i < n; i++){
                _id.push_back(i);
                _size.push_back(1);
            }
            _count = n;
        }
        int find(int p){
            // 从p开始遍历到根节点,根节点p == _id[p]
            while(p != _id[p]){
                // 采用路劲压缩算法
                _id[p] = _id[_id[p]];
                p = _id[p];
            }
            return p;
        }
        // 优化算法: 将较较的子树合并到较大的子树可以使得树更加的平衡
        void Union(int p, int q){
            int i = find(p);
            int j = find(q);
            if(i == j){// 一颗树
                return;
            }
            if(_size[i] < _size[j]){
                _id[i] = j;
                _size[j] += _size[i];
            }
            else{
                _id[j] = i;
                _size[i] += _size[j];
            }
            _count--;
        }
        int count(){
            return _count;
        }
    private:
        vector<int> _id; // 存储该结点的父节点
        vector<int> _size; // 记录没棵子树的大小
        int _count;  // 记录有多少个子树
};
// 并查集解决朋友圈问题
int findCircleNum2(vector<vector<int> >& M){
    DisjoinSet2 ds(M.size());
    for(int i = 0; i < M.size(); i++){
        for(int j = i + 1; j < M[i].size(); j++){
            if(M[i][j]){
                ds.Union(i, j);
            }
        }
    }
    return ds.count(); 
}
int main()
{
    vector<vector<int> > M{{1,1,0},{1,1,0},{0,0,1}};
    cout << findCircleNum2(M) << endl;
    return 0;
}
