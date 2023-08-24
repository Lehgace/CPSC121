#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "gtest_ext.h"
#include "../weapons.hpp"

using ::testing::HasSubstr;

class DaggerTest: public ::testing::Test {
public:
  void SetUp() override {

  }

  void TearDown() override {
    delete your_dagger;
  }
  Weapon* your_dagger;
};

class ShortSwordTest : public ::testing::Test {
public:
  void SetUp() override {
  }

  void TearDown() override {
    delete your_short_sword;
  }
  Weapon* your_short_sword;
};

TEST(Weapon, DefaultConstructor) {
  Weapon your_weapon;
  ASSERT_EQ(your_weapon.name(), "weapon") << "The default name should be weapon.";
  ASSERT_EQ(your_weapon.attack_min(), 1) << "The default attack_min should be 1.";
  ASSERT_EQ(your_weapon.attack_max(), 2)  << "The default attack_max should be 2.";
}

TEST(Weapon, NonDefaultConstructor) {
  Weapon your_weapon(0, 1, "weap");
  ASSERT_EQ(your_weapon.name(), "weap")  << "The name should be weap.";
  ASSERT_EQ(your_weapon.attack_min(), 0)  << "The attack_min should be 0.";
  ASSERT_EQ(your_weapon.attack_max(), 1) << "The attack_max should be 1.";
}

TEST(Daggers, AccessorAndMutator) {
  Daggers your_dagger;
  your_dagger.set_crit(4);
  your_dagger.set_crit_dice(14);
  ASSERT_EQ(your_dagger.crit(), 4) << "The default crit should be 4.";
  ASSERT_EQ(your_dagger.crit_dice(), 14) << "The default crit_dice should be 14.";
}

TEST(Daggers, DefaultConstructor) {
  Daggers your_dagger;
  ASSERT_EQ(your_dagger.name(), "daggers") << "The default name should be daggers.";
  ASSERT_EQ(your_dagger.attack_min(), 2) << "The default attack_min should be 2.";
  ASSERT_EQ(your_dagger.attack_max(), 3) << "The default attack_max should be 3.";
  ASSERT_EQ(your_dagger.crit(), 1) << "The default crit should be 1.";
  ASSERT_EQ(your_dagger.crit_dice(), 18) << "The default crit_dice should be 18.";
}

TEST(Daggers, NonDefaultConstructor) {
  Daggers your_dagger(3, 4, "dags", 3, 15);
  ASSERT_EQ(your_dagger.name(), "dags")  << "The name should be dags.";
  ASSERT_EQ(your_dagger.attack_min(), 3) << "The attack_min should be 3.";
  ASSERT_EQ(your_dagger.attack_max(), 4) << "The attack_max should be 4.";
  ASSERT_EQ(your_dagger.crit(), 3) << "The crit should be 3.";
  ASSERT_EQ(your_dagger.crit_dice(), 15) << "The crit_dice should be 15.";
}

TEST(Shortsword, AccessorAndMutator) {
  ShortSword your_short_sword;
  your_short_sword.set_multiplier(3);
  ASSERT_EQ(your_short_sword.multiplier(), 3) << "The multiplier should be 3.";
}

TEST(ShortSword, DefaultConstructor) {
  ShortSword your_short_sword;
  ASSERT_EQ(your_short_sword.name(), "shortsword")  << "The default name should be shortsword.";
  ASSERT_EQ(your_short_sword.attack_min(), 6) << "The default attack_min should be 6.";
  ASSERT_EQ(your_short_sword.attack_max(), 7) << "The default attack_max should be 7.";
  ASSERT_EQ(your_short_sword.multiplier(), 1) << "The default multiplier should be 1.";
}

TEST(Shortsword, NonDefaultConstructor) {
  ShortSword your_short_sword(5, 9, "sword", 4);
  ASSERT_EQ(your_short_sword.name(), "sword") << "The name should be sword.";
  ASSERT_EQ(your_short_sword.attack_min(), 5) << "The attack_min should be 5.";
  ASSERT_EQ(your_short_sword.attack_max(), 9) << "The attack_max should be 9.";
  ASSERT_EQ(your_short_sword.multiplier(), 4) << "The multiplier should be 4.";
}

TEST(Enemy, AccessorAndMutator) {
  Enemy your_enemy;
  your_enemy.set_name("bear");
  your_enemy.set_health(50);
  ASSERT_EQ(your_enemy.name(), "bear") << "The name should be bear.";
  ASSERT_EQ(your_enemy.health(), 50) << "The health should be 50.";
}

TEST(Enemy, DefaultConstructor) {
  Enemy your_enemy;
  ASSERT_EQ(your_enemy.name(), "dragon") << "The default name should be dragon.";
  ASSERT_EQ(your_enemy.health(), 500) << "The default health should be 500.";
}

