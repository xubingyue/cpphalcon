<?php

class Test extends \Phalcon\DI\Injectable {}

class DIInjectableTest extends PHPUnit_Framework_TestCase
{
	public function testBasic()
	{
		$test = new \Test;
		$this->assertTrue(is_object($test));
		$this->assertTrue(method_exists($test, 'getDI'));
	}
}
