
#include <opencv2/opencv.hpp>
#include <string>

class Cam
{
private:

	cv::Mat img;
	cv::VideoCapture avc;
	bool etat;
	std::string ImagePrise;
	

		void Connexion();
		void PrendrePhoto(std::string DestImage);

public:
	Cam(std::string DestImage);
	~Cam();
	bool IsimagePrise();
	std::string GetImagePrise();

};
