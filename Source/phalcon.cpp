#include <phpcpp.h>
#include "Version.h"
#include "Loader.h"
#include "Dispatcher.h"
#include "DI.h"
#include "DI_Service.h"
#include "Db.h"

extern "C" {

	PHPCPP_EXPORT void *get_module() {

		static Php::Extension extension("Phalcon++", "0.0.1");

		Php::Namespace phalconNamespace("Phalcon");
		Php::Namespace diNamespace("DI");

		/* Interface Phalcon\DiInterface */
		Php::Interface diInterface("DiInterface");

		diInterface.method("set",{
			Php::ByVal("name", Php::Type::String, true),
			Php::ByVal("definition", Php::Type::Null, true),
			Php::ByVal("shared", Php::Type::Bool, false),
		});
		diInterface.method("setShared",{
			Php::ByVal("name", Php::Type::String, true),
			Php::ByVal("definition", Php::Type::Null, true),
		});
		diInterface.method("get",{
			Php::ByVal("name", Php::Type::String, true),
			Php::ByVal("parameters", Php::Type::Array, false),
		});
		diInterface.method("getShared",{
			Php::ByVal("name", Php::Type::String, true),
			Php::ByVal("parameters", Php::Type::Array, false),
		});
		diInterface.method("remove",{
			Php::ByVal("name", Php::Type::String, true),
		});
		diInterface.method("setService",{
			Php::ByVal("name", Php::Type::String, true),
			Php::ByVal("parameters", "Phalcon\\DI\\ServiceInterface", true),
		});
		diInterface.method("getService",{
			Php::ByVal("name", Php::Type::String, true),
		});
		diInterface.method("has",{
			Php::ByVal("name", Php::Type::String, true),
		});
		diInterface.method("wasFreshInstance");
		diInterface.method("getServices");

		phalconNamespace.add(std::move(diInterface));

		/* Interface Phalcon\DI\ServiceInterface */
		Php::Interface di_serviceInterface("ServiceInterface");

		di_serviceInterface.method("getName");
		di_serviceInterface.method("setShared",{
			Php::ByVal("shared", Php::Type::Bool, true),
		});
		di_serviceInterface.method("isShared");
		di_serviceInterface.method("setDefinition",{
			Php::ByVal("shared", Php::Type::Bool, true),
		});
		di_serviceInterface.method("getDefinition");
		di_serviceInterface.method("isResolved");
		di_serviceInterface.method("resolve");

		diNamespace.add(std::move(di_serviceInterface));

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

		di_service.implements(di_serviceInterface);

		diNamespace.add(std::move(di_service));

		/* namespace Phalcon\DI */
		phalconNamespace.add(std::move(diNamespace));

		extension.add(std::move(phalconNamespace));
		return extension;
	}
}