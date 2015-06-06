#ifndef PHALCON_DEBUG_H
#define PHALCON_DEBUG_H

#include <phpcpp.h>

namespace Phalcon
{

	class Debug : public Php::Base
	{
	public:
		Debug();
		virtual ~Debug();

		template<typename T>
		static void Init(Php::Class<T> &debug)
		{
			/**
			 * Change the base URI for static resources
			 */
			debug.method("setUri", &Phalcon::Debug::setUri, {
				Php::ByVal("uri", Php::Type::String),
			});
			debug.method("setShowBackTrace", &Phalcon::Debug::setShowBackTrace, {
				Php::ByVal("showBackTrace", Php::Type::Bool),
			});
			debug.method("setShowFiles", &Phalcon::Debug::setShowFiles, {
				Php::ByVal("showFiles", Php::Type::Bool),
			});
			debug.method("setShowFileFragment", &Phalcon::Debug::setShowFileFragment, {
				Php::ByVal("showFileFragment", Php::Type::Bool),
			});
			debug.method("listen", &Phalcon::Debug::listen, {
				Php::ByVal("exceptions", Php::Type::Bool),
				Php::ByVal("lowSeverity", Php::Type::Bool),
			});
			debug.method("listenExceptions", &Phalcon::Debug::listenExceptions);
			debug.method("listenLowSeverity", &Phalcon::Debug::listenLowSeverity);
			debug.method("halt", &Phalcon::Debug::halt);
			debug.method("debugVar", &Phalcon::Debug::debugVar, {
				Php::ByVal("varz"),
				Php::ByVal("key", Php::Type::String),
			});
			debug.method("clearVars", &Phalcon::Debug::debugVar);
			debug.method("getMajorVersion", &Phalcon::Debug::getMajorVersion);
			debug.method("getVersion", &Phalcon::Debug::getVersion);
			debug.method("getCssSources", &Phalcon::Debug::getCssSources);
			debug.method("getJsSources", &Phalcon::Debug::getJsSources);
			debug.method("showTraceItem", &Phalcon::Debug::showTraceItem, {
				Php::ByVal("n", Php::Type::Numeric),
				Php::ByVal("trace", Php::Type::Array),
			});
			debug.method("onUncaughtLowSeverity", &Phalcon::Debug::onUncaughtLowSeverity, {
				Php::ByVal("severity", Php::Type::Numeric),
				Php::ByVal("message", Php::Type::String),
				Php::ByVal("file", Php::Type::String),
				Php::ByVal("line", Php::Type::Numeric),
			});
			debug.method("onUncaughtException", &Phalcon::Debug::onUncaughtException, {
				Php::ByVal("exception", "Exception"),
			});
		}

		/**
		 * Change the base URI for static resources
		 *
		 * @param string $uri
		 * @return Phalcon\Debug
		 */
		Php::Value setUri(Php::Parameters &params);

		/**
		 * Sets if files the exception's backtrace must be showed
		 *
		 * @param boolean $showBackTrace
		 * @return Phalcon\Debug
		 */
		Php::Value  setShowBackTrace(Php::Parameters &params);

		/**
		 * Set if files part of the backtrace must be shown in the output
		 *
		 * @param boolean $showFiles
		 * @return Phalcon\Debug
		 */
		Php::Value setShowFiles(Php::Parameters &params);

		/**
		 * Sets if files must be completely opened and showed in the output
		 * or just the fragment related to the exception
		 *
		 * @param boolean $showFileFragment
		 * @return Phalcon\Debug
		 */
		Php::Value setShowFileFragment(Php::Parameters &params);

		/**
		 * Listen for uncaught exceptions and unsilent notices or warnings
		 *
		 * @param boolean $exceptions
		 * @param boolean $lowSeverity
		 * @return Phalcon\Debug
		 */
		Php::Value listen(Php::Parameters &params);

		/**
		 * Listen for uncaught exceptions
		 *
		 * @return Phalcon\Debug
		 */
		Php::Value listenExceptions();

		/**
		 * Listen for unsilent notices or warnings or user-defined error
		 *
		 * @return Phalcon\Debug
		 */
		Php::Value listenLowSeverity();

		/**
		 * Halts the request showing a backtrace
		 */
		void halt();

		/**
		 * Adds a variable to the debug output
		 *
		 * @param mixed $var
		 * @param string $key
		 * @return Phalcon\Debug
		 */
		Php::Value debugVar(Php::Parameters &params);

		/**
		 * Clears are variables added previously
		 *
		 * @return Phalcon\Debug
		 */
		Php::Value clearVars();

		/**
		 * Returns the major framework's version
		 *
		 * @return string
		 */
		Php::Value getMajorVersion();

		/**
		 * Generates a link to the current version documentation
		 *
		 * @return string
		 */
		Php::Value getVersion();

		/**
		 * Returns the css sources
		 *
		 * @return string
		 */
		Php::Value  getCssSources();

		/**
		 * Returns the javascript sources
		 *
		 * @return string
		 */
		Php::Value getJsSources();

		/**
		 * Shows a backtrace item
		 *
		 * @param int $n
		 * @param array $trace
		 */
		Php::Value showTraceItem(Php::Parameters &params);

		/**
		* Throws an exception when a notice or warning is raised
		*
		* @param int $severity
		* @param string $message
		* @param string $file
		* @param string $line
		* @return boolean
		 */
		void onUncaughtLowSeverity(Php::Parameters &params);

		/**
		 * Handles uncaught exceptions
		 *
		 * @param \Exception $exception
		 * @return boolean
		 */
		Php::Value onUncaughtException(Php::Parameters &params);

	protected:
	private:
	};

} // namespace Phalcon

#endif // PHALCON_DEBUG_H
