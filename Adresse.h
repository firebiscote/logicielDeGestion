#pragma once
#include "pch.h"

ref class Adresse {
public:
	void set_numeroDeVoie(int^);
	void set_complementDeNumero(String^);
	void set_typeDeVoie(String^);
	void set_nomDeVoie(String^);
	void set_codePostal(int^);
	void set_nomDeCommune(String^);
	int^ get_numeroDeVoie(void);
	String^ get_complementDeNumero(void);
	String^ get_typeDeVoie(void);
	String^ get_nomDeVoie(void);
	int^ get_codePostal(void);
	String^ get_nomDeCommune(void);
private:
	int^ _numeroDeVoie;
	String^ _complementDeNumero;
	String^ _typdeDeVoie;
	String^ _nomDeVoie;
	int^ _codePostal;
	String^ _nomDeCommune;
};

