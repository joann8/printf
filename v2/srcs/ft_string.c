/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 19:18:21 by jacher            #+#    #+#             */
/*   Updated: 2020/12/08 19:07:18 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

static void		ft_string_left(char *s, char *tmp, unsigned int width,
								unsigned int length)
{
	unsigned int i;

	i = 0;
	while (s[i] && i < length)
	{
		tmp[i] = s[i];
		i++;
	}
	while (i < width)
	{
		tmp[i] = ' ';
		i++;
	}
	tmp[i] = '\0';
}

static void		ft_string_right(char *s, char *tmp, unsigned int width,
									unsigned int length)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	tmp[width] = '\0';
	while (length + i < width)
	{
		tmp[i] = ' ';
		i++;
	}	
	while (i + ft_strlen(s) < width)
	{
		tmp[i] = ' ';
		i++;
	}
	j = 0;
	while (s[j] && j < length)
	{
		tmp[i + j] = s[j];
		j++;
	}
}

int		ft_string(va_list args, int *res, flag_list *flags)
{
	char 			*s;
	char			*tmp;
	unsigned int	length;
	unsigned int	width;
	
	//print_flags(*flags);
	if (flags->b_flag_zero == 1)
		return ((*res = -1)); 
	s = va_arg(args, char *);
	if (s == NULL)
	{
		s = ft_strdup("(null)");
		if (flags->b_width == 0 && flags->b_star_width == 1)
			flags->b_precision = 0;
	}
	width = ft_strlen(s);
	if (flags->b_width == 1)
		width = flags->v_width;
	length = ft_strlen(s);
	if (flags->b_precision == 1)
	{
		length = flags->v_length;
		if (length > ft_strlen(s))
		{
			if (width < ft_strlen(s))
				width = ft_strlen(s);
		}
		if (length < ft_strlen(s))
			if (flags->b_width == 0)
				width = length;
				
	}
//	printf("\n*****width =%u | length = %d\n", width, length);
	if (!(tmp = malloc(sizeof(char) * (width + 1))))
		return ((*res = 1)); //erreur >> -1?
	if (flags->b_flag_minus == 1)
		ft_string_left(s, tmp, width, length);
	else
		ft_string_right(s, tmp, width, length);
	ft_putstr(tmp);
	*res = ft_strlen(tmp);
	free(tmp);
	return (1);
}
