/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moeota <moeota@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 22:58:35 by moeota            #+#    #+#             */
/*   Updated: 2022/11/23 20:25:22 by moeota           ###   ########.fr       */
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




int get_next_line(int fd, char **line)
{
	int read_byte;
	char *memo;
	int BUFFER_SIZE;
	int i;
	static char *save;
	save = malloc (sizeof(char) * 1);
	save[0] = 0;
	BUFFER_SIZE = 5;

	memo = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!memo)
		return (0);
	
	// printf("~~~~~~~~~~~~~~~~~~~~~test1~~~~~~~~~~\n");
	read_byte = read(fd,memo, BUFFER_SIZE);
	i = 0;

	if (read_byte < 0)
		return (0);
	if (read_byte == 0)
	{
		// line2 = save;
		// printf("%s\n", save);
		printf ("0\n");
		return (0);
	}
	while (read_byte > 0)
	{
		memo[BUFFER_SIZE + 1] = 0;
		char *find;
		char *line2;
		line2 = *line;
		find = ft_strchr(memo, '\n');
		// printf("%d", ft_strchr(memo, '\n') - memo[0]);

		// printf("%s", find);

		if(find != 0 )
		{
			*find = 0;
			printf("~~~~~~~~~~~~~~~~~~~~~改行発見~~~~~~~~~~\n");
			printf("%s\n", save);
			printf("%s\n", memo);

			line2 = (char *)malloc((sizeof(char))*((ft_strlen(save)) + (ft_strlen(memo)) + 1));
			line2 = ft_strjoin(save,memo);
			// printf ("%s",ft_strjoin(save,memo));
			printf ("%s\n",line2);
			save = find + 1;
			printf("現時点でのsave");
			printf("%s\n", save);

		}

		else
		{
			printf("~~~~~~~~~~~~~~~~~~~~~改行なし~~~~~~~~~~\n");
			if (*save == 0)
				save = &memo[0];
			else
			{
				char *temp;
				temp = malloc(sizeof(char) * BUFFER_SIZE + 1);
				temp = memo;
				save = ft_strjoin(save,temp);
			}
			
			// printf ("%s\n",memo);
			printf ("変更後%s\n",save);

		}
		// printf ("%p",save);
		// for (int i = 0; i < BUFFER_SIZE ; i++)
		i++;
		printf("%d回目\n",i);
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		read_byte = read(fd,memo, BUFFER_SIZE);
		// printf("~~~~~~~~~~~~再読み込み~~~~~~~~~~~~~~~~~~~\n");




	}
	printf ("0\n");

	return (0);
}



// int get_next_line(int fd)
// {
// 	int flag;
// 	char *memo;
// 	int BUFFER_SIZE;
// 	int i;
// 	char *save;
// 	char *temp;
// 	char **line;
// 	BUFFER_SIZE = 4;
// 	line = 0;
// 	memo = malloc(sizeof(char) * BUFFER_SIZE + 1);
// 	// printf("~~~~~~~~~~~~~~~~~~~~~test1~~~~~~~~~~\n");
// 	flag = read(fd,&memo[0], BUFFER_SIZE);
// 	if (flag == -1)
// 		return (0);
// 	// if (flag == 1) //ファイルの終端にたどり着いた時
// 	if (flag > 0)
// 	{
// 		// printf("~~~~~~~~~~~test2~~~~~~~~~~~~~~~~~~~~~~~\n");
// 		flag = read(fd,&memo[0], BUFFER_SIZE);
// 		// flag = read(fd,&memo[0], BUFFER_SIZE);
// 		// flag = read(fd,&memo[0], BUFFER_SIZE);
// 		i = 0;
// 		while(i < BUFFER_SIZE)
// 		{
// 			// printf("~~~~~~~~~~~~~~~~~~~~~~test3~~~~~~~\n");

// 			if (check(memo[i]) != 0)
// 			{
// 			// printf("---------------test4----------------------\n");

// 				memo[i] = 0;//関数を使うために改行をヌルにする
// 				temp = malloc(sizeof(char) * ((ft_strlen)(save) + i + 1 ));
// 				temp = ft_strjoin(save , &memo[0]); 
// 				*line = temp;
// 				save = &memo[i + 1];//saveに残りの文字列の先頭ポインタを入れる
// 				// printf("%s\n",temp);
// 				return (0);
// 			}
// 			i++;

// 		}

// 	}
// 	return (0);


// }




int main()
{
// 変数定義
    int fd1;
    // char buf[BUF_SIZE];

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
	char **line;
	get_next_line(fd1, line);

   
    // ファイルを閉じる
    close(fd1);
    return 0;
}