/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhasoneh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 18:28:33 by mhasoneh          #+#    #+#             */
/*   Updated: 2024/10/04 19:45:03 by mhasoneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_sign(const char *nptr, int i)
{
	if (((nptr[i] == '+') || (nptr[i] == '-')) && (ft_isdigit(nptr[i + 1])))
	{
		if ((nptr[i] == '+') || (ft_isdigit(nptr[i])))
			return (1);
		if (nptr[i] == '-')
			return (-1);
	}
	if (ft_isdigit(nptr[i]))
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	nbr;
	int	sign;

	i = 0;
	nbr = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || (nptr[i] == 32))
		i++;
	sign = ft_sign(nptr, i);
	if (sign == 0)
		return (0);
	if (!ft_isdigit(nptr[i]))
		i++;
	while (ft_isdigit(nptr[i]))
	{
		nbr *= 10;
		nbr = nbr + (nptr[i] - '0');
		i++;
	}
	return (sign * nbr);
}
