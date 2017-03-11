#ifndef DICOM_READER_H
#define DICOM_READER_H

#include "image.h"
#include <cv.h>
#include <core.hpp>
#include <opencv2\opencv.hpp>
#include <iostream>
#include <read_dicom.h>
#include <highgui.h>

class DicomReader
{
private:

public:
	Image *read(const char *s);
	DicomReader();
};

#endif // !DICOM_READER




