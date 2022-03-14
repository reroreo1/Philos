/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 14:58:02 by mac               #+#    #+#             */
/*   Updated: 2022/03/14 21:12:10 by mac              ###   ########.fr       */
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
	static int total;
	int n_f = fay->n_p;
	int meals = fay->meals; 
    while(fay->dead == 0)
    {
        pthread_mutex_lock(fay->fork);
        printing(fay, msg1, time_now());
        pthread_mutex_lock(fay->next_fork);
        printing(fay, msg2, time_now());
        mywayofsleep(fay->eat);
		if(total > meals * n_f && meals > 0)
			exit(0);
		total++;
		fay->last_meal = time_now();
        pthread_mutex_unlock(fay->fork);
        pthread_mutex_unlock(fay->next_fork);
        printing(fay, msg3, time_now());
        mywayofsleep(fay->sleep);
        printing(fay, msg4, time_now()); 
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

void supervisor(t_philo *philo)
{
	unsigned long long diff = 0;
	int i = 0;
	//pthread_mutex_t	deadly;
	while (i < philo[0].n_p)
	{
			diff = time_now() - philo[i].last_meal;
			if (diff > (unsigned long long)philo[i].time_to_die)
			{
				//pthread_mutex_lock(&deadly);
				philo[i].dead = 1;
				printing(&philo[i],msg5,time_now());
				i = 0;
				while(i < philo[0].n_p)
				{
					pthread_mutex_destroy(philo[i].fork);
					i++;
				}
				exit(0);
			}
		i++;
	}
}