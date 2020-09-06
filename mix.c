/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mix.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaxime <dmaxime@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 10:42:48 by dmaxime           #+#    #+#             */
/*   Updated: 2020/07/22 18:15:01 by kosgrey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		c_s(t_a **stack, int index)
{
	int tmp;

	if (*stack != NULL && (*stack)->next != NULL)
	{
		tmp = (*stack)->f_a;
		(*stack)->f_a = (*stack)->next->f_a;
		(*stack)->next->f_a = tmp;
		if (index == 1)
			ft_printf("%s\n", "sa");
		else if (index == 2)
			ft_printf("%s\n", "sb");
	}
	else
	{
		err("Ошибка");
	}
}

void		c_ss(t_a **stack_a, t_a **stack_b, int index)
{
	c_s(stack_a, 0);
	c_s(stack_b, 0);
	if (index == 1)
		ft_printf("%s\n", "ss");
}

void		c_r(t_a **stack, int index)
{
	t_a	*head;

	if (*stack && (*stack)->next)
	{
		head = (*stack);
		while (head->next)
			head = head->next;
		head->next = *stack;
		*stack = (*stack)->next;
		head = head->next;
		head->next = NULL;
		if (index == 1)
			ft_printf("%s\n", "ra");
		else if (index == 2)
			ft_printf("%s\n", "rb");
	}
}

void		c_rs(t_a **stack_a, t_a **stack_b, int index)
{
	c_r(stack_a, 0);
	c_r(stack_b, 0);
	if (index == 1)
		ft_printf("%s\n", "rr");
}

void		c_rr(t_a **stack, int index)
{
	t_a *head;
	t_a *new;

	if (*stack && (*stack)->next)
	{
		head = *stack;
		while (head->next)
		{
			new = head;
			head = head->next;
		}
		new->next = NULL;
		head->next = *stack;
		*stack = head;
	}
	if (index == 1)
		ft_printf("%s\n", "rra");
	else if (index == 2)
		ft_printf("%s\n", "rrb");
}
