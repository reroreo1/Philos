/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rezzahra <rezzahra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 14:58:02 by mac               #+#    #+#             */
/*   Updated: 2022/03/18 09:55:17 by rezzahra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(char *str)
{
	int	i;
	int	nbr;
	int	sign;

	i = 0;
	nbr = 0;
	sign = 1;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' || str[i] == '\f'
		|| str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = (-1);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10 + (str[i] - 48);
		i++;
	}
	return (nbr * sign);
}

void	*routine(void *philo)
{
	t_philo	*fay;

	fay = (t_philo *)philo;
	while (!fay->dead)
	{
		pthread_mutex_lock(fay->fork);
		printing(fay, MSG1, time_now(), fay->print);
		pthread_mutex_lock(fay->next_fork);
		printing(fay, MSG2, time_now(), fay->print);
		fay->last_meal = time_now();
		fay->meals_eaten++;
		mywayofsleep(fay->eat);
		pthread_mutex_unlock(fay->fork);
		pthread_mutex_unlock(fay->next_fork);
		printing(fay, MSG3, time_now(), fay->print);
		mywayofsleep(fay->sleep);
		printing(fay, MSG4, time_now(), fay->print);
	}
	return (NULL);
}

void	mywayofsleep(unsigned long long timetosleep)
{
	unsigned long long	time;

	time = time_now();
	while (time_now() < time + timetosleep)
		usleep(400);
}

int	supervisor(t_philo *philo)
{
	int					i;
	int					dead;

	i = 0;
	while (i < philo[0].n_p)
	{
		if (time_now() - philo[i].last_meal
			>= (unsigned long long)philo[i].time_to_die)
		{
			dead = 1;
			printing(&philo[i], MSG5, time_now(), philo[i].print);
			i = 0;
			while (i < philo[0].n_p)
			{
				philo[i].dead = dead;
				pthread_mutex_destroy(philo[i].fork);
				i++;
			}
			pthread_mutex_destroy(philo->print);
			return (1);
		}
		i++;
	}
	return (0);
}
