#include "Camera1.h"



using namespace cv;

Camera1::Camera1(std::string DestImage,int type)
{
	etatAcq = false; // Etat de l'image prise r�gl�e par d�faut � false
	etatRef = false;
	Connexion();
	if (flux.isOpened()) // V�rifie si le flux vid�o a bien �t� ouvert
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
		MessageBox(NULL,L"L'Image n'a pas pu �tre prise , la connexion � la cam�ra n'a pas eue lieu.",L"Erreur li�e � la cam�ra", 16);
	}

}
Camera1::~Camera1()
{
	flux.release();
	cv::destroyAllWindows();
}
void Camera1::Connexion()
{
	flux.open(0); // Ouvre le flux vid�o de la cam�ra
}
void Camera1::PrendrePhoto(std::string DestImage)
{
	flux >> frame;
	imwrite(DestImage, frame); // Permet d'enregistrer l'image � l'endroit voulu
	etatAcq = true; // Etat de l'image prise est du coup r�gl�e � true
	ImagePrise = DestImage; 
}
void Camera1::AcquerirReference(std::string DestImage)
{
	flux >> frame;
	imwrite(DestImage, frame); // Permet d'enregistrer l'image � l'endroit voulu
	etatRef = true; // Etat de l'image prise est du coup r�gl�e � true
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
