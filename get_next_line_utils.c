/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  rapgonca < rapgonca@student.42sp.org.b    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 16:05:57 by  rapgonca         #+#    #+#             */
/*   Updated: 2022/10/04 20:28:35 by  rapgonca        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	count;

	count = 0;
	if (!s)
		return (0);
	while (s[count])
		count++;
	return (count);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (0);
	while (*s != (unsigned char)c && *s != '\0')
	{
		s++;
	}
	if (*s == '\0' && *s != (unsigned char)c)
		return (NULL);
	else
		return ((char *)s);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	size_t	i;
	char	*dst;

	i = -1;
	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	dst = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!dst)
		return (NULL);
	while (s1[++i] != '\0' )
		dst[i] = s1[i];
	while (s2[i - ft_strlen(s1)] != '\0')
	{
		dst[i] = *(s2 + (i - ft_strlen(s1)));
		i++;
	}
	dst[i] = '\0';
	free(s1);
	return (dst);
}
