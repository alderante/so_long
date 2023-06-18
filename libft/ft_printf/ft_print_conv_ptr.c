/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_conv_ptr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpopolan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:23:13 by cpopolan          #+#    #+#             */
/*   Updated: 2022/12/15 12:41:03 by cpopolan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

//Scrive tutti gli esadecimali preceduti da un "0x"

static void	support(long unsigned int n)
{
	if (n > 15)
		support(n / 16);
	write(1, &"0123456789abcdef"[n % 16], 1);
}

int	ft_print_conv_ptr(long unsigned int n)
{
	long unsigned int	t;
	int					l;

	t = n;
	l = 3;
	if (!n)
	{
		write(1, "(nil)", 5);
		l = 5;
	}
	else
	{
		write(1, "0x", 2);
		support(n);
		while (t >= 16)
		{
			t = t / 16;
			l++;
		}
	}
	return (l);
}
