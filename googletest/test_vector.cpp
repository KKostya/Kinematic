#include "gtest/gtest.h"
#include "kinematic.hpp"

// GeV Units tests

TEST(KinematicVector,ProtonGeV_p_beta) {
    Particle proton( 0.938, 1, 1);
    std::vector<double> momenta = {5,1};
    auto beta = proton.p(momenta).beta();
    EXPECT_DOUBLE_EQ( beta[0] , 0.98285437970289613);
    EXPECT_DOUBLE_EQ( beta[1] , 0.72935521859971675);
}

TEST(KinematicVector,ProtonGeV_loop1) {            
    Particle proton( 0.938, 1, 1);
    std::vector<double> Ek = {0.6,0.8,1.0,2.0};
    std::vector<double> loop = proton.p(proton.beta(proton.Ek(Ek).beta()).p()).Ek();    
    
    EXPECT_DOUBLE_EQ( loop[0] , Ek[0] );
    EXPECT_DOUBLE_EQ( loop[1] , Ek[1] );
    EXPECT_DOUBLE_EQ( loop[2] , Ek[2] );
    EXPECT_DOUBLE_EQ( loop[3] , Ek[3] );    
}

TEST(KinematicVector,ProtonGeV_loop2) {            
    Particle proton( 0.938, 1, 1);
    std::vector<double> beta = {0.7,0.8,0.9,0.98,0.991};
    std::vector<double> loop = proton.p(proton.Ek(proton.beta(beta).Ek()).p()).beta();    
    
    EXPECT_DOUBLE_EQ( loop[0] , beta[0] );
    EXPECT_DOUBLE_EQ( loop[1] , beta[1] );
    EXPECT_DOUBLE_EQ( loop[2] , beta[2] );
    EXPECT_DOUBLE_EQ( loop[3] , beta[3] );    
    EXPECT_DOUBLE_EQ( loop[4] , beta[4] );        
}

TEST(KinematicVector,HeliumGeV_p_beta) {
    Particle helium( 3.727, 2, 4);
    std::vector<double> momenta = {5,1};
    auto beta = helium.p(momenta).beta();
    EXPECT_DOUBLE_EQ( beta[0] , 0.80176681894408008);
    EXPECT_DOUBLE_EQ( beta[1] , 0.25914625471721692);
}

TEST(KinematicVector,HeliumGeV_loop1) {            
    Particle helium( 3.727, 2, 4);
    std::vector<double> Ek = {1.7,1.9,2.0,4.0};
    std::vector<double> loop = helium.p(helium.beta(helium.Ek(Ek).beta()).p()).Ek();    
    
    EXPECT_DOUBLE_EQ( loop[0] , Ek[0] );
    EXPECT_DOUBLE_EQ( loop[1] , Ek[1] );
    EXPECT_DOUBLE_EQ( loop[2] , Ek[2] );
    EXPECT_DOUBLE_EQ( loop[3] , Ek[3] );    
}

TEST(KinematicVector,HeliumGeV_loop2) {            
    Particle helium( 3.727, 2, 4);
    std::vector<double> beta = {0.7,0.8,0.9,0.98,0.991};
    std::vector<double> loop = helium.p(helium.Ek(helium.beta(beta).Ek()).p()).beta();    
    
    EXPECT_DOUBLE_EQ( loop[0] , beta[0] );
    EXPECT_DOUBLE_EQ( loop[1] , beta[1] );
    EXPECT_DOUBLE_EQ( loop[2] , beta[2] );
    EXPECT_DOUBLE_EQ( loop[3] , beta[3] );    
    EXPECT_DOUBLE_EQ( loop[4] , beta[4] );        
}
