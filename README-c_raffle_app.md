# Raffle
A simple solution to a bigger problem. This project creates a raffle to participate 
in with randomly generated ticket numbers. There was a list of participants, and 
upon completion of selecting a winner, an email or text should be generated to 
inform the winning ticket holder. After sample upload I will verify program working
order, as it was not designed to be platform agnostic, and was created on an older
Debian machine.

The entry point to main is in raf_main.c. I am still looking for the Makefile, but 
I do believe this project is in its entirety and could be rebuilt and run with
little modification. After updating all my samples I will come back and add in a 
Cmake and test with clang. I will verify integrity of this application when 
updating the steps needed to build for MacOS.