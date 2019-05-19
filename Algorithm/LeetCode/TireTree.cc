#include <iostream>

using namespace std;

#define TRIE_MAX_CAHR_NUM 26

class TrieNode
{
    public:
        TrieNode() : is_end(false){
            for(int i = 0; i < TRIE_MAX_CAHR_NUM; i++){
                child[i] = nullptr;
            }
        }
        TrieNode* child[TRIE_MAX_CAHR_NUM]; // 保存所有结点的子节点
        bool is_end; // 标识这个结点是否为字符串结尾的结点
};

void preorder_trie(TrieNode* root, int layer){
    if(root == nullptr || layer < 0){
        return;
    }
    for(int i = 0; i < TRIE_MAX_CAHR_NUM; i++){
        if(root->child[i]){
            for(int j = 0; j < layer; j++){
                cout << "---" << endl;
            }
            printf("%c", i + 'a');
            if(root->child[i]->is_end){
                cout << "(end)";
            }
            cout << endl;
            preorder_trie(root->child[i], layer + 1);
        }
    }
}
int main()
{
    // 简单构造一颗Tire树
    TrieNode root;
    TrieNode n1,n2,n3;
    root.child['a' - 'a'] = &n1;
    root.child['b' - 'a'] = &n2;
    root.child['e' - 'a'] = &n3;
    n2.is_end = true;

    TrieNode n4,n5,n6;
    n1.child['b' - 'a'] = &n4;
    n2.child['c' - 'a'] = &n5;
    n3.child['f' - 'a'] = &n6;

    TrieNode n7,n8,n9,n10;
    n4.child['c' - 'a'] = &n7;
    n4.child['d' - 'a'] = &n8;
    n5.child['d' - 'a'] = &n9;
    n6.child['g' - 'a'] = &n10;
    n7.is_end = true;
    n8.is_end = true;
    n9.is_end = true;
    n10.is_end = true;

    TrieNode n11;
    n7.child['d' - 'a'] = &n11;
    n11.is_end = true;

    preorder_trie(&root, 0);
    
    return 0;
}


