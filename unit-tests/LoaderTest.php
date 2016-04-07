<?php

class LoaderTest extends PHPUnit_Framework_TestCase
{
	public function testBasic()
	{
		$loader = new \Phalcon\Loader;
		$this->assertTrue(is_object($loader));
		$this->assertTrue(method_exists($loader, 'getEventsManager'));
		$this->assertTrue(method_exists($loader, 'register'));
	}
}
