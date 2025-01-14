/*  Part of SWI-Prolog

    Author:        Jan Wielemaker and Anjo Anjewierden
    E-mail:        J.Wielemaker@cs.vu.nl
    WWW:           http://www.swi-prolog.org
    Copyright (c)  2004-2020, University of Amsterdam
                              VU University Amsterdam
    All rights reserved.

    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions
    are met:

    1. Redistributions of source code must retain the above copyright
       notice, this list of conditions and the following disclaimer.

    2. Redistributions in binary form must reproduce the above copyright
       notice, this list of conditions and the following disclaimer in
       the documentation and/or other materials provided with the
       distribution.

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
    "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
    LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
    FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
    COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
    INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
    BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
    LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
    CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
    LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
    ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
    POSSIBILITY OF SUCH DAMAGE.
*/

#include "pl-incl.h"

#ifndef _PL_GVAR_H
#define _PL_GVAR_H

#if USE_LD_MACROS
#define	freezeGlobal(_)		LDFUNC(freezeGlobal, _)
#define	gvar_value(name, p)	LDFUNC(gvar_value, name, p)
#define setval(var, value, backtrackable) LDFUNC(setval, var, value, backtrackable)
#define getval(var, value, raise_error) LDFUNC(getval, var, value, raise_error)
#endif /*USE_LD_MACROS*/

#define LDFUNC_DECLARATIONS

void	destroyGlobalVars(void);
void	freezeGlobal(void);
int	gvar_value(atom_t name, Word p);

int getval(term_t var, term_t value, int raise_error);
int setval(term_t var, term_t value, int backtrackable);

#undef LDFUNC_DECLARATIONS

#endif /*_PL_GVAR_H*/
