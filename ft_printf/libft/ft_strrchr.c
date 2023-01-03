/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  rapgonca < rapgonca@student.42sp.org.b    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 16:38:24 by  rapgonca         #+#    #+#             */
/*   Updated: 2022/06/25 16:38:28 by  rapgonca        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*scopy;
	int		len;

	len = ft_strlen(s);
	scopy = NULL;
	while (s[len] != c && len >= 1)
	{
		if (s[len] == (unsigned char) c)
			scopy = (char *)s + len;
		len--;
	}
	if (s[len] == (char) c)
		scopy = (char *)s + len;
	return (scopy);
}
