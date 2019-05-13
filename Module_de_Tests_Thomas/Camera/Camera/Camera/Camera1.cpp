#include "Camera1.h"



using namespace cv;

Camera1::Camera1(std::string DestImage)
{
	etat = false;
	Connexion();
	if (avc.isOpened())
	{
		PrendrePhoto(DestImage);
	}
	else
	{
		MessageBox(NULL,L"L'Image n'a pas pu être prise , la connexion à la caméra n'a pas eue lieu.",L"Erreur liée à la caméra", 16);
	}

}


Camera1::~Camera1()
{
	avc.release();
	cv::destroyAllWindows();
}


void Camera1::Connexion()
{
	avc.open(0);
}
void Camera1::PrendrePhoto(std::string DestImage)
{
	avc >> img;
	imwrite(DestImage, img);
	etat = true;
	ImagePrise = DestImage;
}
bool Camera1::IsimagePrise()
{
	return etat;
}
std::string Camera1::GetImagePrise()
{
	return ImagePrise;
}


