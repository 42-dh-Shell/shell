#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#define MAXLINE 256

int main()
{
    FILE *fp;
    int state;

    char buff[MAXLINE];
    fp = popen("ls -al", "r");
    if (fp == NULL)
    {
        perror("erro : ");
        exit(0);
    }

    while(fgets(buff, MAXLINE, fp) != NULL)
    {
        printf("%s", buff);
    }

    state = pclose(fp);
    printf("state is %d\n", state);
}
