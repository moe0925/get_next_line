/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moeota <moeota@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 22:58:35 by moeota            #+#    #+#             */
/*   Updated: 2022/11/30 20:28:05 by moeota           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

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
	static char *save;
	char *temp;
	char *line;
	char *temp1;
	int		find;
	
	if (!save)
		save = ft_calloc(1,sizeof(char));

	memo = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!memo)
		return (malloc_free(memo));
	read_byte = read(fd,memo, BUFFER_SIZE);

	if (read_byte < 0)
		return (0);

	while (read_byte > 0)
	{
		memo[BUFFER_SIZE + 1] = 0;
		if (save == 0)
			save = &memo[0];

		while(check(memo) != 0 || memo[0] == '\n')
		{
			find = check(memo);
			
			temp1 = malloc(sizeof(char) * (find + 1));
			ft_strlcpy(temp1,memo, (find + 1));
			// printf("---------------%s-----------\n",temp1);
			line = (char *)malloc((sizeof(char))*((ft_strlen(save)) + (ft_strlen(temp1)) + 1));
			line = ft_strjoin(save,temp1);
			free(temp1);
			save[0] = 0;
			save = &memo[find + 1] ;
			return (line);
		}

		// while(ft_strchr(memo,'\n') != 0)
		// {
		// 	find = ft_strchr(memo, '\n');
		// 	// *find = 0;
			
		// 	temp1 = malloc(sizeof(char) * )

		// 	line = (char *)malloc((sizeof(char))*((ft_strlen(save)) + (ft_strlen(memo)) + 1));
		// 	// if (!line)
		// 	// {
		// 	// 	malloc_free(line);
		// 	// 	return (malloc_free)
		// 	// }
		// 	line = ft_strjoin(save,memo);
		// 	save[0] = 0;
		// 	save = find +1 ;
		// 	return (line);
		// }
		
		// if (ft_strchr(memo,'\n')== 0)
		// {
			
		// 	temp = malloc(sizeof(char) * BUFFER_SIZE + 1);
		// 	temp = memo;
		// 	save = ft_strjoin(save,temp);
		// 	temp = 0;
		// }
		if (check(memo)== 0 && memo[0] != '\n')
		{
			temp = malloc(sizeof(char) * BUFFER_SIZE + 1);
			temp = memo;
			save = ft_strjoin(save,temp);
			temp = 0;
		}
		
		free(memo);
		read_byte = read(fd,memo, BUFFER_SIZE);
	}
	
	if (read_byte == 0 && ((save[0] != 0)))
		{
			line = ft_strdup(save);
			save[0] = 0; 
			return (line);
		}
	// if (read_byte == 0 && (save))
	// line = ft_strdup(save);
	// return (line);
	// 	printf("%s",save);
	// {
	// 	printf("-----------%s\n",save);	
	// printf("~~~~~~~~~~~~^%s\n",line);
	// save[0] = 0;
	// 	return (line);
	// }
	// return (line);
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

