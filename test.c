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
	
	read_byte = read(fd,memo,BUFFER_SIZE);
    printf("memo;%s\n",memo);

    // printf("%d",read_byte);
	if (read_byte < 0)
		return (NULL);

	if  (read_byte > 0)
	{
		// memo[BUFFER_SIZE + 1] = 0;
		int find;
		find = check(memo);
		
		// printf ("〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜テスト１〜〜〜〜〜〜〜〜〜\n");
        printf("%d\n",find);
        
       
        
		if (find >= 0)
		{

			// j++;
    // printf("memo;%s",memo);

			// printf("〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜%d回目の改行発見~~~~~~~~~~\n",j);
			// printf("〜〜〜〜〜〜〜〜〜〜〜〜〜〜２~~~~~~~~~~\n");
			// printf("%s\n",save);
			// printf("%s\n",memo);
            
            temp = malloc(sizeof(char) * (find + 2));
            // printf("%d",temp);
            // printf("hi");

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
			// printf ("%s",ft_strjoin(save,memo));
			// printf ("%s\n",line);


			// save[0] = 0;


			// printf("現時点でのsave");
			// printf("%s\n", save);
			// printf("line: %s\n",line2);
		}

        if (find == -1)
        {
            save = ft_strjoin(save,memo);
            free(memo);
        }
       
       
		// save = find + 1;
		// printf ("〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜テスト2〜〜〜〜〜〜〜〜〜\n%s\n",save);

		
		// if (ft_strchr(memo,'\n'))
		// {
		// printf("~~~~~~~~~~~~~~~~~~~~~改行なし~~~~~~~~~~\n");

		// // if (*save == 0 )
		// // 	save = &memo[0];
		
		// temp = malloc(sizeof(char) * BUFFER_SIZE + 1);
		// temp = memo;
		// save = ft_strjoin(save,temp);
		// temp = 0;
		
		// // printf ("%s\n",memo);
		// printf ("変更後%s\n",save);

		// // printf ("%p",save);
		// // for (int i = 0; i < BUFFER_SIZE ; i++)
		// i++;
		// printf("%d回目\n",i);
		// printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		// printf ("最後%s\n",save);
	}
    if (read_byte == 0)
    {
        printf("%s\n",memo);
        line = ft_strjoin(save,memo);
        free(memo);
        return (line);
    }
		

		// read_byte = read(fd,memo, BUFFER_SIZE);
		// printf("~~~~~~~~~~~~再読み込み~~~~~~~~~~~~~~~~~~~\n");

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
    printf("> %s", line);
    check++;
    free(line);
    }
    // system("leaks a.out");
    return (0);
}