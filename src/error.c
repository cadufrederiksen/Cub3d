/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheferna <sheferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 18:24:36 by sheferna          #+#    #+#             */
/*   Updated: 2024/11/25 20:19:39 by sheferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	error(char *message)
{
	ft_fprintf(2, message);
	return (1);
}

void	error_exit(char *message)
{
	ft_fprintf(2, message);
	exit(1);
}
