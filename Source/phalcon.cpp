#include <phpcpp.h>
#include "Version.h"
#include "Loader.h"
#include "Dispatcher.h"
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

		/* Class Phalcon\Loader */
		Php::Class<Phalcon::Loader> loader("Loader");

		loader.property("_foundPath", nullptr, Php::Protected);
		loader.property("_checkedPath", nullptr, Php::Protected);
		loader.property("_prefixes", nullptr, Php::Protected);
		loader.property("_classes", nullptr, Php::Protected);
		loader.property("_extensions", nullptr, Php::Protected);
		loader.property("_namespaces", nullptr, Php::Protected);
		loader.property("_directories", nullptr, Php::Protected);
		loader.property("_registered", false, Php::Protected);
		loader.property("_eventsManager", nullptr, Php::Protected);

		loader.method("__construct", &Phalcon::Loader::__construct);
		loader.method("register", &Phalcon::Loader::_register);
		loader.method("unregister", &Phalcon::Loader::unregister);

		phalconNamespace.add(std::move(loader));

		/* Class Phalcon\Dispatcher */
		Php::Class<Phalcon::Dispatcher> dispatcher("Dispatcher");

		dispatcher.property("_dependencyInjector", nullptr, Php::Protected);
		dispatcher.property("_eventsManager", nullptr, Php::Protected);
		dispatcher.property("_activeHandler", nullptr, Php::Protected);
		dispatcher.property("_finished", nullptr, Php::Protected);
		dispatcher.property("_forwarded", false, Php::Protected);
		dispatcher.property("_moduleName", nullptr, Php::Protected);
		dispatcher.property("_namespaceName", nullptr, Php::Protected);
		dispatcher.property("_handlerName", nullptr, Php::Protected);
		dispatcher.property("_actionName", nullptr, Php::Protected);
		dispatcher.property("_params", nullptr, Php::Protected);
		dispatcher.property("_returnedValue", nullptr, Php::Protected);
		dispatcher.property("_lastHandler", nullptr, Php::Protected);
		dispatcher.property("_defaultNamespace", nullptr, Php::Protected);
		dispatcher.property("_defaultHandler", nullptr, Php::Protected);
		dispatcher.property("_defaultAction", nullptr, Php::Protected);
		dispatcher.property("_handlerSuffix", nullptr, Php::Protected);
		dispatcher.property("_actionSuffix", "Action", Php::Protected);
		dispatcher.property("_previousHandlerName", nullptr, Php::Protected);
		dispatcher.property("_previousActionName", nullptr, Php::Protected);

		dispatcher.property("EXCEPTION_NO_DI", Phalcon::Dispatcher::EXCEPTION_NO_DI, Php::Const);
		dispatcher.property("EXCEPTION_CYCLIC_ROUTING", Phalcon::Dispatcher::EXCEPTION_CYCLIC_ROUTING, Php::Const);
		dispatcher.property("EXCEPTION_HANDLER_NOT_FOUND", Phalcon::Dispatcher::EXCEPTION_HANDLER_NOT_FOUND, Php::Const);
		dispatcher.property("EXCEPTION_INVALID_HANDLER", Phalcon::Dispatcher::EXCEPTION_INVALID_HANDLER, Php::Const);
		dispatcher.property("EXCEPTION_INVALID_PARAMS", Phalcon::Dispatcher::EXCEPTION_INVALID_PARAMS, Php::Const);
		dispatcher.property("EXCEPTION_ACTION_NOT_FOUND", Phalcon::Dispatcher::EXCEPTION_ACTION_NOT_FOUND, Php::Const);

		dispatcher.method("__construct", &Phalcon::Dispatcher::__construct);

		phalconNamespace.add(std::move(dispatcher));

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