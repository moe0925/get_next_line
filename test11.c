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

char *make_memo(int fd)
{
    int read_byte;
	char *memo;
    memo = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    memo[BUFFER_SIZE + 1] = 0;
	if (!memo)
		return (NULL);
	
	read_byte = read(fd,memo,BUFFER_SIZE);
    if (read_byte < 0)
        return (NULL);
    return (memo);
}

char *read_memo(int fd)
{
    char *memo;
    static char *save;
    char *line;
    while(make_memo(fd))
    {
        int find;
        char *temp;

        memo = make_memo(fd);
        if(check(memo)== -1)
        {
        save = ft_strjoin(save,memo);
        free(memo);
        }
        if (check(memo) > 0)
        {

            find = check(temp);
            temp = malloc(sizeof(char) * (find + 2));
            int j;
            j = 0;
            
            while(j < find)
            {
                temp[j] = memo[j];
                j++;
            }
            temp[j] = 0;

            // ft_strlcpy(temp,memo,find+1);
            printf("temp:%s",temp);
            printf("hi");
			line = (char *)malloc((sizeof(char))*((ft_strlen(save)) + (ft_strlen(temp)) + 1));
			line = ft_strjoin(save,memo);
            int i;
            i = 0;
            save = malloc(sizeof(char) * (BUFFER_SIZE - find));
            while (memo[find + i + 1] != 0 )
            {
                save[i] = memo[find + i + 1];
                i++;
            }
            save[i] = 0;
            free(memo);
            printf("save;%s\n",save);
            return (line);
        }
    }
    return (NULL);
    
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
    // line = get_next_line(fd);
    line = read_memo(fd);
    printf("> %s", line);
    check++;
    free(line);
    }
    // system("leaks a.out");
    return (0);
}

