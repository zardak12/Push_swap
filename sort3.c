/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaxime <dmaxime@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 10:51:52 by dmaxime           #+#    #+#             */
/*   Updated: 2020/07/17 18:46:01 by dmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		push_to_a_2(t_p **stack)
{
	while ((*stack)->ra)
	{
		(*stack)->ra--;
		c_r(&(*stack)->s_a, 1);
	}
	while ((*stack)->rb)
	{
		(*stack)->rb--;
		c_r(&(*stack)->s_b, 2);
	}
	while ((*stack)->rra)
	{
		(*stack)->rra--;
		c_rr(&(*stack)->s_a, 1);
	}
	while ((*stack)->rrb)
	{
		(*stack)->rrb--;
		c_rr(&(*stack)->s_b, 2);
	}
}

void		push_to_a(t_p *stack)
{
	while (stack->rr != 0 || stack->rrr != 0)
	{
		if (stack->rr != 0)
		{
			stack->rr--;
			c_rs(&stack->s_a, &stack->s_b, 1);
		}
		if (stack->rrr != 0)
		{
			stack->rrr--;
			c_rrs(&stack->s_a, &stack->s_b, 1);
		}
	}
	push_to_a_2(&stack);
}

void		find_move_b(t_p *stack)
{
	t_a *head;
	int i;

	i = stack->s_b->count.sum;
	if (stack->s_b != NULL)
	{
		head = stack->s_b;
		while (stack->s_b != NULL)
		{
			if (stack->s_b->count.sum < i && stack->s_b)
				i = stack->s_b->count.sum;
			stack->s_b = stack->s_b->next;
		}
		stack->s_b = head;
		start_find(stack);
		fill(stack, i);
	}
}

void		fill(t_p *stack, int i)
{
	t_a *head;

	head = stack->s_b;
	while (stack->s_b->count.sum != i)
		stack->s_b = stack->s_b->next;
	stack->rr = stack->s_b->count.rr;
	stack->rb = stack->s_b->count.rb;
	stack->ra = stack->s_b->count.ra;
	stack->rrb = stack->s_b->count.rrb;
	stack->rra = stack->s_b->count.rra;
	stack->rrr = stack->s_b->count.rrr;
	stack->s_b = head;
}

void		start_find(t_p *stack)
{
	stack->rr = 0;
	stack->rb = 0;
	stack->ra = 0;
	stack->rrb = 0;
	stack->rra = 0;
	stack->rrr = 0;
}
