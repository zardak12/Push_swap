/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaxime <dmaxime@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 10:26:55 by dmaxime           #+#    #+#             */
/*   Updated: 2020/07/17 18:36:56 by dmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		*push_massiv(int *massiv, t_a *stack)
{
	t_a *head;
	int i;

	i = 0;
	head = stack;
	while (stack != NULL)
	{
		massiv[i] = stack->f_a;
		stack = stack->next;
		i++;
	}
	stack = head;
	return (massiv);
}

void	put_index(t_a **stack, int *massiv)
{
	int i;
	t_a *head;

	i = 0;
	head = *stack;
	while (massiv[i])
	{
		*stack = head;
		while ((*stack)->f_a != massiv[i] && stack != NULL)
		{
			(*stack) = (*stack)->next;
		}
		(*stack)->index = i + 1;
		i++;
	}
	*stack = head;
}

void	free_stack(t_p *stack)
{
	t_a *head_a;
	t_a *delete_a;
	t_a *head_b;
	t_a *delete_b;

	head_a = stack->s_a;
	head_b = stack->s_b;
	while (head_a != NULL)
	{
		delete_a = head_a;
		head_a = head_a->next;
		free(delete_a);
	}
	while (head_b != NULL)
	{
		delete_b = head_b;
		head_b = head_b->next;
		free(delete_b);
	}
	free(stack);
}

void	check_err(char **av)
{
	int i;

	i = 0;
	if (av[1] == NULL)
		exit(0);
	while (av[1][i])
	{
		if (ft_isdigit(av[1][i]) == 0)
			err("Error");
		i++;
	}
	if (ft_validation_int(av[1]))
		exit(0);
}
