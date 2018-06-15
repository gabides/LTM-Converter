# LTM-Converter

C++ application for micro-expressions detection and recognition with graphical interface (video player). This engine is the video editing part of the app (displays the ME at the right place and time in the video, with annotations). OpenCV is necessary to run the app.

 This converter is part of the LTM microexpressions analysis project.
 It allows you to change the video encoding.

The interface is being implemented for OSX with Swift language in another project ([LTM-interface](https://github.com/gabides/LTM-Interface-cocoa/)).
The engine to annotate videos (augmented video) is ([LTM-Engine](https://github.com/gabides/LTM-Engine/)).


Usage:  
./LTM-Engine  
[--inputname={input video filename} this is the video you want to analyse] = mandatory  
[--outputname={output video filename} this is the path of the video you want to write] = mandatory

During execution:
Hit any key to quit.

This app was developped using OpenCV version 3.4.1


ME = micro-expression


Year-long project with Louis Lenief at CentraleSupélec (2018) and the Facial Analysis Synthesis and Tracking ([FAST](http://www.rennes.supelec.fr/ren/rd/fast/fast_accueil.php)) research team.

