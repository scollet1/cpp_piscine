/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 10:47:21 by scollet           #+#    #+#             */
/*   Updated: 2018/01/13 15:13:04 by jchow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Header.hpp"
#include "Character.hpp"

/*******************************************************************************
**********************************  CHARACTER  *********************************
*******************************************************************************/


/************* PUBLIC *************/

// Coplien Methods

Character::Character(int x, int y, bool direction, unsigned int hp, unsigned int atkDmg, unsigned int bulletSpeed):
GameEntity(x, y, direction, ALIVE),
_hp(hp), _atkDmg(atkDmg), _bulletSpeed(bulletSpeed) {};

Character::Character(Character const& rhs) {
    *this = rhs;
};

Character& Character::operator=(Character const& rhs) {

    _hp = rhs._hp;
    _atkDmg = rhs._atkDmg;
    _bulletSpeed = rhs._bulletSpeed;
    _posX = rhs._posX;
    _posY = rhs._posY;
    _direction = rhs._direction;
    _alive = rhs._alive;

    for (int i = 0; i < MAX_BULLETS; i++) {
        _bullets[i] = rhs._bullets[i];
    }

    return *this;
};

Character::~Character() {

    for (int i = 0; i < MAX_BULLETS; i++) {
        delete _bullets[i];
    }
};

// Getters

unsigned int Character::getHP() const {
    return _hp;
};

unsigned int Character::getAtkDmg() const {
    return _atkDmg;
};

unsigned int Character::getBulletSpeed() const {
    return _bulletSpeed;
};

Bullet*      Character::getBullet(int idx) const {
    if (idx >= 0 && idx < MAX_BULLETS) {
        return _bullets[idx];
    }
    return NULL;
};

// Methods

void         Character::shootBullet() {

    for (int i = 0; i < MAX_BULLETS; i++) {
        // exit(1); // TESTING SEGFAULT
        if (this->_bullets[i]->getAliveStatus() == false) {
            this->_bullets[i]->activateBullet(_posY - 1, _posX);
            return ;
        }
    }

    // Else, bullet slots are full, do not fire.

};

void         Character::takeDamage(unsigned int dmg) {

    if (dmg >= _hp) {

        _hp = 0;
        triggerDeath();

    } else {
        _hp -= dmg;
    }
};


/*******************************************************************************
***********************************  PLAYER  ***********************************
*******************************************************************************/


/************ PRIVATE ************/

void    Player::initBullets() {

    for (int i = 0; i < MAX_BULLETS; i++) {
        _bullets[i] = new Bullet(_atkDmg, _bulletSpeed, ALLY);
    }
};

void         Player::triggerDeath() {

    _lives -= 1;

    if (_lives == 0) {
        _alive = false;
    } else {
        _posX = _maxY - 5;
        _posY = _maxX / 2;
        _hp = PLAYER_HP;
    }
};

/************* PUBLIC *************/

// Coplien Methods

Player::Player(int y, int x) :
Character(x, y, UP, PLAYER_HP, PLAYER_DAMAGE, PLAYER_BULLET_SPEED),
 _lives(PLAYER_LIVES) {

    Player::initBullets();
};

Player::Player(Player const& rhs) {
    *this = rhs;
};

Player& Player::operator=(Player const& rhs) {

    _hp = rhs._hp;
    _lives = rhs._lives;
    _atkDmg = rhs._atkDmg;
    _bulletSpeed = rhs._bulletSpeed;
    _posX = rhs._posX;
    _posY = rhs._posY;
    _direction = rhs._direction;
    _alive = rhs._alive;

    for (int i = 0; i < MAX_BULLETS; i++) {
        _bullets[i] = rhs._bullets[i];
    }

    return *this;
};

// Getters

unsigned int Player::getLives() const {
    return _lives;
};

// Methods

void         Player::updateObject(int y, int x) {
  _posX += x;
  _posY += y;
  return ;
    // Move the player and stuff
};
