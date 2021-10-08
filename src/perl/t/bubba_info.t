# Before `make install' is performed this script should be runnable with
# `make test'. After `make install' it should work as `perl bubba_ident.t'

#########################

# change 'tests => 1' to 'tests => last_test_to_print';

use Test::More tests => 2;
BEGIN { use_ok('Bubba::Info') };

SKIP: {
	skip "platform dependent test, testing for platform makes a recursive requirment", 1;
	is( getHWType(), 3, 'armv5tel' )
};

#########################

# Insert your test code below, the Test::More module is use()ed here so read
# its man page ( perldoc Test::More ) for help writing this test script.

