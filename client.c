/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkiloul <lkiloul@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 12:33:02 by lkiloul           #+#    #+#             */
/*   Updated: 2025/03/28 14:23:56 by lkiloul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	main(int argc, char **argv)
{
	int	i;
	int	blip;
    t_data data;
	i = 0;
	if (argc != 2)
		return (ft_printf("Error : Not enough arguments"), 0);
    malloc(data);
    if (!data)
        return (0);
	while (argv[1])
	{
		blip = ft_atoi(argv[1][i])
        conversion(blip, data);
	}
	argv[0] = "test";
}

int	conversion(int dec, t_data data)
{
	int i;
	int j;
	i = 128;
	j = 0;
	while (i >= 1)
	{
		data->tab[j] = i;
		i = i / 2;
		j++;
	}
    j = 0;
    while (dec != 0)
    {
        if (dec < data->tab[j])
        {
            data->bits[j] == 1
            dec -= data->bits[j];
        }
        else
            data->bits[j] == 0;
        j++;
    }
}
