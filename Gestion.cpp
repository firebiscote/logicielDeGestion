#include "Gestion.h"

namespace Services {
	void Gestion::initGestion(void) {
		this->_cad = gcnew Composants::CAD();
		this->_ds = nullptr;
	}

	DataSet^ Gestion::simulation(double TVA, double margeCommerciale, double remiseCommerciale, double demarqueInconnue) {
		this->_ds = gcnew DataSet();
		this->_ds = this->_cad->getRows("SELECT CONCAT(cast(sum(inter.valeur) as decimal(18, 2)), ' €') AS simulation FROM (SELECT ((stock*'" + (100-demarqueInconnue) + "'/100)*(prixHT*'" + (100+TVA) + "'*'" + (100+margeCommerciale) + "'*'" + (100-remiseCommerciale) + "'/1000000)) AS valeur FROM article) AS inter", "article");
		return this->_ds;
	}
}
