/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 19:17:13 by jacher            #+#    #+#             */
/*   Updated: 2020/12/08 12:40:40 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

unsigned int	ft_atoi_printf(const char *str, unsigned int *pos, flag_list *flags)
{
	unsigned int		i;
	unsigned int		res;

	i = 0;
	res = 0;
	while (str[i] == '-')
	{
		flags->b_flag_minus = 1; 
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - 48;
		i++;
	}
	*pos = *pos + i;
	return (res);
}
