# pooler
modding poolians

# Changing background textures
theres 3 ways to go about doing this:
  ## 1.
      download pooler.exe

  ## 2.
      download main.py and run that if you have python installed

  ## 3.
      if you have another way of xoring things then go for it but i made main.py and pooler.exe for convenience.

once you have either pooler.exe, main.py or some other method, go to "C:\Program Files (x86)\Steam\steamapps\common\Real Pool 3D" (or on steam, go to poolians in your library -> click the gear -> manage -> browse local files) then go to the "RealPool3D" folder then to the "3d" folder. inside you will see 2 .pak files:
  ## common.pak
  ## room1.pak

we only care about room1.pak here.
copy room1.pak to the same place where you have pooler.exe or main.py. once copied, run the program and as the input, put room1.pak and as the output you can put whatever you want (as long as its a .zip), but for the sake of niceness, lets say room1.zip.
once you have room1.zip created from the program, right click it then click extract. hooray! we now have access to all of the textures inside room1!
you are now free to replace any of these textures with whatever you want, but (afaik) they have to be the same filetype (extension (.png, .bmp, .jpg, etc.)).

## Repacking
once you are satisfied with the new textures you have, you need to get it back to the .pak file. to do this, select everything inside the folder (in our case room1), and right click -> send to -> compressed zip.
drag that zip back to where you have pooler.exe or main.py and run the program again, but this time make the input file be whatever the name of the zip file you created is, and the output can be whatever name you want but it MUST have the .pak extension. in this example lets call it room2.pak.
now we want to move our room2.pak back to where we initially got room1.pak ("C:\Program Files (x86)\Steam\steamapps\common\Real Pool 3D\RealPool3D\3d\"), and place it there. if you still have room1.pak in there, you can just delete it. then make sure to rename room2.pak to room1.pak

## Done!
thats it! you should now be able to open the game and enjoy your brand new textures in-game!



# Using your own room model
this part can be more complicated. in order to do this, you need to have blender installed. since this part has just SOOOOOOO many steps, just check out this repo:
https://github.com/OGRECave/blender2ogre

it goes much more in depth and can actually explain how to do things correctly (i suck at explaining things)
note: you get the .mesh files from the .pak files.



# Misc
funny thing you can do with the game:
  if you go back to "C:\Program Files (x86)\Steam\steamapps\common\Real Pool 3D" and put a picture in there (extension doesnt matter) and name it just 'none' (without quotes), it does some funny stuff to the game and i dont know why.
