/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkiloul <lkiloul@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 12:44:35 by lkiloul           #+#    #+#             */
/*   Updated: 2025/04/03 16:47:45 by lkiloul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include "signal.h"
void signal_check(int signal)
{
    static unsigned char character;
    static int bit;

    if (signal == SIGUSR1)
        character |= (0x01 << bit);
        
    bit++; 
    if (bit == 8)
    {
        ft_printf("%c", character);
        bit = 0;
        character = 0;
    }
}

int main(void)
{
    ft_printf("Your pid : %d\n", getpid());
    signal(SIGUSR1, signal_check);
    signal(SIGUSR2, signal_check);
    while (1)
        pause();
    return (0);
}