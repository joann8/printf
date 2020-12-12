/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 16:36:09 by jacher            #+#    #+#             */
/*   Updated: 2020/12/10 15:54:53 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pf.h"

char	*str_analysis_help(t_flag *flags, unsigned int *i,
							char **str, va_list args)
{
	unsigned int	j;
	unsigned int	plus;
	char			*tmp;

	j = *i;
	plus = 0;
	while ((*str)[j] != '%' && (*str)[j])
		j++;
	if ((*str)[j])
		if (flag_parsing(flags, *str + j + 1, &plus, args) == 0)
			return (NULL);
	tmp = ft_strdup_pf(*str, *i, j);
	*i = plus + j;
	if (tmp != NULL)
		ft_putstr(tmp);
	return (tmp);
}

int		str_analysis(char **str, int *res, va_list args)
{
	unsigned int		i;
	char				*tmp;
	t_flag				flags;

	i = 0;
	while ((*str)[i] != '\0')
	{
		flag_init(&flags);
		if ((tmp = str_analysis_help(&flags, &i, str, args)) == NULL)
			return (-1);
		*res += ft_strlen(tmp);
		free(tmp);
		if ((look_for_function((*str)[i], args, res, &flags) == -1))
		{
			if ((*str)[i])
				return (-1);
		}
		if ((*str)[i])
			i += 1;
	}
	return (1);
}

int		ft_printf(const char *input, ...)
{
	va_list			args;
	char			*str;
	int				res;

	res = 0;
	str = ft_strdup(input);
	va_start(args, input);
	if ((str_analysis(&str, &res, args) == -1))
	{
		free(str);
		va_end(args);
		return (-1);
	}
	va_end(args);
	free(str);
	return (res);
}
