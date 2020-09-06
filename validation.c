/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaxime <dmaxime@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 11:08:40 by dmaxime           #+#    #+#             */
/*   Updated: 2020/07/17 14:15:36 by dmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_validation_int(const char *str)
{
	int			sign;
	long double	num;
	int			i;

	if (ft_strlen(str) == 0)
		return (0);
	i = 0;
	num = 0;
	sign = 1;
	if (str[i] == '-')
	{
		i++;
		sign = -sign;
	}
	while (str[i] >= '0' && str[i] <= '9' && str[i])
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	if (str[i] != '\0')
		err("Error");
	if ((num > INT_MAX) || (num < INT_MIN))
		err("Error");
	return (sign * num);
}

t_a		*create_first_stack(t_a **stack_a, char *b)
{
	if (!((*stack_a) = (t_a*)malloc(sizeof(t_a))))
		return (NULL);
	(*stack_a)->f_a = ft_validation_int(b);
	(*stack_a)->next = NULL;
	return (*stack_a);
}

t_a		*create_stack(t_a **stack_a, char *b)
{
	t_a		*head;
	t_a		*tmp;

	head = *stack_a;
	while ((*stack_a)->next != NULL)
		*stack_a = (*stack_a)->next;
	if (!(tmp = (t_a*)malloc(sizeof(t_a))))
		return (NULL);
	tmp->next = NULL;
	(*stack_a)->next = tmp;
	*stack_a = (*stack_a)->next;
	(*stack_a)->f_a = ft_validation_int(b);
	(*stack_a)->next = NULL;
	(*stack_a) = head;
	return (head);
}

t_p		*validator(int a, char **b, int command)
{
	t_p *new;
	int i;

	i = 1;
	if (a < 2)
		return (NULL);
	if (!(new = (t_p*)ft_memalloc(sizeof(t_p))))
		return (NULL);
	create_first_stack(&new->s_a, b[i]);
	i++;
	while (b[i])
	{
		create_stack(&new->s_a, b[i]);
		i++;
	}
	new->count_a = i - 1;
	validation(new, command);
	return (new);
}
