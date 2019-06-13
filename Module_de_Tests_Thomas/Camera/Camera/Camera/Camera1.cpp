#include "Camera1.h"



using namespace cv;

Camera1::Camera1(std::string DestImage,int type)
{
	etatAcq = false; // Etat de l'image prise réglée par défaut à false
	etatRef = false;
	Connexion();
	if (flux.isOpened()) // Vérifie si le flux vidéo a bien été ouvert
	{
		if (type == 1)
		{
			PrendrePhoto(DestImage);
		}
		if (type == 2)
		{
			AcquerirReference(DestImage);
		}
		
	}
	else
	{
		MessageBox(NULL,L"L'Image n'a pas pu être prise , la connexion à la caméra n'a pas eue lieu.",L"Erreur liée à la caméra", 16);
	}

}
Camera1::~Camera1()
{
	flux.release();
	cv::destroyAllWindows();
}
void Camera1::Connexion()
{
	flux.open(0); // Ouvre le flux vidéo de la caméra
}
void Camera1::PrendrePhoto(std::string DestImage)
{
	flux >> frame;
	imwrite(DestImage, frame); // Permet d'enregistrer l'image à l'endroit voulu
	etatAcq = true; // Etat de l'image prise est du coup réglée à true
	ImagePrise = DestImage; 
}
void Camera1::AcquerirReference(std::string DestImage)
{
	flux >> frame;
	imwrite(DestImage, frame); // Permet d'enregistrer l'image à l'endroit voulu
	etatRef = true; // Etat de l'image prise est du coup réglée à true
	ImagePriseRef = DestImage;
}
bool Camera1::IsimagePrise()
{
	return etatAcq;
}
std::string Camera1::GetImagePrise()
{
	return ImagePrise;
}

bool Camera1::IsimageRefPrise()
{
	return etatRef;
}
std::string Camera1::GetImageRefPrise()
{
	return ImagePriseRef;
}
