#include "Gestion.h"

namespace Services {
	void Gestion::initGestion(void) {
		this->_cad = gcnew Composants::CAD();
		this->_ds = nullptr;
	}

	DataSet^ Gestion::stat1(void) {
		this->_ds = gcnew DataSet();
		this->_ds = this->_cad->getRows("", "article");
		return this->_ds;
	}

	DataSet^ Gestion::stat2(void) {
		this->_ds = gcnew DataSet();
		this->_ds = this->_cad->getRows("", "article");
		return this->_ds;
	}

	DataSet^ Gestion::stat3(void) {
		this->_ds = gcnew DataSet();
		this->_ds = this->_cad->getRows("", "article");
		return this->_ds;
	}

	DataSet^ Gestion::stat4(void) {
		this->_ds = gcnew DataSet();
		this->_ds = this->_cad->getRows("", "article");
		return this->_ds;
	}

	DataSet^ Gestion::stat5(void) {
		this->_ds = gcnew DataSet();
		this->_ds = this->_cad->getRows("", "article");
		return this->_ds;
	}

	DataSet^ Gestion::stat6(void) {
		this->_ds = gcnew DataSet();
		this->_ds = this->_cad->getRows("", "article");
		return this->_ds;
	}

	DataSet^ Gestion::stat7(void) {
		this->_ds = gcnew DataSet();
		this->_ds = this->_cad->getRows("", "article");		
		return this->_ds;
	}

	DataSet^ Gestion::stat8(void) {
		this->_ds = gcnew DataSet();
		this->_ds = this->_cad->getRows("", "article");
		return this->_ds;
	}

	DataSet^ Gestion::simulation(double TVA, double margeCommerciale, double remiseCommerciale, double demarqueInconnue) {
		this->_ds = gcnew DataSet();
		this->_ds = this->_cad->getRows("SELECT CONCAT(cast(sum(inter.valeur) as decimal(18, 2)), ' €') AS simulation FROM (SELECT ((stock*'" + (100-demarqueInconnue) + "'/100)*(prixHT*'" + (100+TVA) + "'*'" + (100+margeCommerciale) + "'*'" + (100-remiseCommerciale) + "'/1000000)) AS valeur FROM article) AS inter", "article");
		return this->_ds;
	}
}
