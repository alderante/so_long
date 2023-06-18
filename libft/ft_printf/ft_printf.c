/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpopolan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 10:13:30 by cpopolan          #+#    #+#             */
/*   Updated: 2022/12/15 13:05:45 by cpopolan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

//La conv mi converte nel giusto tipo cio' che
//trova a seconda del carattere che segue il %

static int	conv(va_list list, int n)
{
	int	print_conv;

	print_conv = 0;
	if (n == 'c')
		print_conv = ft_print_conv_chr(va_arg(list, int));
	else if (n == 's')
		print_conv = ft_print_conv_str(va_arg(list, char *));
	else if (n == 'd' || n == 'i')
		print_conv = ft_print_conv_nbr(va_arg(list, int));
	else if (n == 'x')
		print_conv = ft_print_conv_hex_min(va_arg(list, unsigned int));
	else if (n == 'X')
		print_conv = ft_print_conv_hex_maj(va_arg(list, unsigned int));
	else if (n == 'p')
		print_conv = ft_print_conv_ptr(va_arg(list, long unsigned int));
	else if (n == 'u')
		print_conv = ft_print_conv_uns(va_arg(list, unsigned int));
	else if (n == '%')
	{
		write(1, "%", 1);
		print_conv = 1;
	}
	return (print_conv);
}

//La ft_printf, usando le variadiche, va a leggere il contenuto
//di tutto cio' che le viene dato come input

int	ft_printf(const char *stringa, ...)
{
	va_list	list;
	int		i;
	int		printer;

	i = 0;
	printer = 0;
	va_start(list, stringa);
	while (stringa[i] != 0)
	{
		if (stringa[i] == '%')
		{
			printer += conv(list, stringa[i + 1]);
			i++;
		}
		else
		{
			printer += write (1, &stringa[i], 1);
		}
		i++;
	}
	va_end(list);
	return (printer);
}
