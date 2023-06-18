/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpopolan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 10:54:36 by cpopolan          #+#    #+#             */
/*   Updated: 2022/12/15 16:10:24 by cpopolan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

int	ft_printf(const char *stringa, ...);
int	ft_print_conv_chr(int c);
int	ft_print_conv_str(char *str);
int	ft_print_conv_nbr(int n);
int	ft_print_conv_hex_min(unsigned int n);
int	ft_print_conv_hex_maj(unsigned int n);
int	ft_print_conv_ptr(long unsigned int n);
int	ft_print_conv_uns(unsigned int n);
#endif
