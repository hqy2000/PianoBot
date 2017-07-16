    # Convert the note on/off events to frequency/duration pair
	# 1. Create the midi notes2frequency table. Tuning is based upon A=440
	my $a = 440; # a is 440 hz...
	my @midi;
	for($x = 0; $x < 127; ++$x)
	{
		$midi[$x] = ($a / 32) * (2 ** (($x - 9) / 12));		
	}
	# 2. Parse the channel events
    my $note_on = 0;
	my $note_on_time = 0;
	my $note = 0;
	my $velocity = 0;
	my $end_time = 0;
	print("//frequency, volume, duration}\n");
    while ($a = <>) {
    	if (!($a =~ m/\s*[\#\;]/)) { 	# Ignore comment lines
			# match note on
			if ($a =~ m/\s*\d+\s*,\s*(\d+)\s*,\s*Note_on_c\s*,\s*(\d+)\s*,\s*(\d+)\s*,\s*(\d+)\s*/) {
				# $1 time, $2 channel, $3 note, $4 velocity
				if(!$note_on) {
					$note_on = 1;					
				} else {
					print($note_on_time." ".$note." ".($1 - $note_on_time)." \n");					
				}				
				$note_on_time = $1;
				$note = $3;
				$velocity = $4;
			}
			# match note off
			elsif ($a =~ m/\s*\d+\s*,\s*\d+\s*,\s*Note_off_c\s*,\s*(\d+)/){
				if($note_on) {
					$note_on = 0;
					print($note_on_time." ".$note." ".($1 - $note_on_time)." \n");	
				}
			}
			# match end of track
			elsif ($a =~ m/\s*\d+\s*,\s*(\d+)\s*,\s*End_track\s*/){
				$end_time = $1;
			}
		}
	}
	# The last note may not be set off
	if($note_on) {
		print($note_on_time." ".$note." ".($end_time - $note_on_time)." \n");	
	}
