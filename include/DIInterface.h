#ifndef PHALCON_DIINTERFACE_H
#define	PHALCON_DIINTERFACE_H

#include <phpcpp.h>

namespace Phalcon {

	/**
	 * Phalcon\DIInterface
	 *
	 * Interface for Phalcon\DI
	 */
	class DIInterface : public Php::Interface {
	public:

		/**
		 *  Constructor
		 *  @param  name
		 */
		DIInterface(const char *name) : Interface(name) {
			method("set",{
				Php::ByVal("name", Php::Type::String, true),
				Php::ByVal("definition", Php::Type::Null, true),
				Php::ByVal("shared", Php::Type::Bool, false),
			});
			method("setShared",{
				Php::ByVal("name", Php::Type::String, true),
				Php::ByVal("definition", Php::Type::Null, true),
			});
			method("get",{
				Php::ByVal("name", Php::Type::String, true),
				Php::ByVal("parameters", Php::Type::Array, false),
			});
			method("getShared",{
				Php::ByVal("name", Php::Type::String, true),
				Php::ByVal("parameters", Php::Type::Array, false),
			});
			method("remove",{
				Php::ByVal("name", Php::Type::String, true),
			});
			method("setService",{
				Php::ByVal("name", Php::Type::String, true),
				Php::ByVal("parameters", "Phalcon\\DI\\ServiceInterface", true),
			});
			method("getService",{
				Php::ByVal("name", Php::Type::String, true),
			});
			method("has",{
				Php::ByVal("name", Php::Type::String, true),
			});
			method("wasFreshInstance");
			method("getServices");
		}
	};

} // namespace Phalcon

#endif	/* PHALCON_DIINTERFACE_H */