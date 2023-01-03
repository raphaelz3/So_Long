/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  rapgonca < rapgonca@student.42sp.org.b    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 13:43:56 by  rapgonca         #+#    #+#             */
/*   Updated: 2022/06/25 01:11:47 by  rapgonca        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dst;
	size_t	ssize;
	size_t	count;

	count = 0;
	ssize = ft_strlen(s);
	if (len > ssize)
		len = ssize;
	if (start > ssize)
		len = 0;
	if (len >= ssize && start >= 1)
		len = ssize - start;
	dst = malloc((len + 1) * sizeof (char));
	if (!dst)
		return (NULL);
	while (len && start < ssize)
	{
		dst[count++] = s[start++];
		len--;
	}
	dst[count] = '\0';
	return (dst);
}
