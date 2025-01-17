/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mlx_ptrs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiftyblue <fiftyblue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 17:44:35 by fiftyblue         #+#    #+#             */
/*   Updated: 2025/01/07 11:49:23 by fiftyblue        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

#if defined(__linux__)

// free(world->world->data);
void	free_ptrs(t_world *world)
{
	if (world->data->img)
		mlx_destroy_image(world->data->mlx, world->data->img);
	if (world->data->win)
		mlx_destroy_window(world->data->mlx, world->data->win);
	if (world->data->mlx)
		mlx_destroy_display(world->data->mlx);
	if (world->data)
		free(world->data);
	cleanup(world);
	exit(EXIT_SUCCESS);
}

#elif defined(__APPLE__)

/* freeing mlx directly will cause leaks */
void	free_ptrs(t_world *world)
{
	if (world->data->img)
		mlx_destroy_image(world->data->mlx, world->data->img);
	if (world->data->win)
		mlx_destroy_window(world->data->mlx, world->data->win);
	if (world->data)
		free(world->data);
	cleanup(world);
	exit(EXIT_SUCCESS);
}

#endif

int	close_win(void *param)
{
	free_ptrs((t_world *)param);
	return (0);
}
