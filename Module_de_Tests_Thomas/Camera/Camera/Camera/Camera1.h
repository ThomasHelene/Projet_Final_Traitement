#pragma once
#include <opencv2/opencv.hpp>
#include <string>
#include <Windows.h>

class Camera1
{

	cv::Mat img;
	cv::VideoCapture avc;
	bool etat;
	std::string ImagePrise;


	void Connexion();
	void PrendrePhoto(std::string DestImage);

public:
	Camera1(std::string DestImage);
	~Camera1();
	bool IsimagePrise();
	std::string GetImagePrise();

};

