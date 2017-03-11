#include "dicomReader.h"

using namespace std;


DicomReader::DicomReader(){
	cout << "Initializing Dicom reader... " << endl;
	if (!read_dicomInitialize()){
		throw runtime_error("Fail to initialize Dicom reader!");
	}
}

/**
* The method to read dicom files from hard disk
* 
* @arg1 : The dicom path in your hard disk
*/
Image *DicomReader::read(const char *path){
	cout << "Reading dicom files..." << std::endl;
	mwArray R(1, 1, mxINT32_CLASS);
	mwArray C(1, 1, mxINT32_CLASS);
	mwArray p(path);
	mwArray I(1000, 1000, mxINT16_CLASS); //Create a Matlab matrix to restore the dicom data, assert that the resolution of the dicom file is less than 1000*1000
	read_dicom(3, R, C, I, p);
	int r = R, c = C;
	int *G = new int[r*c+1];
	cout << "Getting data..." << endl;
	I.GetData(G, r*c);  //Save the data in Matlab matrix object to the array G
	Image *image = new Image(r, c, G);
	return image;
}