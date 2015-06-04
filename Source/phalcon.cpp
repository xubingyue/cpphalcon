#include <phpcpp.h>
#include "Version.h"
#include "Config.h"
#include "Loader.h"
#include "DispatcherInterface.h"
#include "Dispatcher.h"
#include "DIInterface.h"
#include "DI.h"
#include "DI_ServiceInterface.h"
#include "DI_Service.h"
#include "Db.h"

extern "C" {

	PHPCPP_EXPORT void *get_module()
	{

		static Php::Extension extension("Phalcon++", "0.0.1");

		/* Namespace Phalcon */
		Php::Namespace phalconNamespace("Phalcon");

		/* Class Phalcon\Version */
		Php::Class<Phalcon::Version> version("Version");

		phalconNamespace.add(std::move(version));

		/* Class Phalcon\Config */
		Php::Class<Phalcon::Config> config("Config");

		phalconNamespace.add(std::move(config));

		/* Class Phalcon\Loader */
		Php::Class<Phalcon::Loader> loader("Loader");

		phalconNamespace.add(std::move(loader));

		/* Interface Phalcon\DiInterface */
		Phalcon::DIInterface diInterface("DIInterface");

		phalconNamespace.add(std::move(diInterface));

		/* Class Phalcon\DI */
		Php::Class<Phalcon::DI> di("DI");

		di.implements(diInterface);

		phalconNamespace.add(std::move(di));

		/* Interface Phalcon\DiInterface */
		Phalcon::DispatcherInterface dispatcherInterface("DispatcherInterface");

		phalconNamespace.add(std::move(dispatcherInterface));

		/* Class Phalcon\Dispatcher */
		Php::Class<Phalcon::Dispatcher> dispatcher("Dispatcher");

		dispatcher.implements(dispatcherInterface);

		phalconNamespace.add(std::move(dispatcher));

		/* Class Phalcon\Db */
		Php::Class<Phalcon::Db> db("Db");

		phalconNamespace.add(std::move(db));

		/* Namespace DI */
		Php::Namespace diNamespace("DI");

		/* Interface Phalcon\DI\ServiceInterface */
		Phalcon::DI_ServiceInterface diServiceInterface("ServiceInterface");

		diNamespace.add(std::move(diServiceInterface));

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
