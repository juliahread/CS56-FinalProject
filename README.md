# CS56-FinalProject
## Disaster at the 5Cs in 2200
![alttext](https://github.com/juliahread/CS56-FinalProject/blob/master/images/title.PNG "Disaster at the 5Cs in 2200")

This game was developed by Sean Costello, Owen Gillespie, Janice Lee, and Julia Read for CS056 (Object-Oriented Game Development) Spring 2019. Special thanks to Professor Saleem for helping us along the way!

## Description and Controls
### Backstory
It's the year 2200, and the Claremont Colleges have successfully migrated to space... But over-enrollment in CS 5 at HMC has caused a singularity to form, and the Claremont Colleges have been destroyed! Now you are floating in the depths of space... Armed with a grappling hook, a jetpack, and your knowledge of zero-gravity physics, you must reach the Campus Safety vehicle before the time runs out in order to survive. Good luck!
### Controls
+ Left Click - shoot the grappling hook
+ Right Click - detach the grappling hook
+ WASD - control the jetpack
+ ![alttext](https://github.com/juliahread/CS56-FinalProject/blob/master/images/apple.png "Fuel") - additional fuel
+ ![alttext](https://github.com/juliahread/CS56-FinalProject/blob/master/images/oldenborg_smaller.png "Oldenborg Fuel Depot") - fuel depot
+ ![alttext](https://github.com/juliahread/CS56-FinalProject/blob/master/images/end_smaller.png) - Campus Safety vehicle

![alttext](https://github.com/juliahread/CS56-FinalProject/blob/master/images/controls.PNG "Description and Controls")

## Compilation Instructions
### On Linux
You will need the following libraries: ```SDL2, SDL2_Image, SDL2_TTF, and SDL2_Mixer```.
To install, run 
```
#install sdl2
sudo apt-get install libsdl2-dev libsdl2-2.0-0 -y

#install sdl image
sudo apt-get install libjpeg9-dev libwebp-dev libtiff5-dev libsdl2-image-dev libsdl2-image-2.0-0 -y

#install sdl true type fonts
sudo apt-get install libfreetype6-dev libsdl2-ttf-dev libsdl2-ttf-2.0-0 -y

#install sdl mixer
sudo apt-get install libmikmod-dev libfishsound1-dev libsmpeg-dev liboggz2-dev libflac-dev libfluidsynth-dev libsdl2-mixer-dev libsdl2-mixer-2.0-0 -y
```
Credits to [this](https://gist.github.com/BoredBored/3187339a99f7786c25075d4d9c80fad5)

