/*
 * rmw.h
 *
 * This file is part of rmw (https://github.com/andy5995/rmw/wiki)
 *
 * Copyright (C) 2012-2016  Andy Alt (andy400-dev@yahoo.com)
 * Other authors: https://github.com/andy5995/rmw/blob/master/AUTHORS.md
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 *
 *
 */

#ifndef INC_RMW_H
#define INC_RMW_H

/* Enable support for files over 2G  */
#define _FILE_OFFSET_BITS 64

#include "config.h"
#include <errno.h>
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <locale.h>
#include "gettext.h"

#define _(String) gettext (String)
#define gettext_noop(String) String
#define N_(String) gettext_noop (String)

#ifndef VERSION
#define VERSION "0.4.01-pre3"
#endif

#define DEBUG 0

#ifndef SYSCONFDIR
#define SYSCONFDIR "/usr/local/etc"
#endif

/* DATA_DIR is relative to $HOME */
#ifndef DATA_DIR
  #ifndef WIN32
    #define DATA_DIR "/.config/rmw"
  #else
    #define DATA_DIR "/rmw"
  #endif
#endif

#define CFG_FILE DATA_DIR"/config"
#define UNDO_FILE DATA_DIR"/lastrmw"
#define PURGE_DAY_FILE DATA_DIR"/lastpurge"

/* Set a sane limit on maximum number of Waste dirs */
/* This will provide 16 MAX, and 1 extra that will be "NULL" */
#define WASTENUM_MAX 17

/**
 * How many folder can be set for "protection" in rmwrc
 */
#define PROTECT_MAX 32

#define DOT_TRASHINFO ".trashinfo"

#define START_WASTE_COUNTER -1

#ifndef PATH_MAX /* for portability */
#define PATH_MAX 256
#endif

/** shorten PATH_MAX to two characters */
#define MP PATH_MAX + 1

#ifndef ushort
  #define ushort unsigned short int
#endif

struct waste_containers
{
  char parent[MP];
  char info[MP];
  char files[MP];

  int dev_num;
};

struct rmw_target
{
  char main_argv[MP];
  char real_path[MP];
  char base_name[MP];
  char dest_name[MP];

  bool is_duplicate;
};

bool verbose;

/**
 * Exit Codes
 */

#define EXIT_FAILED_GETENV 2
#define NO_WASTE_FOLDER -1
#define EXIT_BUF_ERR 1
#define EXIT_MALLOC 3
#define EXIT_OPENDIR_FAILURE 4

#endif
