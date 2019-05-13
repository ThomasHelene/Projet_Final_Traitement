#include "Camera.h"

#include <opencv2/opencv.hpp>

using namespace cv;

Cam::Camera(std::string DestImage)
{
	etat = false;
	Connexion();
	if (avc.isOpened())
	{
		PrendrePhoto(DestImage);
	}
	
}


Cam::~Camera()
{
	avc.release();
	cv::destroyAllWindows();
}


void Cam::Connexion()
{
	avc.open(0);
}
void Cam::PrendrePhoto(std::string DestImage)
{
	avc >> img;
	DestImage += "ImageAcquise.jpg";
	imwrite(DestImage, img);
	etat = true;
	ImagePrise = DestImage;
}
bool Cam::IsimagePrise()
{
	return etat;
}
std::string Cam::GetImagePrise()
{
	return ImagePrise;
}

