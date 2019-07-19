/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamerd <gamerd@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 12:14:56 by gamerd            #+#    #+#             */
/*   Updated: 2019/07/19 13:07:24 by gamerd           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

int main(int argc, char **argv)
{
	t_mydata	*mydata;
	int			i;

	if((mydata = (t_mydata *)malloc(sizeof(t_mydata))) == NULL)
		exit(1);
	mydata->win_count = 0;
	if (ft_sdl_init() != 0)
		exit(1);
	i = 0;
	while (++i < argc)
		ft_add_win(mydata, ft_init_win(argv[i], (t_point){100, 100}, (t_point){620, 387}, SDL_WINDOW_SHOWN));

	// mydata->bmp = SDL_LoadBMP("./img/cat.bmp");
	// if (mydata->bmp == NULL) {
	// 	fprintf(stderr, "SDL_LoadBMP Error: %s\n", SDL_GetError());
	// 	return EXIT_FAILURE;
	// }

	// mydata->tex = SDL_CreateTextureFromSurface(mydata->ren, mydata->bmp);
	// if (mydata->tex == NULL) {
	// 	fprintf(stderr, "SDL_CreateTextureFromSurface Error: %s\n", SDL_GetError());
	// 	return EXIT_FAILURE;
	// }
	// SDL_FreeSurface(mydata->bmp);

	for (int i=0; i < 20; i++) {
			// SDL_RenderClear(mydata->wins->ren);
			// SDL_RenderCopy(mydata->ren, mydata->tex, NULL, NULL);
			// SDL_RenderPresent(mydata->wins->ren);
			SDL_Delay(100);
	}

	// free(mydata);
	// // SDL_DestroyTexture(mydata->tex);
	// SDL_DestroyRenderer(mydata->wins->ren);
	// SDL_DestroyWindow(mydata->wins->win);
	// SDL_Quit();

	return EXIT_SUCCESS;
}