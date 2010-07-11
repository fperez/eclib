// FILE HOMTEST.CC: Test program for homspace class
//////////////////////////////////////////////////////////////////////////
//
// Copyright 1990-2007 John Cremona
// 
// This file is part of the mwrank/g0n package.
// 
// mwrank is free software; you can redistribute it and/or modify it
// under the terms of the GNU General Public License as published by the
// Free Software Foundation; either version 2 of the License, or (at your
// option) any later version.
// 
// mwrank is distributed in the hope that it will be useful, but WITHOUT
// ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
// FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
// for more details.
// 
// You should have received a copy of the GNU General Public License
// along with mwrank; if not, write to the Free Software Foundation,
// Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
// 
//////////////////////////////////////////////////////////////////////////
//
#include "moddata.h"
#include "symb.h"
#include "cusp.h"
#include "homspace.h"
#include "timer.h"

#define AUTOLOOP

int main(void)
{
  init_time();
 int n=1; 
 int plus=1;
 int verbose=0;
 int cuspidal=0;
 long *dims = new long[3];
 // cout << "Verbose? "; cin >> verbose;
 // cout << "Plus space, minus space or full space (+1,-1,0)? "; cin >> plus;
 int limit; 
#ifdef AUTOLOOP
  cout<<"Enter first and last levels: ";cin>>n>>limit; n--;
  while (n<limit) { n++;
#else
  while (n>0) { cout<<"Enter level: "; cin>>n;
#endif
 if (n>0)
{
  //  start_time();
  {
    cout << "\n>>>Level " << n << "\n";
    for (plus=1; plus>-2; plus--)
      {
	homspace hplus(n,plus, cuspidal,verbose);
	int dim = hplus.h1dim();
	dims[plus+1]=dim;
	cout << "\t\tDimension (sign="<<plus<<") = " << dim << "\t";
	int d = hplus.h1denom();
	if(d>1) cout<<" (denom = "<<d<<")";
	cout<<endl;
      }
    if (dims[1]==dims[0]+dims[2])
      cout<<"\tDimensions add up OK at level "<<n<<endl;
    else
      cout<<"****************Dimensions inconsistent for level "<<n<<" ***************"<<endl;
  }
  cout<<endl;
  //  stop_time();
  //  show_time();
}       // end of if(n)
}       // end of while()
  delete[] dims;
}       // end of main()
