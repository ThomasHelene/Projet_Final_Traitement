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
	int s_bins = 256;
	int v_bins = 10;
	int histSize[] = { h_bins, s_bins };

	float h_ranges[] = { 0, 180 };
	float s_ranges[] = { 0, 256 };
	//float v_ranges[] = { 0, 256 };

	const float* ranges[] = { h_ranges, s_ranges };
	int channels[] = { 0, 1 };
	Mat hist_ref, hist_acq;
	calcHist(&ImgHsvRef, 1, channels, Mat(), hist_ref, 2, histSize, ranges, true, false);
	calcHist(&ImgHsvAcq, 1, channels, Mat(), hist_acq, 2, histSize, ranges, true, false);
	normalize(hist_ref, hist_ref, 0, hist_ref.rows, NORM_MINMAX, -1, Mat());
	normalize(hist_acq, hist_acq, 0, hist_acq.rows, NORM_MINMAX, -1, Mat());

	printf("Affichage des Résultats \n");
	/// Apply the histogram comparison methods
	for (int i = 0; i < 4; i++)
	{
		int compare_method = i;
		ResultatsRef.push_back(compareHist(hist_ref, hist_ref, compare_method));
		ResultatsAcq.push_back(compareHist(hist_ref, hist_acq, compare_method));


		
	}



	namedWindow("REF", WINDOW_AUTOSIZE);
	imshow("REF", hist_ref);

	namedWindow("ACQ", WINDOW_AUTOSIZE);
	imshow("ACQ", hist_acq);
	//waitKey();
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