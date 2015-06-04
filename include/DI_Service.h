#ifndef PHALCON_DI_SERVICE_H
#define	PHALCON_DI_SERVICE_H

#include <phpcpp.h>

namespace Phalcon
{

	/**
	 * Phalcon\DI\Service
	 *
	 * Represents individually a service in the services container
	 *
	 *<code>
	 * $service = new Phalcon\DI\Service('request', 'Phalcon\Http\Request');
	 * $request = $service->resolve();
	 *<code>
	 *
	 */
	class DI_Service : public Php::Base
	{
	protected:
		Php::Value _name;
		Php::Value _definition;
		Php::Value _shared = false;
		Php::Value _resolved = false;
		Php::Value _sharedInstance;

	public:

		DI_Service()
		{
		}

		virtual ~DI_Service()
		{
		}

		template<typename T>
		static void Init(Php::Class<T> &di_service)
		{
			di_service.method("__construct", &Phalcon::DI_Service::__construct, {
				Php::ByVal("name", Php::Type::String, true),
				Php::ByVal("definition", Php::Type::Null, true),
				Php::ByVal("shared", Php::Type::Bool, false),
			});
			di_service.method("setSharedInstance", {
				Php::ByVal("sharedInstance", Php::Type::Null, true),
			});
			di_service.method("setParameter", {
				Php::ByVal("position", Php::Type::Numeric, true),
				Php::ByVal("parameter", Php::Type::Array, true),
			});
			di_service.method("getParameter", {
				Php::ByVal("position", Php::Type::Numeric, true),
			});
		}

		/**
		 * Phalcon\DI\Service
		 *
		 * @param string $name
		 * @param mixed $definition
		 * @param boolean $shared
		 */
		void __construct(Php::Parameters &params);

		/**
		 * Returns the service's name
		 */
		Php::Value getName();

		/**
		 * Sets if the service is shared or not
		 */
		void setShared(Php::Parameters &params);

		/**
		 * Check whether the service is shared or not
		 */
		Php::Value isShared();


		/**
		 * Sets/Resets the shared instance related to the service
		 *
		 * @param mixed sharedInstance
		 */
		void setSharedInstance(Php::Parameters &params);

		/**
		 * Set the service definition
		 *
		 * @param mixed definition
		 */
		void setDefinition(Php::Parameters &params);

		/**
		 * Returns the service definition
		 *
		 * @return mixed
		 */
		Php::Value getDefinition();

		/**
		 * Resolves the service
		 *
		 * @param array parameters
		 * @param Phalcon\DiInterface dependencyInjector
		 * @return mixed
		 */
		Php::Value resolve(Php::Parameters &params);

		/**
		 * Changes a parameter in the definition without resolve the service
		 */
		Php::Value setParameter(Php::Parameters &params);

		/**
		 * Returns a parameter in a specific position
		 *
		 * @param int position
		 * @return array
		 */
		Php::Value getParameter(Php::Parameters &params);

		/**
		 * Returns true if the service was resolved
		 */
		Php::Value isResolved();
	};

} // namespace Phalcon

#endif
