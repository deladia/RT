/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sdl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deladia <deladia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 10:20:37 by sleonia           #+#    #+#             */
/*   Updated: 2020/01/31 10:25:05 by deladia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void			init_sdl_music(t_key_value *assets, t_sdl *sdl)
{
	int				i;

	i = 0;
	while (++i < MAX_NBR_OF_SONGS)
		sdl->music[i] = NULL;
	Mix_OpenAudio(22050, AUDIO_S16SYS, 2, 640);
	initAudio();
	parse_songs_json(assets, sdl);
	sdl->volume = parse_volume_json(assets);
	Mix_VolumeMusic(sdl->volume);
	parse_sounds_json(assets, sdl);
}

static void			set_window_icon(t_key_value *assets, t_sdl *sdl)
{
	char			*icon;
	SDL_Surface		*sur_win;
	SDL_Surface		*sur_img;
	SDL_Surface		*conv_sur_img;

	icon = parse_icon_json(assets, sdl);
	if (!(sur_win = SDL_CreateRGBSurface(0, WIDTH, HEIGHT, 32, 0xFF000000,
										0x00FF0000, 0x0000FF00, 0x000000FF)))
		ft_error((char *)SDL_GetError());
	if (!(sur_img = IMG_Load(icon)))
		ft_error((char *)SDL_GetError());
	if (!(conv_sur_img = SDL_ConvertSurface(sur_img, sur_win->format, 0)))
		ft_error((char *)SDL_GetError());
	SDL_FreeSurface(sur_win);
	SDL_FreeSurface(sur_img);
	SDL_SetWindowIcon(sdl->window, conv_sur_img);
	SDL_FreeSurface(conv_sur_img);
	ft_strdel(&icon);
}

static void			init_sdl_2(t_key_value *json, t_sdl *sdl)
{
	t_key_value		*assets;

	if (!(sdl->pixels = (int *)ft_memalloc(sizeof(int) * WIDTH * HEIGHT)))
		ft_error((char *)SDL_GetError());
	SDL_UpdateTexture(sdl->texture, NULL, sdl->pixels, WIDTH * sizeof(int));
	SDL_RenderClear(sdl->render);
	SDL_RenderCopy(sdl->render, sdl->texture, NULL, NULL);
	SDL_RenderPresent(sdl->render);
	assets = parse_assets(json, sdl);
	set_window_icon(assets, sdl);
	init_sdl_music(assets, sdl);
}

t_sdl				*init_sdl(t_key_value *json)
{
	t_sdl			*sdl;

	if ((sdl = (t_sdl *)ft_memalloc((sizeof(t_sdl)))) == NULL)
		ft_error(ERROR_INPUT);
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) != 0)
		ft_error((char *)SDL_GetError());
	if (!(sdl->window = SDL_CreateWindow("Hello World!", SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN)))
		ft_error((char *)SDL_GetError());
	if (!(sdl->render = SDL_CreateRenderer(sdl->window, -1,
						SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC)))
		ft_error((char *)SDL_GetError());
	if (!(sdl->texture = SDL_CreateTexture(sdl->render,
										SDL_PIXELFORMAT_ARGB8888,
										SDL_TEXTUREACCESS_STREAMING,
										WIDTH, HEIGHT)))
		ft_error((char *)SDL_GetError());
	init_sdl_2(json, sdl);
	return (sdl);
}