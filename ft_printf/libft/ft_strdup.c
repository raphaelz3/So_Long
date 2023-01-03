/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  rapgonca < rapgonca@student.42sp.org.b    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 13:04:00 by  rapgonca         #+#    #+#             */
/*   Updated: 2022/06/16 19:28:57 by  rapgonca        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*scopy;
	int		len;
	int		count;

	count = 0;
	len = ft_strlen(s);
	scopy = malloc((len + 1) * sizeof(char));
	if (!scopy)
		return (NULL);
	while (*s)
	{
		scopy[count] = *s;
		s++;
		count++;
	}
	scopy[count] = '\0';
	return (scopy);
}
