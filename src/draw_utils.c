/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkim2 <mkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 19:10:18 by mkim2             #+#    #+#             */
/*   Updated: 2022/04/16 19:12:07 by mkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "so_long.h"
#include "libft.h"

static int	get_file_size(char *file_name)
{
	int		fd;
	int		size;
	int		len;
	char	buffer[BUFFER_SIZE];

	size = 0;
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		exit_game(NULL, ERROR_FD);
	while (1)
	{
		len = read(fd, buffer, BUFFER_SIZE);
		if (len == -1)
		{
			close(fd);
			exit_game(NULL, ERROR_FD);
		}
		if (len == 0)
			break ;
		size += len;
	}
	close(fd);
	return (size);
}

static void	set_string(t_info *info)
{
	int		fd;
	int		len;
	char	buffer[BUFFER_SIZE];

	fd = open(info->file_name, O_RDONLY);
	if (fd == -1)
		exit_game(NULL, ERROR_FD);
	*info->s = '\0';
	while (1)
	{
		len = read(fd, buffer, BUFFER_SIZE);
		if (len == -1)
			exit_game(NULL, ERROR_FD);
		if (len == 0)
			break ;
		buffer[len] = '\0';
		ft_strlcat(info->s, buffer, len + 1);
	}
	close(fd);
}

static void	set_board_height_width(t_info *info)
{
	int	idx;
	int	len;

	idx = -1;
	while (++idx < info->s_size)
		if (info->s[idx] != '\n' && (idx == 0 || info->s[idx - 1] == '\n'))
			info->board_h++;
	idx = -1;
	while (++idx < info->s_size)
	{
		len = 0;
		while (idx < info->s_size && info->s[idx] != '\n')
		{
			idx++;
			len++;
		}
		if (info->board_w == 0)
			info->board_w = len;
		else if (info->board_w != len)
			exit_game(info, ERROR_RECTANGLE);
	}
}

static void	set_board_main(t_info *info)
{
	int	i;
	int	j;
	int	idx;

	info->board = (char **)malloc(sizeof(char *) * (info->board_h + 1));
	if (info->board == NULL)
		exit_game(info, ERROR_MALLOC);
	idx = 0;
	i = -1;
	while (++i < info->board_h)
	{
		info->board[i] = (char *)malloc(sizeof(char) * (info->board_w + 1));
		if (info->board[i] == NULL)
			exit_game(info, ERROR_MALLOC);
		j = -1;
		while (++j < info->board_w)
		{
			while (info->s[idx] == '\n')
				idx++;
			info->board[i][j] = info->s[idx++];
			set_board_data(info, info->board[i][j], i, j);
		}
	}
}

void	set_board(t_info *info)
{
	info->s_size = get_file_size(info->file_name);
	if (info->s_size < 17)
		exit_game(info, ERROR_MAP_SIZE);
	info->s = (char *)malloc(sizeof(char) * (info->s_size + 1));
	if (info->s == NULL)
		exit_game(info, ERROR_MALLOC);
	set_string(info);
	set_board_height_width(info);
	set_board_main(info);
	check_board_data(info);
	check_wall(info);
	check_invalid_char(info);
}
