#include <stdio.h>
//#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "validate.h"

int isNumber(char* string)
{
    int ret=-1;
    int i=0;
    if(string!=NULL)
    {
        while(string[i]!='\0')
        {
            if(string[i]<'0' || string[i]>'9')
                break;
            i++;
        }
        if(string[i]=='\0')
        {
            ret=1;
        }
    }
    return ret;
}

int getNumber(char* number)
{
    int ret;

    scanf("%s", number);

    if(isNumber(number)!=-1)
    {
        ret = 1;
    }
    else
    {
        ret = 0;
    }

    return ret;
}

int isWord(char* string)
{
    int ret=-1;
    int i=0;
    if(string!=NULL)
    {
        while(string[i]!='\0')
        {
            if(string[i]!=' ' && (string[i]<'a' || string[i]>'z') && (string[i]<'A' || string[i]>'Z'))
                break;
            i++;
        }
        if(string[i]=='\0')
        {
            ret=1;
        }
    }
    return ret;
}
