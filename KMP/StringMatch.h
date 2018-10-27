#ifndef STRING_MATCH
#define STRING_MATCH
typedef struct 
{
    char *data;
    int length;
} String;
String* intitString(char *data,int len);
void printString(String *str);
int LinearMatch(String* str,String *pattern,int pos);
#endif