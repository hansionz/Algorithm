#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 问题1:给定一个数组和一个值num,将小于等于num的值放在num左边,大于num值放在num右边
// 解决: i初始值为-1,遇到大于num下边i向后移动,遇到小于等于的数x和小于等于num的下一个数交换
void Solution1(vector<int> &arr, int num){
    if(arr.empty()){
        return;
    }
    int less = -1;
    int cur = 0;
    while(cur < arr.size()){
        if(arr[cur] > num){
            cur++;
        } else{
            swap(arr[cur++], arr[++less]);
        }
    }
}
// 问题2:(荷兰国旗问题)在问题1基础上，分为3部分:小于num num 大于num
// 解决: less=-1,more=size表示小于num和大于num的区域没有数;cur遇到等于num下标cur++,
//       遇到小于num，那个数和less下一个数交换，less++,cur++;遇到大于num的数,和more的
//       前一个位置的值交换,more--,cur不变，直到more和cur撞上了即停止
// 荷兰国旗问题做不到稳定性 eg: 4443
void Solution2_landsFlag(vector<int> &arr, int num){
    if(arr.empty()){
        return;
    }
    int less = -1;
    int more = arr.size();
    int cur = 0;
    while(cur < more){
        if(arr[cur] < num){
            swap(arr[cur++], arr[++less]);
        } else if(arr[cur] > num){
            swap(arr[cur], arr[--more]);
        } else{
            cur++;
        }
    }
}

void quickSort(vector<int> &arr){
    if(arr.empty()){
        return;
    }

}
// 问题4: 一个吐数机,怎样才能找出这些数的中位数
// 解决1: 使用一个数组保存吐出来的所有的数，然后进行排序.时间复杂度O(N*Log(N))
// 解决2: 使用两个堆结构,一个大堆一个小堆,大堆保留所有小于中位数N/2的数
//        小堆保留大于中位数的N/2的数.
//        调堆规则:小于等于堆顶的数进大堆,否则进小堆.如果两个堆的数量不平衡,将数量
//        多的那个堆堆顶的数弹出进另一个堆.

// 问题5: 堆排序
// 解决:  1. 将数组变成一个大堆
//        2. 将最后一个元素和堆顶元素交换,最大值到数组最后的位置
//        3. 堆的大小减一
//        4. 从头结点开始向下调整

//  排序稳定性: 相同的值在排序后与原始的相对位置保持不变
//  冒泡排序:  可以实现为稳定的,遇到相同的值不改变它们的相对位置,从下一个值继续冒泡
//  插入排序:  插入排序可以实现为稳定的,遇到相等的放在后边不用向前插即可
//  选择排序:  做不到稳定排序 eg 55555401 --> 05555451 
//  归并排序:  可以做到稳定排序 eg 33456-35674,遇到相等的情况先拷贝左区就可以做到
//  快速排序:  做不带稳定排序,因为Partion做不到(实际可以做到,但是很难)
//  堆排序:    做不到稳定 44455 调大堆过程中第二个4和第一个5交换位置,改变了4的相对位置
//  桶排序、计数排序、基数排序: 都可以做到稳定
//  
//  稳定性的意义: 比如学生系统在一次考试中,有一些同学考的总分相同,现在要求按照总分从高到低
//                排序,但是总分相同的同学号相同,起初这些记录的顺序是按照学号排序,此时就可以
//                使用稳定排序来解决这个问题,可以保证相同总分的相对顺序不变;但是如果使用非
//                稳定的排序,就可能会改变相同总分同学的顺序。
//                
//  工程中综合排序算法: 
//          1. 对于内置类型:使用快速排序,不需要稳定性
//          2. 对于自定义类型:使用归并排序,对于自定义类型,有多个排序项,可能会涉及到稳定性的问题 
//          3. 数组长度很短(<60): 插入排序,插入的常数项很低,在小样本的情况,插排的效率很高
//          
// 归并排序: 可以改成空间复杂度为O(1),归并排序 内部缓存法
// 快速排序: 可以做到稳定,叫01 stable sort
// 问题: 一个数组奇数放在左边,右边放在右边,并且保持所有数的相对位置不变(时间复杂度O(N),空间复杂度O(1))
// 解决: 奇偶数是01标准,和快排的partion的稳定实现版本类似(大于等于或小于),很难实现
// 
// 比较器的使用: C++中相当于仿函数中重载了> 或者 < 符号(查)
// 堆结构也可以使用比较器


// 非基于比较的排序
// 桶排序: 计数排序、基数排序都是桶排序的一种
// 计数排序: 一个数组中所有数的范围都在0-60,这样可以开辟一个61大小的数组,遍历一遍数组
//           计算出每一个数的个数,最后在将这些数组织在数组中，基于哈希的思想
//           
// 问题: 一个数组排序后,求相邻两数的最大差值,要求时间复杂度为O(N)
// 解决: 借用桶的概念，但是不是桶排序.
//       1.准备桶,如果有N个数就准备N+1个桶
//       2.遍历数组，找到最小值和最大值, 如果最小值和最大值相等，说明只有一种数
//         如果不相等,最小值放在0号桶,最大值放在N好桶中,将0-N等分成N份,数组中的其他数
//         属于哪个范围就放在哪个桶
//       3.最左边和最右边的桶必然不为空，中间必然存在一个空桶，相邻的两个数可能来自同一个桶
//         空桶的左右一定存在非空的桶,左桶中的最大值和右桶中的最小值的差值一定大于一个桶所表达的范围
// 代码:
int maxGap(vector<int>& arr){
    if(arr.size() == 0){
        return 0;
    }
    int max = arr[0];
    int min = arr[0];
    for(size_t i = 1; i < arr.size(); i++){
        if(arr[i] > max){
            max = arr[i];
        }
        if(arr[i] < min){
            min = arr[i];
        }
    }
    vector<bool> isExist;

}
int main()
{
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(3);
    arr.push_back(-1);
    arr.push_back(4);
    arr.push_back(5);
    Solution2_landsFlag(arr, 3);
    //vector<int>::iterator it = arr.begin();
    //for(; it != arr.end(); it++){
    //    cout << *it << endl;
    //}
    Solution1(arr, 3);
    vector<int>::iterator it = arr.begin();
    for(; it != arr.end(); it++){
        cout << *it << endl;
    }
    return 0;
}
