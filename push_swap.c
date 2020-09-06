/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaxime <dmaxime@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 10:47:12 by dmaxime           #+#    #+#             */
/*   Updated: 2020/07/17 10:48:46 by dmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_p *stack;

	if (ac > 2)
	{
		stack = validator(ac, av, 1);
		if (stack->count_a == 3)
			ft_stack_three(&stack->s_a);
		else if (stack->count_a == 5)
			ft_stack_five(stack);
		else
			sort(stack);
		free_stack(stack);
	}
	else
		check_err(av);
	return (0);
}
