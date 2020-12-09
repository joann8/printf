/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_others.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 16:36:09 by jacher            #+#    #+#             */
/*   Updated: 2020/12/06 17:24:07 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

int	count_arg(char *str)
{
	unsigned int i;
	unsigned int count;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1]) // cas ou %%?
			count++;
		i++;
	}
	return (count);
}

void	print_struct(arg_list *list)
{
	unsigned int i;

	i = 0;
	while (list[i].c_init)
	{
		printf("i = %d || struct.car = %c\n", i, list[i].c_init);
		i++;
	}
}

void	print_flags(flag_list flags)
{
	printf("flag zero = %d\n", flags.b_flag_zero); 
	printf("flag minus = %d\n", flags.b_flag_minus);
	printf("flag star width = %d\n", flags.b_star_width);
	printf("value witdh = %u\n", flags.v_width);
	printf("flag precision = %d\n", flags.b_precision);
	printf("flag star length = %d\n", flags.b_star_length);
	printf("value length = %u\n", flags.v_length);
}

//not working as is
void	free_struct(arg_list *list)
{
	unsigned int i;

	i = 0;
	while (list[i].c_init)
	{
		free(&list[i].c_init);
		//free(list[i].f);
		i++;
	}
}
