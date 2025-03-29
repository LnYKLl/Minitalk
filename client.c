/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkiloul <lkiloul@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 12:33:02 by lkiloul           #+#    #+#             */
/*   Updated: 2025/03/29 15:33:22 by lkiloul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <signal.h>

void send(int PID, unsigned char character)
{
    int i;
    unsigned char temp;

    i = 8;

    temp = character;

    while (i > 0)
    {
        i--;
        temp = character >> i;
        if (temp % 2 == 0)
            kill(PID, SIGUSR2);
        else
            kill(PID, SIGUSR1);
        usleep(100);
    }
}

int	main(int argc, char **argv)
{
    pid_t PID;
    int i;
    const char *message;

    i = 0;
	if (argc != 3)
        return (ft_printf("error"), 0);
    PID = ft_atoi(argv[1]);
    message = argv[2];
    while (message[i])
    {
        send(PID, message[i++]);
    }
    send(PID, '\0');
}
