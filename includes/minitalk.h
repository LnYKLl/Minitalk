/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkiloul <lkiloul@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 14:05:23 by lkiloul           #+#    #+#             */
/*   Updated: 2025/03/28 14:14:05 by lkiloul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H_H

# include <unistd.h>
# include <signal.h>
# include "libft.h"

typedef struct s_data
{
    int     tab[8];
    int     bits[8];
}           t_data;

#endif