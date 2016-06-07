# SDL_Hub

An orgnised group of folders, to make it simpler to setup an SDL software rendering enviornment up.

To use you need to have the SDL2.framework in your computers framwork lookup directory. (This is for mac)

Download the mac SDL framework from:
https://libsdl.org/download-2.0.php

The make file uses -framwork, which searches in your framework folders (Static link)
Follow instructions in the download link and put it in your framwork folder:

/Library/Frameworks/
or
~/Library/Frameworks/


Example projects

#Drawing:
A very simple 20 line drawing script.

#Moving_Boxes:
A simple dragging boxes around using the alpha byte of to detect button presses.

#Vector_moving_boxes
Using rects for box click detection
