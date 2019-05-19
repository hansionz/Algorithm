/**
 * LeetCode刷题链表部分
 */ 
#include <iostream>

using namespace std;

// 链表结点
typedef struct Node{
    int data;
    struct Node* next;
}ListNode;

// 问题1: 翻转整条链表LeetCode206
ListNode* reverseList1(ListNode* head){
    ListNode* new_head = nullptr;
    while(head){
        ListNode* next = head->next;
        head->next = new_head;
        new_head = head;
        head = next;
    }
    return new_head;
}
// 方法二:三指针法
ListNode* reverseList2(ListNode* head){
    ListNode* new_head = nullptr;
    ListNode* cur = head;
    ListNode* prev = nullptr;
    while(cur){
        ListNode* next = cur->next;
        if(next == nullptr){
            new_head = cur;
        }

        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return new_head;
}

// 问题2: 翻转一条链表的一部分,将链表m-n个结点逆序, 1 <= m <= n <= size,空间复杂度O(1)（LeetCode92）
// 特殊情况: m = 1
ListNode* reverseBetween(ListNode* head, int m, int n){
    int change_len = n - m + 1;
    ListNode* pre_head = nullptr;
    ListNode* res = head;//最终链表的头非特殊情况为原来的head
    while(head && --m){   // 找到开始逆序的第一个结点
        pre_head = head;
        head = head->next;
    }
    ListNode* modify_list_tail = head;// m-n逆序后的尾结点既head
    ListNode* new_head = nullptr;
    while(head && change_len){
        ListNode* next = head->next;
        head->next = new_head;
        new_head = head;

        head = next;
        change_len--;
    }
    modify_list_tail->next = head;

    if(pre_head){
        pre_head->next = new_head;
    } else{
        res = new_head;
    }
    return res;
}
// 问题3:求两个无环链表的交点（LeetCode 160）
ListNode* getInetrsectionNode(ListNode* headA, ListNode* headB){

}
int main()
{
    // 构造一条链表
    ListNode a,b,c,d,e;
    a.data = 10;
    b.data = 20;
    c.data = 30;
    d.data = 40;
    e.data = 50;
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    e.next = nullptr;
    ListNode* old_head = &a;
    ListNode* head = reverseBetween(old_head, 2, 4);
    while(head){
        cout << head->data << endl;
        head = head->next;
    }
    return 0;
}
