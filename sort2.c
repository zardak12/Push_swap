/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaxime <dmaxime@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 10:51:52 by dmaxime           #+#    #+#             */
/*   Updated: 2020/07/17 18:42:13 by dmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		find_summa(t_a *stack)
{
	t_a *head;

	head = stack;
	while (stack)
	{
		while (stack->count.rb && stack->count.ra)
		{
			stack->count.rb--;
			stack->count.ra--;
			stack->count.rr++;
		}
		while (stack->count.rrb && stack->count.rra)
		{
			stack->count.rrb--;
			stack->count.rra--;
			stack->count.rrr++;
		}
		stack->count.sum = stack->count.rb + stack->count.ra +
		stack->count.rrb + stack->count.rra +
		stack->count.rrr + stack->count.rr;
		stack = stack->next;
	}
	stack = head;
}

void		check_b(t_p *stack)
{
	t_a *head;
	int mediana;
	int i;

	i = 1;
	head = stack->s_b;
	stack->count_b = find_count(stack->s_b);
	mediana = stack->count_b / 2;
	find_all_position(stack->s_b);
	while (stack->s_b != NULL)
	{
		count_start(stack->s_b);
		if (stack->s_b->position < mediana || stack->count_b <= 3)
			stack->s_b->count.rb = stack->s_b->position;
		else
		{
			stack->s_b->count.rrb = stack->count_b - stack->s_b->position;
			i++;
		}
		preparation(stack, stack->s_b->f_a);
		stack->s_b = stack->s_b->next;
	}
	stack->s_b = head;
}

void		preparation(t_p *stack, int figure)
{
	int position;
	int mediana;
	t_a *head;

	head = stack->s_a;
	stack->count_a = find_count(stack->s_a);
	find_all_position(stack->s_a);
	mediana = stack->count_a / 2;
	position = find_need_value(stack, figure);
	while (stack->s_a->f_a != position)
		stack->s_a = stack->s_a->next;
	if (stack->s_a->position <= mediana)
		stack->s_b->count.ra = stack->s_a->position;
	else
	{
		stack->s_b->count.rra = stack->count_a - stack->s_a->position;
	}
	stack->s_a = head;
}

void		count_start(t_a *stack)
{
	stack->count.ra = 0;
	stack->count.rb = 0;
	stack->count.rr = 0;
	stack->count.rra = 0;
	stack->count.rrb = 0;
	stack->count.rrr = 0;
	stack->count.sum = 0;
}
