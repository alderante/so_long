/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_conv_hex_maj.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpopolan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:23:13 by cpopolan          #+#    #+#             */
/*   Updated: 2022/12/15 12:36:49 by cpopolan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

//Scrive tutti gli esadecimali maiuscoli

static void	support(unsigned int n)
{
	if (n > 15)
		support(n / 16);
	write(1, &"0123456789ABCDEF"[n % 16], 1);
}

int	ft_print_conv_hex_maj(unsigned int n)
{
	unsigned int	t;
	long			l;

	t = n;
	l = 1;
	support(n);
	while (t >= 16)
	{
		t = t / 16;
		l++;
	}
	return (l);
}
