#ifndef IMAGE_H
#define IMAGE_H

#include <cv.h>
#include <iostream>

class Image
{
private:
	int *imageData, row, column;
public:
	Image(int, int, int*);
	~Image();
	int getPixelAt(int,int);
	cv::Mat getCvMat();
};

#endif

