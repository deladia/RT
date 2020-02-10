/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events_toolbar.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 07:16:51 by sleonia           #+#    #+#             */
/*   Updated: 2020/02/10 16:58:31 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

bool			key_toolbar(SDL_Scancode scancode,
						char *flag,
						t_object *hi_lited_object,
						t_rt *rt)
{
	if (hi_lited_object)
		return (false);
	if (rt->sdl->event.type == SDL_KEYDOWN)
	{
		if (scancode == SDLK_BACKSPACE && ft_strlen(rt->sdl->gui->textbox[0]->text) > 0)
		{
			rt->sdl->gui->textbox[0]->text = pop_back(rt->sdl->gui->textbox[0]->text);
			rt->sdl->gui->textbox[0]->render_text = true;
		}
		if (scancode == SDL_SCANCODE_ESCAPE)
			*flag = 1;
		if (rt->sdl->event.key.keysym.scancode == SDL_SCANCODE_1)
			change_focus(rt->sdl);
	}
	else if(rt->sdl->event.type == SDL_TEXTINPUT)
	{
		if( !( SDL_GetModState() & KMOD_CTRL && ( rt->sdl->event.text.text[ 0 ] == 'c' || rt->sdl->event.text.text[ 0 ] == 'C' || rt->sdl->event.text.text[ 0 ] == 'v' || rt->sdl->event.text.text[ 0 ] == 'V' ) ) )
		{
			rt->sdl->gui->textbox[0]->text = ft_strjoin_free(rt->sdl->gui->textbox[0]->text, rt->sdl->event.text.text, 1);
			rt->sdl->gui->textbox[0]->render_text = true;
		}
	}
	return (false);
}
