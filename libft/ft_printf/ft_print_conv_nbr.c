/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_conv_nbr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpopolan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 12:34:41 by cpopolan          #+#    #+#             */
/*   Updated: 2022/12/15 12:38:14 by cpopolan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	converter(int n)
{
	if (n == -2147483648)
	{	
		write(1, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n > 9)
		converter(n / 10);
	write(1, &"0123456789"[n % 10], 1);
}

int	ft_print_conv_nbr(int n)
{
	long			t;
	unsigned int	l;

	t = n;
	l = 1;
	converter(n);
	if (n < 0)
	{
		t = -t;
		l++;
	}
	while (t >= 10)
	{
		t = t / 10;
		l++;
	}
	return (l);
}
