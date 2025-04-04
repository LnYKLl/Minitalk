/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkiloul <lkiloul@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 12:44:35 by lkiloul           #+#                #+#             */
/*   Updated: 2025/04/03 16:47:45 by lkiloul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <signal.h>

volatile sig_atomic_t client_pid = 0;

void signal_check(int signal, siginfo_t *info, void *context)
{
    static unsigned char character = 0;
    static int bit = 0;

    (void)context;
    client_pid = info->si_pid;

    if (signal == SIGUSR1)
        character |= (0x80 >> bit);
    bit++; 
    if (bit == 8)
    {
        if (character == '\0')
        {
            ft_printf("\n");
        }
        else
        {
            ft_printf("%c", character);
        }
        bit = 0;
        character = 0;
    }
    kill(client_pid, SIGUSR1);
}

int main(void)
{
    struct sigaction sa;

    ft_printf("Your pid : %d\n", getpid());
    sa.sa_sigaction = signal_check;
    sa.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    while (1)
        pause();
    return (0);
}