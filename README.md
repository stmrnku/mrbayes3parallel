# mrbayes_3.2.6_parallel

1. Introduction
2. Getting Started
3. License and Warranty
-------------------------------------------------------------------------------

1. Introduction

CPU Parallel MrBayes version 3.2.6 is a modified version of MrBayes (version 3.2.6) that enables running Metropolis coupled Markov chain Monte Carlo (MC)^3 sampling on a private single-node server.

MrBayes 3.2.6 has an assortment of new features compared to its earlier versions. Here we implement acceleration for DNA and protein module.

Take protein module as example, in this version we exclusively focus on data with rates = gamma which are set with the lset command, and the format setting:

		datatype = protein

-------------------------------------------------------------------------------

2. Getting Started

Here, these following instructions show that how to configure the CPU parallel MrBayes and get it running.

(a)To make sure you have these prerequisites.

Hardware Requirements:
		
	CPU: We use Intel Xeon E5-2650 v4 CPU, each CPU has 12 physical cores.
	
Software Requirements:
	
  	mrbayes_3.2.6_parallel.zip : the zip file of source code
	OS: We have tested on Linux CentOS 6.5
	C compiler: gcc 5.5.0 is used
	MPI (if you need mpi): OpenMPI 1.10.6

(b) Unpack the zip file and go to the top level directory:
	
	unzip mrbayes_3.2.6_parallel.zip
	cd mrbayes_3.2.6_parallel

(c) Configure CPU Parallel MrBayes specifying the building configure:
   
   If you want to use MPI, open 'config.h' and change '#undef MPI_ENABLED' to '#define MPI_ENABLED 1'.

    Configure: 
    If using MPI:
		
    	./configure --enable-mpi --with-beagle=no
    
    else:

    	./configure --with-beagle=no

(d)Set other parallel options:
     
   If you want to use SSE/AVX:
	
	(1) open 'bayes.h':
		
		change '#undef SSE_ENABLED' ('#undef AVX_ENABLED') to '#define SSE_ENABLED 1' ('#define AVX_ENABLED 1').
	
	NOTICE: These two options cannot be defined simultaneously.
	
	(2) if you want to use AVX, then open 'Makefile', find 'CFLAGS', and append		
	
 		 -mavx
	
	to the end of the line.
	
   If you want to use multi-threaded version:
	
	(1) Open 'bayes.h':
		
		change '#undef FINE_GRAINED' to '#define FINE_GRAINED 1'
	
	(2) Open 'likelihood.h'
		
		find 'NUM_THREAD' , then change the number to your desired number of threads.
	
	(3) Open 'Makefile':
		
	   find 'CFLAGS', then append
	   	
		-pthread
	   
	   to the end of this line.

(e) Build CPU parallel MrBayes:
	
   for all shells:

		make
(f) Install CPU parallel MrBayes:
	
CPU parallel Mrbayes does not need to be installed. You can simply copy the file 'mb' to your declinational directory.

(g) Run CPU parallel MrBayes:

if compile without mpi: 
  
	./mb (your data address)
otherwise: 

	mpirun -n (number of process) ./mb (your data address)
For example, if 'mb' is in the same directory as your data: 

	mpirun -n 4 ./mb data/dataset1.nex 

For more operating and experiment details, please see 'MrBayes version 3.2 Manual' and our paper " A Three-Level Parallel Algorithm for MrBayes 3.2 "

3. License and Warranty

CPU parallel MrBayes is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 3 of the License, or (at your option) any later version.
The program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details

	(http://www.gnu.org/copyleft/gpl.html).
	

