#include "GestionArticle.h"

namespace Services {
	GestionArticle::GestionArticle(void) {
		this->_cad = gcnew Composants::CAD();
		this->_article = gcnew Composants::MapArticle();
		this->_ds = nullptr;
	}

	DataSet^ GestionArticle::listeArticle(void) {
		this->_ds = gcnew DataSet();
		this->_ds = this->_cad->getRows(this->_article->SELECT(), "Article");
		return this->_ds;
	}

	void GestionArticle::ajouter(String^ reference, String^ designation, String^ stock, String^ seuilDeReapprovisionnement, String^ prixHT, String^ tauxDeTVA) {
		if (this->_cad->actionRowsID("SELECT * FROM Article WHERE Article.reference = '" + reference + "' AND Article.designation = '" + designation + "'") != 0) {
			throw gcnew String("Cet article existe deja !");
		}
		this->_article = gcnew Composants::MapArticle(reference, designation, stock, seuilDeReapprovisionnement, prixHT, tauxDeTVA);
		this->_cad->actionRows(this->_article->INSERT());
		if (this->_cad->actionRowsID("SELECT * FROM Article WHERE Article.reference = '" + reference + "' AND Article.designation = '" + designation + "'") != 0) {
			throw gcnew bool(1);
		}
		else {
			throw gcnew bool(0);
		}
	}

	void GestionArticle::supprimer(String^ reference, String^ designation) {
		if (this->_cad->actionRowsID("SELECT * FROM Article WHERE Article.reference = '" + reference + "' AND Article.designation = '" + designation + "'") == 0) {
			throw gcnew String("Cet article n\'existe pas !");
		}
		this->_article->set_reference(reference);
		this->_article->set_designation(designation);
		this->_cad->actionRows(this->_article->DELETE());
		if (this->_cad->actionRowsID("SELECT * FROM Article WHERE Article.reference = '" + reference + "' AND Article.designation = '" + designation + "'") == 0) {
			throw gcnew bool(1);
		}
		else {
			throw gcnew bool(0);
		}
	}

	void GestionArticle::modifier(Composants::MapArticle^ article) {
		this->_cad->actionRows(this->_article->UPDATE(article));
	}
}
