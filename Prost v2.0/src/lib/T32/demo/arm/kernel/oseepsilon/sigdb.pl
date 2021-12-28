#!/usr/bin/perl -w

print "/* Epsilon SigDb */\n";
print "/* Usage: sigdb.pl <.sig> <.sig> ... >all_sig.c */\n"

my $input;
$x = "0";
while($input = shift @ARGV){
    if ( -r $input && -f $input){
#	print "Processing $input\n";
	push(@files,$input);
	open(IN,$input);
	while(<IN>){
	    if ( m/SIGNO\([\t ]*(.*)[\t ]*\)/ ){
		$struct = $1;
		/\#define[\t ]*([A-Z0-9_]*)[\t ]*\(([0-9]*)\)/;
#		print $1."---".$2."\n";	      
		if ( defined($2) ){
		    push(@structs,($struct,$1,$2));
		} else {
		    $x = $x+1;
		    push(@structs,($struct,$1,$x));
		}
		
	    }
	}
    }
}
printf "#include <ose.h>\n";

foreach (@files){
    print "#include \"$_\"\n";
}
print "union ALL_SIGNALS {\n";
while(@structs){
    $s = shift @structs;
    $n = shift @structs;
    $i = shift @structs;
    $s =~ m/^struct[\t ]+(.*)/;
    print "$s _$i"."_$1;";
    print "\t/* $n */\n";
}    
print "};\n";

print "volatile union ALL_SIGNALS *all_signalS = (union ALL_SIGNALS *)0;\n";
