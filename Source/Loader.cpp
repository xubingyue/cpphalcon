#include "Loader.h"

namespace Phalcon {

	void Loader::__construct() {
		Php::Value self(this);
		self["_extensions"][0] = "php";
	}

	void Loader::setInternalEventsManager(Php::Parameters &params) {
	}

	Php::Value Loader::getInternalEventsManager() {

		return nullptr;
	}

	Php::Value Loader::setExtensions(Php::Parameters &params) {

		return nullptr;
	}

	Php::Value Loader::getExtensions() {

		return nullptr;
	}

	Php::Value Loader::registerNamespaces(Php::Parameters &params) {

		return nullptr;
	}

	Php::Value Loader::getNamespaces() {

		return nullptr;
	}

	Php::Value Loader::registerPrefixes(Php::Parameters &params) {

		return nullptr;
	}

	Php::Value Loader::getPrefixes() {

		return nullptr;
	}

	Php::Value Loader::registerDirs(Php::Parameters &params) {

		return nullptr;
	}

	Php::Value Loader::getDirs() {

		return nullptr;
	}

	Php::Value Loader::registerClasses(Php::Parameters &params) {

		return nullptr;
	}

	Php::Value Loader::getClasses() {

		return nullptr;
	}

	Php::Value Loader::_register() {

		return nullptr;
	}

	Php::Value Loader::unregister() {

		return nullptr;
	}

	Php::Value Loader::autoLoad(Php::Parameters &params) {

		return nullptr;
	}

	Php::Value Loader::getFoundPath() {

		return nullptr;
	}

	Php::Value Loader::Loader::getCheckedPath() {

		return nullptr;
	}
}

