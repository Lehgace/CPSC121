#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "../super_enemy.hpp"
#include "gtest_ext.h"

TEST(Enemy, PublicMethodsPresent) {
  Enemy e;
  e.xpos();
  e.set_xpos(1);
  e.ypos();
  e.set_ypos(1);
  e.health();
  e.set_health(1);
  e.strength();
  e.set_strength(1);
  e.defense();
  e.set_defense(1);
  e.move_up();
  e.move_down();
  e.move_right();
  e.move_left();
  e.level_up();
  SIMULATE_SIO("", { e.display(); }, {})
}

TEST(Enemy, AccessorsAndMutators) {
  Enemy your_enemy;
  your_enemy.set_xpos(1);
  your_enemy.set_ypos(2);
  your_enemy.set_health(10);
  your_enemy.set_strength(20);
  your_enemy.set_defense(30);
  ASSERT_EQ(your_enemy.xpos(), 1) << "The enemy xpos should be se to 1";
  ASSERT_EQ(your_enemy.ypos(), 2) << "The enemy ypos should be se to 2";
  ASSERT_EQ(your_enemy.health(), 10) << "The enemy health should be se to 10";
  ASSERT_EQ(your_enemy.strength(), 20)
      << "The enemy strength should be se to 20";
  ASSERT_EQ(your_enemy.defense(), 30) << "The enemy defense should be se to 30";
}

TEST(Enemy, DefaultConstructor) {
  Enemy your_enemy;
  ASSERT_EQ(your_enemy.xpos(), 0) << "The enemy xpos should be se to 0";
  ASSERT_EQ(your_enemy.ypos(), 0) << "The enemy ypos should be se to 0";
  ASSERT_EQ(your_enemy.health(), 5) << "The enemy health should be se to 5";
  ASSERT_EQ(your_enemy.strength(), 3) << "The enemy strength should be se to 3";
  ASSERT_EQ(your_enemy.defense(), 1) << "The enemy defense should be se to 1";
}

TEST(Enemy, NonDefaultConstructor) {
  Enemy your_enemy(1, 1, 10, 20, 30);
  ASSERT_EQ(your_enemy.xpos(), 1) << "The default enemy xpos should be se to 1";
  ASSERT_EQ(your_enemy.ypos(), 1) << "The default enemy ypos should be se to 1";
  ASSERT_EQ(your_enemy.health(), 10) << "The default enemy health should be se to 10";
  ASSERT_EQ(your_enemy.strength(), 20) << "The default enemy strength should be se to 20";
  ASSERT_EQ(your_enemy.defense(), 30) << "The default enemy defense should be se to 30";
}

TEST(Enemy, MoveUp) {
  Enemy your_enemy;
  your_enemy.set_ypos(22);
  your_enemy.move_up();
  ASSERT_EQ(your_enemy.ypos(), 23)
      << "The enemy ypos should be 23 after moving "
         "up from a starting ypos of 22.";
}

TEST(Enemy, MoveDown) {
  Enemy your_enemy;
  your_enemy.set_ypos(22);
  your_enemy.move_down();
  ASSERT_EQ(your_enemy.ypos(), 21)
      << "The enemy ypos should be 21 after moving "
         "down from a starting ypos of 22.";
}

TEST(Enemy, MoveRight) {
  Enemy your_enemy;
  your_enemy.set_xpos(17);
  your_enemy.move_right();
  ASSERT_EQ(your_enemy.xpos(), 18)
      << "The enemy ypos should be 18 after moving "
         "right from a starting xpos of 17.";
}

TEST(Enemy, MoveLeft) {
  Enemy your_enemy;
  your_enemy.set_xpos(17);
  your_enemy.move_left();
  ASSERT_EQ(your_enemy.xpos(), 16)
      << "The enemy ypos should be 16 after moving "
         "left from a starting xpos of 17.";
}

TEST(Enemy, LevelUp) {
  Enemy your_enemy(5, 6, 10, 20, 30);
  your_enemy.level_up();
  ASSERT_EQ(your_enemy.health(), 12)
      << "The enemy with health 10 should have health 12 after leveling up.";
  ASSERT_EQ(your_enemy.strength(), 21)
      << "The enemy with health 20 should have strength 21 after leveling up.";
  ASSERT_EQ(your_enemy.defense(), 31)
      << "The enemy with health 30 should have defense 31 after leveling up.";
}

TEST(Enemy, Display) {
  Enemy your_enemy(5, 6, 10, 20, 30);
  std::string unittest_output = "Enemy\n"
                                "Coordinates: (5, 6)\n"
                                "Health: 10\n"
                                "Strength: 20\n"
                                "Defense: 30\n";
  SIMULATE_SIO(
      "", { your_enemy.display(); },
      { ASSERT_EQ(your_output, unittest_output); })
}

TEST(SuperEnemy, CheckInheritance) {
  SuperEnemy your_super_enemy;
  Enemy* your_enemy = dynamic_cast<Enemy*>(&your_super_enemy);
  ASSERT_NE(your_enemy, nullptr)
      << "The SuperEnemy class should inherit from the Enemy class.";
}

