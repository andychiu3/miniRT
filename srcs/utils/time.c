/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiftyblue <fiftyblue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 10:16:49 by fiftyblue         #+#    #+#             */
/*   Updated: 2024/12/22 10:17:25 by fiftyblue        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

double	now(void)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return (now.tv_sec + (now.tv_usec / 1000000.0));
}
