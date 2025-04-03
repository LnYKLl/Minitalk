/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkiloul <lkiloul@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 12:33:02 by lkiloul           #+#    #+#             */
/*   Updated: 2025/04/03 16:57:01 by lkiloul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <signal.h>

int send(int PID, unsigned char character)
{
    unsigned int i;
    i = 0;
    
    while (i < 8)
    {
        if (character & (0x01 << i))
        {
            if (kill(PID, SIGUSR1))
                    return (0);
        }      
        else
        {
            if (kill(PID, SIGUSR2))
                return(0);
        }
        i++;
        usleep(500);
    }
    return(1);
}

int	main(int argc, char **argv)
{
    pid_t PID;
    int i;
    int len;

    i = 0;
    len = 0;
	if (argc != 3)
        return (ft_printf("error"), 0);
    PID = ft_atoi(argv[1]);
    while (*argv[2])
    {
        if (PID < 0 || !send(PID, *argv[2]++))
            ft_printf("send failed.");
    }
    send(PID, '\0');
}
