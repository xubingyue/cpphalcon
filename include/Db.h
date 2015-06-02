#ifndef PHALCON_DB_H
#define	PHALCON_DB_H

#include <phpcpp.h>

namespace Phalcon {

	/**
	 * Phalcon\Db
	 *
	 * Phalcon\Db and its related classes provide a simple SQL database interface for Phalcon Framework.
	 * The Phalcon\Db is the basic class you use to connect your PHP application to an RDBMS.
	 * There is a different adapter class for each brand of RDBMS.
	 *
	 * This component is intended to lower level database operations. If you want to interact with databases using
	 * higher level of abstraction use Phalcon\Mvc\Model.
	 *
	 * Phalcon\Db is an abstract class. You only can use it with a database adapter like Phalcon\Db\Adapter\Pdo
	 */
	class Db : public Php::Base {
	public:

		/**
		 * Enables/disables options in the Database component
		 */
		static void setup(Php::Parameters &params);

	private:

	};

} // namespace Phalcon

#endif	/* PHALCON_DB_H */

