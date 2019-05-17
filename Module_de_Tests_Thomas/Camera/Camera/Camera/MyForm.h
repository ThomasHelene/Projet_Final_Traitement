#pragma once
#include "Camera1.h"
#include <msclr\marshal_cppstd.h>
namespace Camera {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Description r�sum�e de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			
		}

	protected:
		/// <summary>
		/// Nettoyage des ressources utilis�es.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::SaveFileDialog^  saveFileDialog1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Label^  label3;
	protected:

	private:
		/// <summary>
		/// Variable n�cessaire au concepteur.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// M�thode requise pour la prise en charge du concepteur - ne modifiez pas
		/// le contenu de cette m�thode avec l'�diteur de code.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(116, 149);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(203, 41);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Prendre une Photo";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(126, 116);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(182, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Chosissiez l\'emplacement de la photo";
			// 
			// saveFileDialog1
			// 
			this->saveFileDialog1->DefaultExt = L"jpg";
			this->saveFileDialog1->FileName = L"ImageAquise";
			this->saveFileDialog1->Title = L"Enregistrer Image Acquise";
			this->saveFileDialog1->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &MyForm::saveFileDialog1_FileOk);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(299, 30);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(121, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Etat de la prise D\'image:";
			this->label2->Click += gcnew System::EventHandler(this, &MyForm::label2_Click);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::DarkRed;
			this->panel1->Location = System::Drawing::Point(426, 12);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(45, 44);
			this->panel1->TabIndex = 4;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(158, 238);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(0, 13);
			this->label3->TabIndex = 5;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(473, 293);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

		saveFileDialog1->ShowDialog();
	}
	private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
	}



	private: System::Void saveFileDialog1_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) 
	{
	
		// Instanciation de l'objet Cam�ra
		Camera1 *cam;
		cam = new Camera1(msclr::interop::marshal_as<std::string>(saveFileDialog1->FileName));
		
		// On V�rifie que l'image a bien �t� prise
		bool etat = cam->IsimagePrise();
		
		// SI c'est le cas , on r�cup�re l'image et on mets � jour l'IHM
		if (etat == true)
		{
			panel1->BackColor = Color::DarkGreen;
			std::string ImageAcquise;
			ImageAcquise=cam->GetImagePrise();
			String^ ImageAcq = gcnew String(ImageAcquise.c_str());
			label3->Text = ImageAcq;
		}
		// Destruction de l'objet
		delete cam;
	}





private: System::Void label2_Click(System::Object^  sender, System::EventArgs^  e) {
}
};
}
