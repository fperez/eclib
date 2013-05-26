// timer.cc:  implementations of timer functions
//////////////////////////////////////////////////////////////////////////
//
// Copyright 1990-2012 John Cremona
// 
// This file is part of the eclib package.
// 
// eclib is free software; you can redistribute it and/or modify it
// under the terms of the GNU General Public License as published by the
// Free Software Foundation; either version 2 of the License, or (at your
// option) any later version.
// 
// eclib is distributed in the hope that it will be useful, but WITHOUT
// ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
// FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
// for more details.
// 
// You should have received a copy of the GNU General Public License
// along with eclib; if not, write to the Free Software Foundation,
// Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA
// 
//////////////////////////////////////////////////////////////////////////
 
#include <iostream>
#include <iomanip>
#include <eclib/interface.h>
#include <eclib/timer.h>

#ifndef CLK_TCK
#define CLK_TCK	CLOCKS_PER_SEC
#endif

double starttime,stoptime;
void init_time() { ;}
void start_time() { starttime = GetTime();}
void stop_time()  { stoptime  = GetTime();}
void show_time(ostream& s) 
{
  s<<" ("<<(stoptime-starttime)<<" seconds)" << flush; 
}
