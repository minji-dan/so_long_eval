/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkim2 <mkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 19:27:36 by mkim2             #+#    #+#             */
/*   Updated: 2022/04/18 11:27:46 by mkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

typedef struct s_img
{
	void	*img;
	char	*path;
	int		h;
	int		w;
	int		count;
}			t_img;

typedef struct s_info
{
	char	*file_name;
	char	**board;
	char	*s;
	int		s_size;
	int		board_h;
	int		board_w;
	int		move_cnt;
	void	*mlx;
	void	*win;
	int		y;
	int		x;
	int		win_h;
	int		win_w;
	t_img	bg;
	t_img	player;
	t_img	wall;
	t_img	exit;
	t_img	collectible;
}			t_info;

# define EMPTY '0'
# define WALL '1'
# define COLLECTIBLE 'C'
# define EXIT 'E'
# define PLAYER 'P'

# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_ESC 53

# define DESTROY_NOTIFY 17

# define ERROR_EXTENSION "Error! file extension is not .ber"
# define ERROR_FD "Error! invalid file descriptor"
# define ERROR_MAP_SIZE "Error! invalid map size"
# define ERROR_MALLOC "Error! insufficient memory"
# define ERROR_WALL "Error! outside board is not wall"
# define ERROR_RECTANGLE "Error! board is not rectangle"
# define ERROR_INVALID_CHAR "Error! there is invalid character in board"
# define ERROR_NO_PLAYER "Error! there is no player on the board"
# define ERROR_NO_EXIT "Error! there is no exit on the board"
# define ERROR_NO_COLLECTIBLE "Error! there is no collectible on the board"
# define MOVE_CNT_OVER "Game Over!"

# define PATH_BACKGROUND "./img/background.xpm"
# define PATH_PLAYER "./img/player.xpm"
# define PATH_WALL "./img/wall.xpm"
# define PATH_EXIT "./img/exit.xpm"
# define PATH_COLLECTIBLE "./img/collectible.xpm"

void	exit_game(t_info *info, char *s);

void	init_info(t_info *info, char *file_name);
void	init_mlx(t_info *info);

void	check_extension(t_info *info);
void	check_wall(t_info *info);
void	check_invalid_char(t_info *info);
void	check_board_data(t_info *info);

void	print_init_image(t_info *info);
void	print_player(t_info *info, int b_x, int b_y);

void	set_board(t_info *info);

void	set_board_data(t_info *info, const char c, int y, int x);
void	print_board(t_info *info);

int		key_hook(int key, t_info *info);
int		mouse_hook(t_info *info);

# define BUFFER_SIZE 1000000
#endif
