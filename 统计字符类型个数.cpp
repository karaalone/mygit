#include<stdio.h> 
#include<string.h>
void func(char s[100])
{   int i, j=0, m=0, n=0, k=0, z=0;
    char *p=s;
    for(i=0;i<strlen(s);i++)
    {
	    if(*p>='A'&&*p<='Z')
        {  j++;
	    }
	    else if(*p>='a'&&*p<='z')
	    {  m++;
		}
		else if(*p==32)
		{  n++;
		}
		else if(*p>='0'&&*p<='9')
		{  k++;
		}
		else z++;
		p=p+1;
    }
    printf("´óÐ´×ÖÄ¸:%d Ð¡Ð´×ÖÄ¸:%d ¿Õ¸ñ:%d Êý×Ö:%d ÆäËû×Ö·û:%d", j, m, n, k, z);
}
int main()
{   char s[100];
    gets(s);
    func(s);
    return 0;
}
