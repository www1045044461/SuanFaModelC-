#include <iostream>
#include <string>
#include <vector>
using namespace std;
/**
 * num:剩余的木块数
 * tar1:第一个塔，作为源塔
 * tar2:第二个塔,作为中间塔
 * tar3:第三个塔，作为目的塔
 * */
static int num1=0;
void HannoNoStack(int num,string tar1,string tar2,string tar3);
inline void Move(int num,string tarSrc,string dis);
inline void Move(int num,string tarSrc,string dis)
{
    num1++;
    cout<<"Move "<<num<<" From "<<tarSrc<<" to "<<dis<<" 次数:"<<num1<<std::endl; 
}
void HannoNoStack(int num,string tar1,string tar2,string tar3)
{
    if(num==1)
        Move(1,tar1,tar3);
    else{
        HannoNoStack(num-1,tar1,tar3,tar2);
        Move(num,tar1,tar3);
        HannoNoStack(num-1,tar2,tar1,tar3);
    }
}
int main(int argc, char const *argv[])
{
    /* code */
    int num;
    cin>>num;
    HannoNoStack(num,"TarA","TarB","TarC");
    return 0;
}
