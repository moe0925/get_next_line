/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moeota <moeota@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 22:58:35 by moeota            #+#    #+#             */
/*   Updated: 2023/02/19 04:42:10 by moeota           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static ssize_t	check(char *str)
{
	ssize_t	i;

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
	ssize_t		read_byte;
	char	*memo;

	memo = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
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
			return (free_malloc(memo, save));
		memo[read_byte] = '\0';
		save = ft_strjoin(save, memo);
		if (check(memo) != -1 || read_byte == 0)
			break ;
	}
	free(memo);
	return (save);
}

char	*read_memo(char *save)
{
	ssize_t		find;
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
	ssize_t		find;
	size_t		i;
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

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 256)
	{
		return (NULL);
	}
	save = make_memo(fd, save);
	if (!save)
		return (NULL);
	line = read_memo(save);
	save = make_save(save);
	return (line);
}

// char *get_next_line(int fd)
// {
//     static char *save[257];
//     char *line;

//     if (fd < 0 || BUFFER_SIZE <= 0 || fd > 256)
//     {
//         return (NULL);
//     }

//     save[fd] = make_memo(fd, save[fd]);
//     if (!save[fd])
//     {
//         return (NULL);

//     }
//     line = read_memo(save[fd]);
//     save[fd] = make_save(save[fd]);
//     return (line);
// }

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

