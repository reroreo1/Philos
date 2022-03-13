/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 13:28:46 by mac               #+#    #+#             */
/*   Updated: 2022/03/13 16:30:43 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int ac,char **av)
{
    t_philo *philos;
    pthread_mutex_t *forks;
    pthread_mutex_t print;

    if(ac != 5 && ac != 6)
    {
        printf("Error\n");
        return (0);
    }
	pthread_mutex_init(&print, NULL);
    forks = malloc(ft_atoi(av[1]) * sizeof(pthread_mutex_t));
	philos = malloc(ft_atoi(av[1]) * sizeof(t_philo));
    args_init(philos,ac,av, &print);
    m_init(philos, forks, ft_atoi(av[1]));
    create_threads(philos, ft_atoi(av[1]));
	while (1)
    {
        supervisor(philos,&print);
    }
}