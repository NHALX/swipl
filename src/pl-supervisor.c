/*  $Id$

    Part of SWI-Prolog

    Author:        Jan Wielemaker
    E-mail:        wielemak@science.uva.nl
    WWW:           http://www.swi-prolog.org
    Copyright (C): 1985-2006, University of Amsterdam

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

#include "pl-incl.h"

int
createForeignSupervisor(Definition def, Func f)
{ assert(true(def, FOREIGN));
  
  if ( false(def, P_VARARG) )
  { if ( false(def, NONDETERMINISTIC) )
    { Code codes = PL_malloc(sizeof(code)*5);
      
      *codes++ = (code)4;		/* code-size */
      codes[0] = encode(I_FOPEN);
      codes[1] = encode(I_FCALLDET0+def->functor->arity);
      codes[2] = (code)f;
      codes[3] = encode(I_FEXITDET);

      def->codes = codes;
    }
  }

  succeed;
}
