
# Copyright (c) 2018 Kanishchev Konstantin.
# All rights reserved.

import numpy as np

class Particle(object):
    class KinematicProvider(object):

        def _p(self):
            return self.momentum 

        def _R(self):
            return self.momentum / self.q
        
        def _E(self):
            if self._val_E is None:
                p, m = self.momentum, self.m
                self._val_E = np.sqrt(p**2 + m**2)
            return self._val_E

        def _Ek(self):
            if self._val_Ek is None:
                self._val_Ek = self._E() - self.m
            return self._val_Ek

        def _Ekn(self):
            return self._Ek()/self.n
        
        def _beta(self):
            if self._val_beta is None:
                self._val_beta = self.momentum / self._E()
            return self._val_beta
        
        
        def __init__(self, momentum, m, q=1, n=1):
            self.momentum = momentum
            self.m, self.q, self.n = m, q, n            
            self._val_beta = None
            self._val_E = None
            self._val_Ek = None
            self.dispatchdict = {
                "p":self._p,                
                "R":self._R,
                "E":self._E,
                "Ek":self._Ek,
                "Ekn":self._Ekn,
                "beta":self._beta
            }
            
        def __getattr__(self, name):
            if name not in self.dispatchdict:
                raise AttributeError
            return self.dispatchdict[name]()        
        
    def __init__(self, m, q=1, n=1):
        self.m = m
        self.q = q
        self.n = n
        
    def p(self, p):
        return Particle.KinematicProvider(p, self.m, q=self.q, n=self.n)
        
    def R(self, R):
        return Particle.KinematicProvider(R*self.q, self.m, q=self.q, n=self.n)

    def beta(self, beta):
        p = self.m * beta / np.sqrt(1.0 - beta**2)
        return Particle.KinematicProvider(p, self.m, q=self.q, n=self.n)
    
    def E(self, E):
        p = np.sqrt( E**2 - self.m**2)
        return Particle.KinematicProvider(p, self.m, q=self.q, n=self.n)
    
    def Ek(self, Ek):
        return self.E(Ek + self.m)

    def Ekn(self, Ek):
        return self.E(self.n * Ek + self.m)

