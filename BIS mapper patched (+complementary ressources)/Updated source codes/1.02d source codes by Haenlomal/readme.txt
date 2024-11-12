Updated Official Mapper Scripts ReadMe
--------------------------------------

Contents

1.0   SUMMARY
2.0   INSTALLATION
3.0   SPECIAL NOTES
4.0   LIST OF EXCEPTIONS
      4.1 Changed party_size
      4.2 Primitive Headers
      4.3 Misc
5.0   ACKNOWLEDGEMENTS AND CONTACT INFO


1.0   SUMMARY
-------------

(Note: by "bytecode", I mean the compiled *.int files found under the
Scripts directory of both the MASTER.DAT and PATCH000.DAT files.  I
will be using this term throughout the rest of this document.)

The following script and header files have been updated to produce
v1.02D bytecodes.  If you compile the scripts included in this
package, they WILL procduce v1.02D bytecode.  I have personally
compiled each and every single script to confirm this.  The binary
match is EXACTLY the same as those found in PATCH000.DAT.  (Use the
Windows "fc" command with the "/B" option if you want to verify this
for yourself.)  These files are as close as you are going to get to
the actual files that Black Isle used for the v1.02D patch.

On top of that, I've optimized the header files so that they are now
100% compatible with the Visual C++ preprocessor.  Both the Watcom and
VC++ pre-processor should now produce the same bytecode. (I prefer the
VC++ pre-processor because it actually gives more informative error
messages that points to the presence of bugs -- bugs that might
otherwise be missed using the Watcom pre-processor.)

Finally, it is well known that a few scripts (particularly those from
the Den) fail to compile to even v1.0 bytecodes.  While this is
irrelevant if there exists a v1.02D equivalent, it is still a problem
if the script was never patched.  In such cases, I have fixed up the
problematic scripts so that they will produce the correct v1.0 bytecode.

It is my hope that by creating such a baseline, it will become easier
for people to create their own mods, with full confidence that all the
bug fixes that Black Isle has put in their scripts will be fully
incorporated with their changes.  Have fun, and happy modding!

-- The Haen.


2.0   INSTALLATION
------------------

Installation is easy.

1) Backup your scripts.
2) Extract files from the self-extracting ACE archive to a temp
   directory
3) Overwrite the appropriate files in your scripts directory with
   the updated files.
4) Enjoy!


3.0   SPECIAL NOTES
-------------------

1) In re-creating the v1.02D version of some of these scripts, I had
to make educated guesses to certain variable names or define names,
since the bytecode of course didn't store the names of local variables
or #define macros.  These names should be easily understandable, and
at any rate do not change the functionality of the scripts.

2) If there is a bug in the v1.02D version of a script, then the bug
will be found in my scripts as well.  Why?  Because I was trying to
make exact binary copies of the compiled scripts, not making bugfixes.
Rather, I was just creating a "baseline" so that everyone has same
thing to work from with using v1.02D scripts as their starting point.
Fixing bugs is entirely up to you.

3) I have also taken care to make sure that the rest of the scripts
(i.e. v1.0 scripts that were not updated in the patch) still compiles
properly (i.e. produce the v1.0 bytecode found in MASTER.DAT).  For
the vast majority of v1.0 files, they compile properly even with my
changes in place -- a binary file comparison of the respective
bytecodes confirms this.  However, there are some exceptions, which
are noted in Section 4.0 below.


4.0   LIST OF EXCEPTIONS
------------------------

While all the script files in v1.02D have been accounted for, there
some v1.0 scripts that will no longer compile to their equivalent
bytecode found in MASTER.DAT.  There are 3 reasons for this:

1) Changes applied to the header files in order to compile 1.02
bytecodes made the script unable to compile to its 1.0 bytecode.
These scripts are mostly those from Navarro and the Enclave, and is
manifested as the "invisible 1 NPC only" bug (i.e. you can bring
1 NPC along with you, and the scripts in the area treat you as if
you were totally alone).  Read on for more details.

2) The script file that came with the Official Fallout 2 Mapper
never compiled properly to the 1.0 bytecode in the first place.  As
mentioned before, this applies mostly to some of the scripts for the
Den area.

3) Miscellaneous reasons:  Two scripts fall under this category,
and I'll address each one seperately.


4.1   Changed party_size
------------------------

In the header file PARTY.H, there is a macro named "party_size".
This macro called on a metarule function that does the actual
work of returning the total number of people in your party,
including yourself.  The metarule, however, also includes the
car in the count, if you have it.  Since for most scripts, you
obviously don't want to include the car in the count, the macro
"party_size" also took this into account, and subtracted the
car from the count if you own it.

In v1.02D of the Fallout engine, however, the metarule has been
updated to exclude the car in its count.  This meant that the
"party_size" macro no longer had to subtract the car from the
count.  And all v1.02D bytecodes found in PATCH000.DAT reflect
this change.  Theorectically, all scripts that referenced the
macro "party_size" should have been re-compiled and shipped out
with the v1.02D patch, but for some odd reason, quite a few were
missed.  This is the reason why you can walk around the Enclave
or Navarro with only 1 NPC companion without getting in trouble,
and why some doctors in the game will not heal your NPC if you
only had 1 NPC (excluding car) in your party.  This also means
that all the files I am about to list should probably be
re-compiled using my modified PARTY.H header file to eliminate
the bug. :)

