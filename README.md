# Sample Application in C
A simple solution to a larger set of requirements in building a web-application with a networked system method patent. This project was a mock up for investors to see how we could create a raffle to participate in with randomly generated ticket numbers, select a winner, and notify them via their mobile device. 

## Requirements from Admit Split LLC

* Aggregated list/group of users.
* A mock up raffle for participants to "play" their luck with. 
* A random way to selecting a winner.
* An email or text generated to inform the winning ticket holder. 

The build was not designed to be platform agnostic, or even cloud based. It was built on a bare bones Debian machine.

The entry point to main is in raf_main.c. I am still looking for the Makefile, but I do believe this project is in its entirety and could be rebuilt and run with little modification. 

## Steps to modernize

* Describe steps necessary to cmake and test with clang. 
* Look into llvm, Docker, Openshift, K8's, pods, Jenkins, Ansible, Kafka, confluent build, or whatever micro-service solution to show knowledge of these technologies. 
* Look at docker hub for other images I have for c_test.

Still need to verify integrity of this application for MacOS after DR event.