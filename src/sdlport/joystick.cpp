/*
 *  Abuse - dark 2D side-scrolling platform game
 *  Copyright (c) 2001 Anthony Kruize <trandor@labyrinth.net.au>
 *  Copyright (c) 2005-2011 Sam Hocevar <sam@hocevar.net>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software Foundation,
 *  Inc., 51 Franklin Street, Fifth Floor, Boston MA 02110-1301, USA.
 */

#if defined HAVE_CONFIG_H
#   include "config.h"
#endif

#include <SDL.h>
#include "joy.h"

/* NOTE: No joystick support yet.
 */

SDL_Joystick *joystick = NULL;

int joy_init(int argc, char **argv) {
	/* Do Nothing */
	if (!SDL_WasInit(SDL_INIT_JOYSTICK))
		SDL_Init(SDL_INIT_JOYSTICK);

	if (SDL_NumJoysticks() > 0)
	{
		joystick = SDL_JoystickOpen(0);
	}

	return joystick>0;
}

int prev_x, prev_y;
void joy_poll(int &x, int &y)
{
	if (!joystick) return;

	SDL_JoystickUpdate();
	int tx = SDL_JoystickGetAxis(joystick, 0), ty = SDL_JoystickGetAxis(joystick, 1);

	if ((abs(ty) > 1200) || (abs(tx) > 1200))
	{
		prev_x = x = tx;
		prev_y = y = ty;
	}
	else
	{
		x = prev_x;
		y = prev_y;
	}
}

int joy_exists(){
	return joystick > 0;
}

void joy_status(int &b1, int &b2, int &b3, int &xv, int &yv) {
	/* Do Nothing */
}

void joy_calibrate() {
	/* Do Nothing */
}
