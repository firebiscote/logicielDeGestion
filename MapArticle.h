#pragma once
#include "pch.h"

namespace Composants {
	ref class MapArticle {
	public:
		MapArticle(void);
		MapArticle(String^, String^, String^, String^, String^, String^);
		String^ SELECT(void);
		String^ INSERT(void);
		String^ DELETE(void);
		String^ UPDATE(void);
		void set_ID(int);
		void set_reference(String^);
		void set_designation(String^);
		void set_stock(String^);
		void set_seuilDeReapprovisionnement(String^);
		void set_prixHT(String^);
		void set_tauxDeTVA(String^);
		int^ get_ID(void);
		String^ get_reference(void);
		String^ get_designation(void);
		String^ get_stock(void);
		String^ get_seuilDeReapprovisionnement(void);
		String^ get_prixHT(void);
		String^ get_tauxDeTVA(void);
	private:
		int^ _ID;
		String^ _reference;
		String^ _designation;
		String^ _stock;
		String^ _seuilDeReapprovisionnement;
		String^ _prixHT;
		String^ _tauxDeTVA;
	};
}