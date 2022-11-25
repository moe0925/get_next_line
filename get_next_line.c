/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moeota <moeota@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 22:58:35 by moeota            #+#    #+#             */
/*   Updated: 2022/11/25 09:59:58 by moeota           ###   ########.fr       */
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

char *get_next_line(int fd)
{
	int read_byte;
	char *memo;
	int BUFFER_SIZE;
	int i;
	static char *save;
	save = malloc (sizeof(char) * 1);
	save[0] = 0;
	BUFFER_SIZE = 5;
	char *temp;
	char *line;
	int j;
	j = 0;
	

	memo = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!memo)
		return (0);
	
	// printf("~~~~~~~~~~~~~~~~~~~~~test1~~~~~~~~~~\n");
	read_byte = read(fd,memo, BUFFER_SIZE);
	i = 0;

	if (read_byte < 0)
		return (0);

	while (read_byte > 0)
	{
		memo[BUFFER_SIZE + 1] = 0;
		char *find;
	
		find = ft_strchr(memo, '\n');
		if (save == 0)
			save = &memo[0];
		// printf("%s", find);
		printf ("〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜テスト１〜〜〜〜〜〜〜〜〜\n%s\n",save);

		while(ft_strchr(memo,'\n') != 0)
		{
			*find = 0;

			j++;
			printf("〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜%d回目の改行発見~~~~~~~~~~\n",j);
			// printf("%s\n",save);
			// printf("%s\n",memo);

			line = (char *)malloc((sizeof(char))*((ft_strlen(save)) + (ft_strlen(memo)) + 1));
			line = ft_strjoin(save,memo);
			// printf ("%s",ft_strjoin(save,memo));
			printf ("%s\n",line);
			save[0] = 0;
			memo = find +1 ;
			printf("現時点でのsave");
			printf("%s\n", save);
			printf("line: %s\n",line);
			return (line);


		}
		// save = find + 1;
		printf ("〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜テスト2〜〜〜〜〜〜〜〜〜\n%s\n",save);

		
		if (ft_strchr(memo,'\n')== 0)
		{
		printf("~~~~~~~~~~~~~~~~~~~~~改行なし~~~~~~~~~~\n");

		// if (*save == 0 )
		// 	save = &memo[0];
		
		temp = malloc(sizeof(char) * BUFFER_SIZE + 1);
		temp = memo;
		save = ft_strjoin(save,temp);
		temp = 0;
		
		// printf ("%s\n",memo);
		printf ("変更後%s\n",save);

		// printf ("%p",save);
		// for (int i = 0; i < BUFFER_SIZE ; i++)
		i++;
		printf("%d回目\n",i);
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		printf ("最後%s\n",save);




		}
		

		read_byte = read(fd,memo, BUFFER_SIZE);
		// printf("~~~~~~~~~~~~再読み込み~~~~~~~~~~~~~~~~~~~\n");




	}
	
	// temp = malloc(sizeof(char) * (ft_strlen(save) + ft_strlen(memo) + 1));
	// temp = memo;
	// save = ft_strjoin(save,memo);
	if (read_byte == 0)
		printf("%s\n",save);	
	printf ("000\n");

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
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
   
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
	printf("> %s", line);
	check++;
	free(line);
	}
	system("leaks a.out");
   
    // ファイルを閉じる
    close(fd1);
    return 0;
}