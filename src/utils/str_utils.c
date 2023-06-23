/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minylee <minylee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 16:40:52 by minylee           #+#    #+#             */
/*   Updated: 2023/06/23 13:29:32 by minylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != 0)
		len += 1;
	return (len);
}

int	ft_strcpy(char *from, char *to)
{
	int	idx;

	idx = 0;
	while (from[idx] != 0)
	{
		to[idx] = from[idx];
		idx += 1;
	}
	to[idx] = 0;
	return (idx);
}

void	is_ber(const char *path)
{
	int	len;

	len = 0;
	while (path[len] != 0)
		len += 1;
	if (len < 5)
		perror_exit("file name is too short");
	if (path[len - 4] != '.'
		|| path[len - 3] != 'b'
		|| path[len - 2] != 'e'
		|| path[len - 1] != 'r')
		perror_exit("file is not .ber file");
}
