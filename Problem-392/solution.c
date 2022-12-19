#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool isSubsequence(char * s, char * t);
int main (void)
{
    char s[] = "abc";
    char t[] = "ahbgdc";
    bool answer = false;

    answer = isSubsequence(s,t);

    printf("Is Subsequence = %d", answer);

    return 0;
}

bool isSubsequence(char * s, char * t)
{
    int sLen = strlen(s);
    char *chr = (char *) malloc(sLen * sizeof(char));
    int *chrArr = (int *) malloc(sLen * sizeof(int));
    int chrLen;
    int i = 0;
    int prevVal = 0;

    for (i = 0; i < sLen; i++)
    {
        /* '\0' = 0 in int */
        chr = strchr(t, (int) (*(s + i)));
        printf("chr = %s\n", chr);
        chrLen = strlen(chr);
        if (!chr)
        {
            return false;
        }
        *(chrArr + i) = chrLen;
    }
    prevVal = *chrArr;
    for (i = 1; i < sLen; i++)
    {
        /* If descending order */
        if (prevVal < *(chrArr + i))
        {
            return false;
        }
        prevVal = *(chrArr + i);
    }
    free(chr);
    free(chrArr);
    
    return true;
}