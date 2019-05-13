#pragma comment (lib, "user32.lib")
#include <string>
#include <opencv2/opencv.hpp>
#include <vector>
#include <windows.h>
#include <WinUser.h>

using namespace cv;
class Traitement
{
public:

private:
	Mat ImageReference;
	Mat ImageAcquise;
	bool SetImageRef(std::string ImageRef);
	bool SetImageAcquise(std::string ImageAcq);
	void ComparerImages();
	bool EtatTraitement;
public:
	Traitement(std::string ImageAcq, std::string ImageRef);
	~Traitement();
	bool GetEtatTraitement();


};

