/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaxime <dmaxime@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 10:26:55 by dmaxime           #+#    #+#             */
/*   Updated: 2020/07/17 19:39:47 by dmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_p		*validation(t_p *stack, int command)
{
	int *massiv;

	massiv = (int*)ft_memalloc((stack->count_a + 1) * sizeof(int));
	massiv = push_massiv(massiv, stack->s_a);
	if (check_on_order(stack->s_a) == 1 && command == 1)
		exit(0);
	find_repeats(massiv, stack->count_a);
	massiv = sorting(massiv, stack->count_a);
	stack->min = massiv[0];
	stack->max = massiv[stack->count_a - 1];
	stack->mediana = massiv[stack->count_a / 2];
	put_index(&stack->s_a, massiv);
	free(massiv);
	return (stack);
}

int		check_on_order(t_a *stack)
{
	t_a *head;

	head = stack;
	while (stack->next != NULL)
	{
		if (stack->f_a < stack->next->f_a)
			stack = stack->next;
		else
		{
			stack = head;
			return (0);
		}
	}
	stack = head;
	return (1);
}

void	err(char *msg)
{
	ft_printf("%s\n", msg);
	exit(1);
}

void	print_steck(t_a *stack)
{
	if (stack == NULL)
		ft_printf("%s\n", "FUCK");
	while (stack != NULL)
	{
		ft_printf("%d\n", stack->f_a);
		stack = stack->next;
	}
}

int		*sorting(int *massiv, int size)
{
	int i;
	int j;
	int t;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (massiv[i] > massiv[j])
			{
				t = massiv[i];
				massiv[i] = massiv[j];
				massiv[j] = t;
			}
			j++;
		}
		i++;
	}
	return (massiv);
}
