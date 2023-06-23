/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_walk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minylee <minylee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 18:58:51 by minylee           #+#    #+#             */
/*   Updated: 2023/05/30 18:59:02 by minylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	print_walk(int walk)
{
	write(1, "walk : ", 7);
	print_number(walk, "0123456789", 10);
	write(1, "\n", 1);
}
