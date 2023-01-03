/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  rapgonca < rapgonca@student.42sp.org.b    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 16:01:25 by  rapgonca         #+#    #+#             */
/*   Updated: 2022/08/12 16:34:14 by  rapgonca        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*coverte_p(unsigned long nb, int n, char *conv_hx)
{
	unsigned long	div;
	unsigned long	res;

	res = 0;
	while (n > 0)
	{
		div = nb / 16;
		res = nb % 16;
		conv_hx[n - 1] = HEXALOW[res];
		nb = div;
		n--;
	}
	return (conv_hx);
}

int	ft_putp(unsigned long nb)
{
	char			*conv_hx;
	unsigned long	res;
	int				n;

	res = nb;
	n = 0;
	while (res > 0)
	{
		res /= 16;
		n++;
	}
	conv_hx = (char *)malloc((n + 1) * sizeof(char));
	if (!conv_hx)
		return (0);
	conv_hx[n] = '\0';
	ft_putstr_fd(coverte_p(nb, n, conv_hx), 1);
	free(conv_hx);
	return (n);
}
