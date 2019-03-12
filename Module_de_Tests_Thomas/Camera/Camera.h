//---------------------------------------------------------------------------

#ifndef CameraH
#define CameraH
//---------------------------------------------------------------------------

class Camera
{
	private:
			FILE ImageRef;
			FILE ImageAcquise;
			bool Connect();
			bool Disconnect();
			bool AllumerCamera();
			bool EteindreCamera();
			void PrendrePhoto();





	public:
			Camera();
			~Camera();
			FILE GetImagePrise();
			bool IsImageprise();

};


#endif
