/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moeota <moeota@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 22:58:35 by moeota            #+#    #+#             */
/*   Updated: 2023/02/13 19:56:09 by moeota           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char *free_malloc(char *str1,char *str2)
{
	free(str1);
	free(str2);
	return (NULL);
}

static char	*join1(char *ss1, char *ss2, char *p)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (ss1[i] != '\0')
	{
		p[i] = ss1[i];
		i++;
	}
	while (ss2[j] != '\0')
	{
		p[i + j] = ss2[j];
		j++;
	}
	p[i + j] = '\0';
	free(ss1);
	return (p);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ss1;
	char	*ss2;
	char	*p;

	ss1 = (char *)s1;
	ss2 = (char *)s2;
	if (!s1)
		return (NULL);
	p = malloc(sizeof(char) * (ft_strlen(ss1) + ft_strlen(ss2) + 1));
	if (!p)
		return (NULL);
	return (join1(ss1, ss2, p));
}

// char	*ft_strjoin(char const *s1, char const *s2)
// {
// 	char	*p;
// 	char	*head;
// 	char	*ss1;

// 	ss1 = (char *)s1;
// 	if (!s1 || !s2)
// 		return (NULL);
// 	p = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
// 	if (!p)
// 		return (NULL);
// 	head = p;
// 	while (*s1)
// 		*p++ = *s1++;
// 	while (*s2)
// 		*p++ = *s2++;
// 	*p = '\0';
// 	free(ss1);
// 	return (p);
// 	// return (join1(ss1, ss2, p));
// }



// char	*ft_strjoin(char const *s1, char const *s2)
// {
// 	char	*ss1;
// 	// char	*ss2;
// 	char	*p;
// 	size_t	i;
// 	size_t	j;

// 	ss1 = (char *)s1;
// 	i = 0;
// 	j = 0;
// 	ss1 = (char *)s1;
// 	// ss2 = (char *)s2;
// 	if (!s1 || !s2)
// 		return (NULL);
// 	p = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
// 	if (!p)
// 		return (NULL);
// 	while (!s1[i])
// 		p[i++] = s1[i++];
// 	while (!s2[j])
// 		p[j++] = s1[j++];
// 	p[i + j] = 0;
// 	free(ss1);
// 	return (p);
// 	// return (join1(ss1, ss2, p));
// }

size_t	ft_strlen(const char *s)
{
	size_t		i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

