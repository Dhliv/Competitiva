my $let = shift ;
my $n = shift ;
print "$n\n" ;
@a = ('a'..'z')[0..$let-1] ;
while ($n > 0) {
   for ($i=0; $i<@a; $i++) {
      $j = $i + int rand(@a-$i) ;
      $t = $a[$i] ;
      $a[$i] = $a[$j] ;
      $a[$j] = $t ;
   }
   my $w = join '', @a ;
   if (!$seen{$w}++) {
      $n-- ;
      print "$w\n" ;
   }
}
