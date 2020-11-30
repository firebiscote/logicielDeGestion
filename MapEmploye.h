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
	String^ UPDATE(MapEmploye^);
	void set_ID(int);
	void set_nom(String^);
	void set_prenom(String^);
	void set_nomSuperieur(String^);
	void set_prenomSuperieur(String^);
	void set_dateEmbauche(int^ jour, int^ mois, int^ annee);
	void set_dateEmbauche(Date^);
	void set_adresseDomicile(Adresse^);
	int^ get_ID(void);
	String^ get_nom(void);
	String^ get_prenom(void);
	String^ get_nomSuperieur(void);
	String^ get_prenomSuperieur(void);
	Date^ get_dateEmbauche(void);
	Adresse^ get_adresseDomicile(void);
private:
	int^ _ID;
	String^ _nom;
	String^ _prenom;
	String^ _nomSuperieur;
	String^ _prenomSuperieur;
	Date^ _dateEmbauche;
	Adresse^ _adresseDomicile;
};

