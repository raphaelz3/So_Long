/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsnbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  rapgonca < rapgonca@student.42sp.org.b    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 15:06:31 by  rapgonca         #+#    #+#             */
/*   Updated: 2022/08/11 06:35:25 by  rapgonca        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_uns_numbers(unsigned int nb, int length, int fd)
{
	char	*numbers;
	int		count;

	count = 0;
	numbers = (char *) malloc((length + 1) * sizeof(char));
	if (!numbers)
		return ;
	numbers[length] = '\0';
	while (length--)
	{
		numbers[length] = nb % 10 + '0';
		nb = nb / 10;
	}
	ft_putstr_fd(numbers, fd);
	free(numbers);
}

int	ft_putunsnbr(unsigned int n, int fd)
{
	unsigned int	i;
	int				count;

	count = 0;
	i = n;
	if (n == 0)
	{
		ft_putchar_fd('0', fd);
		return (1);
	}
	else
	{
		while (i > 0)
		{
			i /= 10;
			count++;
		}
		ft_uns_numbers(n, count, fd);
	}
	return (count);
}
