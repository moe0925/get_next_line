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
	p[i + j] = 0;
	// free(ss1);
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

size_t	ft_strlen(const char *s)
{
	int		i;
	char	*str2;

	i = 0;
	str2 = (char *)s;
	while (str2[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strcpy(char *dest, char *src);

char	*ft_strdup(const char *src)
{
	char	*p;
	char	*src2;

	src2 = (char *)src;
	p = malloc(ft_strlen(src2) + 1);
	if (!(p))
		return (NULL);
	if (p)
	{
		ft_strncpy (p, src2, ft_strlen(src2));
	}
	return (p);
}

char	*ft_strncpy(char *dst, char *src, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
