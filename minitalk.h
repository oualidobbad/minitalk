/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oobbad <oobbad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:28:56 by oobbad            #+#    #+#             */
/*   Updated: 2025/02/27 23:15:51 by oobbad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
#define MINITALK_H

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int		ft_atoi(char *str);
void	ft_putstr(char *s);
void	ft_putnbr_fd(int n, int fd);
#endif