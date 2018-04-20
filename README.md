This single-file library can be used to perform conversions between kinematic variables for various particles. The goal is to have a straightforward method-chaining interface that allows for transparent conversion between the variables:    
```c++
Particle proton(0.938, 1, 1); // mass [GeV], charge, nucleons
proton.beta(0.95).p(); // calculates the momentum of a beta=0.95 proton
proton.Ek(1.7).beta(); // calculates velocity of a proton with E_kin=1.7 GeV 
```  
The variables provided are:

 - velocity `beta`
 - momentum `p`
 - rigidity `R`
 - total energy `E`
 - kinetic energy `Ek`
 - kinetic energy per nucleon `Ekn`
 
 
 


## Python version

