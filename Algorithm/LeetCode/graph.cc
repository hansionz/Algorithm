#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct GraphNode{
    int label;
    vector<GraphNode* > neigh;
    GraphNode(int x) : label(x){};
};
// 深度优先遍历图
void DFS(GraphNode* node, int visit[]){
    visit[node->label] = 1;
    cout << node->label << " ";
    for(size_t i = 0; i < node->neigh.size(); i++){
        if(visit[node->neigh[i]->label] == 0){
            DFS(node->neigh[i], visit);
        }
    }
}
// 宽度优先遍历图
void BFS(GraphNode* node, int visit[]){
    queue<GraphNode*> Q;
    Q.push(node);
    visit[node->label] = 1;
    while(!Q.empty()){
        GraphNode* front = Q.front();
        Q.pop();
        cout << node->label;
        for(int i = 0; i < node->neigh.size(); i++){
            if(visit[node->neigh[i]->label] == 0){
                Q.push(node->neigh[i]);
                visit[node->neigh[i]->label] = 1;
            }
        }
    }
}
int main()
{
    // 邻接表构造图
    const int MAX_N = 5;
    GraphNode* graph[MAX_N];// 5个顶点
    for(int i = 0; i < MAX_N; i++){
        graph[i] = new GraphNode(i);
    }
    // 添加边
    graph[0]->neigh.push_back(graph[2]);
    graph[0]->neigh.push_back(graph[4]);
    graph[1]->neigh.push_back(graph[0]);
    graph[1]->neigh.push_back(graph[2]);
    graph[2]->neigh.push_back(graph[3]);
    graph[3]->neigh.push_back(graph[4]);
    graph[4]->neigh.push_back(graph[3]);

    int visit[MAX_N] = {0};// 标记已经访问的结点

    for(int i = 0; i < MAX_N; i++){
        cout << "label:" << i << "-";
        for(size_t j = 0; j < graph[i]->neigh.size(); j++){
            cout << graph[i]->neigh[j]->label << "-";
        }
        cout << endl;
    }
    for(int i = 0; i < MAX_N; i++){
        delete graph[i];
    }

    // 邻接矩阵构造
    //const int MAX_N = 5;
    //int graph[MAX_N][MAX_N] = {0};
    //graph[0][2] = 1;
    //graph[0][4] = 1;
    //graph[1][0] = 1;
    //graph[1][2] = 1;
    //graph[2][3] = 1;
    //graph[3][4] = 1;
    //graph[4][3] = 1;
    //cout << "graph" << endl;
    //for(int i = 0; i < MAX_N; i++){
    //    for(int j = 0; j < MAX_N; j++){
    //        cout << graph[i][j];
    //    }
    //    cout << endl;
    //}
    //return 0;
}
