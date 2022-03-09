/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 14:58:02 by mac               #+#    #+#             */
/*   Updated: 2022/03/08 18:35:28 by mac              ###   ########.fr       */
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
    int n_meals = fay->meals;
    while(fay->meals)
    {
        pthread_mutex_lock(fay->fork);
        printing(fay, msg1, time_now());
        pthread_mutex_lock(fay->next_fork);
        printing(fay, msg2, time_now());
        usleep(fay->eat);
        pthread_mutex_unlock(fay->fork);
        pthread_mutex_unlock(fay->next_fork);
        n_meals--;
        printing(fay, msg3, time_now());
        usleep(fay->sleep);
        printing(fay, msg4, time_now());
        if (n_meals == 0)
            exit(0); 
    }
}