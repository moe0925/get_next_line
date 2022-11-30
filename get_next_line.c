/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moeota <moeota@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 22:58:35 by moeota            #+#    #+#             */
/*   Updated: 2022/11/30 21:33:28 by moeota           ###   ########.fr       */
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
	
	while ((line))
	{
		free(line);
		line++;
	}
	return (NULL);
}

char *get_next_line(int fd)
{
	int			read_byte;
	char		*memo;
	static char *save;
	char 		*temp;
	char 		*line;
	char 		*temp1;
	int			find;
	
	if (!save)
		save = ft_calloc(1,sizeof(char));
	memo = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!memo)
		return (0);
	read_byte = read(fd,memo, BUFFER_SIZE);
	// printf("savenew :%s\n", save);

	// printf("memo :%s\n", memo);
	if (read_byte < 0)
		return (0);

	while (read_byte > 0)
	{
		// if (save == 0)
		// 	save = &memo[0];

		while(check(memo) != 0 || memo[0] == '\n')
		{
			
			find = check(memo);
			
			temp1 = malloc(sizeof(char) * (find + 1));
			ft_strlcpy(temp1,memo, (find +1));
			line = (char *)malloc((sizeof(char))*((ft_strlen(save)) + (ft_strlen(temp1)) + 1));
			line = ft_strjoin(save,temp1);
			// printf("save :%s\n",save);
			free(temp1);
			// free(save);
			// if (save)
			// 	free(save);
			// save[0] = 0;
			// save = &memo[find + 1]; 
			save = malloc(sizeof(char) * (BUFFER_SIZE - find));
			int i;
			i = 0;
			while (memo[find + i + 1] != '\0')
			{
				save[i] = memo[find + i + 1];
				i++;
			}
			save[i] = 0;
			free(memo);
			// printf("----------------------save :%s---------------------\n",save);

			return (line);
		}

		if (check(memo)== 0 && memo[0] != '\n')
		{
			// printf("----------------------ここに１が入る-------------- :%s\n",save);
			temp1 = ft_strdup(memo);
			// printf("save3:%s\n",save);
			// printf("temp1:%s\n",temp1);
			save = ft_strjoin(save,temp1);
			// printf("save2 :%s\n",save);
			free(temp1);
		}
		
		// free(memo);//ここおかしい
		read_byte = read(fd,memo, BUFFER_SIZE);
	}
	
	if (read_byte == 0 && ((save[0] != 0)))
		{
			line = ft_strdup(save);
			save[0] = 0;
			// malloc_free(save);
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

