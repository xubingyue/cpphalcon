#include "DI.h"

#include <string>
#include <iostream>
#include <sstream>

namespace Phalcon {

	DI* DI::_default = nullptr;

	void DI::__construct() {
		if (!_default) {
			_default = this;
		}
	}

	void DI::setInternalEventsManager(Php::Parameters &params) {

	}

	Php::Value DI::getInternalEventsManager() {

		return nullptr;
	}

	Php::Value DI::set(Php::Parameters &params) {
		try {
			Php::Value name = params.at(0);
			Php::Value definition = params.at(1);
			Php::Value shared = params.size() > 2 ? params.at(2) : Php::Value(false);
		} catch (const std::out_of_range& e) {
			throw Php::Exception("Invalid number of parameters supplied");
		}

		return this;
	}

	Php::Value DI::setShared(Php::Parameters &params) {

		return nullptr;
	}

	void DI::remove(Php::Parameters &params) {

	}

	Php::Value DI::attempt(Php::Parameters &params) {

		return nullptr;
	}

	Php::Value DI::setRaw(Php::Parameters &params) {

		return nullptr;
	}

	Php::Value DI::getRaw(Php::Parameters &params) {

		return nullptr;
	}

	Php::Value DI::getService(Php::Parameters &params) {

		return nullptr;
	}

	Php::Value DI::get(Php::Parameters &params) {
		try {
			Php::Value name = params.at(0);
			Php::Value parameters = params.size() > 1 ? params.at(1) : Php::Value(nullptr);
		} catch (const std::out_of_range& e) {
			throw Php::Exception("Invalid number of parameters supplied");
		}

		return this;
	}

	Php::Value DI::getShared(Php::Parameters &params) {

		return nullptr;
	}

	Php::Value DI::has(Php::Parameters &params) {

		return nullptr;
	}

	Php::Value DI::wasFreshInstance() {

		return nullptr;
	}

	Php::Value DI::getServices() {

		return nullptr;
	}

	bool DI::offsetExists(const Php::Value &key) {

		return false;
	}

	void DI::offsetSet(const Php::Value &key, const Php::Value &value) {

	}

	Php::Value DI::offsetGet(const Php::Value &key) {

		return nullptr;
	}

	void DI::offsetUnset(const Php::Value &key) {

	}

	Php::Value DI::__call(const char *method, Php::Parameters &params) const {

		std::string message = "Call to undefined method or service '";
		message.append(method);
		message.append("'");

		throw Php::Exception(message);
		
		return nullptr;
	}

	void DI::setDefault(Php::Parameters &params) {
		try {
			Php::Value value = params.at(0);
			_default = (DI *) value.implementation();
		} catch (const std::out_of_range& e) {
			throw Php::Exception("Invalid number of parameters supplied");
		}
	}

	Php::Value DI::getDefault() {
		return _default;
	}

	void DI::reset() {
		_default = nullptr;
	}
}