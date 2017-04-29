#ifndef __TERMIOS_CONTROL_H__
#define __TERMIOS_CONTROL_H__

#include <termios.h> //操作终端
#include <stdio.h>
#include <unistd.h>
#include <assert.h>
#include <string.h>

enum command
{
	UP,
	DOWN,
	LEFT,
	RIGHT,
	QUIT,
	INVALID
};

char my_getch(void);

enum command user_command(void);
#endif
