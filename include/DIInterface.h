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
			/**
			 * Registers a service in the services container
			 *
			 * @param string name
			 * @param mixed definition
			 * @param boolean shared
			 * @return Phalcon\Di\ServiceInterface
			 */
			method("set",{
				Php::ByVal("name", Php::Type::String),
				Php::ByVal("definition", Php::Type::Null),
				Php::ByVal("shared", Php::Type::Bool, false),
			});

			/**
			 * Registers an "always shared" service in the services container
			 *
			 * @param string name
			 * @param mixed definition
			 * @return Phalcon\Di\ServiceInterface
			 */
			method("setShared",{
				Php::ByVal("name", Php::Type::String),
				Php::ByVal("definition", Php::Type::Null),
			});

			/**
			 * Removes a service in the services container
			 */
			method("remove",{
				Php::ByVal("name", Php::Type::String),
			});

			/**
			 * Attempts to register a service in the services container
			 * Only is successful if a service hasn't been registered previously
			 * with the same name
			 *
			 * @param string name
			 * @param mixed definition
			 * @param boolean shared
			 * @return Phalcon\Di\ServiceInterface
			 */
			method("attempt",{
				Php::ByVal("name", Php::Type::String),
				Php::ByVal("definition", Php::Type::Null),
				Php::ByVal("shared", Php::Type::Bool, false),
			});

			/**
			 * Resolves the service based on its configuration
			 *
			 * @param string name
			 * @param array parameters
			 * @return mixed
			 */
			method("get",{
				Php::ByVal("name", Php::Type::String),
				Php::ByVal("parameters", Php::Type::Array, false),
			});

			/**
			 * Returns a shared service based on their configuration
			 *
			 * @param string name
			 * @param array parameters
			 * @return mixed
			 */
			method("getShared",{
				Php::ByVal("name", Php::Type::String),
				Php::ByVal("parameters", Php::Type::Array, false),
			});

			/**
			 * Sets a service using a raw Phalcon\Di\Service definition
			 */
			method("setRaw",{
				Php::ByVal("name", Php::Type::String),
				Php::ByVal("rawDefinition", Php::Type::Object),
			});
			/**
			 * Returns a service definition without resolving
			 *
			 * @param string name
			 * @return mixed
			 */
			method("getRaw",{
				Php::ByVal("name", Php::Type::String),
			});

			/**
			 * Returns the corresponding Phalcon\Di\Service instance for a service
			 */
			method("getService",{
				Php::ByVal("name", Php::Type::String),
			});

			/**
			 * Check whether the DI contains a service by a name
			 */
			method("has",{
				Php::ByVal("name", Php::Type::String),
			});

			/**
			 * Check whether the last service obtained via getShared produced a fresh instance or an existing one
			 */
			method("wasFreshInstance");

			/**
			 * Return the services registered in the DI
			 *
			 * @return array
			 */
			method("getServices");

			/**
			 * Set a default dependency injection container to be obtained into static methods
			 */
			method("setDefault",{
				Php::ByVal("dependencyInjector", Php::Type::Object),
			});

			/**
			 * Return the last DI created
			 */
			method("getDefault");

			/**
			 * Resets the internal default DI
			 */
			method("reset");
		}
	};

} // namespace Phalcon

#endif	/* PHALCON_DIINTERFACE_H */