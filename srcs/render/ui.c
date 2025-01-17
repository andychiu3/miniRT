/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiftyblue <fiftyblue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 12:08:28 by achiu             #+#    #+#             */
/*   Updated: 2025/01/11 11:35:12 by fiftyblue        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vec	rotate_y(t_vec vec, double angle)
{
	t_vec	result;
	double	cos_a;
	double	sin_a;

	cos_a = cos(angle);
	sin_a = sin(angle);
	result.x = cos_a * vec.x + sin_a * vec.z;
	result.y = vec.y;
	result.z = -sin_a * vec.x + cos_a * vec.z;
	return (result);
}

t_vec	rotate_x(t_vec vec, double angle)
{
	t_vec	result;
	double	cos_a;
	double	sin_a;

	cos_a = cos(angle);
	sin_a = sin(angle);
	result.x = vec.x;
	result.y = cos_a * vec.y - sin_a * vec.z;
	result.z = sin_a * vec.y + cos_a * vec.z;
	return (result);
}

int	hook_(int key, void *param)
{
	t_world	*world;

	world = (t_world *)param;
	if (key == ESC)
		free_ptrs(world);
	if (key == LEFT)
		world->cam->vector = rotate_y(world->cam->vector, M_PI / 18);
	else if (key == RIGHT)
		world->cam->vector = rotate_y(world->cam->vector, -M_PI / 18);
	else if (key == UP)
		world->cam->vector = rotate_x(world->cam->vector, M_PI / 18);
	else if (key == DOWN)
		world->cam->vector = rotate_x(world->cam->vector, -M_PI / 18);
	render(world);
	return (0);
}
