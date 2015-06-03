#include <phpcpp.h>
#include "Version.h"
#include "Loader.h"
#include "Dispatcher.h"
#include "DIInterface.h"
#include "DI.h"
#include "DI_ServiceInterface.h"
#include "DI_Service.h"
#include "Db.h"

extern "C" {

	PHPCPP_EXPORT void *get_module() {

		static Php::Extension extension("Phalcon++", "0.0.1");

		Php::Namespace phalconNamespace("Phalcon");
		Php::Namespace diNamespace("DI");

		/* Interface Phalcon\DiInterface */
		Phalcon::DIInterface diInterface("DIInterface");

		phalconNamespace.add(std::move(diInterface));

		/* Interface Phalcon\DI\ServiceInterface */
		Phalcon::DI_ServiceInterface diServiceInterface("ServiceInterface");

		diNamespace.add(std::move(diServiceInterface));

		/* Class Phalcon\Version */
		Php::Class<Phalcon::Version> version("Version");

		phalconNamespace.add(std::move(version));

		/* Class Phalcon\Loader */
		Php::Class<Phalcon::Loader> loader("Loader");

		phalconNamespace.add(std::move(loader));

		/* Class Phalcon\Dispatcher */
		Php::Class<Phalcon::Dispatcher> dispatcher("Dispatcher");

		phalconNamespace.add(std::move(dispatcher));

		/* Class Phalcon\Dispatcher */
		Php::Class<Phalcon::Db> db("Db");

		phalconNamespace.add(std::move(db));

		/* Class Phalcon\DI */
		Php::Class<Phalcon::DI> di("DI");

		di.implements(diInterface);

		phalconNamespace.add(std::move(di));

		/* Class Phalcon\DI\Service */
		Php::Class<Phalcon::DI_Service> di_service("Service");

		di_service.implements(diServiceInterface);

		diNamespace.add(std::move(di_service));

		/* namespace Phalcon\DI */
		phalconNamespace.add(std::move(diNamespace));

		extension.add(std::move(phalconNamespace));
		return extension;
	}
}