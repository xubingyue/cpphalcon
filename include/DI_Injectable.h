#ifndef PHALCON_DI_INJECTABLE_H
#define PHALCON_DI_INJECTABLE_H

#include <phpcpp.h>

namespace Phalcon {

	/**
	 * Phalcon\DI\Injectable
	 *
	 * This class allows to access services in the services container by just only accessing a public property
	 * with the same name of a registered service
	 */
	class DI_Injectable : public Php::Base {
	protected:
		Php::Value _dependencyInjector;
		Php::Value _eventsManager;

	public:

		DI_Injectable()
		{
		}

		virtual ~DI_Injectable()
		{
		}

		template<typename T>
		static void Init(Php::Class<T> &di_injectable)
		{
			di_injectable.method("setDI", &Phalcon::DI_Injectable::setDI,{
				Php::ByVal("dependencyInjector", "Phalcon\\DIInterface"),
			});
			di_injectable.method("getDI", &Phalcon::DI_Injectable::getDI);
			di_injectable.method("setEventsManager", &Phalcon::DI_Injectable::setEventsManager,{
				Php::ByVal("eventsManager", "Phalcon\\Events\\ManagerInterface"),
			});
			di_injectable.method("getEventsManager", &Phalcon::DI_Injectable::getEventsManager);
		}

		/**
		 * Sets the dependency injector
		 */
		void setDI(Php::Parameters &params)
		{
			_dependencyInjector = params[0];
		}

		Php::Value getDI()
		{

			return _dependencyInjector;
		}

		/**
		 * Sets the event manager
		 */
		void setEventsManager(Php::Parameters &params)
		{
			_eventsManager = params[0];
		}

		Php::Value getEventsManager()
		{

			return _eventsManager;
		}
	};
} // namespace Phalcon

#endif /* DI_INJECTABLE_H */

