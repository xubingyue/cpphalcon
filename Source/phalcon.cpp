#include <phpcpp.h>
#include "Version.h"
#include "DI.h"
#include "DI_Service.h"

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

		version.property("TYPE_ALPHA", Phalcon::Version::TYPE_ALPHA, Php::Const);
		version.property("TYPE_BETA", Phalcon::Version::TYPE_BETA, Php::Const);
		version.property("TYPE_RC", Phalcon::Version::TYPE_RC, Php::Const);
		version.property("TYPE_STABLE", Phalcon::Version::TYPE_STABLE, Php::Const);

		version.method("get", &Phalcon::Version::get);
		version.method("getId", &Phalcon::Version::getId);

		phalconNamespace.add(std::move(version));

		/* Class Phalcon\DI */
		Php::Class<Phalcon::DI> di("DI");

		di.method("__construct", &Phalcon::DI::__construct);
		di.method("setDefault", &Phalcon::DI::setDefault,{
			Php::ByVal("dependencyInjector", "Phalcon\\DiInterface", true),
		});
		di.method("getDefault", &Phalcon::DI::getDefault);
		di.method("set", &Phalcon::DI::set,{
			Php::ByVal("name", Php::Type::String, true),
			Php::ByVal("definition", Php::Type::Null, true),
			Php::ByVal("shared", Php::Type::Bool, false),
		});
		di.method("get", &Phalcon::DI::set,{
			Php::ByVal("name", Php::Type::String, true),
			Php::ByVal("parameters", Php::Type::Array, false),
		});

		di.implements(diInterface);

		phalconNamespace.add(std::move(di));

		/* Class Phalcon\DI\Service */
		Php::Class<Phalcon::DI_Service> di_service("Service");

		di_service.method("__construct", &Phalcon::DI_Service::__construct,{
			Php::ByVal("name", Php::Type::String, true),
			Php::ByVal("definition", Php::Type::Null, true),
			Php::ByVal("shared", Php::Type::Bool, false),
		});
		di_service.method("setSharedInstance",{
			Php::ByVal("sharedInstance", Php::Type::Null, true),
		});
		di_service.method("setParameter",{
			Php::ByVal("position", Php::Type::Numeric, true),
			Php::ByVal("parameter", Php::Type::Array, true),
		});
		di_service.method("getParameter",{
			Php::ByVal("position", Php::Type::Numeric, true),
		});

		di_service.implements(di_serviceInterface);

		diNamespace.add(std::move(di_service));

		/* namespace Phalcon\DI */
		phalconNamespace.add(std::move(diNamespace));

		extension.add(std::move(phalconNamespace));
		return extension;
	}
}