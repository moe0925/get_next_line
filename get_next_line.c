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
	return (0);
}

char *malloc_free(char *line)
{
	int i;
	i = 0;
	while (!(line))
	{
		free(line);
		i++;
	}
	line = ft_calloc(1,sizeof(char));
	return (line);
}

char *get_next_line(int fd)
{
	int read_byte;
	char *memo;
	char *line;
	char *temp1;
	int find;
	static char *save;

	if (!save)
		save = ft_calloc(1,sizeof(char));

	memo = ft_calloc(BUFFER_SIZE+ 1, sizeof(char));
	if (!memo)
		return (NULL);
	read_byte = read(fd, memo, BUFFER_SIZE);

	if (read_byte < 0)
		return (NULL);
	
	if (read_byte > 0)
	{
		if (check(memo) != 0 || memo[0] == '\0')
		{
			printf("-------------------------------------");
			find = check(memo);
			temp1 = malloc(sizeof(char) * (find + 1));
			ft_strlcpy(temp1,memo, (find +1));
			line = (char *)malloc((sizeof(char))*((ft_strlen(save)) + (ft_strlen(temp1)) + 1));
			if (!line)
				return (NULL);
			line = ft_strjoin(save,temp1);
			free(temp1);
	 		free(save);
			save = malloc(sizeof(char) * (BUFFER_SIZE - find));
			int i;
			i = 0;
			while (memo[find + i + 1] != '\0')
			{
				save[i] = memo[find + i + 1];
				i++;
			}
			save[i] = 0;
			free(memo);//いる
			return (line);
		}

		else if(check(memo) == 0 && memo[0] != '\n')
		{
			temp1 = ft_strdup(memo);
			save = ft_strjoin(save,temp1);
			free(temp1);
			free(memo);
		}
		// free(memo);

	}

	if (read_byte == 0 && ((save[0] != 0)))
		{
			line = ft_strdup(save);
			free(save);
			return (line);
		}
	// free(save);
	return (NULL);
}



int main()
{
// 変数定義
    int fd1;
    // char buf[BUF_SIZE];
 	char *line;
	int  check;

	line = "";
	//open("text.txt", O_RDONLY);
	check = 1;
    fd1 = 0;
   
    // ファイルのオープン
	fd1 = open("test.txt", O_RDONLY);
	if (fd1 == -1)
	{
			printf("ファイルオープンエラー\n");
			return 0;
	}
	// byte_num = read(fd1, &buf[0], 5);
    // ファイルから5バイト読み込み
	while (line)
	{
	line = get_next_line(fd1);
	printf("> %s\n", line);
	check++;
	free(line);
	}
	system("leaks a.out");
   
    // ファイルを閉じる
    close(fd1);
    return 0;
}