/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchow <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 15:00:29 by jchow             #+#    #+#             */
/*   Updated: 2018/01/13 15:13:14 by jchow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Header.hpp"
#include "Bullet.hpp"
#include "Character.hpp"

/*******************************************************************************
************************************  BULLET  **********************************
*******************************************************************************/


/************* PRIVATE *************/

// Coplien methods

Bullet::Bullet(unsigned int dmg, unsigned int speed, bool friendly) :
GameEntity(-1, -1, friendly, DEAD), _atkDmg(dmg), _speed(speed), _friendly(friendly) {};

Bullet::Bullet(Bullet const& rhs) {
    *this = rhs;
};

Bullet& Bullet::operator=(Bullet const& rhs) {

    _atkDmg = rhs._atkDmg;
    _speed = rhs._speed;
    _friendly = rhs._friendly;
    _alive = rhs._alive;
    return *this;
};


/************* PUBLIC *************/

// Getters

unsigned int Bullet::getAtkDmg() const {
    return _atkDmg;
};

unsigned int Bullet::getSpeed() const {
    return _speed;
};

bool         Bullet::getFriendly() const {
    return _friendly;
};

unsigned int Bullet::getSpeedCoolDown() const {
    return _speedCD;
};

// Methods

void         Bullet::activateBullet(int y, int x) {

    _alive = true;
    _posX = x;
    _posY = y;
    return ;
};

void         Bullet::deactivateBullet() {

    _alive = false;
    return ;
};

void         Bullet::hitTarget(Character& target) {

    target.takeDamage(_atkDmg);
    deactivateBullet();
};

void         Bullet::updateObject(int y, int x) {
    _posX += x;
    _posY += y;
    _speedCD = PLAYER_BULLET_SPEED;
    return ;
};
