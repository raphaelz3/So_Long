/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  rapgonca < rapgonca@student.42sp.org.b    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 16:58:18 by  rapgonca         #+#    #+#             */
/*   Updated: 2022/06/26 03:36:48 by  rapgonca        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_revprint(int size, char *numbers, int fd)
{
	char	alpha;

	while (size > 0)
	{
		alpha = numbers[size - 1];
		ft_putchar_fd(alpha, fd);
		size--;
	}
}

static void	ft_putnumbers(int nb, int fd)
{
	char	numbers[10];
	int		count;
	int		size;

	size = 0;
	count = 0;
	while (nb > 0)
	{
		numbers[count] = nb % 10 + '0';
		count++;
		size++;
		nb = nb / 10;
	}
	if (count <= 10)
	{
		while (count != 10)
		{
			numbers[count] = '\0';
			count++;
		}
	}
	ft_revprint(size, numbers, fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write (fd, "-2", 2);
		n = 147483648;
	}
	if (n < 0)
	{
		write (fd, "-", 1);
		n = n * -1;
	}
	if (n == 0)
		ft_putchar_fd('0', fd);
	ft_putnumbers(n, fd);
}
