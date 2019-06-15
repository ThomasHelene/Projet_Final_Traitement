#include "Camera1.h"



using namespace cv;

Camera1::Camera1(std::string DestImage)
{
	etat = false; // Etat de l'image prise r�gl�e par d�faut � false
	Connexion();
	if (flux.isOpened()) // V�rifie si le flux vid�o a bien �t� ouvert
	{
		PrendrePhoto(DestImage);
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
	etat = true; // Etat de l'image prise est du coup r�gl�e � true
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


