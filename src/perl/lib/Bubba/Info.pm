package Bubba::Info;

use 5.010001;
use strict;
use warnings;

require Exporter;

our @ISA = qw(Exporter);

our @EXPORT = qw(
	getHWType
	isB1
	isB2
	isB3
);

our $VERSION = '1.0';

require XSLoader;
XSLoader::load('bubba_info_perl', $VERSION);

# Preloaded methods go here.

1;
__END__

=head1 NAME

Bubba::Info - Perl extension for querying Bubba platform information

=head1 SYNOPSIS

  use Bubba::Info;
  

=head1 DESCRIPTION

Stub documentation for bubba_ident, created by h2xs. It looks like the
author of the extension was negligent enough to leave the stub
unedited.

Blah blah blah.

=head2 EXPORT

None by default.



=head1 SEE ALSO

Mention other useful documentation such as the documentation of
related modules or operating system documentation (such as man pages
in UNIX), or any relevant external documentation such as RFCs or
standards.

If you have a mailing list set up for your module, mention it here.

If you have a web site set up for your module, mention it here.

=head1 AUTHOR

Carl Fürstenberg, E<lt>carl@E<gt>

=head1 COPYRIGHT AND LICENSE

Copyright (C) 2010 by Carl Fürstenberg

This library is free software; you can redistribute it and/or modify
it under the same terms as Perl itself, either Perl version 5.10.1 or,
at your option, any later version of Perl 5 you may have available.


=cut
