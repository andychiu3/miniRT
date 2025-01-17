/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isspace2space.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiftyblue <fiftyblue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 09:45:09 by fiftyblue         #+#    #+#             */
/*   Updated: 2024/12/18 09:45:14 by fiftyblue        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	only_space(char *line)
{
	if (!line)
		return ;
	while (*line)
	{
		if (ft_isspace(*line) && *line != ' ')
			*line = ' ';
		line++;
	}
}
