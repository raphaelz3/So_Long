/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  rapgonca < rapgonca@student.42sp.org.b    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 17:16:54 by  rapgonca         #+#    #+#             */
/*   Updated: 2022/06/25 16:02:30 by  rapgonca        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(int nb)
{
	int	len;

	len = 0;
	while (nb > 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

static char	*ft_putnumbersneg(int x, int nb, int len)
{
	char	*numbers;

	numbers = malloc((len + x) * sizeof(char));
	if (!numbers)
		return (NULL);
	numbers[len + 1] = '\0';
	while (nb > 0)
	{
		numbers[len--] = nb % 10 + '0';
		nb = nb / 10;
	}
	numbers[len] = '-';
	return (numbers);
}

static char	*ft_minornegative(int nb, int len)
{
	char	*numbers;

	numbers = malloc((len) * sizeof(char));
	if (!numbers)
		return (NULL);
	numbers[len - 1] = '\0';
	len -= 1;
	while (nb > 0)
	{
		numbers[--len] = nb % 10 + '0';
		nb = nb / 10;
	}
	numbers[--len] = '2';
	numbers[--len] = '-';
	return (numbers);
}

static char	*ft_putnumberspos(int x, int nb, int len)
{
	char	*numbers;

	if (nb == 0)
	{
		numbers = malloc(2 * sizeof(char));
		numbers[1] = '\0';
		numbers[0] = 48;
		return (numbers);
	}
	numbers = malloc((len + x) * sizeof(char));
	if (!numbers)
		return (NULL);
	numbers[len] = '\0';
	while (nb > 0)
	{
		numbers[len - 1] = nb % 10 + '0';
		len--;
		nb = nb / 10;
	}
	return (numbers);
}

char	*ft_itoa(int n)
{
	int	len;
	int	isnegative;

	isnegative = 1;
	if (n == -2147483648)
	{
		n = 147483648;
		return (ft_minornegative(n, 12));
	}
	else if (n < 0)
	{
		isnegative = 2;
		n = n * -1;
		len = ft_intlen(n);
		return (ft_putnumbersneg(isnegative, n, len));
	}
	else
	{
		len = ft_intlen(n);
		return (ft_putnumberspos(isnegative, n, len));
	}
}
