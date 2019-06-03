#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 问题1: 用数组结构实现大小固定的队列和栈
// 解决:
//     实现栈: 使用一个变量模拟栈顶top,存一个数top++,弹出一个数top--,
//             插入的时候如果top == size,说明栈存满了,弹出的时候如果
//             top == 0了说明栈为空
//     实现队列: 
class ArrayToStack{
    public:
        ArrayToStack(int size) : arr(size), top(0){

        }
        void Push(int obj){
            if(top == arr.size()){
                cout << "栈已满" << endl;
                return;
            }
            arr[top++] = obj;
        }
        int Top(){
            if(top == 0){
                cout << "栈空" << endl;
                return -1;
            }
            return arr[top - 1];
        }
        int Pop(){
            if(top == 0){
                cout << "栈空" << endl;
                return -1;
            }
            return arr[--top];
        }
        ~ArrayToStack(){
        }
    private:
        vector<int> arr;
        size_t top;
};

class ArrayToQueue{

    public:
        ArrayToQueue(int size) : arr(size), first(0),last(0){

        } 
        ~ArrayToQueue(){

        }
    private:
        vector<int> arr;
        size_t first;
        size_t last;
};
int main()
{
    ArrayToStack s(3);
    s.Push(1);
    s.Push(2);
    s.Push(3);
    cout << s.Top() << endl;
    s.Push(4);
    cout << s.Pop() << endl;
    cout << s.Pop() << endl;
    cout << s.Pop() << endl;
    s.Pop();

    return 0;
}
