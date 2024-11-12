Installation :
-------------

1) Copy the "BIS mapper" folder anywhere you want

2) Open mapper2.cfg with any notepad and change all the "..." into your own path (for example : C:\games\Fallout2\) :
   - 49 : music_path1=...data\sound\music\
   - 50 : music_path2=...data\sound\music\
   - 62 : critter_dat=...critter.dat
   - 63 : critter_patches=...data
   - 70 : master_dat=...master.dat
   - 71 : master_patches=...data
   (The numbers are the line number)

3) Open m2_res with any notepad and change 640 and 480 (the default resolution) to the resolution you want :
   SCR_WIDTH=640
   SCR_HEIGHT=480

4) Now I suggest you check the "Updated source codes" folder and copy past the 1.02d codes in the BIS mapper\scripts folder (overwrite)

5) If you are further developing Killap's restoration project (2.3.3) : similarly copy past his codes and overwrite


NB : check the "Documents" folder and essentially the *amazing* "Compiled arts by Pixote" and the "Mapper keys 1.6 by Red!" if you want to be more productive

NB : you don't necessarily need the "Installer & patchers" folder : it's only here if you'd want to install the mapper yourself :
1) Run BIS mapper installer
2) Patch the mapper with the F49+ city limit patch (don't patch fallout2.exe if you installed the RP or the Megamod)
3) Run Mapper2_High_Resolution_Patch_3.0.2 (put everything in the mapper folder) and then run m2_res_patcher
4) Make the adjustments to mapper2.cfg and m2_res