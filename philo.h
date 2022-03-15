/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rezzahra <rezzahra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 15:22:24 by mac               #+#    #+#             */
/*   Updated: 2022/03/15 02:04:40 by rezzahra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H
#define msg1 "has taken a fork"
#define msg2 "is eating"
#define msg3 "is sleeping"
#define msg4 "is thinking"
#define msg5 "has died"

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>

typedef struct s_philo
{
    int n_p;
	int eat;
	int meals_eaten;
	int dead;
	int meals;
	unsigned long long start;
	int id;
	int sleep;
    int time_to_die;
	unsigned long long last_meal;
	pthread_t 		philo;
	pthread_mutex_t *print;
	pthread_mutex_t	*fork;
    pthread_mutex_t *next_fork;
	pthread_mutex_t *die;
}               t_philo;

int		ft_atoi(char *str);
int 	args_init(t_philo *philo,int ac, char **av,pthread_mutex_t *dead);
void	create_threads(t_philo *philo, int nf);
unsigned long long 	time_now(void);
void 	*routine(void *philo);
void 	m_init(t_philo *philo,pthread_mutex_t *fork,int n_p);
void 	sleeping(long time);
void 	printing(t_philo *philo, char *msg, long time,pthread_mutex_t *print);
void	mywayofsleep(unsigned long long timetosleep);
int		supervisor(t_philo *philo);
int 	total_meals_eaten(t_philo *philo);

#endif