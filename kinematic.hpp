#include <cmath>
#include <vector>
#include <algorithm>
#include <functional>

template<typename T>
class KinematicProvider{};

template<>
class KinematicProvider<double>
{
    double mass;
    int charge, nucleons;
    double momentum;
    double energy, kinetic;

public:
    double p(){ return momentum; }
    double R(){ return momentum / charge; }
    double Ekn(){ return Ek() / nucleons; }    

    double E(){  
        if(energy < 0) 
            energy = std::sqrt(momentum*momentum + mass*mass);
        return energy;
    }

    double Ek(){  
        if(kinetic < 0) kinetic = E() - mass;
        return kinetic;
    }

    KinematicProvider(double m, int q, int n, double p):
        mass(m), charge(q), nucleons(n), momentum(p)
        { energy = -1; kinetic = -1;}
};

template<>
class KinematicProvider< std::vector<double> >
{
    double mass;
    int charge, nucleons;
    std::vector<double> momentum, rigidity;
    std::vector<double> energy, kinetic, kineticN;

    void transform (
        std::vector<double> & in, 
        std::vector<double> & out, 
        std::function<double(double)> f
    ) {
        if(!out.empty()) return;
        std::transform(in.begin(), in.end(), std::back_inserter(out), f);
    }

public:
    std::vector<double> p(){ return momentum; }
    std::vector<double> R(){ 
        transform(momentum, rigidity, [this](double p){ return p / charge; });
        return rigidity; 
    }
    std::vector<double> Ekn(){
        if(kinetic.empty()) { Ek(); }
        transform(kinetic, kineticN, [this](double Ek){ return Ek / nucleons;} );
        return kineticN; 
    }
    std::vector<double> E(){  
        transform(momentum, energy, 
            [this](double p){ return std::sqrt(p*p + mass*mass);} 
        );
        return energy;
    }
    std::vector<double> Ek(){  
        if(energy.empty()) { E(); } 
        transform( energy, kinetic, [this](double E){ return E - mass;} );
        return kinetic;
    }

    KinematicProvider(double m, int q, int n, const std::vector<double> & p):
        mass(m), charge(q), nucleons(n), momentum(p)
    { 
        energy = std::vector<double>(); 
        kinetic = std::vector<double>();
        rigidity = std::vector<double>();
    }
};


class Particle 
{
    double mass;
    int charge, nucleons;

    std::vector<double> transform (
        const std::vector<double> & in, 
        std::function<double(double)> f
    ) {
        std::vector<double> out;
        std::transform(in.begin(), in.end(), std::back_inserter(out), f);
    }

public:
    Particle(double m, int q, int n):
        mass(m), charge(q), nucleons(n) {}
    
    // Single - number

    KinematicProvider<double> p(double p) 
        { return KinematicProvider<double>(mass, charge, nucleons, p); }

    KinematicProvider<double> R(double R) { return p(R*charge); }

    KinematicProvider<double> beta(double beta) 
        { return p(mass * beta / std::sqrt(1.0 - beta * beta)); }

    KinematicProvider<double> E(double E) 
        { return p(std::sqrt(E * E - mass * mass)); }

    KinematicProvider<double> Ek(double Ek) { return E(Ek + mass); }

    KinematicProvider<double> Ekn(double Ekn) { return E(nucleons * Ekn + mass); }

    // Vectorized
    
    KinematicProvider<std::vector<double> > p(const std::vector<double> & p) 
        {   return KinematicProvider<std::vector<double> >(mass, charge, nucleons, p); }

    KinematicProvider<std::vector<double> > R(const std::vector<double> & R) 
    { 
        return p(transform(R, 
            [this](double R){return R*charge;}
        )); 
    }

    KinematicProvider<std::vector<double> > beta(const std::vector<double> & beta) 
    { 
        return p(transform(beta, 
            [this](double beta){ 
                return mass * beta / std::sqrt(1.0 - beta * beta);
            }
        )); 
    }

    KinematicProvider<std::vector<double> > E(const std::vector<double> & E) 
    { 
        return p(transform(E, 
            [this](double E){ 
                return std::sqrt(E * E - mass * mass);
            }
        )); 
    }

    KinematicProvider<std::vector<double> > Ek(const std::vector<double> & Ek) 
    { 
        return E(transform(Ek, 
            [this](double Ek) { 
                return Ek + mass;
            }
        )); 
    }

    KinematicProvider<std::vector<double> > Ekn(const std::vector<double> & Ekn) 
    { 
        return E(transform(Ekn, 
            [this](double Ekn) { 
                return Ekn * nucleons + mass;
            }
        )); 
    }
};
