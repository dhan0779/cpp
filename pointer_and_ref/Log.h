// #pragma once //header guide, prevents including header files multiple times into a translation unit
#ifndef _LOG_H // if not defined, include it, otherwise don't -> but use pragma once
#define _LOG_H

void InitLog();
void Log(const char* message);

struct Player{}; //with no pragma once, we would have redefinition if we do #include "Log.h" twice

#endif