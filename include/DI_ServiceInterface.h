#ifndef PHALCON_DI_SERVICEINTERFACE_H
#define	PHALCON_DI_SERVICEINTERFACE_H

#include <phpcpp.h>

namespace Phalcon
{

	/**
	 * Phalcon\Di\ServiceInterface
	 *
	 * Represents a service in the services container
	 */
	class DI_ServiceInterface : public Php::Interface
	{
	public:

		/**
		 *  Constructor
		 *  @param  name
		 */
		DI_ServiceInterface(const char *name) : Interface(name)
		{
			/**
			 * Phalcon\Di\ServiceInterface
			 *
			 * @param string name
			 * @param mixed definition
			 * @param boolean shared
			 */
			method("__construct", {
				Php::ByVal("name", Php::Type::String),
				Php::ByVal("definition", Php::Type::Null),
				Php::ByVal("shared", Php::Type::Bool, false),
			});

			/**
			 * Returns the service's name
			 *
			 * @param string
			 */
			method("getName");

			/**
			 * Sets if the service is shared or not
			 */
			method("setShared", {
				Php::ByVal("shared", Php::Type::Bool),
			});

			/**
			 * Check whether the service is shared or not
			 */
			method("isShared");

			/**
			 * Set the service definition
			 *
			 * @param mixed definition
			 */
			method("setDefinition", {
				Php::ByVal("shared", Php::Type::Bool),
			});

			/**
			 * Returns the service definition
			 *
			 * @return mixed
			 */
			method("getDefinition");

			/**
			 * Resolves the service
			 *
			 * @param array parameters
			 * @param Phalcon\DiInterface dependencyInjector
			 * @return mixed
			 */
			method("isResolved");

			/**
			 * Restore the interal state of a service
			 */
			method("resolve");
		}
	};

} // namespace Phalcon

#endif	/* PHALCON_DI_SERVICEINTERFACE_H */
