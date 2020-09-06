/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mix2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaxime <dmaxime@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 10:42:48 by dmaxime           #+#    #+#             */
/*   Updated: 2020/07/22 18:15:22 by kosgrey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		c_rrs(t_a **stack_a, t_a **stack_b, int index)
{
	c_rr(stack_a, 0);
	c_rr(stack_b, 0);
	if (index == 1)
		ft_printf("%s\n", "rrr");
}

void		p_a_b(t_a **take, t_a **put, int index)
{
	t_a *tmp;

	if (*take)
	{
		tmp = *take;
		*take = (*take)->next;
		tmp->next = *put;
		*put = tmp;
	}
	if (index == 1)
		ft_printf("%s\n", "pb");
	if (index == 2)
		ft_printf("%s\n", "pa");
}
