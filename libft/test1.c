/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 09:01:44 by daegulee          #+#    #+#             */
/*   Updated: 2022/09/22 09:27:44 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

// int	main(int argc, char **argv, char **envp)
// {
// 	char	*str;
// 	int		i;
// 	char	*full_path;
// 	char	**split;

// 	i = -1;
// 	cmd = "ls";
// 	PATH = PATH=ddfakd:/dafdfaf:/adfasfd:
// 	//bin/ls
// 	if (ft_strnstr(\) )
// 		access(cmd, X_OK);
// 		execve(cmd, argv, envp);
// 	// ls 
// 	bin/ls/cmd;
// 	access(X_OK) == 1
// 	execve(bin/ls/cmd, argv, envp);
// 	usr/bin/cmd;
// 	access(X_OK) == 1
// 	execve(vin/ls/cmd, argv, envp);

// 	check = open( );
// 	if (!(check < 0))
// 		execve
// 	else
// 		print_cmderror;
// }	
// struct stat{
// 	~~
// 	mode_t st_mode;
// }
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>
int main(int argc, char *argv[])
{
    struct stat sb;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <pathname>\n", argv[0]);
        return 1;
    }

    if (stat(argv[1], &sb) == -1) {
        perror("stat");
		error_cmd;
        return 1;
    }

    printf("File type:                ");

    switch (sb.st_mode & S_IFMT) {
        case S_IFBLK:  printf("block device\n");            break;
        case S_IFCHR:  printf("character device\n");        break;
        case S_IFDIR:  printf("directory\n");               break;
        case S_IFIFO:  printf("FIFO/pipe\n");               break;
        case S_IFLNK:  printf("symlink\n");                 break;
        case S_IFREG:  printf("regular file\n");            break;
        case S_IFSOCK: printf("socket\n");                  break;
        default:       printf("unknown?\n");                break;
    }

    printf("I-node number:            %ld\n", (long) sb.st_ino);
    printf("Mode:                     %lo (octal)\n", (unsigned long) sb.st_mode);
    printf("Link count:               %ld\n", (long) sb.st_nlink);
    printf("Ownership:                UID=%ld   GID=%ld\n", (long) sb.st_uid, (long) sb.st_gid);
    printf("Preferred I/O block size: %ld bytes\n",         (long) sb.st_blksize);
    printf("File size:                %lld bytes\n",        (long long) sb.st_size);
    printf("Blocks allocated:         %lld\n",              (long long) sb.st_blocks);
    printf("Last status change:       %s", ctime(&sb.st_ctime));
    printf("Last file access:         %s", ctime(&sb.st_atime));
    printf("Last file modification:   %s", ctime(&sb.st_mtime));

    return 0;
}
