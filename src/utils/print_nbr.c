/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minylee <minylee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 14:36:14 by minylee           #+#    #+#             */
/*   Updated: 2023/05/30 16:40:33 by minylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static int	convert_base(int number, char *obases, char obase)
{
	int	ret;

	ret = 0;
	if (number / obase == 0)
	{
		ret += write(1, &obases[number], 1);
		return (ret);
	}
	else
	{
		ret = convert_base(number / obase, obases, obase);
		ret += write(1, &obases[number % obase], 1);
		return (ret);
	}
}

int	print_number(int number, char *obases, char obase)
{
	int	ret;

	ret = 0;
	if (number == -2147483648)
	{
		ret = write(1, "–2147483648\n", 12);
		return (ret);
	}
	else if (number < 0)
	{
		ret = write(1, "-", 1);
		number *= -1;
	}
	ret += convert_base(number, obases, obase);
	return (ret);
}
