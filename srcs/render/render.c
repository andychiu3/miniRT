/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiftyblue <fiftyblue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 12:12:46 by achiu             #+#    #+#             */
/*   Updated: 2025/01/05 11:35:29 by fiftyblue        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_objs	*ray_hit(t_world *world)
{
	t_list		*tmp;
	t_objs		*objs_;
	double		t;
	t_objs		*closest;

	world->ray->t = INFINITY;
	tmp = world->objs;
	closest = NULL;
	while (tmp)
	{
		objs_ = (t_objs *)tmp->content;
		if (objs_->type == SP)
			t = intersect_sphere(world->ray, (t_sp *)objs_->data);
		else if (objs_->type == PL)
			t = pl_intersect(world->ray, (t_pl *)objs_->data);
		else if (objs_->type == CY)
			t = cy_intersect(world->ray, (t_cy *)objs_->data);
		if (t > EPSILON && t < world->ray->t)
		{
			world->ray->t = t;
			closest = objs_;
		}
		tmp = tmp->next;
	}
	return (closest);
}

/* get the P here seems making sense */
int	color(t_world *world)
{
	t_objs	*obj;

	obj = ray_hit(world);
	if (obj)
	{
		if (obj->type == SP)
			return (sp_color(world, (t_sp *)(obj->data)));
		else if (obj->type == PL)
			return (pl_color(world, (t_pl *)(obj->data)));
		else if (obj->type == CY)
			return (cy_color(world, (t_cy *)(obj->data)));
	}
	return (BLACK);
}

/* should not use getoftime tho */
void	render(t_world *world)
{
	int		x;
	int		y;
	double	start;

	init_cam(world->cam);
	start = now();
	printf("Rendering...\n");
	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			calc_ray(world, x, y);
			world->data->img_data[y * WIDTH + x] = color(world);
		}
	}
	mlx_put_image_to_window
		(world->data->mlx, world->data->win, world->data->img, 0, 0);
	printf("%.2f sec\n", now() - start);
}

void	data_init(t_world *world)
{
	world->data = malloc(sizeof(t_data));
	if (!world->data)
		panic(0, "malloc", 0, world);
	ft_memset(world->data, 0, sizeof(t_data));
	if (WIDTH <= 0 || HEIGHT <= 0)
		panic("Invalid width or height", 0, 0, world);
	world->data->mlx = mlx_init();
	if (!world->data->mlx)
		free_ptrs(world);
	world->data->win
		= mlx_new_window(world->data->mlx, WIDTH, HEIGHT, "miniRT");
	if (!world->data->win)
		free_ptrs(world);
	world->data->img = mlx_new_image(world->data->mlx, WIDTH, HEIGHT);
	if (world->data->img == NULL)
		free_ptrs(world);
	world->data->img_data = (int *)mlx_get_data_addr
		(world->data->img, &(int){32}, &(int){WIDTH * 4}, &(int){0});
	mlx_key_hook(world->data->win, (int (*)())hook_, world);
	mlx_hook(world->data->win, 17, 0, close_win, world);
}
