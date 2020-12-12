/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 12:09:53 by jacher            #+#    #+#             */
/*   Updated: 2020/12/10 13:53:39 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pf.h"

void			man_neg(int n, unsigned int *nbr, unsigned int *size, int mod)
{
	if (n <= 0)
	{
		if (mod == 0)
			*size = *size + 1;
		*nbr = -n;
	}
	else
		*nbr = n;
	if (mod == 0)
	{
		while (*nbr > 0)
		{
			*size = *size + 1;
			*nbr = *nbr / 10;
		}
	}
}

char			*ft_itoa_int(int n)
{
	unsigned int	nbr;
	unsigned int	size;
	char			*tab;

	size = 0;
	man_neg(n, &nbr, &size, 0);
	if (!(tab = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	tab[size] = '\0';
	man_neg(n, &nbr, &size, 1);
	if (nbr == 0)
		tab[0] = '0';
	else
	{
		while (nbr > 0)
		{
			tab[size - 1] = nbr % 10 + '0';
			nbr = nbr / 10;
			size--;
		}
		if (size > 0)
			tab[0] = '-';
	}
	return (tab);
}

void			fill_table(unsigned int n, char *tab, int size, char letter)
{
	char			*base;
	unsigned int	i;

	if (letter == 'd')
	{
		base = "0123456789";
		i = 10;
	}
	if (letter == 'x')
	{
		base = "0123456789abcdef";
		i = 16;
	}
	if (letter == 'X')
	{
		base = "0123456789ABCDEF";
		i = 16;
	}
	while (n > 0)
	{
		tab[size - 1] = base[n % i];
		n = n / i;
		size--;
	}
}

char			*ft_itoa_unsint(unsigned int n)
{
	unsigned int	nbr;
	unsigned int	size;
	char			*tab;

	size = 0;
	if (n == 0)
		size++;
	nbr = n;
	while (nbr > 0)
	{
		size = size + 1;
		nbr = nbr / 10;
	}
	if (!(tab = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	tab[size] = '\0';
	if (n == 0)
		tab[0] = '0';
	else
		fill_table(n, tab, size, 'd');
	return (tab);
}

char			*ft_itoa_x(unsigned int n, char letter)
{
	unsigned int	nbr;
	unsigned int	size;
	char			*tab;

	size = 0;
	if (n == 0)
		size++;
	nbr = n;
	while (nbr > 0)
	{
		size = size + 1;
		nbr = nbr / 16;
	}
	if (!(tab = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	tab[size] = '\0';
	if (n == 0)
		tab[0] = '0';
	else
		fill_table(n, tab, size, letter);
	return (tab);
}
