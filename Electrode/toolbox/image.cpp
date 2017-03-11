#include "image.h"


Image::Image(int row, int column, int *img){
	this->row = row;
	this->column = column;
	imageData = new int[row*column];
	for (auto i = 0; i != row*column; i++){
		imageData[i] = img[i];
	}
	std::cout << "Created image, the row is " << row << " the column is " << column << std::endl;
}

Image::~Image(){
	std::cout << "destructing image" << std::endl;
	delete(imageData);
}


int Image::getPixelAt(int i, int j){
	return imageData[i * row + j];
}

cv::Mat Image::getCvMat(){
	CvSize cvsize; cvsize.height = row; cvsize.width = column;
	IplImage *img = cvCreateImage(cvsize, IPL_DEPTH_8U, 1);
	std::cout << "Converting image to cvArray..." << std::endl;
	for (int i = 0; i < row * column; i++){
		img->imageData[i] = static_cast<uchar>(static_cast<double>(imageData[i] + 1024) / 4096 * 256);
	}
	std::cout << "Converting cvArray to Mat" << std::endl;
	cv::Mat mat = cv::cvarrToMat(img);
	//delete(img);						memory leakage??
	return mat;
}