/*:ts=8*/
/*****************************************************************************
 * HPT --- FTN NetMail/EchoMail Tosser
 *****************************************************************************
 * Copyright (C) 1997-1998
 *
 * Matthias Tichy
 *
 * Fido:     2:2433/1245 2:2433/1247 2:2432/601.29
 * Internet: mtt@tichy.de
 *
 * Grimmestr. 12         Buchholzer Weg 4
 * 33098 Paderborn       40472 Duesseldorf
 * Germany               Germany
 *
 * This file is part of HPT.
 *
 * HPT is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2, or (at your option) any
 * later version.
 *
 * HPT is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with HPT; see the file COPYING.  If not, write to the Free
 * Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.
 *****************************************************************************/
#ifndef _FCOMMON_H
#define _FCOMMON_H

#include <typesize.h>
#include <stdio.h>
#include <common.h>

#include <fidoconfig.h>


enum prio {CRASH, HOLD, NORMAL};
enum type {PKT, REQUEST, FLOFILE};
typedef enum prio e_prio;
typedef enum type e_type;

/* common functions */

e_prio cvtFlavour2Prio(e_flavour flavour);
/*DOC
  Input:  a fidoconfig flavour
  Output: a hpt prio
  FZ:     obvious
*/
  
int   createTempPktFileName(s_link *link);
/*DOC
  Input:  a pointer to a link structure
  Output: 0 is returned if a filename and a packedfilename could be created.
          1 else
  FZ:     createTempPktFile tries to compose a new, not used pktfilename.
          It takes the least 24bit of the actual time. The last 2 Bytes
          area filled with a counter. So you can get up to 256 different files
          in a second and have the same timestamp only every 291 days.
          The pktFileName and the packFileName are stored in the link
          structure
*/

int    createDirectoryTree(const char *pathName);
/*DOC
  Input:  a pointer to a  \0 terminated string
  Output: 0 if successfull, 1 else
  FZ:     pathName is a correct directory name
          createDirectoryTree creates the directory and all parental directories
          if they do not exist.
*/
  
char   *createOutboundFileName(s_addr aka, e_prio prio, e_type typ);
/*DOC
  Input:  aka is the addr whose OutboundFileName should be created.
          prio is some kind of CRASH, HOLD, NORMAL
          typ is some kind of PKT, REQUEST, FLOFILE
  Output: a pointer to a char is returned.
  FZ:     if the fileName could not be created NULL is returned, else the pointer to the fileName.
          Remember to free it.
          If you specify PKT a *.?UT is created.
          If you specify REQUEST a *.REQ is created.
          IF you specify FLOFILE a *.?LO is created.
          if the directory parents of the filename does not exist, they will be
          created.
*/
#endif
