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
	/// Description résumée de MyForm
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
		/// Nettoyage des ressources utilisées.
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
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::SaveFileDialog^  saveFileDialog2;
	protected:

	private:
		/// <summary>
		/// Variable nécessaire au concepteur.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Méthode requise pour la prise en charge du concepteur - ne modifiez pas
		/// le contenu de cette méthode avec l'éditeur de code.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->saveFileDialog2 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(79, 63);
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
			this->label1->Location = System::Drawing::Point(56, 30);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(237, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Chosissiez l\'emplacement de la photo de la pièce";
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
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(56, 145);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(300, 13);
			this->label4->TabIndex = 7;
			this->label4->Text = L"Chosissiez l\'emplacement de la photo de la pièce de référence";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(79, 178);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(203, 41);
			this->button2->TabIndex = 6;
			this->button2->Text = L"Prendre une Photo de Référence";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::DarkRed;
			this->panel2->Location = System::Drawing::Point(426, 178);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(45, 44);
			this->panel2->TabIndex = 9;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(299, 196);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(121, 13);
			this->label5->TabIndex = 8;
			this->label5->Text = L"Etat de la prise D\'image:";
			// 
			// saveFileDialog2
			// 
			this->saveFileDialog2->DefaultExt = L"jpg";
			this->saveFileDialog2->FileName = L"ImageReference";
			this->saveFileDialog2->Title = L"Enregistrer Image Référence";
			this->saveFileDialog2->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &MyForm::saveFileDialog2_FileOk);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(473, 293);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->button2);
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
	
		// Instanciation de l'objet Caméra
		Camera1 *cam;
		cam = new Camera1(msclr::interop::marshal_as<std::string>(saveFileDialog1->FileName),1);
		
		// On Vérifie que l'image a bien été prise
		bool etat = cam->IsimagePrise();
		
		// SI c'est le cas , on récupère l'image et on mets à jour l'IHM
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






private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	
	saveFileDialog2->ShowDialog();
}
private: System::Void saveFileDialog2_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {

	// Instanciation de l'objet Caméra
	Camera1 *cam;
	cam = new Camera1(msclr::interop::marshal_as<std::string>(saveFileDialog2->FileName), 2);

	// On Vérifie que l'image a bien été prise
	bool etat = cam->IsimageRefPrise();

	// SI c'est le cas , on récupère l'image et on mets à jour l'IHM
	if (etat == true)
	{
		panel2->BackColor = Color::DarkGreen;
		std::string ImageAcquise;
		ImageAcquise = cam->GetImageRefPrise();
		String^ ImageAcq = gcnew String(ImageAcquise.c_str());
		label3->Text = ImageAcq;
	}
	// Destruction de l'objet
	delete cam;
}
};
}
