/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moeota <moeota@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 22:58:35 by moeota            #+#    #+#             */
/*   Updated: 2023/02/13 19:35:34 by moeota           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	check(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*make_memo(int fd, char *save)
{
	int		read_byte;
	char	*memo;
	char	*tmp;

	memo = (char *)malloc(sizeof(char) * (BUFFER_SIZE +1));
	if (!memo)
		return (NULL);
	if (!save)
	{
		save = (char *)malloc(sizeof(char) * 1);
		if (!save)
			return (NULL);
		save[0] = '\0';
	}
	while (1)
	{
		read_byte = read(fd, memo, BUFFER_SIZE);
		if (read_byte < 0)
		{
			free(memo);
			free(save);
			return (NULL);
		}
		memo[read_byte] = '\0';
		tmp = ft_strjoin(save, memo);
		if (!tmp)
		{
			free(memo);
			free(save);
			return (NULL);
		}
		free(save);
		save = tmp;
		// printf("readbyte;%d",read_byte);
		// printf("check%d",check(memo));

		if (check(memo) != -1 || read_byte == 0)
		{
			// printf("hi");
			// printf("readbyte;%d",read_byte);
			// printf("check;%d",read_byte);
			break ;
		}
	}
	free(memo);
	return (save);
}

char	*read_memo(char *save)
{
	int		find;
	char	*line;

	if (!save[0])
		return (NULL);
	find = check(save);
	if (find == -1 && (save))
	{
		line = (char *)malloc(sizeof(char) * ft_strlen(save) + 1);
		if (!line)
			return (NULL);
		line = ft_strncpy(line, save, ft_strlen(save));
		return (line);
	}
	line = (char *)malloc(sizeof(char) * (find + 2));
	if (!line)
		return (NULL);
	line = ft_strncpy(line, save, (find + 1));
	return (line);
}

char	*make_save(char *save)
{
	int		find;
	int		i;
	char	*save_new;

	find = check(save);
	i = 0;
	if (find == -1)
	{
		free(save);
		return (NULL);
	}
	save_new = (char *)malloc(sizeof(char) * (ft_strlen(save) - (find + 1)));
	if (!save_new)
		return (NULL);
	while (save[find + i + 1] != '\0')
	{
		save_new[i] = save[find + i + 1];
		i++;
	}
	save_new[i] = '\0';
	free(save);
	return (save_new);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	save = make_memo(fd, save);
	if (!save)
		return (NULL);
	line = read_memo(save);
	save = make_save(save);
	return (line);
}

// #include <fcntl.h>

// int main(void)
// {
//     int  fd;
//     char *line;
//     int  check;

//     line = "";
//     fd = open("text.txt", O_RDONLY);
//     // fd =1000;
//     if (fd == -1)
// 	{
// 			printf("ファイルオープンエラー\n");
// 			return 0;
// 	}
//     check = 1;
//     while (line)
//     {
//     line = get_next_line(fd);
//     printf("> %s", line);
//     check++;
//     free(line);
//     }
//     // system("leaks a.out");
//     return (0);
// }
