/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiftyblue <fiftyblue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:28:45 by fiftyblue         #+#    #+#             */
/*   Updated: 2025/01/05 17:06:57 by fiftyblue        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	parse_line(t_world *world, char *line)
{
	char	**strarray;

	if (!line)
		return ;
	only_space(line);
	strarray = ft_split(line, ' ');
	if (!strarray || !strarray[0])
		return (ft_freematrix(&strarray));
	if (ft_strcmp("A", strarray[0]) == 0)
		parse_ambient(world, strarray);
	else if (ft_strcmp("C", strarray[0]) == 0)
		parse_camera(world, strarray);
	else if (ft_strcmp("L", strarray[0]) == 0)
		parse_light(world, strarray);
	else if (ft_strcmp("sp", strarray[0]) == 0)
		parse_sphere(world, strarray);
	else if (ft_strcmp("pl", strarray[0]) == 0)
		parse_plane(world, strarray);
	else if (ft_strcmp("cy", strarray[0]) == 0)
		parse_cylinder(world, strarray);
	ft_freematrix(&strarray);
}

void	parse_file(t_world *world, char **av)
{
	int		fd;
	char	*line;

	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		panic(0, "fatal", 0, world);
	line = gnl_trimmed(fd);
	while (line)
	{
		parse_line(world, line);
		free(line);
		line = gnl_trimmed(fd);
	}
	close(fd);
}

int	parser(int ac, char **av, t_world *world)
{
	if (ac != 2)
		panic("form: ./miniRT <file>.rt", 0, 0, world);
	if (!is_valid_extension(av[1], ".rt"))
		panic("argv[1] only takes .rt", 0, 0, world);
	parse_file(world, av);
	if (!world->amb)
		panic("ambient not set", 0, 0, world);
	if (!world->cam)
		panic("camera not set", 0, 0, world);
	if (!world->lt)
		panic("light not set", 0, 0, world);
	return (0);
}
