/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkim2 <mkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 19:21:45 by mkim2             #+#    #+#             */
/*   Updated: 2022/04/16 19:22:19 by mkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

int	main(int argc, char **argv)
{
	t_info	info;

	if (1 < argc)
	{
		init_info(&info, argv[1]);
		check_extension(&info);
		set_board(&info);
		print_board(&info);
		init_mlx(&info);
		print_init_image(&info);
		mlx_hook(info.win, DESTROY_NOTIFY, 0, mouse_hook, &info);
		mlx_key_hook(info.win, key_hook, &info);
		mlx_loop(info.mlx);
	}
	return (0);
}
