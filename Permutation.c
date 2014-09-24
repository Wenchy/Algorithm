#include <stdio.h>
void permutation(char* pStr, char* pBegin)
{
    if(!pStr || !pBegin)
        return;
    if(*pBegin == '\0')
    {
        printf("%s\n", pStr);
    }
    else
    {
        char* pCh;
        for(pCh = pBegin; *pCh != '\0'; pCh++)
        {
            char tmp = *pCh;
            *pCh = *pBegin;
            *pBegin = tmp;

            permutation(pStr, pBegin+1);

            tmp = *pCh;
            *pCh = *pBegin;
            *pBegin = tmp;
        }
    }
}

int main(int argc, char* argv[])
{
    char str[10];
    scanf("%s", str);
    permutation(str, str); 
    return 0;    
}
