/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  rapgonca < rapgonca@student.42sp.org.b    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 16:04:41 by  rapgonca         #+#    #+#             */
/*   Updated: 2022/08/12 16:28:31 by  rapgonca        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*coverte_dectohx(unsigned int nb, int n, char *conv_hx, char c)
{
	unsigned int	div;
	unsigned int	res;
	char			*test;

	if (c == 'X')
		test = HEXAUPP;
	else
		test = HEXALOW;
	res = nb;
	while (n > 0)
	{
		div = nb / 16;
		res = nb % 16;
		conv_hx[n - 1] = test[res];
		nb = div;
		n--;
	}
	return (conv_hx);
}

int	ft_puthx(unsigned int nb, char c)
{
	char			*conv_hx;
	unsigned int	res;
	int				n;

	res = nb;
	n = 0;
	if (nb == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	while (res > 0)
	{
		res /= 16;
		n++;
	}
	conv_hx = (char *)malloc((n + 1) * sizeof(char));
	if (!conv_hx)
		return (0);
	conv_hx[n] = '\0';
	ft_putstr_fd(coverte_dectohx(nb, n, conv_hx, c), 1);
	free(conv_hx);
	conv_hx = NULL;
	return (n);
}
