/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 12:09:53 by jacher            #+#    #+#             */
/*   Updated: 2020/12/08 18:03:22 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

static	void	man_neg(int n, unsigned int *nbr, unsigned int *size, int mod)
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
		tab[0] = '\0';
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
		nbr = nbr /10;
	}
	if (!(tab = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	tab[size] = '\0';
	if (n == 0)
		tab[0] = '\0';
	else
	{
		while (n > 0)
		{
			tab[size - 1] = n % 10 + '0';
			n = n / 10;
			size--;
		}
	}
	return (tab);
}

char			*ft_itoa_x(unsigned int n, char letter)
{
	unsigned int	nbr;
	unsigned int	size;
	char			*tab;
	char			*base;

	if (letter == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	size = 0;
	if (n == 0)
		size++;
	nbr = n;
	while (nbr > 0)
	{
		size = size + 1;
		nbr = nbr /16;
	}
	if (!(tab = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	tab[size] = '\0';
	if (n == 0)
		tab[0] = '0';
	else
	{
		while (n > 0)
		{
			tab[size - 1] = base[n % 16];
			n = n / 16;
			size--;
		}
	}
	return (tab);
}
