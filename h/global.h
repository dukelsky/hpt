/*****************************************************************************
 * HPT --- FTN NetMail/EchoMail Tosser
 *****************************************************************************
 * Copyright (C) 1997-1999
 *
 * Matthias Tichy
 *
 * Fido:     2:2433/1245 2:2433/1247 2:2432/605.14
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
#ifndef GLOBAL_H
#define GLOBAL_H

#include <fidoconf/typesize.h>
#include <fidoconf/fidoconf.h>
#include <fidoconf/log.h>

extern int initSMAPI;

// variables for config statements

extern s_fidoconfig *config;
extern char         *cfgFile;

// vriable for current tossing dir
extern char *tossDir;

// var for linkAreas() argument
extern char *linkName;

// buffer for msg->text
extern UCHAR *globalBuffer;

// variables for commandline statements

extern int       cmToss;
extern int       cmScan;
extern int       cmPack;
extern int       cmLink;
extern int       cmAfix;
extern int       cmPause;
extern int       noHighWaters;
extern int       pkt_count; // pkt counter
extern int       pkt_aTime;
extern int	 quiet;

extern s_addr afixAddr;
extern char *afixCmd;

extern int lock_fd;
extern char *_lockfile;

extern unsigned long getfree (char *path);

#endif
