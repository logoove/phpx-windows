/*
  +----------------------------------------------------------------------+
  | Swoole                                                               |
  +----------------------------------------------------------------------+
  | This source file is subject to version 2.0 of the Apache license,    |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.apache.org/licenses/LICENSE-2.0.html                      |
  | If you did not receive a copy of the Apache2.0 license and are unable|
  | to obtain it through the world-wide-web, please send a note to       |
  | license@swoole.com so we can mail you a copy immediately.            |
  +----------------------------------------------------------------------+
  | Author: Tianfeng Han  <mikan.tenny@gmail.com>                        |
  +----------------------------------------------------------------------+
*/

#include "phpx.h"

#include <iostream>

using namespace php;
using namespace std;

PHPX_FUNCTION(dump)
{
	
	Variant a = args[0];
	php::echo("<pre>");
	Variant  str = php::exec("print_r", a);
	php::echo("</pre>");
    //php::echo("argc=%d\n", args.count());
    //php::error(E_WARNING, "extension warning.");
}
/*
PHPX_METHOD(myClass, test)
{
    cout << "myClass::test" << endl;
    retval = 1234.56;
}

PHPX_METHOD(myClass, pget)
{
    String *str = _this.oGet<String>("resource", "ResourceString");
    cout << "ResourceString: " << str->length() << endl;
}

PHPX_METHOD(myClass, pset)
{
    _this.oSet("resource", "ResourceString", new String("hello world"));
}*/
/*
void string_dtor(zend_resource *res)
{
    String *s = static_cast<String *>(res->ptr);
    delete s;
}*/

PHPX_EXTENSION()
{
    Extension *extension = new Extension("dump", "1.0.0");

    extension->onStart = [extension]() noexcept
    {
        extension->registerConstant("DUMP_VERSION", 1002);

        /*Class *c = new Class("myClass");
        c->addMethod(PHPX_ME(myClass, test), STATIC);
        c->addMethod(PHPX_ME(myClass, pget));
        c->addMethod(PHPX_ME(myClass, pset));
        extension->registerClass(c);

        extension->registerResource("ResourceString", string_dtor);*/
    };


    extension->registerFunction(PHPX_FN(dump));
    //extension->registerFunction(PHPX_FN(cpp_ext_test2));

    extension->info(
    {
        "dump support", "enabled"
    },
    {
        { "author", "Yoby" },
        { "version", extension->version },
		{ "qq", "280594236"},
		{ "wechat", "logove"},
        { "date", "2019-11-23" },
    });

    return extension;
}
