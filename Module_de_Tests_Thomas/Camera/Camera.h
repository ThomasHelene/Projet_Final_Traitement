//---------------------------------------------------------------------------

#ifndef CameraH
#define CameraH
//---------------------------------------------------------------------------
#include <string>
#include "include/cxcore.h"
#include "include/highgui.h"
class Camera
{
	private:
			std::string ImageRef;
			std::string ImageAcquise;
			bool Connect();
			bool Disconnect();
			bool AllumerCamera();
			bool EteindreCamera();
			void PrendrePhoto();





	public:
			Camera();
			~Camera();
			std::string GetImagePrise();
			bool IsImageprise();

};


#endif
