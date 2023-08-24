#include <iostream>
#include <random>

class Weapon
{
private:
  int attack_min_;
  int attack_max_;
  std::string name_;

public:
  Weapon() : Weapon(1, 2, "weapon") {}
  Weapon(int attack_min, int attack_max, const std::string & name)
      : attack_min_(attack_min), attack_max_(attack_max), name_(name)
  {
  }

  void set_attack_min(int attack_min) { attack_min_ = attack_min; }
  int attack_min() const { return attack_min_; }
  void set_attack_max(int attack_max) { attack_max_ = attack_max; }
  int attack_max() const { return attack_max_; }
  void set_name(const std::string & name) { name_ = name; }
  std::string name() const { return name_; }

  virtual int attack();
};

class Daggers : public Weapon
{
private:
  int crit_;
  int crit_dice_;

public:
  Daggers() : Daggers(2, 3, "daggers", 1, 18) {}
  Daggers(int attack_min, int attack_max, const std::string & name, int crit,
          int crit_dice)
      : Weapon(attack_min, attack_max, name), crit_(crit), crit_dice_(crit_dice)
  {
  }

  void set_crit(int crit) { crit_ = crit; }
  int crit() { return crit_; }
  void set_crit_dice(int crit_dice) { crit_dice_ = crit_dice; }
  int crit_dice() { return crit_dice_; }

  int attack() override;
};

class ShortSword : public Weapon
{
private:
  int multiplier_;

public:
  ShortSword() : ShortSword(6, 7, "shortsword", 1) {}
  ShortSword(int attack_min, int attack_max, const std::string & name,
             int multiplier)
      : Weapon(attack_min, attack_max, name), multiplier_(multiplier)
  {
  }

  void set_multiplier(int multiplier) { multiplier_ = multiplier; }
  int multiplier() { return multiplier_; }

  int attack() override;
};

class Enemy
{
private:
  std::string name_;
  int health_;

public:
  Enemy() : Enemy("dragon", 500) {}
  Enemy(const std::string & name, int health) : name_(name), health_(health) {}

  void set_name(const std::string & name) { name_ = name; }
  std::string name() const { return name_; }
  void set_health(int health) { health_ = health; }
  int health() { return health_; }

  void receive_attack(Weapon * wep);
};
