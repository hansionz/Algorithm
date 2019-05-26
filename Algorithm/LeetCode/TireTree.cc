#include <iostream>
#include <string>
#include <vector>

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

// trie树的前序遍历
void preorder_trie(TrieNode* root, int layer){
    if(root == nullptr || layer < 0){
        return;
    }
    for(int i = 0; i < TRIE_MAX_CAHR_NUM; i++){
        if(root->child[i]){
            for(int j = 0; j < layer; j++){
                cout << "-"; // 那一层对应几个-
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
// 获取tire树存储的所有字符串
void get_all_eord_from_trie(TrieNode* node, string& word, vector<string>& word_list){
    for(int i = 0; i < TRIE_MAX_CAHR_NUM; i++){
        if(node->child[i]){
            word.push_back(i + 'a');
            if(node->child[i]->is_end){
                word_list.push_back(word);
            }
            get_all_eord_from_trie(node, word, word_list);
            word.erase(word.size() - 1, 1);
        }
    }
}
// 实现trie树
class TrieTree{
    TrieTree(){

    }
    ~TrieTree(){
        for(size_t i = 0; i < node_vec.size(); i++){
            delete node_vec[i];
        }
    }
    // 将word插入到trie
    void insert(const char* word){
        TrieNode* ptr = &_root;
        while(*word){
            int pos = *word - 'a';
            if(!ptr->child[pos]){
                ptr->child[pos] = new_node();
            }
            ptr = ptr->child[pos];
            word++;
        }
        ptr->is_end = true;
    }
    // 搜索trie中是否存在word
    bool search(const char* word){
        TrieNode* ptr = & _root;
        while(*word){
            int pos = *word - 'a';
            if(!ptr->child[pos]){
                return false;
            }
            ptr = ptr->child[pos];
            word++;
        }
        return ptr->is_end;
    }
    // 搜索trie树中是否有前缀为prefix的单词
    bool startsWith(const char* prefix){
        TrieNode* ptr = &_root;
        while(*prefix){
            int pos = *prefix - 'a';
            if(!ptr->child[pos]){
                return false;
            }
            ptr = ptr->child[pos];
            prefix++;
        }
        return true;
    }
    TrieNode* root(){
        return &_root;
    }
    private:
        // 在创建新结点时,使用vector保存指针,方便在析构时直接释放
        TrieNode* new_node(){
            TrieNode* node = new TrieNode();
            node_vec.push_back(node);
            return node;
        }
        vector<TrieNode*> node_vec;
        TrieNode _root;
};
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


