#include "./StringMatch.h"
#include <stdio.h>
#include <stdlib.h>
//打印串
void printString(String *str)
{
    if (str == NULL)
        return;

    for (size_t i = 0; i < str->length - 1; i++)
    {
        printf("%c", str->data[i]);
    }
    printf(" ");
}
//生成串
String *intitString(char *data, int len)
{

    if (data == NULL)
        return NULL;
    String *str = (String *)malloc(sizeof(String));
    if (str == NULL)
        return NULL;
    str->data = (char *)malloc(len * sizeof(char));
    for (size_t i = 0; i < len; i++)
    {
        str->data[i] = data[i];
    }
    str->length = len;
    return str;
}
//暴力匹配
int LinearMatch(String *str, String *pattern, int pos=0)
{
    static int num=0;
    int strP = pos;
    int patternP = 0;

    while ((strP < str->length) && (patternP < pattern->length-1))
    {
        /* code */
        num++;
        printf("%c %c \t",str->data[strP],pattern->data[patternP]);
        if (str->data[strP] == pattern->data[patternP])
        {
            strP++;
            patternP++; //字符匹配下一个
            printf(" OK \n");
        }
        else
        {
            strP = strP - patternP + 1;
            //字符不匹配，模式中的收个匹配字符在ｓｔｒ中对应
            //的字符的下一个字符位置
            patternP = 0; //模式指针归０
            printf("回溯\n");
        }
    }
    printf("暴力次数:%d \n",num);
    if (patternP == pattern->length-1)
    {
        /* code */
        return strP - patternP;
    }
    else
        return -1;
    return 0;
}

//ＫＭＰ算法
int* CreateNext(String *str) //生成next数组
{
    
    if(str==NULL) return NULL;
    int *nextArry=(int*)malloc(sizeof(int)*str->length);
    //要返回的数组只能从堆创建
    int k=-1;int j=0;
    nextArry[0]=-1;//第一个字符无法移动
    
    while(j<str->length-1){
       
       if (k==-1 || str->data[j]==str->data[k]) {
           nextArry[++j]=++k;
           //满足P[0~k-1]k=P[j-k~j-1]j;找到满足该条件的K值
       }
       else
       {
           k=nextArry[k];
       }
    }
    return nextArry;
}
int KMPMatch(String *str,String *pattern)
{
    static int KMPNum=0;
    if((str==NULL)||(pattern==NULL)) return -1;
    
    int *nextArry=CreateNext(pattern);//获取nextArry;
    if(nextArry==NULL) return -1;
    int j=0;int i=0;

    for(i= 0; (i < str->length-1)&&(j<pattern->length-1); )
    {
        KMPNum++;
        printf("%c %c ",str->data[i],str->data[j]);
        if((str->data[i]==pattern->data[j])||(j==-1))
        {
            i++;j++;
            printf("OK　\n");
        }//字符匹配,或者j回溯为-1的时候
        
        else//字符不匹配
        {
            j=nextArry[j];
            printf("回溯j\n");
        }
        
    }
    printf("KMP算法次数:%d \n",KMPNum);
    if (j==pattern->length-1) {
        /* code */
        return i-j;
    }
    else
    {
        return -1;
    }
    
    
}

int main(int argc, char const *argv[])
{
    printf("暴力破解\n");
    char a[] = "0000000000000000001";
    char pattern[] = "0001";
    String *str = intitString(a, 20);
    String *str1 = intitString(pattern, 5);
    int vb = LinearMatch(str, str1);
    printf("return:%d \n",vb);
    printString(str);
    printString(str1);
    
    printf("KMP算法\n");
    int vKmp=KMPMatch(str,str1);
    printf("return:%d \n",vKmp);
    return 0;
}
