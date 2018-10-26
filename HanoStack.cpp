#include <iostream>
#include <time.h>
#include <string>
using namespace std;
//圆盘的个数最多为64
const int MAX = 64;
//用来表示每根柱子的信息
struct Tower
{
    int block[MAX];
    string name;
    int length;

    Tower(int num, string name);

    void push(int num);
    void print();
    int pop(); //提取栈顶元素
    int top(); //获取栈顶元素，不改变
};
void Tower::print()
{
    std::cout << "Name:" << this->name << " Num:" << this->length << std::endl;
}
Tower::Tower(int num, string name)
{
    length = 0;
    this->name = name;
    for (int i = 0; i < num; i++)
    {
        block[length++] = num - i;
    }
}
void Tower::push(int num)
{
    this->block[length++] = num;
}
int Tower::pop()
{
    this->length--;
    return this->block[this->length];
}
int Tower::top()
{
    return this->block[this->length - 1];
}
/**
 * 用数学归纳法很容易证明n阶汉诺塔，需要2^n-1次。
 * n=1 num=1
 * n=2 num=3
 * 令 n时 num=2^n-1;
 * 当n+1时，最终结束前的状态是:src=1,midlle=n;midlle-->dis:2^n-1;src-->middle:2^n-1;src-->dis:1
 * 总结:num=2^n-1 + 2^n-1 +1=2^(n+1)+1;
 * */
Tower *towerArry[3];
int Pow(int base, int exp);

void CreateHanno(Tower *towerArry[3], int BlockNum);
void ResolveHanno(int max, Tower *towerArry[3]); //解析汉诺塔过程
void ResolveHanno(int MAX, Tower *towerArry[3])
{
    int k = 0;
    int i = 0;
    int ch;
    while (k < MAX)
    {
        //按顺时针方向把圆盘1从现在的柱子转移到下一根柱子。
        ch = towerArry[i % 3]->pop();
        towerArry[(i + 1) % 3]->push(ch);
        cout << ++k << ": "
             << "Move Disk " << ch << " from " << towerArry[i % 3]->name << " to "
             << towerArry[(i + 1) % 3]->name << std::endl;
        i++;

        if (k < MAX)
        {
            //将非空的柱子上的栈顶元素放到空的地方去。
            if (towerArry[(i + 1) % 3]->length == 0 || towerArry[(i - 1) % 3]->length > 0 && towerArry[(i + 1) % 3]->top() > towerArry[(i - 1) % 3]->top())
            {
                ch = towerArry[(i - 1) % 3]->pop();
                towerArry[(i + 1) % 3]->push(ch);
                cout << ++k << " : "
                     << "Move Disk " << ch << " from " << towerArry[(i - 1) % 3]->name << " to " << towerArry[(i + 1) % 3]->name
                     << std::endl;
            }
            else
            {
                /* code */
                ch = towerArry[(i + 1) % 3]->pop();
                towerArry[(i - 1) % 3]->push(ch);
                cout << ++k << " : "
                     << "Move Disk " << ch << " from " << towerArry[(i + 1) % 3]->name << " to " << towerArry[(i - 1) % 3]->name
                     << std::endl;
            }
        }
    }
}
void CreateHanno(Tower *towerArry[3], int BlockNum)
{
    towerArry[0] = new Tower(BlockNum, "A");
    if (BlockNum % 2 == 0)
    {

        towerArry[1] = new Tower(0, "B");
        towerArry[2] = new Tower(0, "C");
    }
    else
    {
        towerArry[1] = new Tower(0, "C");
        towerArry[2] = new Tower(0, "B");
    }
}
int Pow(int base, int exp)
{
    int sum = 0;
    int num = base;
    for (int i = 1; i < exp; i++)
    {
        num *= base;
    }
    return num;
}
int main(int argc, char const *argv[])
{
    /* code */
    cout << Pow(2, 2) << std::endl;
    int num;
    cin >> num;
    CreateHanno(towerArry, num);
    for (int i = 0; i < 3; i++)
    {
        towerArry[i]->print();
    }
    ResolveHanno(Pow(2, num) - 1, towerArry);
    return 0;
}
