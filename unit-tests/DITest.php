<?php

class DITest extends PHPUnit_Framework_TestCase
{
	public function testBasic()
	{
		$di = \Phalcon\DI::getDefault();
		$this->assertNull($di);
		
		$di = new \Phalcon\DI();
		$this->assertTrue(is_object($di));

		$di = \Phalcon\DI::getDefault();
		$this->assertTrue(is_object($di));
	}
}
