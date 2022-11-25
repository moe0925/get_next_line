/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moeota <moeota@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 22:58:35 by moeota            #+#    #+#             */
/*   Updated: 2022/11/25 12:32:06 by moeota           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*s2;

	s2 = (char *)s;
	i = 0;
	if (c == 0)
	{
		while (s2[i] != '\0')
		{
			i++;
		}
		return (&s2[i]);
	}
	while (s2[i] != '\0')
	{
		if (s2[i] == (char)c)
			return (&s2[i]);
		else
			i++;
	}
	return (NULL);
}


void	*ft_calloc(size_t count, size_t size)
{
	void	*p;

	if (size != 0 && count > SIZE_MAX / size)
		return (NULL);
	p = malloc(count * size);
	if (!p)
		return (NULL);
	ft_bzero(p, count * size);
	return (p);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*str;
	size_t			i;

	str = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
	return ;
}

static char	*ft_strcpy(char *dest, char *src);

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
		ft_strcpy (p, src2);
	}
	return (p);
}

static char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{	
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
