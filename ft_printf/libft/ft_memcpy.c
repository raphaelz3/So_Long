/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  rapgonca < rapgonca@student.42sp.org.b    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 17:33:49 by  rapgonca         #+#    #+#             */
/*   Updated: 2022/06/25 16:27:52 by  rapgonca        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*dstc;
	char	*srccpy;

	if ((dest == src) || n == 0)
		return (dest);
	if (!dest && !src)
		return (0);
	dstc = (char *)dest;
	srccpy = (char *)src;
	while (n--)
		dstc[n] = srccpy[n];
	return (dest);
}
