/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkim2 <mkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 19:12:22 by mkim2             #+#    #+#             */
/*   Updated: 2022/04/16 19:15:26 by mkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

void	check_extension(t_info *info)
{
	size_t	len;

	len = ft_strlen(info->file_name);
	if (len < 5)
		exit_game(info, ERROR_EXTENSION);
	if (ft_strcmp(info->file_name + len - 4, ".ber") != 0)
		exit_game(info, ERROR_EXTENSION);
}

void	check_wall(t_info *info)
{
	int	i;

	i = -1;
	while (++i < info->board_h)
		if (info->board[i][0] != WALL ||
				info->board[i][info->board_w - 1] != WALL)
			exit_game(info, ERROR_WALL);
	i = -1;
	while (++i < info->board_w)
		if (info->board[0][i] != WALL ||
				info->board[info->board_h - 1][i] != WALL)
			exit_game(info, ERROR_WALL);
}

void	check_invalid_char(t_info *info)
{
	int	i;
	int	j;

	i = -1;
	while (++i < info->board_h)
	{
		j = -1;
		while (++j < info->board_w)
		{
			if (info->board[i][j] == EMPTY)
				continue ;
			if (info->board[i][j] == WALL)
				continue ;
			if (info->board[i][j] == COLLECTIBLE)
				continue ;
			if (info->board[i][j] == EXIT)
				continue ;
			if (info->board[i][j] == PLAYER)
				continue ;
			exit_game(info, ERROR_INVALID_CHAR);
		}
	}
}

void	check_board_data(t_info *info)
{
	if (info->player.count == 0)
		exit_game(info, ERROR_NO_PLAYER);
	if (info->exit.count == 0)
		exit_game(info, ERROR_NO_EXIT);
	if (info->collectible.count == 0)
		exit_game(info, ERROR_NO_COLLECTIBLE);
}
