/*
	Copyright 1998-2003 Interplay Entertainment Corp.  All rights reserved.
*/

#ifndef REDMENT_H
#define REDMENT_H

#define MVAR_Molerat_Count                  (0)
#define MVAR_Deathclaw_Egg_Count            (1)
#define MVAR_Deathclaw_Count                (2)
#define MVAR_Rat_Fighter1                   (3)
#define MVAR_Rat_Fighter2                   (4)
#define MVAR_Bar_Brawl                      (5)
#define MVAR_Ferndown                       (8)
#define MVAR_Nording                        (9)
#define MVAR_Velani                         (10)


// States for Bar Brawl
#define BRAWL_NONE                          (0)
#ifndef BRAWL_NEITHER_JAILED
   #define BRAWL_NEITHER_JAILED             (1)
#endif
#ifndef BRAWL_MORNINGSTAR_JAILED
   #define BRAWL_MORNINGSTAR_JAILED         (2)
#endif
#ifndef BRAWL_KOKOWEEF_JAILED
   #define BRAWL_KOKOWEEF_JAILED            (3)
#endif
#ifndef BRAWL_BOTH_JAILED
   #define BRAWL_BOTH_JAILED                (4)
#endif
#ifndef BRAWL_KILLED
   #define BRAWL_KILLED                     (5)
#endif

#endif // REDMENT_H
