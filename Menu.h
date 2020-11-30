#pragma once
#include "pch.h"
#include "GestionEmploye.h"

namespace logicielDeGestion {

	#define checkErreur catch (String^ e) {\
							this->errorProviderAjouter->SetError(this->bAjouter, e);\
						}\
						catch (bool^ e) {\
							if (e) {\
								this->tBoxReponse->Text = "opération réussie !";\
							}\
							else {\
								this->tBoxReponse->Text = "opération échouée !";\
							}\
						}

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class Menu : public System::Windows::Forms::Form {
	public:
		Menu(void) {
			InitializeComponent();
		}
	protected:
		~Menu() {
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ bAjouter;
	private: System::Windows::Forms::DataGridView^ dataGrid;
	private: System::Windows::Forms::TextBox^ tEmployeNom;
	private: System::Windows::Forms::TextBox^ tEmployePrenom;
	private: System::Windows::Forms::TextBox^ tSuperieurNom;
	private: System::Windows::Forms::TextBox^ tSuperieurPrenom;
	private: System::Windows::Forms::TextBox^ tNumeroDeVoie;
	private: System::Windows::Forms::TextBox^ tComplementDeNumero;
	private: System::Windows::Forms::TextBox^ tTypeDeVoie;
	private: System::Windows::Forms::TextBox^ tNomDeVoie;
	private: System::Windows::Forms::TextBox^ tCodePostal;
	private: System::Windows::Forms::TextBox^ tNomDeCommune;
	private: System::Windows::Forms::Button^ bSupprimer;
	private: System::ComponentModel::IContainer^ components;
	private: System::Windows::Forms::ErrorProvider^ errorProviderAjouter;
	private: System::Windows::Forms::RichTextBox^ tBoxReponse;
	private: Services::GestionEmploye^ gestionEmploye;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Méthode requise pour la prise en charge du concepteur - ne modifiez pas
		/// le contenu de cette méthode avec l'éditeur de code.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->bAjouter = (gcnew System::Windows::Forms::Button());
			this->dataGrid = (gcnew System::Windows::Forms::DataGridView());
			this->tEmployeNom = (gcnew System::Windows::Forms::TextBox());
			this->tEmployePrenom = (gcnew System::Windows::Forms::TextBox());
			this->tSuperieurNom = (gcnew System::Windows::Forms::TextBox());
			this->tSuperieurPrenom = (gcnew System::Windows::Forms::TextBox());
			this->tNumeroDeVoie = (gcnew System::Windows::Forms::TextBox());
			this->tComplementDeNumero = (gcnew System::Windows::Forms::TextBox());
			this->tTypeDeVoie = (gcnew System::Windows::Forms::TextBox());
			this->tNomDeVoie = (gcnew System::Windows::Forms::TextBox());
			this->tCodePostal = (gcnew System::Windows::Forms::TextBox());
			this->tNomDeCommune = (gcnew System::Windows::Forms::TextBox());
			this->bSupprimer = (gcnew System::Windows::Forms::Button());
			this->errorProviderAjouter = (gcnew System::Windows::Forms::ErrorProvider(this->components));
			this->tBoxReponse = (gcnew System::Windows::Forms::RichTextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGrid))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProviderAjouter))->BeginInit();
			this->SuspendLayout();
			// 
			// bAjouter
			// 
			this->bAjouter->Location = System::Drawing::Point(226, 14);
			this->bAjouter->Name = L"bAjouter";
			this->bAjouter->Size = System::Drawing::Size(84, 23);
			this->bAjouter->TabIndex = 0;
			this->bAjouter->Text = L"Ajouter";
			this->bAjouter->UseVisualStyleBackColor = true;
			this->bAjouter->Click += gcnew System::EventHandler(this, &Menu::bAjouter_Click);
			// 
			// dataGrid
			// 
			this->dataGrid->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGrid->Location = System::Drawing::Point(320, 12);
			this->dataGrid->Name = L"dataGrid";
			this->dataGrid->RowHeadersWidth = 51;
			this->dataGrid->RowTemplate->Height = 24;
			this->dataGrid->Size = System::Drawing::Size(428, 419);
			this->dataGrid->TabIndex = 1;
			// 
			// tEmployeNom
			// 
			this->tEmployeNom->Location = System::Drawing::Point(119, 14);
			this->tEmployeNom->Name = L"tEmployeNom";
			this->tEmployeNom->Size = System::Drawing::Size(100, 22);
			this->tEmployeNom->TabIndex = 3;
			// 
			// tEmployePrenom
			// 
			this->tEmployePrenom->Location = System::Drawing::Point(13, 14);
			this->tEmployePrenom->Name = L"tEmployePrenom";
			this->tEmployePrenom->Size = System::Drawing::Size(100, 22);
			this->tEmployePrenom->TabIndex = 2;
			// 
			// tSuperieurNom
			// 
			this->tSuperieurNom->Location = System::Drawing::Point(119, 42);
			this->tSuperieurNom->Name = L"tSuperieurNom";
			this->tSuperieurNom->Size = System::Drawing::Size(100, 22);
			this->tSuperieurNom->TabIndex = 5;
			// 
			// tSuperieurPrenom
			// 
			this->tSuperieurPrenom->Location = System::Drawing::Point(13, 42);
			this->tSuperieurPrenom->Name = L"tSuperieurPrenom";
			this->tSuperieurPrenom->Size = System::Drawing::Size(100, 22);
			this->tSuperieurPrenom->TabIndex = 4;
			// 
			// tNumeroDeVoie
			// 
			this->tNumeroDeVoie->Location = System::Drawing::Point(13, 70);
			this->tNumeroDeVoie->Name = L"tNumeroDeVoie";
			this->tNumeroDeVoie->Size = System::Drawing::Size(35, 22);
			this->tNumeroDeVoie->TabIndex = 7;
			// 
			// tComplementDeNumero
			// 
			this->tComplementDeNumero->Location = System::Drawing::Point(54, 70);
			this->tComplementDeNumero->Name = L"tComplementDeNumero";
			this->tComplementDeNumero->Size = System::Drawing::Size(44, 22);
			this->tComplementDeNumero->TabIndex = 8;
			// 
			// tTypeDeVoie
			// 
			this->tTypeDeVoie->Location = System::Drawing::Point(104, 70);
			this->tTypeDeVoie->Name = L"tTypeDeVoie";
			this->tTypeDeVoie->Size = System::Drawing::Size(100, 22);
			this->tTypeDeVoie->TabIndex = 9;
			// 
			// tNomDeVoie
			// 
			this->tNomDeVoie->Location = System::Drawing::Point(210, 70);
			this->tNomDeVoie->Name = L"tNomDeVoie";
			this->tNomDeVoie->Size = System::Drawing::Size(100, 22);
			this->tNomDeVoie->TabIndex = 10;
			// 
			// tCodePostal
			// 
			this->tCodePostal->Location = System::Drawing::Point(12, 98);
			this->tCodePostal->Name = L"tCodePostal";
			this->tCodePostal->Size = System::Drawing::Size(100, 22);
			this->tCodePostal->TabIndex = 11;
			// 
			// tNomDeCommune
			// 
			this->tNomDeCommune->Location = System::Drawing::Point(120, 98);
			this->tNomDeCommune->Name = L"tNomDeCommune";
			this->tNomDeCommune->Size = System::Drawing::Size(190, 22);
			this->tNomDeCommune->TabIndex = 12;
			// 
			// bSupprimer
			// 
			this->bSupprimer->Location = System::Drawing::Point(226, 42);
			this->bSupprimer->Name = L"bSupprimer";
			this->bSupprimer->Size = System::Drawing::Size(84, 23);
			this->bSupprimer->TabIndex = 13;
			this->bSupprimer->Text = L"Supprimer";
			this->bSupprimer->UseVisualStyleBackColor = true;
			this->bSupprimer->Click += gcnew System::EventHandler(this, &Menu::bSupprimer_Click);
			// 
			// errorProviderAjouter
			// 
			this->errorProviderAjouter->ContainerControl = this;
			// 
			// tBoxReponse
			// 
			this->tBoxReponse->Location = System::Drawing::Point(13, 364);
			this->tBoxReponse->Name = L"tBoxReponse";
			this->tBoxReponse->Size = System::Drawing::Size(298, 67);
			this->tBoxReponse->TabIndex = 14;
			this->tBoxReponse->Text = L"";
			// 
			// Menu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(760, 443);
			this->Controls->Add(this->tBoxReponse);
			this->Controls->Add(this->bSupprimer);
			this->Controls->Add(this->tNomDeCommune);
			this->Controls->Add(this->tCodePostal);
			this->Controls->Add(this->tNomDeVoie);
			this->Controls->Add(this->tTypeDeVoie);
			this->Controls->Add(this->tComplementDeNumero);
			this->Controls->Add(this->tNumeroDeVoie);
			this->Controls->Add(this->tSuperieurPrenom);
			this->Controls->Add(this->tSuperieurNom);
			this->Controls->Add(this->tEmployePrenom);
			this->Controls->Add(this->tEmployeNom);
			this->Controls->Add(this->dataGrid);
			this->Controls->Add(this->bAjouter);
			this->Name = L"Menu";
			this->Text = L"Menu";
			this->Load += gcnew System::EventHandler(this, &Menu::Menu_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGrid))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProviderAjouter))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Menu_Load(System::Object^ sender, System::EventArgs^ e) {
		this->gestionEmploye = gcnew Services::GestionEmploye();
		this->loadDataGridView();
	}

	private: void loadDataGridView(void) {
		this->dataGrid->DataSource = this->gestionEmploye->listeEmploye();
		this->dataGrid->DataMember = "Employe";
	}

	private: void resetForm(void) {
		this->errorProviderAjouter->Clear();
		this->tBoxReponse->Text = "";
	}

	private: System::Void bAjouter_Click(System::Object^ sender, System::EventArgs^ e) {
		this->resetForm();
		try {
			this->gestionEmploye->ajouter(this->tEmployeNom->Text->Trim(), this->tEmployePrenom->Text->Trim(), this->tSuperieurNom->Text->Trim(), this->tSuperieurPrenom->Text->Trim(), DateTime::Today, gcnew Adresse(this->tNumeroDeVoie->Text->Trim(), this->tComplementDeNumero->Text->Trim(), this->tTypeDeVoie->Text->Trim(), this->tNomDeVoie->Text->Trim(), this->tCodePostal->Text->Trim(), this->tNomDeCommune->Text->Trim()));
		}
		checkErreur
		this->loadDataGridView();
	}

	private: System::Void bSupprimer_Click(System::Object^ sender, System::EventArgs^ e) {
		this->resetForm();
		try {
			this->gestionEmploye->supprimer(this->tEmployeNom->Text, this->tEmployePrenom->Text);
		}
		checkErreur
		this->loadDataGridView();
	}
};
}
