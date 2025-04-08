/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkiloul <lkiloul@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 12:33:02 by lkiloul           #+#    #+#             */
/*   Updated: 2025/04/08 15:13:04 by lkiloul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <signal.h>

volatile sig_atomic_t ack_received = 0;

void handle_ack(int signal)
{
    (void)signal;
    ack_received = 1;
}

int send(int PID, unsigned char character)
{
    unsigned int i;
    i = 0;

    while (i < 8)
    {
        ack_received = 0;
        if (character & (0x80 >> i))
        {
            if (kill(PID, SIGUSR1))
                return (0);
        }
        else
        {
            if (kill(PID, SIGUSR2))
                return (0);
        }
        while (!ack_received)
            continue;
        i++;
    }
    return (1);
}

int main(int argc, char **argv)
{
    pid_t PID;

    signal(SIGUSR1, handle_ack);
    if (argc != 3)
        return (ft_printf("error : Not enough arguments."), 0);
    PID = ft_atoi(argv[1]);
    if (PID <= 0)
    return (ft_printf("Error : Bad PID."), 0);
    while (*argv[2])
    {
        if (PID < 0 || !send(PID, *argv[2]++))
            return(ft_printf("An error occured, data can't be sended.\n"),  0);
            
    }
    send(PID, '\0');
}
