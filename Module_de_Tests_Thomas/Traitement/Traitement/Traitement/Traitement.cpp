#include "pch.h"
#include "Traitement.h"



Traitement::Traitement(std::string ImageAcq, std::string ImageRef)

{
	bool etatImageAcq = SetImageAcquise(ImageAcq);

	bool etatImageRef = SetImageRef(ImageRef);

	if (etatImageRef == true)
	{

	}
	else
	{
		MessageBox(NULL, L"L'Image de Référence n'a pas été Insérée", L"Problème avec l'Image de Référence", MB_OK);
	}

	if (etatImageAcq == true)
	{

	}
	else
	{
		MessageBox(NULL, L"L'Image Acquise n'a pas été Insérée", L"Problème avec l'Image Acquise", MB_OK);
	}

	ComparerImages();









}


Traitement::~Traitement()
{
}
bool Traitement::SetImageAcquise(std::string ImageAcq)
{
	if (ImageAcq != "")
	{
		ImageAcquise = imread(ImageAcq);
		return true;
	}
	else
	{
		return false;
	}

}
bool Traitement::SetImageRef(std::string ImageRef)
{
	if (ImageRef != "")
	{
		ImageReference = imread(ImageRef);
		return true;
	}
	else
	{
		return false;
	}

}

void Traitement::ComparerImages()
{
	Mat ImgGriseAcq = ImageAcquise.clone();
	Mat ImgGriseRef = ImageReference.clone();
	Mat ImgHsvAcq;
	Mat ImgHsvRef;


	/// Convert to HSV
	cvtColor(ImgGriseAcq, ImgHsvAcq, COLOR_BGR2HSV);
	cvtColor(ImgGriseRef, ImgHsvRef, COLOR_BGR2HSV);
	std::vector<Mat> bgr_planes;
	split(ImgHsvAcq, bgr_planes);
	std::vector<Mat> bgr_planes1;
	split(ImgHsvRef, bgr_planes1);


	//// Set histogram bins count
	//int bins = 256;
	//int histSize[] = { bins };
	//// Set ranges for histogram bins
	//float lranges[] = { 0, 256 };
	//const float* ranges[] = { lranges };
	//// create matrix for histogram
	//MatND hist_ImageRef;
	//MatND hist_ImageAcq;
	//int channels[] = { 0 };

	//// create matrix for histogram visualization
	//int const hist_height = 256;
	//cv::Mat3b hist_image = cv::Mat3b::zeros(hist_height, bins);

	//cv::calcHist(&ImgHsvRef, 1, channels, cv::Mat(), hist_ImageRef, 1, histSize, ranges, true, false);
	//normalize(ImgHsvRef, ImgHsvRef, 0, 1, NORM_MINMAX, -1, Mat());
	//cv::calcHist(&ImgHsvAcq, 1, channels, cv::Mat(), hist_ImageAcq, 1, histSize, ranges, true, false);
	//normalize(ImgHsvAcq, ImgHsvAcq, 0, 1, NORM_MINMAX, -1, Mat());


	int h_bins = 180;
	//int s_bins = 256;
	int v_bins = 10;
	
	//int histSize[] = { h_bins };

	float h_ranges[] = { 0, 180 };
	
	//float s_ranges[] = { 0, 256 };
	//float v_ranges[] = { 0, 256 };

	const float* ranges[] = { h_ranges };
	int channels[] = { 0 };
	Mat hist_ref, hist_acq;
	calcHist(&bgr_planes[0], 1, 0, Mat(), hist_ref, 1, &h_bins,ranges,true, false);
	calcHist(&bgr_planes1[0], 1, 0, Mat(), hist_acq, 1, &h_bins,ranges, true, false);
	normalize(hist_ref, hist_ref, 0, hist_ref.rows, NORM_MINMAX, -1, Mat());
	normalize(hist_acq, hist_acq, 0, hist_acq.rows, NORM_MINMAX, -1, Mat());
	
	int histSize = 180;
	int hist_w = 512, hist_h = 400;
	int bin_w = cvRound((double)hist_w / histSize);
	Mat histImage(hist_h, hist_w, CV_8UC3, Scalar(0, 0, 0));
	Mat histImage1(hist_h, hist_w, CV_8UC3, Scalar(0, 0, 0));
	for (int i = 1; i < histSize; i++)
	{
		line(histImage, Point(bin_w*(i - 1), hist_h - cvRound(hist_ref.at<float>(i - 1))),
			Point(bin_w*(i), hist_h - cvRound(hist_ref.at<float>(i))),
			Scalar(255, 0, 0), 2, 8, 0);
		line(histImage1, Point(bin_w*(i - 1), hist_h - cvRound(hist_acq.at<float>(i - 1))),
			Point(bin_w*(i), hist_h - cvRound(hist_acq.at<float>(i))),
			Scalar(0, 255, 0), 2, 8, 0);
	}
	imshow("Reference", histImage);
	imshow("Acquise", histImage1);
	waitKey();


	printf("Affichage des Résultats \n");
	/// Apply the histogram comparison methods
	for (int i = 0; i < 4; i++)
	{
		int compare_method = i;
		ResultatsRef.push_back(compareHist(hist_ref, hist_ref, compare_method));
		ResultatsAcq.push_back(compareHist(hist_ref, hist_acq, compare_method));


		
	}



	
	EtatTraitement = true;
}

bool Traitement::GetEtatTraitement()
{
	return EtatTraitement;
}
std::vector <double> Traitement::GetResultatsRef()
{
	return ResultatsRef;
}
std::vector <double> Traitement::GetResultatsAcq()
{
	return ResultatsAcq;
}