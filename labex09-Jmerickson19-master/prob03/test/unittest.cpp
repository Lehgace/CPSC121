#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <random>
#include "../player.hpp"
#include "gtest_ext.h"

using ::testing::HasSubstr;

TEST(Player, DefaultConstructor) {
  Player your_player;
  ASSERT_EQ(your_player.xpos(), 0) << "The default constructor should set xpos to 0.";
  ASSERT_EQ(your_player.ypos(), 0) << "The default constructor should set ypos to 0.";
  ASSERT_EQ(your_player.name(), "Ash") << "The default constructor should set name to Ash.";
  ASSERT_EQ(your_player.health(), 10) << "The default constructor should set health to 10.";
  ASSERT_EQ(your_player.strength(), 5) << "The default constructor should set strength to 5.";
  ASSERT_EQ(your_player.defense(), 2) << "The default constructor should set defense to 2.";
}

TEST(Player, NonDefaultConstructor) {
  Player your_player("Almira", 5, 4, 3, 2, 1);
  ASSERT_EQ(your_player.xpos(), 2) << "The nondefault constructor should have set xpos to 2.";
  ASSERT_EQ(your_player.ypos(), 1) << "The nondefault constructor should have set ypos to 1.";
  ASSERT_EQ(your_player.name(), "Almira") << "The nondefault constructor should have set name to Almira.";
  ASSERT_EQ(your_player.health(), 5) << "The nondefault constructor should have set health to 5.";
  ASSERT_EQ(your_player.strength(), 4)<< "The nondefault constructor should have set strength to 4.";
  ASSERT_EQ(your_player.defense(), 3)<< "The nondefault constructor should have set defense to 3.";
}

TEST(Player, PublicMethodPresent) {
  Player your_player1;
  your_player1.xpos();
  your_player1.ypos();
  your_player1.name();
  your_player1.health();
  your_player1.strength();
  your_player1.defense();
  your_player1.set_xpos(1);
  your_player1.set_ypos(1);
  your_player1.set_name("Name");
  your_player1.set_health(1);
  your_player1.set_strength(1);
  your_player1.set_defense(1);
  SIMULATE_SIO("", {
    your_player1.display_stat();
    your_player1.player_move();
    your_player1.is_player_dead();
    your_player1.take_damage(1);
  }, {})  
}

TEST(Player, MutatorsAndAccessors) {
  Player your_player;
  your_player.set_xpos(2);
  your_player.set_ypos(1);
  your_player.set_name("Almira");
  your_player.set_health(5);
  your_player.set_strength(4);
  your_player.set_defense(3);

  ASSERT_EQ(your_player.xpos(), 2) << "The mutator should have set xpos to 2.";
  ASSERT_EQ(your_player.ypos(), 1) << "The mutator should have set ypos to 1.";
  ASSERT_EQ(your_player.name(), "Almira") << "The mutator should have set name to Almira.";
  ASSERT_EQ(your_player.health(), 5) << "The mutator should have set health to 5.";
  ASSERT_EQ(your_player.strength(), 4)<< "The mutator should have set strength to 4.";
  ASSERT_EQ(your_player.defense(), 3)<< "The mutator should have set defense to 3.";
}

TEST(Player, DisplayStat) {
  Player your_player;
  your_player.set_xpos(22);
  your_player.set_ypos(71);
  your_player.set_name("Shaniqua");
  your_player.set_health(50);
  your_player.set_strength(14);
  your_player.set_defense(47);

  SIMULATE_SIO("", {
    your_player.display_stat();
  }, {
    ASSERT_THAT(your_output, HasSubstr("22")) << "The display should have shown xpos as 22.";
    ASSERT_THAT(your_output, HasSubstr("71")) << "The display should have shown ypos as 71.";
    ASSERT_THAT(your_output, HasSubstr("Shaniqua")) << "The display should have shown name as Shaniqua.";
    ASSERT_THAT(your_output, HasSubstr("50")) << "The display should have shown health as 50.";
    ASSERT_THAT(your_output, HasSubstr("14"))<< "The display should have shown strength as 14.";
    ASSERT_THAT(your_output, HasSubstr("47"))<< "The display should have shown defense as 47.";
  });
}

TEST(Player, ChangePosition1) {
  Player your_player;
  your_player.player_move();
  your_player.player_move();
  your_player.player_move();
  ASSERT_EQ(your_player.xpos(), 3) << "Callling player_move three times should have set xpos to 3.";
  ASSERT_EQ(your_player.ypos(), 3) << "Callling player_move three times should have set ypos to 3.";
}

TEST(Player, ChangePosition2) {
  Player your_player;
  your_player.player_move();
  your_player.player_move();
  your_player.player_move();
  your_player.player_move();
  your_player.player_move();
  your_player.player_move();  
  ASSERT_EQ(your_player.xpos(), 6) << "Callling player_move six times should have set xpos to 6.";
  ASSERT_EQ(your_player.ypos(), 6) << "Callling player_move six times should have set ypos to 6.";
}

TEST(Player, IsPlayerDeadFalse) {
  Player your_player;
  your_player.set_health(10);
  ASSERT_FALSE(your_player.is_player_dead()) << "The player should not be dead with a health of 10.";
}

TEST(Player, IsPlayerDeadTrue) {
  Player your_player;
  your_player.set_health(0);
  ASSERT_TRUE(your_player.is_player_dead()) << "The player should be dead with a health of 0.";
}

TEST(Player, DamagePlayerAlive) {
  Player your_player;
  your_player.set_name("Tifa");
  your_player.set_health(30);
  SIMULATE_SIO("", {
    your_player.take_damage(20);
  }, {
    ASSERT_THAT(your_output, HasSubstr("Tifa took 20 damage")) << "The program should display 20 damage dealt to Tifa.";
    ASSERT_THAT(your_output, Not(HasSubstr("Tifa is dead"))) << "The damage dealt to Tifa should not be enough to kill her.";
  })
}

TEST(Player, DamagePlayerDead) {
  Player your_player;
  your_player.set_name("Snake");
  your_player.set_health(30);
  SIMULATE_SIO("", {
    your_player.take_damage(40);
  }, {
    ASSERT_THAT(your_output, HasSubstr("Snake took 40 damage"));
    ASSERT_THAT(your_output, HasSubstr("Snake is dead"));
  })
}

TEST(Driver, Output) {
  std::string unittest_output = "Player: Ash\n"
                                "Health: 10\n"
                                "Strength: 5\n"
                                "Defense: 2\n"
                                "At position: (10, 10)\n\n"
                                "Player: Les\n"
                                "Health: 20\n"
                                "Strength: 10\n"
                                "Defense: 6\n"
                                "At position: (0, 0)\n\n"
                                "Ash took 25 damage\n"
                                "Ash is dead\n\n"
                                "Player: Ash\n"
                                "Health: 0\n"
                                "Strength: 5\n"
                                "Defense: 2\n"
                                "At position: (10, 10)\n";
  ASSERT_EXECEQ("main", "", unittest_output);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);    
  ::testing::UnitTest::GetInstance()->listeners().Append(new SkipListener());
  return RUN_ALL_TESTS();
}
