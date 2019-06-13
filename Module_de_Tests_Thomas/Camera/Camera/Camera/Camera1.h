#pragma once
#include <opencv2/opencv.hpp>
#include <string>
#include <Windows.h>
#pragma comment(lib,"User32.lib")

class Camera1
{

	cv::Mat frame;
	cv::VideoCapture flux;

	bool etatAcq,etatRef;
	std::string ImagePrise;
	std::string ImagePriseRef;

	void Connexion();
	void PrendrePhoto(std::string DestImage);

public:
	Camera1(std::string DestImage, int type);
	~Camera1();
	bool IsimagePrise();
	std::string GetImagePrise();
	void AcquerirReference(std::string DestImage);
		bool IsimageRefPrise();
		std::string GetImageRefPrise();
};

