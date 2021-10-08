
PHP_ARG_ENABLE(bubbainfo, whether to enable Bubba Info support,
			   [ --enable-bubba-info   Enable Bubba Info support])

if test "$PHP_BUBBAINFO" = "yes"; then

	PHP_ADD_LIBRARY([bubba-info],1,BUBBAINFO_SHARED_LIBADD)

	AC_DEFINE(HAVE_PHP_BUBBAINFO, 1, [Whether you have Bubba Info])
	PHP_NEW_EXTENSION(bubbainfo, bubba_info.c, $ext_shared)
	PHP_SUBST(BUBBAINFO_SHARED_LIBADD)

fi
