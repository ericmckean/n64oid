/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *   Mupen64plus - r4300.h                                                 *
 *   Mupen64Plus homepage: http://code.google.com/p/mupen64plus/           *
 *   Copyright (C) 2002 Hacktarux                                          *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.          *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef R4300_H
#define R4300_H

#include "recomp.h"
#include "memory/tlb.h"

extern precomp_instr *PC;

extern precomp_block *blocks[0x100000], *actual;

extern int stop, llbit, rompause;
extern long long int reg[32], hi, lo;
extern long long int local_rs, local_rt;
extern unsigned int reg_cop0[32];
extern int local_rs32, local_rt32;
extern unsigned int jump_target;
extern double *reg_cop1_double[32];
extern float *reg_cop1_simple[32];
extern long long int reg_cop1_fgr_64[32];
extern int FCR0, FCR31;
extern tlb tlb_e[32];
extern unsigned int delay_slot, skip_jump, dyna_interp;
extern unsigned long long int debug_count;
extern unsigned int r4300emu;
extern unsigned int next_interupt, CIC_Chip;
extern int rounding_mode, trunc_mode, round_mode, ceil_mode, floor_mode;
extern unsigned int last_addr, interp_addr;
extern char invalid_code[0x100000];
extern unsigned int jump_to_address;
extern int no_compiled_jump;

void init_blocks();
void r4300_reset_hard();
void r4300_reset_soft();
void r4300_execute();
void pure_interpreter();
void compare_core();
void jump_to_func();
void update_count();
int check_cop1_unusable();
void shuffle_fpr_data(int oldStatus, int newStatus);
void set_fpr_pointers(int newStatus);

#define jump_to(a) { jump_to_address = a; jump_to_func(); }

// r4300 emulators
#define CORE_PURE_INTERPRETER 0
#define CORE_INTERPRETER      1
#define CORE_DYNAREC          2

// profiling

#define GFX_SECTION 1
#define AUDIO_SECTION 2
#define COMPILER_SECTION 3
#define IDLE_SECTION 4

#ifndef __WIN32__

//#define PROFILE

#ifdef PROFILE

void start_section(int section_type);
void end_section(int section_type);
void refresh_stat();

#else

#define start_section(a)
#define end_section(a)
#define refresh_stat()

#endif

#else

#define start_section(a)
#define end_section(a)
#define refresh_stat()

#endif

#endif

