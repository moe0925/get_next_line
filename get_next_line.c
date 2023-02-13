#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include <stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include "get_next_line.h"

int check(char *str)
{
	int i;

	i = 0;
	while(str[i] != '\0')
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char *make_memo(int fd, char *save)
{
    int read_byte;
	char *memo;

    memo = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!memo)
		return (NULL);
    memo[BUFFER_SIZE] = 0;
    if (!save)
    {
        save = (char *)malloc(sizeof(char) * 1);
        if (!save)
            return NULL;
	    save[0] = 0;
    }
	while  (1)
	{
	    read_byte = read(fd,memo,BUFFER_SIZE);
        if (read_byte == -1)
        {
            break ;
        }
        // printf("readbyte:%d\n",read_byte);
        // printf("memo:%s\n",memo);
        memo[read_byte] = 0;
        if (read_byte!= 0)
            save = ft_strjoin(save,memo);
        if (check(memo) != -1 || read_byte == 0)
            break ;
            // save = NULL;
        // printf("save:%s\n",save);
    }
    // if (read_byte == 0)
    // {
    //     return (NULL);
    // }
    if (read_byte < 0)
    {
        free(memo);
        return (NULL);

    }
    // if (read_byte == 0)
    // {
    //     return (NULL);
    // }
    free(memo);
    return (save);
}

char *read_memo(char *save)
{
    int find;
    char *line;
    int j;

    j = 0;
    if (!save[0])
		return (NULL);
	find = check(save);
    if (find == -1 && (save))
    {
        line = (char *)malloc(sizeof(char) * ft_strlen(save) + 1);
        if (!line)
            return NULL;
        while(j < (int)ft_strlen(save))
        {
            line[j] = save[j];
            j++;
        }
        line[j] = 0;
        return (line);
    }
    // else if ((save[0] = 0))
    //     return (NULL);
    line = (char *)malloc(sizeof(char) * (find + 2));
    if (!line)
    {
        return (NULL);
    }
    
    while(j <= find)
    {
        line[j] = save[j];
        j++;
    }
    line[j] = 0;
    // printf("line:%s\n",line);
    // printf("save:%s\n",save);
    return (line);
}

char *make_save(char *save)
{
    int find;
    int i;
    char *save_new;
    // printf("save:%s\n",save);

    find = check(save);
    i = 0;

    // if(find == -1 && save[0] == 0)
    // {

    // }
    if (find == -1)
	{
		free(save);
        // printf("hi");
		return (NULL);
	}

    save_new = (char *)malloc(sizeof(char) * (ft_strlen(save) - (find + 1)));
    if (!save_new)
        return (NULL);
    
    while (save[find + i + 1] != 0)
    {
        save_new[i] = save[find + i + 1];
        i++;
    }
    save_new[i] = 0;
    // printf("savenew-----:%s\n",save_new);
    free(save);
    return (save_new);
}
    
char *get_next_line(int fd)
{
    static char *save;
    char *line;

    if (fd < 0 || BUFFER_SIZE <= 0)
    {
        return (NULL);
    }

    save = make_memo(fd, save);
    // printf("save:%s\n",save);
    
    if (!save)
    {
        return (NULL);

    }
    line = read_memo(save);
    save = make_save(save);
    // printf("save:%s\n",save);ç
    return (line);
}


int main(void)
{
    int  fd;
    char *line;
    int  check;

    line = "";
    fd = open("text.txt", O_RDONLY);
    // fd =1000;
    // if (fd == -1)
	// {
	// 		printf("ファイルオープンエラー\n");
	// 		return 0;
	// }
    check = 1;

    while (line)
    {
    line = get_next_line(fd);
        printf("fd:%d\n",fd);

    printf("> %s", line);
    check++;
    free(line);


    }
    system("leaks a.out");
    return (0);
}

