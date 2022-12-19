#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool isSubsequence(char * s, char * t);
int main (void)
{
    char s[] = "aaaaaa";
    char t[] = "bbaaaa";
    bool answer = false;

    answer = isSubsequence(s,t);

    printf("Is Subsequence = %d", answer);

    return 0;
}

bool isSubsequence(char * s, char * t)
{
    int sLen = strlen(s);
    int tLen = strlen(t);
    char *chr;
    int *chrArr;
    int chrLen;
    int i = 0;
    int prevVal = 0;
    
    if (s == NULL || t == NULL)
    {
        return false;
    }
    if (*s == '\0')
    {
        return true;
    }
    else if (*t == '\0' && *s != '\0')
    {
        return false;
    }
    else if (*s == '\0' && *t == '\0')
    {
        return true;
    }
    chrArr = (int *) malloc(sLen * sizeof(int));
    for (i = 0; i < sLen; i++)
    {
        /* '\0' = 0 in int */
        chr = strchr(t, (int) (*(s + i)));
        if (!chr)
        {
            free(chrArr);
            return false;
        }
        chrLen = strlen(chr);
        *(chrArr + i) = chrLen;
    }
    prevVal = *chrArr;
    if (prevVal != tLen)
    {
        if (prevVal < sLen)
        {
            return false;
        }
    }
    for (i = 1; i < sLen; i++)
    {
        /* If descending order */
        if (prevVal < *(chrArr + i))
        {
            free(chrArr);
            return false;
        }
        prevVal = *(chrArr + i);
    }
    
    free(chrArr);
    return true;
}