Anyway, here is the list of scripts with this problem:

CCACON.SSL
CCATECH.SSL
CCCHRIS.SSL
CCCOMP1.SSL
CCCOMP2.SSL
CCCOOK.SSL
CCDOCTOR.SSL
CCDRILL.SSL
CCGGBAK.SSL
CCGGUARD.SSL
CCGRDCA.SSL
CCGRDPA.SSL
CCKEVIN.SSL
CCMANDR.SSL
CCMEDGRD.SSL
CCQMSTR.SSL
CCQUINCY.SSL
CCRAUL.SSL
CCTECH1.SSL
CCTECH2.SSL
DCSHEILA.SSL
FCFMATT.SSL
FCSKIDS.SSL
HCDOC.SSL
OCJUL.SSL
QCBIRD.SSL
QCCURLING.SSL
QCGENGRD.SSL
QCMURRAY.SSL
QCTURRET.SSL
RCJOSH.SSL
RCSAVINE.SSL
RCSTANWL.SSL
RCWADE.SSL
SCHAL.SSL
SCKARL.SSL
VCANDY.SSL
VCSKEEVE.SSL

Note that none of the above are included in the v1.02D patch.  If
you really want or need to compile v1.0 bytecodes for these scripts,
all you have to do is to substitute the "party_size" macro found in
my modified PARTY.H header with the "party_size" macro found in the
original PARTY.H header that you backed up (you DID do the backup
like I suggested, right? :)), and compile away.  But like I wrote
earlier, these files should probably have been patched but didn't
get patched for whatever reason, so you should do it yourself.


4.2   Primitive Headers
-----------------------

For the next set of scripts, there are major structural differences
between the bytecodes found in MASTER.DAT and those produced by the
official Fallout 2 Mapper, and the nature of these differences suggest
that the files that came in the MASTER.DAT file were compiled with
substantially different and more primitive (earlier) versions of the
header files that comes with the Official Mapper.  As a result, in
order to change these files enough to get them to compile "properly",
substantial changes would have to be applied to the existing header
files, which will in turn break "compilability" with the rest of the
scripts (i.e. other scripts won't compile the v1.0 or v1.02D bytecodes
anymore).

Fortunately, NONE (that's right, ZERO) of these scripts are used at
all in the game, so you can safely ignore them without any
consequences.  If you should decide to use them, making them work is
entirely up to you!

Here is the list:

COWBOMB.SSL
DCSLVRUN.SSL
DIBONES.SSL 
DIDIARY.SSL
DIFLKBOX.SSL
DISLVCRT.SSL
DIVICTBL.SSL


4.3   Misc
----------

There are two more files that do not successfully compile to their
v1.0 bytecode, but this is more an issue with the preprocessor being
used.  If you are using Watcom, you should have no problems with
these two scripts, but read on nonethesless for my comments.

********

### GCLUMPY.SSL ###

In this script, the variable "HOUSE" was defined two times: near
the beginning as "1", and about 70 lines further down as "2".
The Watcom pre-processor takes the ignore the second #define
statement, and so "HOUSE" retains the value of "1".  This is in
fact what is in the bytecode.

However, the VC++ preprocessor accepts the SECOND value (with a
warning message), so "HOUSE" becomes "2", and the compiled bytecode
differs from the original bytecode in two bytes, and both have a
value of "0x02" instead of "0x01".

It is here that the advantages of using the VC++ preprocessor
comes out, since I wouldn't have given this script a second glance
without the warning messages generated by the preprocessor.  When
you look at the rest of the script, the variable "HOUSE" *should*
have a value of "2" instead of "1", which is assigned to another
variable ("WORKSHOP").  But because both of them have the same
value, a potential branch of Lumpy's dialogue tree is never
accessed.

In the script I've included, I have commented out the second line
to keep consistency with the original bytecode:  both watcom and
VC++ preprocessors should yield the same results that lead to the
original bytecode.  However, if you are actually fixing bugs and
stuff, you should consider uncommenting the second define, and
commenting out the first define to fix the bug in this script.

***********

### VCMSMITH.SSL ###

Again, the issue here mainly with the VC++ preprocessor.  The
variable "PID_SMITH_COOL_ITEM" is defined as "(3)" near the very
beginning of this script.  But, it has been previously defined
as "(264)" in the header file ITEMPID.H.  Since everything else
points to latter value being correct, the fix to the script is
simply to comment out the define line near the beginning of the
script.

Not that it matters much: PID_SMITH_COOL_ITEM is never referenced
again in the rest of the script (Mr. Smith now give a Desert Eagle
as a reward, so the "cool item" part of the code was commented out),
so both preprocessors ultimately produce the correct bytecode
regardless of whether or not the fix is made.  In the interest of
keeping things ok for the VC++ preprocessor, I've made the fix.

***********


5.0   ACKNOWLEDGEMENTS AND CONTACT INFO
---------------------------------------

Acknowledgments: NOID's ruby decompiler really helped!  Saved me the
trouble of whipping up my own decompiler.  Without it, you would not
have these updated scripts...or you would have had them much, much
later. :)  Thanks, NOID!

Contact info:

Suggestions, comments, corrections?  Remove the "no_spam" below, and
e-mail me at:

no_spamhaen@no_spamgrex.org

All trademarks belong to their respective owners.  You can freely post
these files on the condition that this readme file is included and
proper credit is given...just be smart about it, and it'll be cool.
