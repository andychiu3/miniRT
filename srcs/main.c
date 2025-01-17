/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiftyblue <fiftyblue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 20:38:36 by fiftyblue         #+#    #+#             */
/*   Updated: 2025/01/05 17:06:36 by fiftyblue        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/* prnt_world(&world); */
int	main(int ac, char **av)
{
	t_world	world;

	ft_memset(&world, 0, sizeof(t_world));
	parser(ac, av, &world);
	init_ray(&world);
	data_init(&world);
	render(&world);
	mlx_loop(world.data->mlx);
	cleanup(&world);
}
