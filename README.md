# Science Fair 1985

This is a transcription of one of my fist C programs. It was created for my high school science fair in 1985.

This version of the code comes from the print outs I'd made for display. There are bugs (some of which are pointed out by penciled annotations), and it seems unlikely that this version ever compiled.

The code was written on and (eventually) ran on a Vax 11/780 running VMS.

The program simulated the system of a _primary_ (i.e. a star or planet), its _planets_ (i.e. planets or satellites), and a spaceship travelling among them. When the ship came within a certain distance of a _planet_, the simulation would then load the system of that _planet_. When the ship got to the "edge" of the current system, it would load the parent system.

The simulation is naively implemented. When finished, it did not work well, but it did work enough to demonstrate to the judges.

In 1985, the only computers in my high school were a few TRS-80 Model III in the business department and perhaps a few personal Apple IIe that science teachers had brought in. The newspaper and yearbook did share a typesetting machine, but it wasn't a general purpose system. Since my demonstration required a phone line for the modem to connect my terminal to the Vax, I was set up in an office away from the other projects.
