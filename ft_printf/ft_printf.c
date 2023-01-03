/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  rapgonca < rapgonca@student.42sp.org.b    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 14:08:46 by  rapgonca         #+#    #+#             */
/*   Updated: 2022/08/12 16:29:40 by  rapgonca        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_nb(int n)
{
	int	i;

	i = 0;
	ft_putnbr_fd(n, 1);
	if (n <= 0)
	{
		if (n == -2147483648)
		{
			n += 1;
		}
		n = n * -1;
		i++;
	}
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static int	print_str(char *str)
{
	int	i;

	if (str == NULL)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	i = ft_strlen(str);
	if (!i)
		ft_putstr_fd("", 1);
	else
		ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

static int	print_set_a(va_list args, char str)
{
	char	*c;

	if (str == 'c')
	{
		ft_putchar_fd(va_arg(args, int), 1);
		return (1);
	}
	else if (str == 's')
	{
		c = va_arg (args, char *);
		return (print_str(c));
	}
	else if (str == 'd' || str == 'i')
		return (print_nb(va_arg (args, int)));
	else if (str == '%')
	{
		write(1, "%%", 1);
		return (1);
	}
	return (0);
}

static int	print_set_b(va_list args, char str)
{
	unsigned long	p;
	unsigned int	u;

	if (str == 'p')
	{
		p = va_arg (args, unsigned long);
		if (p == 0)
		{
			ft_putstr_fd("(nil)", 1);
			return (5);
		}
		ft_putstr_fd("0x", 1);
		return (ft_putp(p) + 2);
	}
	else if (str == 'x' || str == 'X')
	{
		u = va_arg (args, unsigned int);
		return (ft_puthx(u, str));
	}
	else if (str == 'u')
	{
		u = va_arg (args, unsigned int);
		return (ft_putunsnbr(u, 1));
	}
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;

	i = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			i += print_set_a(args, *str);
			i += print_set_b(args, *str);
		}
		else
		{
			ft_putchar_fd(*str, 1);
			i++;
		}
		str++;
	}
	va_end(args);
	return (i);
}
