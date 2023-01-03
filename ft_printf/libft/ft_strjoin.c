/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  rapgonca < rapgonca@student.42sp.org.b    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 15:07:39 by  rapgonca         #+#    #+#             */
/*   Updated: 2022/08/11 07:06:22 by  rapgonca        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	int		lens1;
	int		lens2;
	int		count;

	count = 0;
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	dst = malloc((lens1 + lens2 + 1) * sizeof(char));
	if (!dst)
		return (NULL);
	while (lens1)
	{
		dst[count] = s1[count];
		count++;
		lens1--;
	}
	while (lens2)
	{
		dst[count++] = s2[lens1++];
		lens2--;
	}
	dst[count] = '\0';
	return (dst);
}
