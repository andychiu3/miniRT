/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   panic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiftyblue <fiftyblue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 18:21:41 by fiftyblue         #+#    #+#             */
/*   Updated: 2025/01/05 15:51:00 by fiftyblue        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	free_objs(void	*obj_ptr)
{
	t_objs	*obj;

	obj = (t_objs *)obj_ptr;
	if (obj)
	{
		if (obj->data)
		{
			if (obj->type == SP)
				free((t_sp *)obj->data);
			else if (obj->type == PL)
				free((t_pl *)obj->data);
			if (obj->type == CY)
				free((t_cy *)obj->data);
		}
		free(obj);
	}
}

void	cleanup(t_world *world)
{
	if (world->amb)
		free(world->amb);
	if (world->cam)
		free(world->cam);
	if (world->lt)
		free(world->lt);
	if (world->objs)
		ft_lstclear(&world->objs, free_objs);
	if (world->ray)
		free(world->ray);
}

/*
yet to clean fd??
*/
void	panic(char *msg1, char *msg2, char *msg3, t_world *world)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	if (msg1)
		ft_putstr_fd(msg1, STDERR_FILENO);
	if (msg2)
		strerror(errno);
	if (msg3)
		ft_putstr_fd(msg3, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
	if (world)
		cleanup(world);
	exit(1);
}
