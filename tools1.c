/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rezzahra <rezzahra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 14:58:02 by mac               #+#    #+#             */
/*   Updated: 2022/03/15 02:05:10 by rezzahra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int ft_atoi(char *str)
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

void    *routine(void *philo)
{
    t_philo *fay;
	fay = (t_philo *)philo;
	
    while(!fay->dead)
    {
        pthread_mutex_lock(fay->fork);
        printing(fay, msg1, time_now(),fay->print);
        pthread_mutex_lock(fay->next_fork);
        printing(fay, msg2, time_now(),fay->print);
        mywayofsleep(fay->eat);
		fay->meals_eaten++;
		fay->last_meal = time_now();
        pthread_mutex_unlock(fay->fork);
        pthread_mutex_unlock(fay->next_fork);
        printing(fay, msg3, time_now(),fay->print);
        mywayofsleep(fay->sleep);
        printing(fay, msg4, time_now(),fay->print); 
    }
	return NULL;
}

void mywayofsleep(unsigned long long timetosleep)
{
	unsigned long long time;

	time = time_now();
	while(time_now() < time + timetosleep)
		usleep(400);
}

int supervisor(t_philo *philo)
{
	unsigned long long diff = 0;
	int i = 0;
	
	while(total_meals_eaten(philo) != 1)
	{
		while (i < philo[0].n_p)
		{
			diff = time_now() - philo[i].last_meal;
			if (diff > (unsigned long long)philo[i].time_to_die)
			{
				philo[i].dead = 1;
				printing(&philo[i],msg5,time_now(),philo[i].print);
				i = 0;
				while(i < philo[0].n_p)
				{
					pthread_mutex_destroy(philo[i].fork);
					i++;
				}
				break;
			}
		i++;
		}
	}
	return 0;
}