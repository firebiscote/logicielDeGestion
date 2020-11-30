#pragma once
#include "pch.h"
#include "Adresse.h"
#include "Date.h"

ref class MapEmploye {
public:
	MapEmploye(void);
	String^ SELECT(void);
	String^ INSERT(void);
	String^ DELETE(void);
	String^ UPDATE(String^, String^);
private:
	int _ID;
	String^ _nom;
	String^ _prenom;
	String^ _nomSuperieur;
	String^ _prenomSuperieur;
	Date^ _dateEmbauche;
	Adresse^ _adresseDomicile;
};

