/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpopolan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 16:45:47 by cpopolan          #+#    #+#             */
/*   Updated: 2022/10/16 15:56:25 by cpopolan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*begin;

	if (new != NULL)
	{
		begin = *lst;
		if (begin == NULL)
			*lst = new;
		else
		{
			while (begin->next != NULL)
				begin = begin->next;
			begin->next = new;
		}
	}
}