TEST(SuperEnemy, PublicMethodsPresent) {
  SuperEnemy se;
  se.move_up();
  se.move_down();
  se.move_right();
  se.move_left();
  se.level_up();
  SIMULATE_SIO("", { se.display(); }, {})
}

TEST(SuperEnemy, DefaultConstructor) {
  SuperEnemy your_super_enemy;
  ASSERT_EQ(your_super_enemy.xpos(), 0) << "The default super enemy xpos should be se to 0";
  ASSERT_EQ(your_super_enemy.ypos(), 0) << "The default super enemy ypos should be se to 0";
  ASSERT_EQ(your_super_enemy.health(), 7) << "The default super enemy health should be se to 7";
  ASSERT_EQ(your_super_enemy.strength(), 5) << "The default super enemy strength should be se to 5";
  ASSERT_EQ(your_super_enemy.defense(), 3) << "The default super enemy defense should be se to 3";
}

TEST(SuperEnemy, NonDefaultConstructor) {
  SuperEnemy your_super_enemy(1, 1, 10, 20, 30);
  ASSERT_EQ(your_super_enemy.xpos(), 1) << "The default super enemy xpos should be se to 1";
  ASSERT_EQ(your_super_enemy.ypos(), 1) << "The default super enemy ypos should be se to 1";
  ASSERT_EQ(your_super_enemy.health(), 10) << "The default super enemy health should be se to 10";
  ASSERT_EQ(your_super_enemy.strength(), 20) << "The default super enemy strength should be se to 20";
  ASSERT_EQ(your_super_enemy.defense(), 30) << "The default super enemy defense should be se to 30";
}

TEST(SuperEnemy, MoveUp) {
  SuperEnemy your_super_enemy;
  your_super_enemy.set_ypos(22);
  your_super_enemy.move_up();
  ASSERT_EQ(your_super_enemy.ypos(), 24)
      << "The super enemy ypos should be 24 after moving "
         "up from a starting ypos of 22.";
}

TEST(SuperEnemy, MoveDown) {
  SuperEnemy your_super_enemy;
  your_super_enemy.set_ypos(22);
  your_super_enemy.move_down();
  ASSERT_EQ(your_super_enemy.ypos(), 20)
      << "The super enemy ypos should be 20 after moving "
         "up from a starting ypos of 22.";
}

TEST(SuperEnemy, MoveRight) {
  SuperEnemy your_super_enemy;
  your_super_enemy.set_xpos(17);
  your_super_enemy.move_right();
  ASSERT_EQ(your_super_enemy.xpos(), 19)
      << "The super enemy xpos should be 19 after moving "
         "up from a starting xpos of 17.";
}

TEST(SuperEnemy, MoveLeft) {
  SuperEnemy your_super_enemy;
  your_super_enemy.set_xpos(17);
  your_super_enemy.move_left();
  ASSERT_EQ(your_super_enemy.xpos(), 15)
      << "The super enemy xpos should be 15 after moving "
         "up from a starting xpos of 17.";
}

TEST(SuperEnemy, LevelUp) {
  SuperEnemy your_super_enemy(5, 6, 10, 20, 30);
  your_super_enemy.level_up();
  ASSERT_EQ(your_super_enemy.health(), 15)
      << "The enemy with health 10 should have health 15 after leveling up.";
  ASSERT_EQ(your_super_enemy.strength(), 23)
      << "The enemy with health 20 should have strength 23 after leveling up.";
  ASSERT_EQ(your_super_enemy.defense(), 32)
      << "The enemy with health 30 should have defense 32 after leveling up.";
}

TEST(SuperEnemy, Display) {
  SuperEnemy your_super_enemy(5, 6, 10, 20, 30);
  std::string unittest_output = "Super Enemy\n"
                                "Coordinates: (5, 6)\n"
                                "Health: 10\n"
                                "Strength: 20\n"
                                "Defense: 30\n";
  SIMULATE_SIO(
      "", { your_super_enemy.display(); },
      { ASSERT_EQ(your_output, unittest_output); })
}

TEST(Driver, Output) {

  std::string unittest_output = "Enemy\n"
                                "Coordinates: (0, 0)\n"
                                "Health: 5\n"
                                "Strength: 3\n"
                                "Defense: 1\n\n"

                                "Super Enemy\n"
                                "Coordinates: (0, 0)\n"
                                "Health: 7\n"
                                "Strength: 5\n"
                                "Defense: 3\n\n"

                                "Enemy\n"
                                "Coordinates: (5, 5)\n"
                                "Health: 7\n"
                                "Strength: 4\n"
                                "Defense: 2\n\n"

                                "Super Enemy\n"
                                "Coordinates: (10, 10)\n"
                                "Health: 12\n"
                                "Strength: 8\n"
                                "Defense: 5\n";

  ASSERT_EXECEQ("main", "", unittest_output);
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  ::testing::UnitTest::GetInstance()->listeners().Append(new SkipListener());
  return RUN_ALL_TESTS();
}
