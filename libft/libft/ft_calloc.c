/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpopolan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 15:57:02 by cpopolan          #+#    #+#             */
/*   Updated: 2022/10/18 11:57:07 by cpopolan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	tot_size;
	void	*dst;

	tot_size = (size * count);
	dst = malloc(tot_size);
	if (!(dst))
		return (0);
	ft_memset(dst, 0, tot_size);
	return (dst);
}
