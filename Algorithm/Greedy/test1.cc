#include <iostream>

using namespace std;

// Q:六种面额 1 5 10 20 100 200, 给定一个具体的钱数X,求使用最少几张钱能凑出来X
// 当前最优解为全局最优解,因为后边的面值都是前边的面值的倍数
// 注意:如果增加一种面值7,不满足当前倍数关系，不满足贪心(使用动态规划解决)
int main()
{
    const int RMB[] = {200, 100, 20, 10, 5, 1};
    const int NUM = 6;
    int X = 0;
    cin >> X; // 具体钱数
    int count = 0;// 记录当前人民币的张数
    for(int i = 0; i < NUM; i++)
    {
        int tmp = X / RMB[i];
        count += tmp;
        X = X - tmp * RMB[i];
        cout << "需要面值为:" << RMB[i] << "的 " << tmp << " 张" << endl;
        cout << "剩余的支付金额为:" << X << endl;
    }
    cout << "最少需要:" << count << "张面额人民币" << endl;
    return 0;
}
