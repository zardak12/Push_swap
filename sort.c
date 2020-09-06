/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaxime <dmaxime@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 10:51:52 by dmaxime           #+#    #+#             */
/*   Updated: 2020/07/28 13:24:19 by dmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_stack_three(t_a **stack)
{
	if ((*stack)->f_a > (*stack)->next->f_a &&
	(*stack)->f_a < (*stack)->next->next->f_a)
		c_s(stack, 1);
	else if ((*stack)->f_a > (*stack)->next->f_a &&
	(*stack)->f_a > (*stack)->next->next->f_a &&
	(*stack)->next->f_a < (*stack)->next->next->f_a)
		c_r(stack, 1);
	else if ((*stack)->f_a > (*stack)->next->f_a &&
	(*stack)->f_a > (*stack)->next->next->f_a &&
	(*stack)->next->f_a > (*stack)->next->next->f_a)
	{
		c_s(stack, 1);
		c_rr(stack, 1);
	}
	else if ((*stack)->f_a < (*stack)->next->f_a &&
	(*stack)->f_a < (*stack)->next->next->f_a &&
	(*stack)->next->f_a > (*stack)->next->next->f_a)
	{
		c_s(stack, 1);
		c_r(stack, 1);
	}
	else if ((*stack)->f_a < (*stack)->next->f_a &&
	(*stack)->f_a > (*stack)->next->next->f_a &&
	(*stack)->next->f_a > (*stack)->next->next->f_a)
		c_rr(stack, 1);
}

void		ft_stack_five(t_p *stack)
{
	int i;

	i = 2;
	while (i)
	{
		if (stack->s_a->f_a == stack->max || stack->s_a->f_a == stack->min)
		{
			i--;
			p_a_b(&stack->s_a, &stack->s_b, 1);
		}
		else
			c_r(&stack->s_a, 1);
	}
	ft_stack_three(&stack->s_a);
	if (stack->s_b->f_a == stack->min)
		c_s(&stack->s_b, 2);
	p_a_b(&stack->s_b, &stack->s_a, 2);
	c_r(&stack->s_a, 1);
	p_a_b(&stack->s_b, &stack->s_a, 2);
}

void		sort(t_p *stack)
{
	push_to_b(stack);
	if (stack->s_a->f_a == stack->min)
		c_s(&stack->s_a, 1);
	p_a_b(&stack->s_b, &stack->s_a, 2);
	while (stack->s_b)
	{
		check_b(stack);
		find_summa(stack->s_b);
		find_move_b(stack);
		push_to_a(stack);
		p_a_b(&stack->s_b, &stack->s_a, 2);
	}
	while (stack->s_a->f_a != stack->min)
	{
		c_r(&stack->s_a, 1);
	}
}

void		push_to_b2(t_p **stack, int b)
{
	int i;

	i = (*stack)->count_a - b;
	while (i > 2)
	{
		if ((*stack)->s_a->f_a == (*stack)->max
		|| (*stack)->s_a->f_a == (*stack)->min)
			c_r(&(*stack)->s_a, 1);
		else
		{
			p_a_b(&(*stack)->s_a, &(*stack)->s_b, 1);
			i--;
		}
	}
}

void		push_to_b(t_p *stack)
{
	int i;
	int b;

	i = stack->count_a / 2;
	b = 0;
	while (i - 1)
	{
		if (stack->s_a->f_a == stack->max)
			c_r(&stack->s_a, 1);
		if (stack->s_a->f_a >= stack->mediana)
		{
			p_a_b(&stack->s_a, &stack->s_b, 1);
			i--;
			b++;
		}
		else
			c_r(&stack->s_a, 1);
	}
	push_to_b2(&stack, b);
}
