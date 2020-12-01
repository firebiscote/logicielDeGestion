#include "Gestion.h"

namespace Services {
	void Gestion::initGestion(void) {
		this->_cad = gcnew Composants::CAD();
		this->_ds = nullptr;
	}
}