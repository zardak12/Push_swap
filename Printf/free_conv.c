/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_conv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosgrey <kosgrey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 19:28:28 by dmaxime           #+#    #+#             */
/*   Updated: 2020/01/28 15:11:34 by kosgrey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	free_conv(t_conversion *conv)
{
	free(conv->flag);
	free(conv->modif);
	free(conv);
}