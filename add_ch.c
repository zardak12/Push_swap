/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_ch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaxime <dmaxime@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 10:17:03 by dmaxime           #+#    #+#             */
/*   Updated: 2020/07/17 10:22:23 by dmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exec_command(t_p *stack, char *command)
{
	if (ft_strequ(command, "sa"))
		c_s(&stack->s_a, 0);
	else if (ft_strequ(command, "sb"))
		c_s(&stack->s_b, 0);
	else if (ft_strequ(command, "ss"))
		c_ss(&stack->s_a, &stack->s_b, 0);
	else if (ft_strequ(command, "ra"))
		c_r(&stack->s_a, 0);
	else if (ft_strequ(command, "rb"))
		c_r(&stack->s_b, 0);
	else if (ft_strequ(command, "rr"))
		c_rs(&stack->s_a, &stack->s_b, 0);
	else if (ft_strequ(command, "rra"))
		c_rr(&stack->s_a, 0);
	else if (ft_strequ(command, "rrb"))
		c_rr(&stack->s_b, 0);
	else if (ft_strequ(command, "rrr"))
		c_rrs(&stack->s_a, &stack->s_b, 0);
	else if (ft_strequ(command, "pb"))
		p_a_b(&stack->s_a, &stack->s_b, 0);
	else if (ft_strequ(command, "pa"))
		p_a_b(&stack->s_b, &stack->s_a, 0);
	else
		err("Error");
}

int		check_is_sorted(t_p *checker)
{
	t_a *head;

	head = checker->s_a;
	while (checker->s_a->next != NULL)
	{
		if (checker->s_a->f_a < checker->s_a->next->f_a)
			checker->s_a = checker->s_a->next;
		else
			return (-1);
	}
	checker->s_a = head;
	return (1);
}
