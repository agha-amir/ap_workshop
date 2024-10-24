#include "War.h"
#include "Resistance.h"
#include "Combine.h"
#include "GunList.h"
#include "Gun.h"
#include <gtest/gtest.h>


TEST(combine_reinforce, _cmbr1){
    GunList combineGuns;
    Gun* gun = new Gun(30, "ak47", 2.8, 1);
    combineGuns.addGun(*gun);
    *gun = Gun(7, "desert-eagle", 1.5, 0);
    combineGuns.addGun(*gun);
    *gun = Gun(25, "mp5", 3.5, 1);
    combineGuns.addGun(*gun);
    GunList resistanceGuns;
    *gun = Gun(30, "m4a4", 3.1, 1);
    resistanceGuns.addGun(*gun);
    *gun = Gun(25, "famas", 2.9, 1);
    resistanceGuns.addGun(*gun);
    *gun = Gun(30, "aug", 3.0, 1);
    resistanceGuns.addGun(*gun);
    Combine cmb(100, combineGuns, 80, 1);
    Resistance res(70, resistanceGuns, 30, 50);
    War war(res, cmb);
    war.startWar();
    EXPECT_EQ(war.getResult(), 1);
}

TEST(combine_reinforce, _cmbr2) {
    GunList combineGuns;
    Gun* gun = new Gun(30, "ak47", 2.8, 1);
    combineGuns.addGun(*gun);
    *gun = Gun(7, "desert-eagle", 1.5, 0);
    combineGuns.addGun(*gun);
    *gun = Gun(25, "mp5", 3.5, 1);
    combineGuns.addGun(*gun);
    GunList resistanceGuns;
    *gun = Gun(30, "m4a4", 3.1, 1);
    resistanceGuns.addGun(*gun);
    *gun = Gun(25, "famas", 2.9, 1);
    resistanceGuns.addGun(*gun);
    *gun = Gun(30, "aug", 3.0, 1);
    resistanceGuns.addGun(*gun);
    Combine cmb(10, combineGuns, 80, 1);
    Resistance res(70, resistanceGuns, 100, 50);
    War war(res, cmb);
    war.startWar();
    EXPECT_EQ(war.getResult(), 0);
}

TEST(combine_reinforce, _cmbr3) {
    GunList combineGuns;
    Gun* gun = new Gun(30, "ak47", 2.8, 1);
    combineGuns.addGun(*gun);
    *gun = Gun(7, "desert-eagle", 1.5, 0);
    combineGuns.addGun(*gun);
    *gun = Gun(25, "mp5", 3.5, 1);
    combineGuns.addGun(*gun);
    GunList resistanceGuns;
    *gun = Gun(20, "m4a4", 3.1, 1);
    resistanceGuns.addGun(*gun);
    *gun = Gun(15, "famas", 2.9, 1);
    resistanceGuns.addGun(*gun);
    *gun = Gun(20, "aug", 3.0, 1);
    resistanceGuns.addGun(*gun);
    Combine cmb(10, combineGuns, 80, 1);
    Resistance res(0, resistanceGuns, 100, 50);
    War war(res, cmb);
    war.startWar();
    EXPECT_EQ(war.getResult(), 1);
}


TEST(combine_no_reinforce, _cmbnr1) {
    GunList combineGuns;
    Gun* gun = new Gun(30, "ak47", 2.8, 1);
    combineGuns.addGun(*gun);
    *gun = Gun(7, "desert-eagle", 1.5, 0);
    combineGuns.addGun(*gun);
    *gun = Gun(25, "mp5", 3.5, 1);
    combineGuns.addGun(*gun);
    GunList resistanceGuns;
    *gun = Gun(30, "m4a4", 3.1, 1);
    resistanceGuns.addGun(*gun);
    *gun = Gun(25, "famas", 2.9, 1);
    resistanceGuns.addGun(*gun);
    *gun = Gun(30, "aug", 3.0, 1);
    resistanceGuns.addGun(*gun);
    Combine cmb(100000, combineGuns, 80, 0);
    Resistance res(10, resistanceGuns, 100, 50);
    War war(res, cmb);
    war.startWar();
    EXPECT_EQ(war.getResult(), 0);
}

TEST(combine_no_reinforce, _cmbnr1) {
    GunList combineGuns;
    Gun* gun = new Gun(30, "ak47", 2.8, 1);
    combineGuns.addGun(*gun);
    *gun = Gun(7, "desert-eagle", 1.5, 0);
    combineGuns.addGun(*gun);
    *gun = Gun(25, "mp5", 3.5, 1);
    combineGuns.addGun(*gun);
    GunList resistanceGuns;
    *gun = Gun(20, "m4a4", 3.1, 1);
    resistanceGuns.addGun(*gun);
    *gun = Gun(15, "famas", 2.9, 1);
    resistanceGuns.addGun(*gun);
    *gun = Gun(20, "aug", 3.0, 1);
    resistanceGuns.addGun(*gun);
    Combine cmb(100000, combineGuns, 80, 0);
    Resistance res(10, resistanceGuns, 100, 50);
    War war(res, cmb);
    war.startWar();
    EXPECT_EQ(war.getResult(), 1);
}


int main(int argc, char* argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}