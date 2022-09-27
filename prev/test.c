#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#define MAXLINE 256



static const t_fp	g_action[2] = {
	do_s0, do_s1
	// , do_s2, do_s3, do_s4, do_s5, do_s6, do_s7, do_s8, \
	// do_s9, do_s10, do_s11, do_s12
};

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
