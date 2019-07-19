/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamerd <gamerd@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 12:14:56 by gamerd            #+#    #+#             */
/*   Updated: 2019/07/19 18:52:59 by gamerd           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

int main(int argc, char **argv)
{
	t_mydata	*mydata;
	int			i;

	if (argc == 1)
		return (0);
	if((mydata = (t_mydata *)malloc(sizeof(t_mydata))) == NULL)
		exit(1);
	mydata->win_count = 0;
	mydata->keyboardState = SDL_GetKeyboardState(NULL);
	if (ft_sdl_init() != 0)
		exit(1);
	i = 0;
	while (++i < argc)
		ft_add_win(mydata, ft_init_win(argv[i], (t_point){100, 100}, (t_point){640, 480}, SDL_WINDOW_SHOWN));

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

	// SDL_Texture * texture = SDL_CreateTexture(mydata->wins[0]->ren,
	// 	SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STATIC, 640, 480);
	// Uint32 *pixels = (Uint32 *)malloc(sizeof(Uint32) * 640 * 480);
	// SDL_UpdateTexture(texture, NULL, pixels, 640 * sizeof(Uint32));

	SDL_Event	ev;
	int			run;
	
	run = 1;
	while (run == 1)
	{
		while (SDL_PollEvent(&ev) != 0)
		{
			SDL_PumpEvents();
			ft_run_mouse_fun(mydata, ev);
			// if (SDL_BUTTON(SDL_BUTTON_LEFT))
			// {
			// 	int mouseX = ev.motion.x;
			// 	int mouseY = ev.motion.y;
			// 	pixels[mouseY * 640 + mouseX] = 0xff;
			// }
			ft_run_keyboard_fun(mydata, ev);
			if (mydata->win_count == 0)
				run = 0;
		}
		ft_update_win_surface(mydata);
	}

	// // SDL_DestroyTexture(mydata->tex);
	ft_destroy_wins(mydata);
	free(mydata);
	SDL_Quit();

	return EXIT_SUCCESS;
}