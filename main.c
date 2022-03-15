/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rezzahra <rezzahra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 13:28:46 by mac               #+#    #+#             */
/*   Updated: 2022/03/15 03:59:18 by rezzahra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_philo			*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;

	pthread_mutex_init(&print, NULL);
	if (ac != 5 && ac != 6)
	{
		printf("Error\n");
		return (0);
	}
	forks = malloc(ft_atoi(av[1]) * sizeof(pthread_mutex_t));
	philos = malloc(ft_atoi(av[1]) * sizeof(t_philo));
	if (args_init(philos, ac, av, &print) == 0)
		return (0);
	m_init(philos, forks, ft_atoi(av[1]));
	create_threads(philos, ft_atoi(av[1]));
	while (total_meals_eaten(philos) != 1 && supervisor(philos) == 0)
		;
	return (0);
}
