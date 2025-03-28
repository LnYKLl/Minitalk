/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkiloul <lkiloul@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 12:33:02 by lkiloul           #+#    #+#             */
/*   Updated: 2025/03/28 14:54:47 by lkiloul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	main(int argc, char **argv)
{
    int PID;
    int i;
    char message;

    i = 0;
	if (argc != 2)
        return (0);
    PID = ft_atoi(argv[0]);
    message = argv[1];
    while (message[i])
    {
        
    }
}


