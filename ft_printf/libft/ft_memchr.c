/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  rapgonca < rapgonca@student.42sp.org.b    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 16:12:56 by  rapgonca         #+#    #+#             */
/*   Updated: 2022/06/25 15:31:20 by  rapgonca        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	count;
	int		i;

	count = 0;
	i = 0;
	if (n == 0)
		return (0);
	while (count < n)
	{
		if (*(char *)(s + i) == (char)c)
			return ((void *)(s + i));
		i++;
		count++;
	}
	return (0);
}
