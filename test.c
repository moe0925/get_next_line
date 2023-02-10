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

char *get_next_line(int fd)
{
	int read_byte;
	char *memo;
    char *line;
	static char *save;
    char *temp;

    if (!save)
    {
        save = malloc(sizeof(char) * 1);
	    save[0] = 0;
    }
	
	memo = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    memo[BUFFER_SIZE + 1] = 0;
	if (!memo)
		return (NULL);
	
    // printf("memo;%s\n",memo);

    // printf("%d",read_byte);

    // while ()
	if (read_byte < 0)
		return (NULL);


    read_byte = 1;
	while  (read_byte > 0)
	{
	    read_byte = read(fd,memo,BUFFER_SIZE);

		// memo[BUFFER_SIZE + 1] = 0;
		int find;
		find = check(memo);
		
		// printf ("〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜テスト１〜〜〜〜〜〜〜〜〜\n");
        // printf("%d\n",find);
        
       
        
		while (find >= 0)
		{
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
            printf("temp:%s\n",temp);
			line = (char *)malloc((sizeof(char))*((ft_strlen(save)) + (ft_strlen(temp)) + 1));
            printf("save;%s\n------------\n",save);
            printf("memo;%s\n------------\n",memo);
			line = ft_strjoin(save,temp);
            int i;
            i = 0;
            save = malloc(sizeof(char) * (BUFFER_SIZE - find));
            while (memo[find + i + 1] != 0 )
            {
                save[i] = memo[find + i + 1];
                i++;
            }
            save[i] = 0;
            printf("line;%s\n----------\n",line);
            // free(memo);
            return (line);
		}

        if (find == -1)
        {
            // free(memo);
            save = ft_strjoin(save,memo);
            printf("save;%s\n------------\n",save);
            printf("memo;%s\n------------\n",memo);
            free(memo);
        }

	}
    if (read_byte == 0)
    {
        printf("read_byte0:%s\n",save);
        printf("hi");
        line = ft_strjoin(save,memo);
        printf("%s", line);
        free(memo);
        return (line);
    }
	return (NULL);
	}
	
	
	// if (read_byte == 0)
	// 	printf("%s\n",save);	
	// printf ("000\n");
	// return (0);


//  int  BUFFER_SIZE = 1000;

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
    line = get_next_line(fd);
    printf(">%d回目の出力 %s\n~~~~~~~~~~~~~~~~~~\n", check,line);
    check++;
    free(line);
    }
    // system("leaks a.out");
    return (0);
}