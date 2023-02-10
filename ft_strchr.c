/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moeota <moeota@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 22:35:35 by ootamoeakir       #+#    #+#             */
/*   Updated: 2022/11/23 17:06:02 by moeota           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*s2;

	while (c > 256)
		c = c % 256;
	s2 = (char *)s;
	i = 0;
	if (c == 0)
	{
		while (s2[i] != '\0')
			i++;
		return (&(s2[i]));
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

// int main(void)
// {
//     const char *p = strchr( "abcdef", '\0');
//     if ( p == NULL )
//     {
//         puts( "見つからない。" );
//     }
//     else
//     {
//         puts( p );
//     }

//     printf("-----------------\n");
//     const char *s = ft_strchr( "abcdef", '\0' );
//     int ans = ft_strchr( "abcdef", '\0' );
//     // if ( s == NULL )
//     // {
//     //     puts( "見つからない。" );
//     // }
//     // else
//     // {
//     //     puts(s);
//     // }
//     printf("%s\n",ans);
//     printf("-----------------\n");
// }