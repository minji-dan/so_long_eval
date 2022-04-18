/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkim2 <mkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 19:25:08 by mkim2             #+#    #+#             */
/*   Updated: 2022/04/16 19:26:46 by mkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

static void	print_image(t_info *info, void *img, int x, int y)
{
	if (img == info->player.img)
		mlx_put_image_to_window(info->mlx, info->win, img, x - 5, y - 5);
	else
		mlx_put_image_to_window(info->mlx, info->win, img, x, y);
}

void	print_init_image(t_info *info)
{
	int	i;
	int	j;

	info->win = mlx_new_window(info->mlx, info->win_w, info->win_h, "mkim2");
	i = -1;
	while (++i < info->board_w)
	{
		j = -1;
		while (++j < info->board_h)
		{
			if (info->board[j][i] == WALL)
				print_image(info, info->wall.img,
					i * info->bg.w, j * info->bg.h);
			else
				print_image(info, info->bg.img, i * info->bg.w, j * info->bg.h);
			if (info->board[j][i] == COLLECTIBLE)
				print_image(info, info->collectible.img,
					i * info->bg.w, j * info->bg.h);
			if (info->board[j][i] == EXIT)
				print_image(info, info->exit.img,
					i * info->bg.w, j * info->bg.h);
		}
	}
	print_player(info, info->x, info->y);
}

void	print_player(t_info *info, int b_x, int b_y)
{
	print_image(info, info->bg.img, b_x * info->bg.w, b_y * info->bg.h);
	print_image(info, info->bg.img,
		info->x * info->bg.w, info->y * info->bg.h);
	print_image(info, info->player.img,
		info->x * info->bg.w, info->y * info->bg.h);
}
