/**
 * Marlin 3D Printer Firmware
 * Copyright (c) 2020 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (c) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */
#pragma once

/**
 * Standard Marlin Boot Screen bitmaps
 *
 * Use the Marlin Bitmap Converter to make your own:
 * http://marlinfw.org/tools/u8glib/converter.html
 */

#include "../../inc/MarlinConfig.h"

#if ENABLED(SHOW_CUSTOM_BOOTSCREEN)

  #include "../../../_Bootscreen.h"

  #ifndef CUSTOM_BOOTSCREEN_BMP_BYTEWIDTH
    #define CUSTOM_BOOTSCREEN_BMP_BYTEWIDTH CEILING(CUSTOM_BOOTSCREEN_BMPWIDTH, 8)
  #endif
  #ifndef CUSTOM_BOOTSCREEN_BMPHEIGHT
    #define CUSTOM_BOOTSCREEN_BMPHEIGHT (sizeof(custom_start_bmp) / (CUSTOM_BOOTSCREEN_BMP_BYTEWIDTH))
  #endif

#endif


#ifndef EAGLE_CONFIG
  #define EAGLE_CONFIG
#endif

#ifdef EAGLE_CONFIG
	#ifdef BOOT_MARLIN_LOGO_SMALL
	  #undef BOOT_MARLIN_LOGO_SMALL
	#endif
	#ifdef BOOT_MARLIN_LOGO_ANIMATED
	  #undef BOOT_MARLIN_LOGO_ANIMATED
	#endif
#endif


#if ENABLED(BOOT_MARLIN_LOGO_SMALL)

  #include "dogm_Bootscreen_logo_small.h"

#else

  #ifndef EAGLE_CONFIG
    #include "dogm_Bootscreen_logo_big.h"
  #endif
  #ifdef EAGLE_CONFIG
    #include "dogm_Bootscreen_Eagle_logo_big.h"
  #endif

#endif

#if ENABLED(BOOT_MARLIN_LOGO_ANIMATED)
  #ifndef MARLIN_BOOTSCREEN_FRAME_TIME
    #define MARLIN_BOOTSCREEN_FRAME_TIME 100 // (ms)
  #endif
  const unsigned char * const marlin_bootscreen_animation[] PROGMEM = {
    start_bmp1, start_bmp2, start_bmp3, start_bmp4, start_bmp5, start_bmp6, start_bmp
  };
#endif

#ifndef START_BMP_BYTEWIDTH
  #define START_BMP_BYTEWIDTH CEILING(START_BMPWIDTH, 8)
#endif
#ifndef START_BMPHEIGHT
  #define START_BMPHEIGHT (sizeof(start_bmp) / (START_BMP_BYTEWIDTH))
#endif

static_assert(sizeof(start_bmp) == (START_BMP_BYTEWIDTH) * (START_BMPHEIGHT), "Bootscreen (start_bmp) dimensions don't match data.");
