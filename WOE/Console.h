#ifndef WOE_CONSOLE_H
#define WOE_CONSOLE_H

#include "Defines.h"

#if defined(_WOE_WINDOWS)

#include <windows.h>

#include <stdio.h>
#include <fcntl.h>
#include <io.h>
#include <iostream>
#include <fstream>

using std::string;
using std::ios;

static const WORD MAX_CONSOLE_LINES = 500;

void initConsole( void );

#elif defined(_WOE_LINUX)

void initConsole( void ) { }

#endif

#endif // WOE_CONSOLE_H