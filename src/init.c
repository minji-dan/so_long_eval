/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkim2 <mkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 19:24:40 by mkim2             #+#    #+#             */
/*   Updated: 2022/04/16 19:24:55 by mkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "so_long.h"
#include "mlx.h"

static void	set_image(void *mlx, char *path, t_img *image)
{
	image->img = mlx_xpm_file_to_image(mlx, path, &image->w, &image->h);
}

void	init_mlx(t_info *info)
{
	info->mlx = mlx_init();
	set_image(info->mlx, PATH_BACKGROUND, &info->bg);
	set_image(info->mlx, PATH_PLAYER, &info->player);
	set_image(info->mlx, PATH_WALL, &info->wall);
	set_image(info->mlx, PATH_EXIT, &info->exit);
	set_image(info->mlx, PATH_COLLECTIBLE, &info->collectible);
	info->win_w = info->board_w * info->bg.w;
	info->win_h = info->board_h * info->bg.h;
}

void	init_info(t_info *info, char *file_name)
{
	info->file_name = file_name;
	info->board = NULL;
	info->s = NULL;
	info->board_h = 0;
	info->board_w = 0;
	info->collectible.count = 0;
	info->exit.count = 0;
	info->player.count = 0;
	info->move_cnt = 0;
	info->y = -1;
	info->x = -1;
	info->mlx = NULL;
	info->win = NULL;
}
