/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  rapgonca < rapgonca@student.42sp.org.b    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 16:21:03 by  rapgonca         #+#    #+#             */
/*   Updated: 2022/07/10 21:22:53 by  rapgonca        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_repeatedchr(char *s, char c)
{
	int	res;

	res = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s != c && *s != '\0')
		{
			res++;
			while (*s != c && *s != '\0')
				s++;
		}
		if (!*s)
			return (res);
		else
			s++;
	}
	return (res);
}

static char	**ft_strsize(char **dst, char *s, char c)
{
	int	res;
	int	i;

	i = 0;
	while (*s)
	{
		res = 0;
		while (*s == c)
		{
			s++;
		}
		while (*s != c && *s != '\0')
		{
			res++;
			s++;
		}
		if (res > 0)
		{
			dst[i] = malloc((res + 1) * sizeof(char));
			i++;
		}
		if (*s != '\0')
			s++;
	}
	return (dst);
}

static char	**ft_cpy(char **cpy, char *s, char c)
{
	int	line;
	int	collun;

	line = 0;
	while (*s)
	{
		collun = 0;
		while (*s == c)
			s++;
		if (*s && *s != c)
		{
			while (*s != c && *s != '\0')
			{
				cpy[line][collun] = *s;
				collun++;
				s++;
			}
			cpy[line][collun] = '\0';
			line++;
		}
		if (*s)
			s++;
	}
	return (cpy);
}

char	**ft_split(char const *s, char c)
{
	char	**dst;
	int		len;

	len = ft_repeatedchr((char *)s, c);
	dst = malloc((len + 1) * sizeof(char *));
	if (!dst)
		return (0);
	dst[len] = 0;
	if (ft_cpy(ft_strsize(dst, (char *)s, c), (char *)s, c) != 0)
		return (dst);
	else
	{
		free(dst);
		return (0);
	}
}
