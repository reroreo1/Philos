/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_race.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rezzahra <rezzahra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 17:12:51 by mac               #+#    #+#             */
/*   Updated: 2022/03/15 03:43:28 by rezzahra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	total_meals_eaten(t_philo *philo)
{
	int	i;
	int	sum;
	int	total;

	i = 0;
	sum = 0;
	total = philo[0].n_p * philo[0].meals;
	while (i < philo[0].n_p && philo[0].meals > 0)
	{
		sum += philo[i].meals_eaten;
		i++;
	}
	if (sum > total && philo[0].meals > 0)
		return (1);
	return (0);
}
