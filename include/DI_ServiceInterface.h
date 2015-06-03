#ifndef PHALCON_DI_SERVICEINTERFACE_H
#define	PHALCON_DI_SERVICEINTERFACE_H

#include <phpcpp.h>

namespace Phalcon {

	/**
	 * Phalcon\DI\ServiceInterface
	 *
	 * Interface for Phalcon\DI
	 */
	class DI_ServiceInterface : public Php::Interface {
	public:

		/**
		 *  Constructor
		 *  @param  name
		 */
		DI_ServiceInterface(const char *name) : Interface(name) {
			method("getName");
			method("setShared",{
				Php::ByVal("shared", Php::Type::Bool, true),
			});
			method("isShared");
			method("setDefinition",{
				Php::ByVal("shared", Php::Type::Bool, true),
			});
			method("getDefinition");
			method("isResolved");
			method("resolve");
		}
	};

} // namespace Phalcon

#endif	/* PHALCON_DI_SERVICEINTERFACE_H */