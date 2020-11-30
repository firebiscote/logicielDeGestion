#pragma once
#include "pch.h"

ref class Date {
public:
	Date();
	void set_jour(int^);
	void set_mois(int^);
	void set_annee(int^);
	int^ get_jour(void);
	int^ get_mois(void);
	int^ get_annee(void);
private:
	int^ _jour;
	int^ _mois;
	int^ _annee;
};

