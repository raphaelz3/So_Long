/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  rapgonca < rapgonca@student.42sp.org.b    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 22:22:59 by  rapgonca         #+#    #+#             */
/*   Updated: 2022/06/21 15:05:29 by  rapgonca        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*memalloc;

	if (nmemb > 2147483647 || size > 2147483647)
		return (NULL);
	memalloc = (void *)malloc(nmemb * size);
	if (!memalloc)
		return (NULL);
	ft_bzero(memalloc, nmemb * size);
	return (memalloc);
}
