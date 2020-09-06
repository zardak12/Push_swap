/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaxime <dmaxime@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 11:32:24 by dmaxime           #+#    #+#             */
/*   Updated: 2020/07/17 11:33:29 by dmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_p		*checker;
	char	*line;
	int		c;

	if (ac > 2)
	{
		checker = validator(ac, av, 0);
		while ((c = get_next_line(0, &line)) > 0)
		{
			exec_command(checker, line);
			free(line);
		}
		if (check_is_sorted(checker) == 1 && checker->s_b == NULL)
			ft_printf("%s\n", "OK");
		else
			err("KO");
		free_stack(checker);
	}
	else
		check_err(av);
	return (0);
}