TEST(Enemy, NonDefaultConstructor)  {
  Enemy your_enemy("orc", 30);
  ASSERT_EQ(your_enemy.name(), "orc") << "The name should be orc.";
  ASSERT_EQ(your_enemy.health(), 30) << "The health should be 30.";
}

TEST_F(DaggerTest, Damage1) {
  your_dagger = new Daggers(2,3,"super crit daggers",3,0);
  ASSERT_EQ(your_dagger->attack(), 12) << "Dagger's damage with attack min 3, attack max 4, crit 1, and crit dice 1 is 12.";
}

TEST_F(DaggerTest, Damage2) {
  your_dagger = new Daggers(3,4,"no crit daggers",1,21);
  ASSERT_EQ(your_dagger->attack(), 6) << "Dagger's damage with attack min 3, attack max 4, crit 1, and crit dice 1 is 6.";
}

TEST_F(ShortSwordTest, Damage1) {
  your_short_sword = new ShortSword(8,9,"super multiplier sword",1);
  ASSERT_EQ(your_short_sword->attack(), 8) << "Dagger's damage with attack min 8, attack max 9, and crit 0 is 8.";
}

TEST_F(ShortSwordTest, Damage2) {
  your_short_sword = new ShortSword(20,21,"no multip sword",1);
  ASSERT_EQ(your_short_sword->attack(), 20) << "Dagger's damage with attack min 3, attack max 4, crit 1, and crit dice 1 is 6.";
}

TEST_F(DaggerTest, EnemyDaggerAttack) {
  Enemy your_enemy("bear",30);
  your_dagger = new Daggers(3,4,"super crit daggers",1,1);
  SIMULATE_SIO("", {
    your_enemy.receive_attack(your_dagger);
  }, {
    ASSERT_THAT(your_output, HasSubstr("super crit daggers")) << "The message should state the name of the weapon.";
    ASSERT_THAT(your_output, HasSubstr("6 damage")) << "The message should state the damage of the weapon.";
    ASSERT_THAT(your_output, HasSubstr("bear")) << "The message should state the name of the enemy.";
  })
}

TEST_F(ShortSwordTest, EnemyShortSwordAttack) {
  Enemy your_enemy("bear",30);
  your_short_sword = new ShortSword(8,9,"super multiplier sword",1);
  SIMULATE_SIO("", {
    your_enemy.receive_attack(your_short_sword);
  }, {
    ASSERT_THAT(your_output, HasSubstr("super multiplier sword")) << "The message should state the name of the weapon.";
    ASSERT_THAT(your_output, HasSubstr("8 damage")) << "The message should state the damage of the weapon.";
    ASSERT_THAT(your_output, HasSubstr("bear")) << "The message should state the name of the enemy.";
  })
}

TEST_F(ShortSwordTest, EnemySlain) {
  Enemy your_enemy("ant",5);
  your_short_sword = new ShortSword(8,9,"super multiplier sword",1);
  SIMULATE_SIO("", {
    your_enemy.receive_attack(your_short_sword);
  }, {
    ASSERT_THAT(your_output, HasSubstr("super multiplier sword")) << "The message should state the name of the weapon.";
    ASSERT_THAT(your_output, HasSubstr("8 damage")) << "The message should state the damage of the weapon.";
    ASSERT_THAT(your_output, HasSubstr("ant")) << "The message should state the name of the enemy.";
    ASSERT_THAT(your_output, HasSubstr("has been slain")) << "The message should state that enemy was slain as its health is less than the minimum damage of the weapon.";
  })
}

TEST(Driver, Input) {
  std::string unittest_input = "goblin\n10\n";
  ASSERT_EXECEXIT("main", unittest_input, 3);
}

TEST(Driver, Output) {
  std::string unittest_input = "goblin\n10\n";
  ASSERT_EXECTHAT("main", unittest_input, HasSubstr("daggers")) << "The message should state the name of the first weapon, daggers.";
  ASSERT_EXECTHAT("main", unittest_input, HasSubstr("4 damage")) << "The message should state the damage of the daggers.";
  ASSERT_EXECTHAT("main", unittest_input, HasSubstr("shortsword")) << "The message should state the name of the second weapon, shortsword.";
  ASSERT_EXECTHAT("main", unittest_input, HasSubstr("6 damage")) << "The message should state the damage of the shortsword.";
  ASSERT_EXECTHAT("main", unittest_input, HasSubstr("goblin")) << "The message should state the name of the enemy.";
  ASSERT_EXECTHAT("main", unittest_input, HasSubstr("has been slain"))  << "The message should state that enemy was slain.";
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  ::testing::UnitTest::GetInstance()->listeners().Append(new SkipListener());
  return RUN_ALL_TESTS();
}
