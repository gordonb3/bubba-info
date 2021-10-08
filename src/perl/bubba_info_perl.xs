#include "EXTERN.h"
#include "perl.h"
#include "XSUB.h"

#include "ppport.h"


MODULE = bubba_info_perl PACKAGE = Bubba::Info

#include <bubba-info.h>
int
getHWType()

int
isB1()

int
isB2()

int
isB3()
