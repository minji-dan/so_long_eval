/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkim2 <mkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 19:22:36 by mkim2             #+#    #+#             */
/*   Updated: 2022/04/16 19:43:31 by mkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "so_long.h"

void	set_board_data(t_info *info, const char c, int y, int x)
{
	if (c == PLAYER)
	{
		info->player.count++;
		info->y = y;
		info->x = x;
	}
	else if (c == COLLECTIBLE)
		info->collectible.count++;
	else if (c == EXIT)
		info->exit.count++;
}

void	print_board(t_info *info)
{
	int	i;
	int	j;

	i = -1;
	while (++i < info->board_h)
	{
		j = -1;
		while (++j < info->board_w)
			printf("%c", info->board[i][j]);
		printf("\n");
	}
}
