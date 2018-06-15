//
//  main.cpp
//  LTM-Converter
//
//  Created by Gabriel Dittrick on 15/05/2018.
//  Copyright © 2018 LTM. All rights reserved.
//


#include "opencv2/highgui.hpp"
#include <iostream>
#include <fstream>

using namespace std;
using namespace cv;



static void help()
{
    cout << "\n This engine is part of the LTM microexpressions analysis project.\n With the engine you can annotate a video with the related micro-exressions (from the video .txt file). It will result in a new video in output with details about the micro expression\n\n"
    "Usage:\n"
    "./LTM-Engine [--inputname=<input video filename> this is the video you want to analyse] = mandatory\n"
    "             [--outputname=<output video filename> this is the path of the video you want to write] = optional (if not chosen the video will be writen to 'OUT'+inputname\n"
    "             [--color=<integer between 0 and 7> to choose the color in which to show the ME] = optional\n"
    "             [--livedisplay= to choose whether to show the video while its being processed] = optional\n"
    "During execution:\n\tHit any key to quit.\n"
    "\n"
    "\tUsing OpenCV version " << CV_VERSION << "\n" << endl;
}


int main(int argc, const char * argv[]) {
    void    ofSetDataPathRoot( string root );
    
    double t = 0;
    t = (double)getTickCount();
    
    
    VideoCapture capture;
    Mat frame, image;
    string inputName;
    string outputName;
    double fps;
    bool display;
    
    cv::CommandLineParser parser(argc, argv,
                                 "{help h||}"
                                 "{inputname|EP01_5.avi|}"
                                 "{outputname||}"
                                 "{livedisplay|false|}");
    
    if (parser.has("help"))
    {
        help();
        return 0;
    }
    
    
    inputName = parser.get<string>("inputname");
    outputName = parser.get<string>("outputname");
    display = parser.get<bool>("livedisplay");
    
    cout << "input name : " << inputName << endl << "given output name : " + outputName << endl;
    
    
    if (outputName == "")
    {
        outputName = "CONVERT"+inputName;
        outputName.pop_back();
        outputName.pop_back();
        outputName.pop_back();
        outputName.pop_back();
        outputName.append(".mp4");
    }
    
    cout << "output name : " + outputName << endl;
    
    capture.open(inputName);
    capture >> frame;
    
    fps = capture.get(CAP_PROP_FPS);
    
    
    // Check if camera opened successfully
    if(!capture.isOpened())
    {
        cout << "Error opening video stream" << endl;
        return -1;
    }
    
    
    int frame_width = frame.cols;
    int frame_height = frame.rows;
    int len = capture.get(CAP_PROP_FRAME_COUNT);
    cout << "video has " << len << " frames" << endl;
    
    
    VideoWriter video(outputName,CV_FOURCC('M','J','P','G'),fps, Size(frame_width,frame_height));
    
    video.write(frame);
    

    vector<cv :: Point> points;
    
    cout << "Video capturing has been started ..." << endl;
    
    for(int i = 0; i < len ;i++)
    {
        
        capture >> frame;
        if( frame.empty() )
            break;
        

        //if (display == true){imshow( "result", frame );}
        video.write(frame);        // Write the frame into the file "outputName"
        
        //char c = (char)waitKey(5); //why 10 ?
        
        //if( c == 27 || c == 'q' || c == 'Q' ) // ?
        //    break;
    }
    capture.release();
    video.release();
    t = (double)getTickCount() - t;
    printf( "conversion time = %g s\n", t/getTickFrequency());
    
    // Closes all the windows
    destroyAllWindows();
    
    
    return 0;
}



