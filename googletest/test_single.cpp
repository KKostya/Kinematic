#include "gtest/gtest.h"
#include "kinematic.hpp"

double mp = 0.938, mhe = 3.727, melectron = 0.000511;

// GeV Units tests

TEST(KinematicSingle,ProtonGeV_p_beta) {
    Particle proton( 0.938, 1, 1);
    EXPECT_DOUBLE_EQ( proton.p(5).beta() , 0.98285437970289613);
    EXPECT_DOUBLE_EQ( proton.p(1).beta() , 0.72935521859971675);
}

TEST(KinematicSingle,ProtonGeV_p_E) {        
    Particle proton( 0.938, 1, 1);    
    EXPECT_DOUBLE_EQ( proton.p(2).E()    , 2.209036894214309  );
}

TEST(KinematicSingle,ProtonGeV_p_Ek) {        
    Particle proton( 0.938, 1, 1);        
    EXPECT_DOUBLE_EQ( proton.p(2.7).Ek() , 1.9202938967153116 );
}

TEST(KinematicSingle,ProtonGeV_Ekn_p) {        
    Particle proton( 0.938, 1, 1);        
    EXPECT_DOUBLE_EQ( proton.Ekn(1.0).p(), 1.6958773540560059 );
}

TEST(KinematicSingle,ProtonGeV_loops) {            
    Particle proton( 0.938, 1, 1);            
    EXPECT_DOUBLE_EQ( proton.p(proton.beta(proton.Ek(0.5).beta()).p()).Ek(), 0.5);
    EXPECT_DOUBLE_EQ( proton.p(proton.Ek(proton.beta(0.6).Ek()).p()).beta(), 0.6);
}

TEST(KinematicSingle,Helium4GeV_p_beta) {
    Particle helium( 3.727, 2, 4);
    EXPECT_DOUBLE_EQ( helium.p(5).beta() , 0.80176681894408008);
    EXPECT_DOUBLE_EQ( helium.p(1).beta() , 0.25914625471721692);    
}

TEST(KinematicSingle,Helium4GeV_p_E) {    
    Particle helium( 3.727, 2, 4);
    EXPECT_DOUBLE_EQ( helium.p(2).E()    , 4.2297197306677425 );
}

TEST(KinematicSingle,Helium4GeV_p_Ek) {    
    Particle helium( 3.727, 2, 4);
    EXPECT_DOUBLE_EQ( helium.p(2.7).Ek() , 0.87523087208801398);
}

TEST(KinematicSingle,Helium4GeV_Ekn_p) {    
    Particle helium( 3.727, 2, 4);
    EXPECT_DOUBLE_EQ( helium.Ekn(1.0).p(), 6.7687517313017178 );
}

TEST(KinematicSingle,Helium4GeV_loops) {    
    Particle helium( 3.727, 2, 4);
    EXPECT_DOUBLE_EQ( helium.p(helium.beta(helium.Ek(0.5).beta()).p()).Ek(), 0.5);
    EXPECT_DOUBLE_EQ( helium.p(helium.Ek(helium.beta(0.6).Ek()).p()).beta(), 0.6);
}

// MeV Units

TEST(KinematicSingle,ProtonMeV_p_beta) {
    Particle proton( 938, 1, 1);
    EXPECT_DOUBLE_EQ( proton.p(5000).beta() , 0.98285437970289613);
    EXPECT_DOUBLE_EQ( proton.p(1000).beta() , 0.72935521859971675);
}

TEST(KinematicSingle,ProtonMeV_p_E) {        
    Particle proton( 938, 1, 1);    
    EXPECT_DOUBLE_EQ( proton.p(2000).E()    , 2209.036894214309  );
}

TEST(KinematicSingle,ProtonMeV_p_Ek) {        
    Particle proton( 938, 1, 1);        
    EXPECT_DOUBLE_EQ( proton.p(2700).Ek() , 1920.2938967153116 );
}

TEST(KinematicSingle,ProtonMeV_Ekn_p) {        
    Particle proton( 938, 1, 1);        
    EXPECT_DOUBLE_EQ( proton.Ekn(1000).p(), 1695.8773540560059 );
}

TEST(KinematicSingle,ProtonMeV_loops) {            
    Particle proton( 938, 1, 1);            
    EXPECT_DOUBLE_EQ( proton.p(proton.beta(proton.Ek(500).beta()).p()).Ek(), 500);
    EXPECT_DOUBLE_EQ( proton.p(proton.Ek(proton.beta(0.6).Ek()).p()).beta(), 0.6);
}

TEST(KinematicSingle,Helium4MeV_p_beta) {
    Particle helium( 3727, 2, 4);
    EXPECT_DOUBLE_EQ( helium.p(5000).beta() , 0.80176681894408008);
    EXPECT_DOUBLE_EQ( helium.p(1000).beta() , 0.25914625471721692);    
}

TEST(KinematicSingle,Helium4MeV_p_E) {    
    Particle helium( 3727, 2, 4);
    EXPECT_DOUBLE_EQ( helium.p(2000).E()    , 4229.7197306677425 );
}

TEST(KinematicSingle,Helium4MeV_p_Ek) {    
    Particle helium( 3727, 2, 4);
    EXPECT_DOUBLE_EQ( helium.p(2700).Ek() , 875.23087208801398);
}

TEST(KinematicSingle,Helium4MeV_Ekn_p) {    
    Particle helium( 3727, 2, 4);
    EXPECT_DOUBLE_EQ( helium.Ekn(1000).p(), 6768.7517313017178 );
}

TEST(KinematicSingle,Helium4MeV_loops) {    
    Particle helium( 3727, 2, 4);
    EXPECT_DOUBLE_EQ( helium.p(helium.beta(helium.Ek(500).beta()).p()).Ek(), 500);
    EXPECT_DOUBLE_EQ( helium.p(helium.Ek(helium.beta(0.6).Ek()).p()).beta(), 0.6);
}