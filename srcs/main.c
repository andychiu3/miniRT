/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achiu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 20:40:16 by achiu             #+#    #+#             */
/*   Updated: 2024/12/06 20:40:18 by achiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <mlx.h>

void	panic(t_data *data, char *str)
{
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
		mlx_destroy_display(data->mlx);
	free(data);
	perror(str);
	exit(1);
}

int close_window(void *param)
{
    t_data	*data;

	data = (t_data *)param;
	panic(data, "ESC");
    // write(STDERR_FILENO, "Window closed\n", 14);
    exit(0);
}

int main()
{
    t_data  *data;

    data = malloc(sizeof(t_data));
	if (!data)
		return (perror("malloc error"), 1);
	memset(data, 0, sizeof(*data));
    data->mlx = mlx_init();
    if (!data->mlx)
        return (panic(data, "init error"), 1);
    data->win = mlx_new_window(data->mlx, 800, 600, "Test Window");
    if (!data->win)
        return (panic(data, "win error"), 1);
    mlx_hook(data->win, 17, 0, close_window, data);
    mlx_loop(data->mlx);

    return (0);
}

