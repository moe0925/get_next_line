#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include <stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include "get_next_line.h"

int BUFFER_SIZE = 5;

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

    memo = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    memo[BUFFER_SIZE + 1] = 0;
	if (!memo)
		return (NULL);

    if (!save)
    {
        save = malloc(sizeof(char) * 1);
	    save[0] = 0;
    }
	
    read_byte = 1;
	while  ((read_byte > 0 && check(memo) == -1) )
	{
	    read_byte = read(fd,memo,BUFFER_SIZE);
        save = ft_strjoin(save,memo);

    }
    if (read_byte < 0)
        return (NULL);
   
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
        line = malloc(sizeof(char) * ft_strlen(save) + 1);
        while(j < ft_strlen(save))
        {
            line[j] = save[j];
            j++;
        }
        line[j] = 0;
        return (line);
    }
    // else if ((save[0] = 0))
    //     return (NULL);
    line = malloc(sizeof(char) * (find + 2));
    if (!line)
    {
        return (NULL);
    }
    
    while(j < find)
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

    if (find == -1)
	{
		free(save);
		return (NULL);
	}
    save_new = malloc(sizeof(char) * (ft_strlen(save) - (find + 1)));
    if (!save_new)
        return (NULL);
    
    while (save[find + i + 1] != 0)
    {
        save_new[i] = save[find + i + 1];
        i++;
    }
    save_new[i] = 0;
    // printf("save:%s\n",save);
    return (save_new);
}
    
char *get_next_line(int fd)
{
    static char *save;
    char *line;
    save = make_memo(fd, save);
    if (!save)
        return (NULL);
    line = read_memo(save);
    save = make_save(save);
    // printf("save:%s\n",save);
    return (line);
}


int main(void)
{
    int  fd;
    char *line;
    int  check;

    line = "";
    fd = open("text.txt", O_RDONLY);
    if (fd == -1)
	{
			printf("ファイルオープンエラー\n");
			return 0;
	}
    check = 1;

    while (line)
    {
    // for (int i = 1;i < 8;i++)
    line = get_next_line(fd);
    printf("> %s", line);
    check++;
    free(line);


    }
    // system("leaks a.out");
    return (0);
}

