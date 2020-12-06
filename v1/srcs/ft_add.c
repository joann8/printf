/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_support.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 14:28:47 by jacher            #+#    #+#             */
/*   Updated: 2020/12/06 12:02:48 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"
#include <stdio.h>

void	ft_p(va_list args, char **res, flag_list *flags)
{
	void			*ptr;
	char			*tmp1;
	char			*tmp2;

	(void)flags;

	ptr = va_arg(args, void*);
	//ft_putnbr_fd(d, 1);
	tmp1 = ft_putadd(ptr);
	tmp2 = ft_strjoin_printf(*res, tmp1);
	free(*res);
	*res = ft_strdup(tmp2);
}
