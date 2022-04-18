/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkim2 <mkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 19:23:34 by mkim2             #+#    #+#             */
/*   Updated: 2022/04/18 11:27:37 by mkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "so_long.h"
#include "mlx.h"

static void	free_struct(t_info *info)
{
	int	idx;

	if (info->board == NULL)
		return ;
	idx = 0;
	while (idx < info->board_h)
	{
		if (info->board[idx])
			free(info->board[idx]);
		info->board[idx++] = NULL;
	}
	if (info->board)
	{
		free(info->board);
		info->board = NULL;
	}
}

static void	destroy_image(t_info *info)
{
	if (info->bg.img != NULL)
		mlx_destroy_image(info->mlx, info->bg.img);
	if (info->player.img != NULL)
		mlx_destroy_image(info->mlx, info->player.img);
	if (info->collectible.img != NULL)
		mlx_destroy_image(info->mlx, info->collectible.img);
	if (info->exit.img != NULL)
		mlx_destroy_image(info->mlx, info->exit.img);
	if (info->wall.img != NULL)
		mlx_destroy_image(info->mlx, info->wall.img);
	if (info->win != NULL)
		mlx_destroy_window(info->mlx, info->win);
}

void	exit_game(t_info *info, char *s)
{
	if (!info)
	{
		printf("%s\n", s);
		exit(1);
	}
	if (info->s != NULL)
		free(info->s);
	if (info->board != NULL)
		free_struct(info);
	if (info->win != NULL)
		destroy_image(info);
	if (s != NULL)
		printf("%s\n", s);
	exit(0);
}
